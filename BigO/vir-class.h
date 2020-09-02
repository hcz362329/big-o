#pragma once
#include <iostream>
#pragma pack(push,1)
using namespace std;
class A {
public:
	A() {
		func();
	}
	virtual ~A() {

	}
	virtual void func() {
		cout << "func a"<<endl;
	}
private:
	
};

class B : public A {
public:
	B() {
		
	}
	~B() {

	}
	void func() {
		cout << "func b" << endl;
	}
	
};
#pragma pack(pop)