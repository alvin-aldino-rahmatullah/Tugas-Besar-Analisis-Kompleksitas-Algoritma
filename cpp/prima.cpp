#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;

// cek bilangan prima secara rekursif
bool primaRekursif(int n, int pembagi) {
    if (n < 2) return false;
    if (pembagi > sqrt(n)) return true;
    if (n % pembagi == 0) return false;
    return primaRekursif(n, pembagi + 1);
}

// cek bilangan prima secara iteratif
bool primaIteratif(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
    int n = stoi(argv[1]);        // input bilangan
    string mode = argv[2];       // iterative / recursive

    bool hasil;

    auto mulai = chrono::high_resolution_clock::now();

    if (mode == "iterative") {
        hasil = primaIteratif(n);
    } else {
        hasil = primaRekursif(n, 2);
    }

    auto selesai = chrono::high_resolution_clock::now(); // mengukur waktu selesai
    double waktu = chrono::duration<double, milli>(selesai - mulai).count(); // waktu dalam milidetik

    if (hasil)
        cout << "PRIMA ";
    else
        cout << "BUKAN_PRIMA ";

    cout << waktu << endl;
    return 0;
}
