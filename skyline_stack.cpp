#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <chrono>
using namespace std;

struct Produk {
    int harga;
    int ulasan;
};

vector<Produk> bacaCSV(const string& filename) {
    vector<Produk> data;
    ifstream file(filename);
    string line;
    getline(file, line); // Lewati header

    while (getline(file, line)) {
        stringstream ss(line);
        string hargaStr, ulasanStr;
        getline(ss, hargaStr, ',');
        getline(ss, ulasanStr, ',');
        Produk p;
        p.harga = stoi(hargaStr);
        p.ulasan = stoi(ulasanStr);
        data.push_back(p);
    }
    return data;
}

vector<Produk> skylineQueryDenganStack(const vector<Produk>& data) {
    vector<Produk> hasil;
    stack<Produk> skyline;

    for (const auto& p : data) {
        bool didominasi = false;
        stack<Produk> temp;
        while (!skyline.empty()) {
            Produk top = skyline.top();
            skyline.pop();
            // Jika top mendominasi p, maka p tidak layak masuk skyline
            if (top.harga <= p.harga && top.ulasan >= p.ulasan &&
                (top.harga < p.harga || top.ulasan > p.ulasan)) {
                didominasi = true;
            }
            // Jika p tidak mendominasi top, simpan kembali
            if (!(p.harga <= top.harga && p.ulasan >= top.ulasan &&
                  (p.harga < top.harga || p.ulasan > top.ulasan))) {
                temp.push(top);
            }
        }
        // Restore isi stack yang valid
        while (!temp.empty()) {
            skyline.push(temp.top());
            temp.pop();
        }

        if (!didominasi) {
            skyline.push(p);
        }
    }
    while (!skyline.empty()) {
        hasil.push_back(skyline.top());
        skyline.pop();
    }

    return hasil;
}

int main() {
    string filename = "ind_1000_2_product.csv";
    vector<Produk> data = bacaCSV(filename);
    auto start = chrono::high_resolution_clock::now();
    vector<Produk> hasil = skylineQueryDenganStack(data);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Waktu eksekusi skylineQueryDenganStack: " << duration.count() << " detik\n\n";
    cout << "Hasil Skyline (pakai stack):\n";
    for (const auto& p : hasil) {
        cout << "- Harga: " << p.harga << ", Ulasan: " << p.ulasan << '\n';
    }
    return 0;
}
