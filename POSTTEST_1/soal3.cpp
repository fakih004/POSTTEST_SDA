#include <iostream>
using namespace std;

// Fungsi untuk membalikkan array
void reverseArray(int* arr, int n) {
    int* start = arr;
    int* end = + arr + (n-1);

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

// Fungsi untuk menampilakn array dan alamatnya
void displayArray(int* arr, int n) {
    cout << "indeks\tIsi\tAlamat Memori" << endl;
    for (int i = 0; i < n; i++){
        cout << i << "\t" << *(arr + i) << "\t" << (arr + i) << endl;
    }
    cout << endl;
}

int main(){
    const int jumlah_indeks = 7;
    int prima[jumlah_indeks] = {2,3,5,7,11,13,17};

    cout << "Array sebelum dibalik" << endl;
    displayArray(prima, jumlah_indeks);
    reverseArray(prima, jumlah_indeks);

    cout << "Array setelah dibalik" << endl;
    displayArray(prima, jumlah_indeks);

    return 0;
}
