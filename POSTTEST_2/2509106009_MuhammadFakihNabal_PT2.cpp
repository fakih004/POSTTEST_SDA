#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Hewan {
    int id;
    string nama;
    string jenis;
    double harga;
};

void tampilkanData(Hewan* arr, int n);
void tambahData(Hewan* arr, int &n);
void swap(Hewan* a, Hewan* b);
void bubble(Hewan* arr, int n);
void selectionSort(Hewan* arr, int n);
void linierSearch(Hewan* arr, int n, string target);
void fibonacci(Hewan* arr, int n, int target);

int main() {
    Hewan daftarHewan[50];
    int jumlah = 0;
    int pilihan;

    daftarHewan[0] = {202, "yanto", "Kucing", 800000};
    daftarHewan[1] = {101, "hamud", "Kelinci", 150000};
    daftarHewan[2] = {305, "sky", "Anjing", 200000};
    jumlah = 3;

    do {
        cout << "\n========================================";
        cout << "\n              PET SALON                 ";
        cout << "\n========================================";
        cout << "\n1. Tampilkan Semua Data";
        cout << "\n2. Tambah Data Hewan Baru";
        cout << "\n3. Urutkan Nama ";
        cout << "\n4. Urutkan Harga  ";
        cout << "\n5. Cari Nama ";
        cout << "\n6. Cari ID ";
        cout << "\n7. Keluar";
        cout << "\nPilih Menu: "; cin >> pilihan;

    switch (pilihan) {
                case 1: tampilkanData(daftarHewan, jumlah); break;
                case 2: tambahData(daftarHewan, jumlah); break;
                case 3: 
                    bubble(daftarHewan, jumlah); 
                    tampilkanData(daftarHewan, jumlah);
                    break;
                case 4: 
                    selectionSort(daftarHewan, jumlah); 
                    tampilkanData(daftarHewan, jumlah); 
                    break;
                case 5: {
                    string cari;
                    cout << "Masukkan nama hewan: "; cin.ignore(); getline(cin, cari);
                    linierSearch(daftarHewan, jumlah, cari);
                    break;
                }
                case 6: {
                    int cariID;
                    cout << "Masukkan ID hewan: "; cin >> cariID;
                    fibonacci(daftarHewan, jumlah, cariID);
                    break;
                }
            }
    } while (pilihan != 7);
    return 0;
}

void tampilkanData(Hewan* arr, int n) {          //parameter pointer (*) syarat 1
    cout << "\n=== DATA HEWAN PET SALON ===" << endl;
    for (int i = 0; i < n; i++) {
        cout << "ID: " << (arr + i)->id << " | Nama: " << (arr + i)->nama        //Pointer aritmatika (arr + i) syarat 3
            << " | Jenis: " << (arr + i)->jenis << " | Harga: Rp" << (arr + i)->harga << endl;
    }
}

void tambahData(Hewan* arr, int &n) {      //pointer (&) syarat 2
    int idBaru;
    bool duplikat;

    cout << "\n=== Input Hewan Baru ===" << endl;
    do {
        duplikat = false;
        cout << "ID: "; cin >> idBaru;
        for (int i = 0; i < n; i++) {
            if ((arr + i)->id == idBaru) {
                cout << "ID " << idBaru << " sudah digunakan oleh hewan '" << (arr + i)->nama << endl;
                cout << "Masukkan ID lain\n" << endl;
                duplikat = true;
                break;
            }
        }
    } while (duplikat == true);

    (arr + n)->id = idBaru;
    cout << "Nama: "; cin.ignore(); getline(cin, (arr + n)->nama);
    cout << "Jenis: "; getline(cin, (arr + n)->jenis);
    cout << "Harga: "; cin >> (arr + n)->harga;
    
    n++;
    cout << "Data berhasil ditambahkan" << endl;
}

void bubble(Hewan* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((arr + j)->nama > (arr + j + 1)->nama) {
                Hewan* a = &arr[j];      //swap syarat 4
                Hewan* b = &arr[j+1];
                Hewan temp = *a;
                *a = *b;
                *b = temp;
            }
        }
    }
    cout << "Nama berhasil diurutkan" << endl;
}

void selectionSort(Hewan* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i; 
        for (int j = i + 1; j < n; j++) {
            if ((arr + j)->harga > (arr + maxIdx)->harga) {
                maxIdx = j;
            }
        }
        Hewan* a = &arr[maxIdx];   //swap syarat 4
        Hewan* b = &arr[i];
        Hewan temp = *a;
        *a = *b;
        *b = temp;
    }
    cout << "Harga berhasil diurutkan" << endl;
}

void linierSearch(Hewan* arr, int n, string target) {
    bool ketemu = false;
    for (int i = 0; i < n; i++) {
        if ((arr + i)->nama == target) {
            cout << "Data ditemukan ID: " << (arr + i)->id << " | Jenis: " << (arr + i)->jenis << endl;
            ketemu = true;
            break;
        }
    }
    if (!ketemu) cout << "Data tidak ada" << endl;
}

// syarat 5
// ==============================================================================
// Proses iterasi linier search:

// 1. Ambil data nama pada indeks ke-i
// 2. Bandingkan satu per satu dengan nama target
// 3. Jika cocok, maka data ditemukan dan loop dihentikan 
// 4. Jika tidak cocok, lanjut ke indeks i + 1

// Contoh

// Masukkan nama hewan: sky
// Iterasi ke-1: Memeriksa nama yanto (bukan ini)
// Iterasi ke-2: Memeriksa nama hamud (bukan ini)
// Iterasi ke-3: Memeriksa nama sky (ketemu)
// Ketemu ID: 305 | Jenis: Anjing
// ==============================================================================


void fibonacci(Hewan* arr, int n, int target) {
    for (int i = 0; i < n-1; i++) {        //sorting ID
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j].id > arr[j+1].id) {
                Hewan temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    int fibM2 = 0, fibM1 = 1, fibM = fibM2 + fibM1;
    while (fibM < n) {
        fibM2 = fibM1; fibM1 = fibM; fibM = fibM2 + fibM1;
    }

    int offset = -1;
    while (fibM > 1) {
        int i = min(offset + fibM2, n - 1);
        if (arr[i].id < target) {
            fibM = fibM1; fibM1 = fibM2; fibM2 = fibM - fibM1;
            offset = i;
        } else if (arr[i].id > target) {
            fibM = fibM2; fibM1 = fibM1 - fibM2; fibM2 = fibM - fibM1;
        } else {
            cout << "ID ditemukan nama: " << arr[i].nama << endl;
            return;
        }
    }
    if (fibM1 && arr[offset + 1].id == target) {
        cout << "ID ditemukan nama: " << arr[offset + 1].nama << endl;
    } else {
        cout << "\nID tidak ada" << endl;
    }
}