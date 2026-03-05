// Satria Arya Mahendra_124250160_StudyCaseSorting
#include <iostream>
using namespace std;

// fungsi untuk menampilkan daftar nama
void tampilData(string data[], int jumlah){
    cout << endl;
    for(int i = 0; i < jumlah; i++){
        cout << i+1 << ". " << data[i] << endl;
    }
}

// Bubble Sort (Ascending)
void urutBubble(string data[], int jumlah){
    string sementara;

    for(int i = 0; i < jumlah-1; i++){
        for(int j = 0; j < jumlah-1-i; j++){
            if(data[j] > data[j+1]){
                sementara = data[j];
                data[j] = data[j+1];
                data[j+1] = sementara;
            }
        }
    }
}

// fungsi pembagi quick sort
int bagi(string data[], int awal, int akhir){
    string pivot = data[akhir];
    int indeks = awal - 1;

    for(int k = awal; k < akhir; k++){
        if(data[k] > pivot){ // descending
            indeks++;

            string temp = data[indeks];
            data[indeks] = data[k];
            data[k] = temp;
        }
    }

    string temp = data[indeks+1];
    data[indeks+1] = data[akhir];
    data[akhir] = temp;

    return indeks + 1;
}

// Quick Sort (Descending)
void urutQuick(string data[], int awal, int akhir){
    if(awal < akhir){
        int posisi = bagi(data, awal, akhir);

        urutQuick(data, awal, posisi-1);
        urutQuick(data, posisi+1, akhir);
    }
}

int main(){
    int jumlah;

    cout << "Program Pengurutan Nama Mahasiswa\n";
    cout << "----------------------------------\n";

    cout << "Masukkan jumlah data: ";
    cin >> jumlah;
    cin.ignore();

    string mahasiswa[jumlah];

    cout << "\nInput nama mahasiswa:\n";
    for(int i = 0; i < jumlah; i++){
        cout << "Nama ke-" << i+1 << " : ";
        getline(cin, mahasiswa[i]);
    }

    // Bubble Sort
    urutBubble(mahasiswa, jumlah);
    cout << "\nHasil urutan ASCENDING (Bubble Sort):";
    tampilData(mahasiswa, jumlah);

    // Quick Sort
    urutQuick(mahasiswa, 0, jumlah-1);
    cout << "\nHasil urutan DESCENDING (Quick Sort):";
    tampilData(mahasiswa, jumlah);

    return 0;
}
