// Satria Arya Mahendra_124250160_StudyCase_Searching
#include <iostream>
using namespace std;

struct Buku {
    string nama;
    int harga;
};

int NonSentinel(Buku arr[], int n, string cari) {
    for (int i = 0; i < n; i++) {
        if (arr[i].nama == cari)
            return i;
    }
    return -1;
}

int Sentinel(Buku arr[], int n, string cari) {
    arr[n].nama = cari;
    int i = 0;

    while (arr[i].nama != cari)
        i++;

    if (i < n) return i;
    else return -1;
}

int binarySearch(Buku arr[], int n, string cari) {
    int kiri = 0, kanan = n - 1;

    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;

        if (arr[tengah].nama == cari)
            return tengah;
        else if (arr[tengah].nama < cari)
            kiri = tengah + 1;
        else
            kanan = tengah - 1;
    }
    return -1;
}

int main() {
    Buku data[100] = {
        {"Algoritma", 76000},
        {"Basis Data", 81000},
        {"C++ Dasar", 65500},
        {"Struktur Data", 95000},
        {"Komik", 87000}
    };

    int n = 10;
    string cari;
    cout << "Masukkan nama buku yang dicari: ";
    getline(cin, cari);

    int hasil = NonSentinel(data, n, cari);

    if (hasil != -1)
        cout << "Buku ditemukan nih, Harganya : " << data[hasil].harga << endl;
    else
        cout << "Buku ngga ditemukan :(" << endl;

    return 0;
}
