#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
    Mahasiswa daftar_mhs[5];
    cout << "=== Input Data 5 Mahasiswa ===" << endl;

    // Input Data
    for (int i = 0; i < 5; i++) {
        cout << "\nData Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama : ";
        getline(cin >> ws, daftar_mhs[i].nama);
        cout << "NIM  : ";
        cin >> daftar_mhs[i].nim;
        cout << "IPK  : ";
        cin >> daftar_mhs[i].ipk;
    }

    // Mencari IPK tertinggi
    int nilaiTertinggi = 0;
    for (int i = 1; i < 5; i++) {
        if (daftar_mhs[i].ipk > daftar_mhs[nilaiTertinggi].ipk) {
            nilaiTertinggi = i;
        }
    }

    cout << "\n------------------------------" << endl;
    cout << "Mahasiswa dengan IPK Tertinggi:" << endl;
    cout << "Nama : " << daftar_mhs[nilaiTertinggi].nama << endl;
    cout << "NIM  : " << daftar_mhs[nilaiTertinggi].nim << endl;
    cout << "IPK  : " << daftar_mhs[nilaiTertinggi].ipk << endl;
    cout << "------------------------------" << endl;

    return 0;
}