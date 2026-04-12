#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 50; // Maks

struct Hewan {
    int id;
    string nama;
    string jenis;
    double harga;
};

struct Riwayat {
    int id;
    string nama;
    string tindakan;
};


void tampilkanData(Hewan* arr, int n);
void tambahData(Hewan* arr, int &n);
void swap(Hewan* a, Hewan* b);
void bubble(Hewan* arr, int n);
void selectionSort(Hewan* arr, int n);
void linierSearch(Hewan* arr, int n, string target);
void fibonacci(Hewan* arr, int n, int target);
void enqueue(Hewan* q, int &front, int &rear, Hewan pasienBaru);
void dequeue(Hewan* q, int &front, int &rear, Riwayat* s, int &top);
void popRiwayat(Riwayat* s, int &top);
void peek(Hewan* q, int front, Riwayat* s, int top);
void tampilkanAntrian(Hewan* q, int front, int rear);
void tampilkanRiwayat(Riwayat* s, int top);

int main() {
    Hewan daftarHewan[MAX];
    Hewan antrian[MAX];
    Riwayat stackRiwayat[MAX];
    
    int jumlah = 0;
    int front = -1, rear = -1;
    int top = -1;              
    int pilihan;

    daftarHewan[0] = {1, "yanto", "Kucing", 800000};
    daftarHewan[1] = {2, "hamud", "Kelinci", 150000};
    daftarHewan[2] = {3, "sky", "Anjing", 200000};
    jumlah = 3;

    do {
        cout << "\n========================================";
        cout << "\n           PAWCARE PETSHOP              ";
        cout << "\n========================================";
        cout << "\n1. Tampilkan Semua Data Hewan";
        cout << "\n2. Tambah Data Hewan Baru";
        cout << "\n3. Urutkan Nama Hewan ";
        cout << "\n4. Urutkan Harga Hewan ";
        cout << "\n5. Cari Nama Hewan ";
        cout << "\n6. Cari ID Hewan ";
        cout << "\n7. Tambah Antrian Pasien ";
        cout << "\n8. Panggil Pasien & Catat ";
        cout << "\n9. Batalkan Tindakan Terakhir ";
        cout << "\n10. Lihat Antrian Depan & Riwayat Terakhir ";
        cout << "\n11. Tampilkan Daftar Antrian";
        cout << "\n12. Tampilkan Riwayat Medis";
        cout << "\n13. Keluar";
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
            case 7: {
                int cariID;
                bool ketemu = false;
                cout << "Masukkan ID Hewan yang ingin antri: "; cin >> cariID;
                for (int i = 0; i < jumlah; i++) {
                    if (daftarHewan[i].id == cariID) {
                        enqueue(antrian, front, rear, daftarHewan[i]);
                        ketemu = true;
                        break;
                    }
                }
                if (!ketemu) cout << "ID Hewan tidak ditemukan" << endl;
                break;
            }
            case 8: dequeue(antrian, front, rear, stackRiwayat, top); break;
            case 9: popRiwayat(stackRiwayat, top); break;
            case 10: peek(antrian, front, stackRiwayat, top); break;
            case 11: tampilkanAntrian(antrian, front, rear); break;
            case 12: tampilkanRiwayat(stackRiwayat, top); break;
            case 13: cout << "program selesai" << endl; break;
            default: cout << "Pilihan tidak valid" << endl;
        }
    } while (pilihan != 13);
    return 0;
}


void tampilkanData(Hewan* arr, int n) {          
    cout << "\n=== DATA HEWAN ===" << endl;
    if (n == 0) cout << "Tidak ada data" << endl;
    for (int i = 0; i < n; i++) {
        cout << "ID: " << (arr + i)->id << " | Nama: " << (arr + i)->nama        
            << " | Jenis: " << (arr + i)->jenis << " | Harga: Rp" << (arr + i)->harga << endl;
    }
}

