#include <iostream>
using namespace std;

int main() {
    // Array dengan 8 elemen bilangan Fibonacci
    int A[] = {1, 1, 2, 3, 5, 8, 13, 21};
    int n = 8;

    // Inisialisasi
    int min = A[0];
    int indeksMin = 0;

    // Algoritma FindMin
    for (int i = 1; i < n; i++) {
        if (A[i] < min) {
            min = A[i];
            indeksMin = i;
        }
    }
    cout << "=== Hasil Pencarian Elemen Minimum ===" << endl;
    cout << "Nilai Minimum : " << min << endl;
    cout << "Ditemukan pada indeks ke- : " << indeksMin << endl;
    return 0;
}




//=======================================================================
// Baris Pseudocode   |  Cost  |  Frekuensi Tmin   |   ​Frekuensi Tmax​   |
// procedure FindMin  |   C1   | ​    1             |         1          |
// min ← A[0]         |   C2   |     ​1             |         1          |
// for i ← 1 to n - 1 |   C3   |     ​n             |         n          |
// if A[i] < min      |   C4   |     ​n−1           |         n−1        | 
// min ← A[i]         |   C5   |     ​0             |         n−1        |
// end if             |   C6   |     ​n−1           |         n−1        |
// end for            |   C7   |     ​n             |         n          |
// return min         |   C8   |     ​1             |         1          |
//=======================================================================

// BEST CASE: T(n) C1 + C2 + C3n + C4(n-1) + 0 + C6(n-1) + C7n + C8
// maka     : C4(n-1) => C4n-C4; C6(n-1) => C6n-C6
// T(n) = (C3 + C4 + C6)n + (C1 + C2 + C7 + C8 - C4 - C6) 
// T(n) = (1 + 1 + 1)n + (1 + 1 + 1 + 1 - 1 - 1)
// T(n) = 3n + 2 => O(n)


// WORST CASE: T(n) C1 + C2 + C3(n) + C4(n-1) + C5(n-1) + C6(n-1) + C7 + C8
// maka      : C4(n-1) => C4n-C4; C5(n-1) => C5n-C5; C6(n-1) => C6n-C6
// T(n) = (C3 + C4 + C5 + C6)n + (C1 + C2 + C7 + C8 - C4 - C5 - C6)
// T(n) = (1 + 1 + 1 + 1)n + (1 + 1 + 1 + 1 - 1 - 1 -1)
// T(n) = 4n + 1 => O(n)