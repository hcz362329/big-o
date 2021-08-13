#include "stdafx.h"
#include "memory_tracker.h"
#include <sstream>
#include <vector>
#include <algorithm>
namespace VCUTIL {
     MemoryTracker::MAP_HASH_PAIR MemoryTracker::mapRefCount;
     std::mutex MemoryTracker::mutex;

     void MemoryTracker::CheckMemoryLeak() {
        std::lock_guard<std::mutex> locker(mutex);
        std::ostringstream oss;
        try
        {
            std::vector<std::string> vecString;
            if (!mapRefCount.empty())
            {
                auto iter = mapRefCount.cbegin();
                for (; iter != mapRefCount.cend(); ++iter)
                {
                    oss.str("");
                    if (iter->second.second > 0)
                    {
                        oss << iter->second.first;
                        oss << ": leak ";
                        oss << (iter->second.second);
                        oss << " objects \n";
                        vecString.emplace_back(oss.str());
                    }
                }

                if (!vecString.empty())
                {
                    std::for_each(vecString.cbegin(), vecString.cend(), [](const std::string& str) {
                        
                    });
                }
            }
        }
        catch (std::exception* e)
        {
            oss.str("");
            oss << "ClassMemoryTracer::checkMemoryLeaks() exception(std::exception): "
                << std::string(e->what())
                << "\n";
        }
        catch (...)
        {
            oss.str("");
            oss << "ClassMemoryTracer::checkMemoryLeaks() unknown exception"
                << "\n";
        }
     }
}