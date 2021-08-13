#ifndef MEMORY_TRACKER_H
#define MEMORY_TRACKER_H
#include <map>
#include <mutex>
#include <typeinfo>
namespace VCUTIL {
    
    class MemoryTracker {
    public:
        typedef std::map<size_t, std::pair<std::string, int> > MAP_HASH_PAIR;
        static MAP_HASH_PAIR mapRefCount;
        static std::mutex mutex;

        template<typename T>
        static void AddRef() {
            static_assert(std::is_class<T>::value, "T must be class type.");
            const type_info& typeInfo = typeid(T);
            const size_t hash_code = typeInfo.hash_code();
            auto iter = mapRefCount.find(hash_code);
            if (iter == mapRefCount.end()) {
                mapRefCount[hash_code] = std::make_pair<std::string, int>(typeInfo.name(), 1);
            }
            else
            {
                iter->second.second++;
            }
        }

        template<typename T>
        static void ReleaseRef() {
            static_assert(std::is_class<T>::value, "T must be class type.");
            const type_info& typeInfo = typeid(T);
            const size_t hash_code = typeInfo.hash_code();
            auto iter = mapRefCount.find(hash_code);
            if (iter != mapRefCount.end()) {
                iter->second.second--;
            }
        }

        static void CheckMemoryLeak();
        MemoryTracker(){}
        ~MemoryTracker(){}
        MemoryTracker(const MemoryTracker&) = delete;
        MemoryTracker& operator=(const MemoryTracker&) = delete;
    };
}

#endif