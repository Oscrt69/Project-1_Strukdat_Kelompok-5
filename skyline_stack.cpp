#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <string>
#include <chrono>
using namespace std;

struct Produk {
    int harga;
    int ulasan;

    Produk(int h, int u) : harga(h), ulasan(u) {}
};

// Cek apakah a mendominasi b
bool mendominasi(const Produk& a, const Produk& b) {
    return (a.harga <= b.harga && a.ulasan <= b.ulasan) &&
           (a.harga < b.harga || a.ulasan < b.ulasan);
}

vector<Produk> bacaCSV(const string& filename) {
    vector<Produk> data;
    ifstream file(filename);
    string baris;
    getline(file, baris); // skip header dalam file csv product baju

    while (getline(file, baris)) {
        stringstream ss(baris);
        string token;
        int kolom = 0;
        int harga = 0, ulasan = 0;

        while (getline(ss, token, ',')) {
            if (kolom == 2) harga = stoi(token);     // kolom attr_1
            if (kolom == 3) ulasan = stoi(token);    // kolom attr_2
            kolom++;
        }

        data.emplace_back(harga, ulasan);
    }

    return data;
}

vector<Produk> skylineQueryDenganStack(const vector<Produk>& data) {
    stack<Produk> skyline;

    for (const auto& kandidat : data) {
        stack<Produk> sementara;
        bool didominasi = false;

        while (!skyline.empty()) {
            Produk top = skyline.top();
            skyline.pop();

            if (mendominasi(top, kandidat)) {
                didominasi = true;
            } else if (!mendominasi(kandidat, top)) {
                sementara.push(top);
            }
        }

        if (!didominasi) {
            sementara.push(kandidat);
        }

        // Balikin isi stack sementara ke skyline
        while (!sementara.empty()) {
            skyline.push(sementara.top());
            sementara.pop();
        }
    }

    // Konversi hasil dari stack ke vector untuk dicetak
    vector<Produk> hasil;
    while (!skyline.empty()) {
        hasil.push_back(skyline.top());
        skyline.pop();
    }

    return hasil;



}

int main() {
    string filename = "ind_1000_2_product.csv";
    vector<Produk> data = bacaCSV(filename);

    // Ukur waktu eksekusi skylineQuery
    auto start = chrono::high_resolution_clock::now();
    vector<Produk> hasil = skylineQueryDenganStack(data);\
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = end - start;
    cout << "Waktu eksekusi skylineQueryDenganStack: " << duration.count() << " detik\n\n";

    // Cetak hasil setelah pengukuran waktu
    cout << "Hasil Skyline (pakai stack):\n";
    for (const auto& p : hasil) {
        cout << "- Harga: " << p.harga << ", Ulasan: " << p.ulasan << '\n';
    }

    return 0;
}
