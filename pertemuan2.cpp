#include <iostream>
using namespace std;

int main (){
	// Tanpa Sentinel
	//~ int array[5] = {6, 3, 7, 4, 5};
	//~ int cari = 3;
	//~ int i = 0;
	//~ bool found = false;
	
	//~ while(i < 5 && found == false){
		//~ if (array[i] == cari){
			//~ found = true;
			//~ } else {
				//~ i++;
				//~ }
		//~ }
	//~ if (found == true){
		//~ cout << cari <<" Ditemukan pada index array ke - " << i <<endl;
		//~ } else {
			//~ cout << cari <<" Tidak ditemukan dalam array" <<endl;
			//~ }
			
			//~ int x[9] = {80, 60, 40, 20, 70, 50, 30, 10, 5};
			//~ int i = 0, cari;
			
			//~ cout << "Masukkan angka yang ingin dicari: ";
			//~ cin >> cari;
			//~ x[8] = cari;
			
			//~ while(x[i] != cari){
				//~ i++;
				//~ }
			
			//~ if(i < 8) {
				//~ cout << cari <<" Ditemukan pada index array ke - " << i <<endl; 
				//~ } else {
					//~ cout << cari <<" Tidak ditemukan dalam array" <<endl;
					//~ }
					
			int x[10] = {10, 20, 38, 48, 50, 60, 70, 80, 90, 100};
			int i = 0, j = 10, k, cari;
			bool found = false;
			
			while((!found) && (i <= j)) {
				k = (i + j) / 2;
				if (cari == x[k]){
					found = true;
					} else {
						if (cari < x[k]){
							j = k - 1;
							} else {
								j = k + 1;
								}
						}
				}
				
				if (found) {
					cout << cari <<" Ditemukan pada index array ke - " << k <<endl;
					} else {
						cout << cari <<" Tidak ditemukan dalam array" <<endl;
						}
	}
