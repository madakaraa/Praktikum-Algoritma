// Satria Arya Mahendra 124250160 SI-H TUGAS 2

#include <iostream>
#include <queue>
#include <stack>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int MAX = 3;

struct Kendaraan {
    string nopol;
    string pemilik;
    string status;
};

struct Node {
    Kendaraan data;
    Node *left, *right;
};

struct Aksi {
    string nopol;
    string tipe;
};

Node* root = NULL;

queue<string> antrian;
stack<Aksi> undoData;

int isiParkir = 0;
int totalKendaraan = 0;

// ================= TAMPILAN =================

void garis() {
    cout << "====================================================\n";
}

void clearScreen() {
    system("cls");
}

void pause() {
    cout << "\nTekan ENTER untuk kembali...";
    cin.ignore();
    cin.get();
}

void judul() {

    garis();
    cout << "           SISTEM PARKIR BANDARA GSA\n";
    garis();

    cout << "Total Kendaraan   : "
         << totalKendaraan << endl;

    cout << "Kapasitas Parkir  : "
         << isiParkir << "/" << MAX << endl;

    garis();
}

// ================= BST =================

Node* buatNode(string nopol, string pemilik) {

    Node* baru = new Node;

    baru->data.nopol = nopol;
    baru->data.pemilik = pemilik;
    baru->data.status = "Di Luar Parkiran";

    baru->left = NULL;
    baru->right = NULL;

    return baru;
}

Node* insert(Node* root, string nopol, string pemilik) {

    if (root == NULL)
        return buatNode(nopol, pemilik);

    if (nopol < root->data.nopol)
        root->left = insert(root->left, nopol, pemilik);

    else if (nopol > root->data.nopol)
        root->right = insert(root->right, nopol, pemilik);

    return root;
}

Node* cari(Node* root, string nopol) {

    if (root == NULL || root->data.nopol == nopol)
        return root;

    if (nopol < root->data.nopol)
        return cari(root->left, nopol);

    return cari(root->right, nopol);
}

void tampil(Node* root) {

    if (root != NULL) {

        tampil(root->left);

        cout << left
             << setw(15) << root->data.nopol
             << setw(20) << root->data.pemilik
             << setw(20) << root->data.status
             << endl;

        tampil(root->right);
    }
}

