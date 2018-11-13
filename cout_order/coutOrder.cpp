
#include <stdio.h>
#include <iostream>

using namespace std;

int func(int &a)
{
    a = 5;
    return 1;
}

int main()
{
    int a=2;
    cout<<"func return:"<<func(a)<<",a="<<a<<endl;

    return 0;
}
