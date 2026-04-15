#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 50;

// --- STRUKTUR DATA DASAR ---
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

struct NodeAntrian {
    Hewan data;
    NodeAntrian* next;
};

struct NodeRiwayat {
    Riwayat data;
    NodeRiwayat* next;
};



void tampilkanData(Hewan* arr, int n);
void tambahData(Hewan* arr, int &n);
void bubble(Hewan* arr, int n);
void selectionSort(Hewan* arr, int n);
void linierSearch(Hewan* arr, int n, string target);
void fibonacci(Hewan* arr, int n, int target);
void enqueue(NodeAntrian*& front, NodeAntrian*& rear, Hewan pasienBaru);
void pushRiwayat(NodeRiwayat*& top, Riwayat riwayatBaru);
void dequeue(NodeAntrian*& front, NodeAntrian*& rear, NodeRiwayat*& top);
void popRiwayat(NodeRiwayat*& top);
void peek(NodeAntrian* front, NodeRiwayat* top);
void tampilAntrian(NodeAntrian* front);
void tampilRiwayat(NodeRiwayat* top);


int main() {
    Hewan daftarHewan[MAX];
    int jumlah = 0;
    NodeAntrian* front = nullptr;
    NodeAntrian* rear = nullptr;
    NodeRiwayat* top = nullptr;
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
        cout << "\n7. Tambah Antrian Pasien (Enqueue)";
        cout << "\n8. Panggil Pasien & Catat (Dequeue & Push)";
        cout << "\n9. Batalkan Tindakan Terakhir (Pop)";
        cout << "\n10. Lihat Antrian Depan & Riwayat Terakhir (Peek)";
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
                        enqueue(front, rear, daftarHewan[i]);
                        ketemu = true;
                        break;
                    }
                }
                if (!ketemu) cout << "ID Hewan tidak ditemukan" << endl;
                break;
            }
            case 8: dequeue(front, rear, top); break; 
            case 9: popRiwayat(top); break; 
            case 10: peek(front, top); break; 
            case 11: tampilAntrian(front); break; 
            case 12: tampilRiwayat(top); break;
            case 13: cout << "Program selesai" << endl; break;
            default: cout << "Pilihan tidak valid" << endl;
        }
    } while (pilihan != 13);
    
    return 0;
}

void enqueue(NodeAntrian*& front, NodeAntrian*& rear, Hewan pasienBaru) {  // enqueue
    NodeAntrian* newNode = new NodeAntrian;
    newNode->data = pasienBaru;
    newNode->next = nullptr;
    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << pasienBaru.nama << " berhasil masuk antrian" << endl;
}

void pushRiwayat(NodeRiwayat*& top, Riwayat riwayatBaru) {  // Push
    NodeRiwayat* newNode = new NodeRiwayat;
    newNode->data = riwayatBaru;
    newNode->next = top;
    top = newNode;
    cout << "Tindakan dicatat ke riwayat" << endl;
}

void dequeue(NodeAntrian*& front, NodeAntrian*& rear, NodeRiwayat*& top) {  // dequeue
    if (front == nullptr) {
        cout << "Antrian kosong (Underflow)" << endl; 
        return;
    }
    NodeAntrian* temp = front;
    cout << "\nMemanggil Pasien" << endl;
    cout << "Nama : " << temp->data.nama << " (ID: " << temp->data.id << ")" << endl;
    string tindakanMasuk;
    cout << "Tindakan medis yang dilakukan: ";
    cin.ignore(); getline(cin, tindakanMasuk);
    Riwayat r = {temp->data.id, temp->data.nama, tindakanMasuk};
    pushRiwayat(top, r); 
    front = front->next;
    if (front == nullptr) rear = nullptr;
    delete temp; 
}

void popRiwayat(NodeRiwayat*& top) {  // pop
    if (top == nullptr) {
        cout << "Tidak ada riwayat (Underflow)" << endl; 
        return;
    }
    NodeRiwayat* temp = top;
    cout << "Membatalkan riwayat terakhir: " << temp->data.nama 
        << " (" << temp->data.tindakan << ")" << endl;
    top = top->next;
    delete temp;
}

void peek(NodeAntrian* front, NodeRiwayat* top) {  // peek
    cout << "\n=== STATUS SAAT INI ===" << endl;
    if (front == nullptr) {
        cout << "Antrian Pasien  : [KOSONG]" << endl;
    } else {
        cout << "Antrian Terdepan: " << front->data.nama << " (ID: " << front->data.id << ")" << endl;
    }
    if (top == nullptr) {
        cout << "Riwayat Medis   : [KOSONG]" << endl;
    } else {
        cout << "Riwayat Terakhir: " << top->data.nama << " | Tindakan: " << top->data.tindakan << endl;
    }
}

void tampilAntrian(NodeAntrian* front) {  // tampil antrian
    if (front == nullptr) {
        cout << "Antrian kosong" << endl;
        return;
    }
    cout << "\n=== DAFTAR ANTRIAN ===" << endl;
    NodeAntrian* current = front;
    int i = 1;
    while (current != nullptr) {
        cout << i++ << ". " << current->data.nama << " (ID: " << current->data.id << ")" << endl;
        current = current->next;
    }
}

void tampilRiwayat(NodeRiwayat* top) {  // tampil riwayat
    if (top == nullptr) {
        cout << "Riwayat medis kosong" << endl;
        return;
    }
    cout << "\n=== RIWAYAT MEDIS (Terbaru di atas) ===" << endl;
    NodeRiwayat* current = top;
    while (current != nullptr) {
        cout << "- Pasien: " << current->data.nama << " | Tindakan: " << current->data.tindakan << endl;
        current = current->next;
    }
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
                cout << "ID " << idBaru << " sudah digunakan, masukkan ID lain\n";
                duplikat = true;
                break;
            }
        }
    } while (duplikat);
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
    if (fibM1 && offset + 1 < n && arr[offset + 1].id == target) {
        cout << "ID ditemukan nama: " << arr[offset + 1].nama << endl;
    } else {
        cout << "\nID tidak ada" << endl;
    }
}