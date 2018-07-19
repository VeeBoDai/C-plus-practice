#include <stdlib.h>
#include <iostream>

using namespace std;

class A
{
public:
	A(int k):i(k){}	
	int i;
};


class B
{
public:
	B(int k):i(k){}	
	const int i;
};




int main()
{
	const int i = 10;
	int *p = const_cast<int *>(&i);
	cout<<"i="<<i<<" ,*p= "<<*p<<endl;
	cout<<"&i="<<&i<<" ,p= "<<p<<endl;

	*p = 20;
	cout<<"i="<<i<<" ,*p= "<<*p<<" ,*&i"<<*(&i)<<endl;
    
	const A a(3);
	cout<<"a.i="<<a.i<<endl;
	A *pa = const_cast<A *>(&a);
	cout<<"a.i="<<a.i<<" ,pa->i="<<pa->i<<endl;

	pa->i = 5;
	cout<<"a.i="<<a.i<<" ,pa->i="<<pa->i<<endl;


	B b(6);
	cout<<"b.i="<<a.i<<endl;
	int *pbi = const_cast<int *>(&(b.i));
	cout<<"b.i="<<b.i<<" ,b->i="<<*pbi<<endl;

	*pbi = 7;
	cout<<"b.i="<<b.i<<" ,b->i="<<*pbi<<endl;

	return 0;

}		
