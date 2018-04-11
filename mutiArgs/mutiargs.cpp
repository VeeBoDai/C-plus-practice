#include <stdlib.h>
#include <iostream>

using namespace std;
void showall()
{
    return;
}

template<typename R1,typename... Args>
void showall(R1 v, Args... args)
{
    cout<<v<<endl;
    showall(args...);
}


int main()
{
    showall(1,2,3,4,5,6);
    cin.get();
    return 0;
}
