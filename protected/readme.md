a:1,2,3
a:1,2,3
a:0,0,0
B:4,5,6

说明：
1. 像private成员一样，protected成员不能被类的用户访问；
2. 像public成员一样，protected成员可被该类的派生类访问；
此外，protected还有另一重要性质：
派生类只能通过派生类对象访问其基类的protected成员，派生类对其基类类型对象的protected成员没有特殊访问权限；

class A{

protected:
    int i;
};

class B:public A{
public:
    void test(const B &b, const A &a){
      int k;
      k = b.i; //ok
      //k = a.i; //error
    }
}

