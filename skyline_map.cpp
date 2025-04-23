#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Product {
    int id;
    int price;
    int review;
};

vector<Product> readDataset() {
    vector<Product> products;
    // Data hardcoded sebagai contoh
    products.push_back({1, 157, 73});
    products.push_back({2, 209, 129});
    products.push_back({3, 104, 73});
    // Tambahkan data lainnya...
    return products;
}

vector<Product> skylineMap(const vector<Product>& products) {
    map<int, int> priceToReview;
    vector<Product> skyline;

    for (const auto& p : products) {
        auto it = priceToReview.lower_bound(p.price);
        bool dominated = false;

        if (it != priceToReview.begin()) {
            auto prevIt = prev(it);
            if (prevIt->second >= p.review) {
                dominated = true;
            }
        }

        if (!dominated) {
            while (it != priceToReview.end() && it->second <= p.review) {
                it = priceToReview.erase(it);
            }
            priceToReview[p.price] = p.review;
            skyline.push_back(p); // Simpan produk asli
        }
    }

    return skyline;
}

int main() {
    vector<Product> products = readDataset();
    
    auto start = high_resolution_clock::now();
    vector<Product> skyline = skylineMap(products);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Skyline Products:" << endl;
    for (const auto& p : skyline) {
        cout << "ID: " << p.id << ", Price: " << p.price 
             << ", Review: " << p.review << endl;
    }

    cout << "Time taken: " << duration.count() << " microseconds" << endl;
    return 0;
}