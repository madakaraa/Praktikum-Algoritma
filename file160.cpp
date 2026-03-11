#include <iostream>
using namespace std;

int main(){
	//~ FILE *pointer;
	//~ pointer = fopen("data.txt", "r");
	//~ if(pointer == NULL){
		//~ cout <<"error opening data.txt\n";
		//~ exit(1);
		//~ }
		
	//~ FILE *pointer;	
	//~ char nama[50];
	//~ int umur;
	
	//~ cout <<"Masukkan nama: ";
	//~ cin >> nama;
	//~ cout <<"Masukkan umur: ";
	//~ cin >> umur;
	//~ pointer = fopen("data.txt", "a");
	//~ fprintf(pointer, "Nama: %s, Umur: %d\n", nama, umur);
	//~ fclose(pointer);
	
	char tampungNama[50];
	int tampungUmur;
	FILE *pointer = fopen("data.txt", "r");
	while (fscanf (pointer, "Nama: %[^,], Umur: %d\n", tampungNama, &tampungUmur) == 2){
			cout <<"Nama: " << tampungNama <<"Umur: " <<tampungUmur <<endl;
		}
		fclose(pointer);
}
