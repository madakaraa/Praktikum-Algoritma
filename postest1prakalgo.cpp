// Satria Arya Mahendra_124250160
#include <iostream>
using namespace std;

int main (){
	int angka;
	cout <<"Masukkan Jumlah Elemen: ";
	cin >> angka;
	
	// array
	int array[angka];
	// pointer nya
	int *ptr = array;
	
	// input 
	cout <<"\nMasukkan " << angka <<" Angka: \n";
		for(int i = 0; i < angka; i++){
			cin >> *(ptr + i);
			}
			
	// cetak
	cout <<"\nIsi Array:\n";
	for (int i = 0; i < angka; i++){
		cout << *(ptr + i) <<" ";
		}
		
	// max & min
	int min = *ptr;
	int max = *ptr;
	for (int i = 0; i < angka; i++){
		if(*(ptr + i) > max) max = *(ptr + i);
		if(*(ptr + i) < min) min = *(ptr + i);
		}
	
	cout <<"\n\nNilai Max: " << max;
	cout <<"\n\nNilai Min: " << min;
	
	// jumlah dan rata-rata
	
	int jumlah = 0;
	for (int i = 0; i < angka; i++){
		jumlah += *(ptr + i);
		}
	
	float rata = (float)jumlah / angka;
	cout <<"\nJumlah: " << jumlah;
	cout <<"\nRata-Rata: " << rata <<endl;
	
	return 0;
	}
