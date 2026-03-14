//Satria Arya Mahendra_124250160_SI-H
#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
using namespace std;

struct Product{
    char name[60];
    char category[30];
    double price;
    int stock;
    float rating;
};

Product arr[100];
int n = 0;

void loadFile(){
    FILE *pf = fopen("shopease_db.txt","r");

    if(pf==NULL) return;

    while(fscanf(pf," %[^|]|%[^|]|%lf|%d|%f\n",
        arr[n].name,
        arr[n].category,
        &arr[n].price,
        &arr[n].stock,
        &arr[n].rating)!=EOF){
        n++;
    }

    fclose(pf);
}

void saveFile(){
    FILE *pf = fopen("shopease_db.txt","w");

    for(int i=0;i<n;i++){
        fprintf(pf,"%s|%s|%.0lf|%d|%.1f\n",
        arr[i].name,
        arr[i].category,
        arr[i].price,
        arr[i].stock,
        arr[i].rating);
    }

    fclose(pf);
}

void tambahProduk(){

    cout<<"\n=== Tambah Produk ===\n";

    cin.ignore();
    cout<<"Nama Produk : ";
    cin.getline(arr[n].name,60);

    cout<<"Kategori : ";
    cin.getline(arr[n].category,30);

    cout<<"Harga : ";
    cin>>arr[n].price;

    cout<<"Stok : ";
    cin>>arr[n].stock;

    cout<<"Rating : ";
    cin>>arr[n].rating;

    n++;

    saveFile();

    cout<<"\nProduk berhasil ditambahkan!\n";
}

void tampilProduk(){

    cout<<"\n============================================================\n";
    cout<<left<<setw(20)<<"Nama"
        <<setw(15)<<"Kategori"
        <<setw(10)<<"Harga"
        <<setw(8)<<"Stok"
        <<setw(6)<<"Rating"<<endl;
    cout<<"============================================================\n";

    for(int i=0;i<n;i++){
        cout<<left<<setw(20)<<arr[i].name
            <<setw(15)<<arr[i].category
            <<setw(10)<<arr[i].price
            <<setw(8)<<arr[i].stock
            <<setw(6)<<arr[i].rating<<endl;
    }

    cout<<"============================================================\n";
}

void bubbleSort(){

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){

            if(strcmp(arr[j].name,arr[j+1].name)>0){

                Product temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

            }
        }
    }
}

int partition(int low,int high){

    float pivot = arr[high].rating;
    int i = low-1;

    for(int j=low;j<high;j++){

        if(arr[j].rating > pivot){

            i++;

            Product temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

        }

    }

    Product temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return i+1;
}

void quickSort(int low,int high){

    if(low<high){

        int pi = partition(low,high);

        quickSort(low,pi-1);
        quickSort(pi+1,high);

    }

}

void cariProduk(){

    char cari[60];
    bool ketemu=false;

    cout<<"\nMasukkan nama produk: ";
    cin.ignore();
    cin.getline(cari,60);

    for(int i=0;i<n;i++){

        if(strcmp(arr[i].name,cari)==0){

            cout<<"\nProduk ditemukan!\n";
            cout<<"Nama : "<<arr[i].name<<endl;
            cout<<"Kategori : "<<arr[i].category<<endl;
            cout<<"Harga : "<<arr[i].price<<endl;
            cout<<"Stok : "<<arr[i].stock<<endl;
            cout<<"Rating : "<<arr[i].rating<<endl;

            ketemu=true;
            break;
        }

    }

    if(!ketemu){
        cout<<"Produk tidak ditemukan!\n";
    }

}

int main(){

    int pilih;
    int mode;

    loadFile();

    do{

        cout<<"\n============================================================\n";
        cout<<"                SHOPEASE PRODUCT MANAGER\n";
        cout<<"============================================================\n";

        cout<<"1. Tambah Produk\n";
        cout<<"2. Tampilkan Produk\n";
        cout<<"3. Cari Produk\n";
        cout<<"4. Keluar\n";

        cout<<"Pilih menu : ";
        cin>>pilih;

        switch(pilih){

            case 1:
                tambahProduk();
                break;

            case 2:

                cout<<"\nMode Tampilan\n";
                cout<<"1. Urut Nama (Bubble Sort Ascending)\n";
                cout<<"2. Urut Rating (Quick Sort Descending)\n";

                cout<<"Pilih : ";
                cin>>mode;

                if(mode==1){
                    bubbleSort();
                }
                else if(mode==2){
                    quickSort(0,n-1);
                }

                tampilProduk();
                break;

            case 3:
                cariProduk();
                break;

            case 4:
                saveFile();
                cout<<"\nTerima kasih telah menggunakan ShopEase!\n";
                break;

        }

    }while(pilih!=4);

}