void tambahData(Hewan* arr, int &n) {      
    if (n >= MAX) {
        cout << "Kapasitas database penuh" << endl;
        return;
    }
    int idBaru;
    bool duplikat;

    cout << "\n=== Input Hewan Baru ===" << endl;
    do {
        duplikat = false;
        cout << "ID: "; cin >> idBaru;
        for (int i = 0; i < n; i++) {
            if ((arr + i)->id == idBaru) {
                cout << "ID " << idBaru << " sudah digunakan Masukkan ID lain\n";
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
                Hewan* a = &arr[j];      
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
        Hewan* a = &arr[maxIdx];   
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

void fibonacci(Hewan* arr, int n, int target) {
    for (int i = 0; i < n-1; i++) {        
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


void enqueue(Hewan* q, int &front, int &rear, Hewan pasienBaru) {
    if (rear == MAX - 1) {
        cout << "Antrian penuh (overflow)" << endl; 
        return;
    }
    if (front == -1) front = 0;
    rear++;
    *(q + rear) = pasienBaru;
    cout << pasienBaru.nama << " berhasil masuk antrian" << endl;
}

void dequeue(Hewan* q, int &front, int &rear, Riwayat* s, int &top) {
    if (front == -1 || front > rear) {
        cout << "Antrian kosong (underflow)" << endl; // Underfloq
        return;
    }
    Hewan dipanggil = *(q + 0); 
    cout << "\nMemanggil Pasien" << endl;
    cout << "Nama : " << dipanggil.nama << " (ID: " << dipanggil.id << ")" << endl;
    string tindakanMasuk;
    cout << "tindakan medis yang dilakukan: ";
    cin.ignore(); getline(cin, tindakanMasuk);
    if (top == MAX - 1) {
        cout << "Riwayat penuh (overflow)" << endl;
    } else {
        top++;
        (s + top)->id = dipanggil.id;
        (s + top)->nama = dipanggil.nama;
        (s + top)->tindakan = tindakanMasuk;
        cout << "Tindakan dicatat ke riwayat" << endl;}
    for (int i = 0; i < rear; i++) {  //Pergeserean dereferensi pointer
        *(q + i) = *(q + i + 1);
    }
    rear--;
    if (rear == -1) {
        front = -1; }
}

void popRiwayat(Riwayat* s, int &top) {
    if (top == -1) {
        cout << "Tidak ada riwayat (Underflow)" << endl;
        return;
    }
    cout << "Membatalkan riwayat terakhir: " << (s + top)->nama 
        << " (" << (s + top)->tindakan << ")" << endl;
    top--;
}

void peek(Hewan* q, int front, Riwayat* s, int top) {
    cout << "\n=== STATUS SAAT INI ===" << endl;
    if (front == -1) {
        cout << "Antrian Pasien : [KOSONG]" << endl;
    } else {
        cout << "Antrian Terdepan: " << (q + 0)->nama << " (ID: " << (q + 0)->id << ")" << endl;}
    if (top == -1) {
        cout << "Riwayat Medis  : [KOSONG]" << endl;
    } else {
        cout << "Riwayat Terakhir: " << (s + top)->nama << " | Tindakan: " << (s + top)->tindakan << endl;}
}

void tampilkanAntrian(Hewan* q, int front, int rear) {
    if (front == -1 || front > rear) {
        cout << "Antrian kosong" << endl;
        return;
    }
    cout << "\n=== DAFTAR ANTRIAN ===" << endl;
    for (int i = 0; i <= rear; i++) {       // Pointer aritmatika iterasi array queue
        cout << i + 1 << ". " << (q + i)->nama << " (ID: " << (q + i)->id << ")" << endl;
    }
}

void tampilkanRiwayat(Riwayat* s, int top) {
    if (top == -1) {
        cout << "Riwayat medis kosong" << endl;
        return;
    }
    cout << "\n=== RIWAYAT MEDIS (Terbaru di atas) ===" << endl;
    for (int i = top; i >= 0; i--) {        //Pointer aritmatika iterasi array stack
        cout << "- Pasien: " << (s + i)->nama << " | Tindakan: " << (s + i)->tindakan << endl;
    }
}