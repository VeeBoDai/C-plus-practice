#include <iostream>

using namespace std;

template<typename T>
class Pair
{
	public:
		Pair(T val1, T val2){
			v1 = val1;
			v2 = val2;
		}			
		
		T Moudle(){return 0;}

	private:
		T v1;
		T v2;
};

template<>
class Pair<int>
{
	public:
		Pair(int val1, int val2){
			v1 = val1;
			v2 = val2;
		}
		 
		int Moudle(){return v1%v2;}
		 
	private:
		int v1;
		int v2;
};

int main()
{
	Pair<double> p(1.0,2.0);
	cout<<p.Moudle()<<endl;
	Pair<int> pi(3,5);
	cout<<pi.Moudle()<<endl;
	cin.get();
	return 0;
}
