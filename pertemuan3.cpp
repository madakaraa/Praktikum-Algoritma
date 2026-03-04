#include <iostream>
using namespace std;

void tampilanData(int array[], int n){
	for(int i = 0; i < n; i++){
		cout << array[i] <<" ";
		}
	}
	
void bubbleSort(int array[], int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(array[j] > array[j+1]){
				int temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
				}
			}
		}
	}
	
void quick_sort(int array[], int awal, int akhir) {

    int low = awal, high = akhir;

    int pivot = array[(awal + akhir) / 2];


    do {

        while (array[low] < pivot)

            low++;

        while (array[high] > pivot)

            high--;


        if (low <= high) {

            swap(array[low], array[high]);

            low++;

            high--;

        }

    } while (low <= high);


    if (awal < high)

        quick_sort(array, awal, high);

    if (low < akhir)

        quick_sort(array, low, akhir);

}

int main(){
	int n = 5;
	int array[n] = {5, 3, 2, 1, 4};
	cout <<"Data sebelum diurutkan" << endl;
	tampilanData(array, n);
	
	//bubbleSort(array, n);
	// cout <<"Data setelah di sort (bubbleSort)" << endl;
	quick_sort(array, 0, n-1);
	
	cout <<"Data setelah di sort (Quick Sort): " <<endl;
	tampilanData(array, n);
	
	
}
