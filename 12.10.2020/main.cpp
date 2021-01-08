#include <iostream>
using namespace std;

template <class T>void add(T a, T b){
	cout<< a+b << endl;
}

int main(){

	add<int>(1, 2);

	return 0;
}
