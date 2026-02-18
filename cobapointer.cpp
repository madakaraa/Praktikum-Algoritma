#include <iostream>
using namespace std;

int main(){
	//~ int num =10;
	//~ int *ptr = &num;
	//~ *ptr = 20;
	
	
	//~ cout << "Alamat dari num: " << &num << endl;
	//~ cout << "Nilai dari num: " << num << endl;
	//~ cout << "Nilai ptr : " << *ptr <<endl;
	//~ cout << "Alamat ptr : " << ptr <<endl;
	//~ cout << "Nilai num dari ptr : " << *ptr <<endl;
	
	//~ int nums[] = {1,2,3,4,5};
	//~ cout << "Alamat indeks 1 array: " << nums << endl;
	//~ cout << "Alamat indeks 2 array: " << nums+1 << endl;
	//~ cout << "Alamat indeks 3 array: " << nums+2 << endl;
	//~ cout << "Alamat indeks 4 array: " << nums+3 << endl;
	//~ cout << "Alamat indeks 5 array: " << nums+4 << endl;
	
	//~ cout <<"================================================" <<endl;
	
	//~ cout << "Nilai indeks 1 array: " << nums << endl;
	//~ cout << "Nilai indeks 2 array: " << nums+1 << endl;
	//~ cout << "Nilai indeks 3 array: " << nums+2 << endl;
	//~ cout << "Nilai indeks 4 array: " << nums+3 << endl;
	//~ cout << "Nilai indeks 5 array: " << nums+4 << endl;
	
	int a = 3, b=4;
	int *p = &a;
	int *q = &b;
	*p = *q;
	
	cout << *p; 
}
