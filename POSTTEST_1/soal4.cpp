#include <iostream>
using namespace std;

// fungsi untuk menukar nilai
void tukar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int angka1, angka2;

    cout << "input angka pertama:";
    cin >> angka1;
    cout << "input angka kedua";
    cin >> angka2;

    cout << "Sebelum ditukar:\n";
    cout <<  angka1 << endl;
    cout <<  angka2 << endl;

    tukar(&angka1,&angka2);

    cout << "Sesudah ditukar:\n";
    cout <<  angka1 << endl;
    cout <<  angka2 << endl;

    return 0;
}