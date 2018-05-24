#include <stdlib.h>
#include <iostream>

using namespace std;

class A{
public:
	A(int l=0, int n=0, int m=0):i(l),j(n),k(m){}
	void test(const A &a){
		i = a.i;
		j = a.j;
		k = a.k;
	}
	void display(){
		cout<<"a:"<<i<<","<<j<<","<<k<<endl;
	}
public:
	int i;
protected:
	int j;
private:
	int k;
};

class B:public A{
public:
	B(int l=0, int n=0, int m=0):bi(l),bj(n),bk(m){}
	void test(const B &b, const A &a){
		bi = b.bi;
		bj = b.bj;
		bk = b.bk;
		i = a.i;
		//j = a.j; //error
		j = b.j; //ok
		//k = b.k; //error
	}
	void display(){
		//cout<<"A:"<<i<<","<<j<<","<<k<<",B:"<<bi<<","<<bj<<","<<bk<<endl;
		A::display();
		cout<<"B:"<<bi<<","<<bj<<","<<bk<<endl;
	}
public:
	int bi;
protected:
	int bj;
private:
	int bk;
};


int main()
{
	//int i = 1;
	//cout<<"1&-1,"<<(1&(-1))<<endl;
	//cout<<"2&-2,"<<(2&(-2))<<endl;
	//cout<<"3&-3,"<<(3&(-3))<<endl;
	A a1(A(1,2,3));
	a1.display();
	A a2;
	a2.test(a1);
	a2.display();
	B b1(B(4,5,6));
	b1.display();
	return 0;
}
