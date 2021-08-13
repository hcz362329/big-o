#pragma once
#include <windows.h>

template<typename T>
class SharedPtr {
public:
	class SharedPtrMgr {
	public:
		SharedPtrMgr(T* t) :count(0), t_(nullptr) {
			t_ = t;
		}
		~SharedPtrMgr() {
			if (t_ != nnullptr) {
				delete t_;
				t_ = nullptr;
			}	
		}
		void increment() {
			if (t_ != nullptr) {
				count++;
			}
		}
		void decrement() {
			if (t_ != nullptr) {
				if (--count == 0) {
					delete this;
				}
			}
		}
		T* Get() {
			return t;
		}
	private:
		int count;
		T* t_;
	};
	SharedPtr(T *t) :ptr(nullptr) {
		ptr = new SharedPtrMgr(t);
		ptr->increment();
	}
	SharedPtr(const SharedPtr & sharedptr) {
		ptr = sharedptr->ptr;
		ptr->increment();
	}

	SharedPtr& operator=(const SharedPtr& sharedptr) {
		ptr->decrement();
		ptr = sharedptr->ptr;
		ptr->increament();
	}
	SharedPtr(SharedPtr&& sharedptr) {
		ptr = sharedptr->ptr;
		sharedptr->ptr = nullptr;
	}
	~SharedPtr() {
		if (ptr != nullptr) {
			ptr->decrement();
		}
	}
private:
	SharedPtrMgr * ptr;
};

