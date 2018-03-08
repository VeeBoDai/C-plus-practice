#include <iostream>
using namespace std;

class Parent
{
public:
    virtual ~Parent(){
        f1();
    }
    virtual void f1(){
        cout<<"Parent f1"<<endl;
    }    
};

class Base:public Parent
{
public:
    virtual ~Base(){
        f1();
    }
    virtual void f1(){
        cout<<"Base f1"<<endl;
    }
};

class A:public Base
{
public:
    virtual ~A(){
        f1();
    }
    
    virtual void f1(){
        cout<<"A f1"<<endl;
    }    
};

void test()
{
	Base *b = new A();
	delete b;
}

int main() {
	cout  << "test\n";

	test();
	return 0;
}