Node* terkecil(Node* node) {

    Node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

Node* hapus(Node* root, string nopol) {

    if (root == NULL)
        return root;

    if (nopol < root->data.nopol)
        root->left = hapus(root->left, nopol);

    else if (nopol > root->data.nopol)
        root->right = hapus(root->right, nopol);

    else {

        if (root->left == NULL) {

            Node* temp = root->right;
            delete root;
            return temp;
        }

        else if (root->right == NULL) {

            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = terkecil(root->right);

        root->data = temp->data;

        root->right = hapus(root->right, temp->data.nopol);
    }

    return root;
}

// ================= MENU =================

void tambahData() {

    clearScreen();

    string nopol, pemilik;

    cin.ignore();

    garis();
    cout << "          TAMBAH DATA KENDARAAN\n";
    garis();

    cout << "Nomor Polisi : ";
    getline(cin, nopol);

    cout << "Nama Pemilik : ";
    getline(cin, pemilik);

    root = insert(root, nopol, pemilik);

    totalKendaraan++;

    cout << "\nData kendaraan berhasil ditambahkan\n";

    pause();
}

void tampilData() {

    clearScreen();

    garis();
    cout << "              DATA KENDARAAN\n";
    garis();

    if (root == NULL) {

        cout << "Data kosong\n";
        pause();
        return;
    }

    cout << left
         << setw(15) << "NO POL"
         << setw(20) << "PEMILIK"
         << setw(20) << "STATUS"
         << endl;

    garis();

    tampil(root);

    garis();

    pause();
}

void kendaraanMasuk() {

    clearScreen();

    string nopol;

    cin.ignore();

    garis();
    cout << "             KENDARAAN MASUK\n";
    garis();

    cout << "Nomor Polisi : ";
    getline(cin, nopol);

    Node* kendaraan = cari(root, nopol);

    if (kendaraan == NULL) {

        cout << "\nKendaraan tidak ditemukan\n";
        pause();
        return;
    }

    if (kendaraan->data.status == "Di Parkiran") {

        cout << "\nKendaraan sudah berada di parkiran\n";
        pause();
        return;
    }

    if (isiParkir < MAX) {

        kendaraan->data.status = "Di Parkiran";

        isiParkir++;

        undoData.push({nopol, "masuk"});

        cout << "\nKendaraan berhasil masuk\n";
    }

    else {

        antrian.push(nopol);

        cout << "\nParkiran penuh, kendaraan masuk antrian\n";
    }

    pause();
}

void kendaraanKeluar() {

    clearScreen();

    string nopol;

    cin.ignore();

    garis();
    cout << "             KENDARAAN KELUAR\n";
    garis();

    cout << "Nomor Polisi : ";
    getline(cin, nopol);

    Node* kendaraan = cari(root, nopol);

    if (kendaraan == NULL) {

        cout << "\nKendaraan tidak ditemukan\n";
        pause();
        return;
    }

    if (kendaraan->data.status == "Di Luar Parkiran") {

        cout << "\nKendaraan sedang tidak di parkiran\n";
        pause();
        return;
    }

    kendaraan->data.status = "Di Luar Parkiran";

    isiParkir--;

    undoData.push({nopol, "keluar"});

    cout << "\nKendaraan berhasil keluar\n";

    if (!antrian.empty()) {

        string next = antrian.front();
        antrian.pop();

        Node* masuk = cari(root, next);

        if (masuk != NULL) {

            masuk->data.status = "Di Parkiran";

            isiParkir++;

            cout << "Kendaraan dari antrian masuk parkiran\n";
        }
    }

    pause();
}

void hapusData() {

    clearScreen();

    string nopol;

    cin.ignore();

    garis();
    cout << "           HAPUS DATA KENDARAAN\n";
    garis();

    cout << "Nomor Polisi : ";
    getline(cin, nopol);

    Node* cek = cari(root, nopol);

    if (cek == NULL) {

        cout << "\nKendaraan tidak ditemukan\n";
        pause();
        return;
    }

    root = hapus(root, nopol);

    totalKendaraan--;

    cout << "\nData kendaraan berhasil dihapus\n";

    pause();
}

void undo() {

    clearScreen();

    garis();
    cout << "                 UNDO AKSI\n";
    garis();

    if (undoData.empty()) {

        cout << "Tidak ada aksi undo\n";
        pause();
        return;
    }

    Aksi terakhir = undoData.top();
    undoData.pop();

    Node* kendaraan = cari(root, terakhir.nopol);

    if (kendaraan == NULL)
        return;

    if (terakhir.tipe == "masuk") {

        kendaraan->data.status = "Di Luar Parkiran";

        isiParkir--;

        cout << "Undo kendaraan masuk berhasil\n";
    }

    else {

        kendaraan->data.status = "Di Parkiran";

        isiParkir++;

        cout << "Undo kendaraan keluar berhasil\n";
    }

    pause();
}

void tampilAntrian() {

    clearScreen();

    garis();
    cout << "             ANTRIAN KENDARAAN\n";
    garis();

    if (antrian.empty()) {

        cout << "Antrian kosong\n";
        pause();
        return;
    }

    queue<string> temp = antrian;

    int no = 1;

    while (!temp.empty()) {

        cout << no << ". "
             << temp.front()
             << " menunggu masuk parkiran\n";

        temp.pop();
        no++;
    }

    garis();

    pause();
}

// ================= MAIN =================

int main() {

    int pilih;

    do {

        clearScreen();

        judul();

        cout << "1. Tambah Data Kendaraan\n";
        cout << "2. Tampil Data Kendaraan\n";
        cout << "3. Kendaraan Masuk\n";
        cout << "4. Kendaraan Keluar\n";
        cout << "5. Hapus Data Kendaraan\n";
        cout << "6. Undo Aksi\n";
        cout << "7. Tampilkan Antrian\n";
        cout << "0. Keluar\n";

        garis();

        cout << "Pilih menu : ";
        cin >> pilih;

        switch (pilih) {

            case 1:
                tambahData();
                break;

            case 2:
                tampilData();
                break;

            case 3:
                kendaraanMasuk();
                break;

            case 4:
                kendaraanKeluar();
                break;

            case 5:
                hapusData();
                break;

            case 6:
                undo();
                break;

            case 7:
                tampilAntrian();
                break;

            case 0:
                clearScreen();
                cout << "Program selesai\n";
                break;

            default:
                cout << "\nMenu tidak tersedia\n";
                pause();
        }

    } while (pilih != 0);

    return 0;
}
