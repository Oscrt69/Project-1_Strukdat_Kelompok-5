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

vector<Product> readDataset(const string& filename) {
    vector<Product> products;
    ifstream file(filename);
    string line;

    // Lewati header
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        Product p;

        getline(ss, token, ',');
        p.id = stoi(token);
        getline(ss, token, ','); // Lewati label
        getline(ss, token, ',');
        p.price = stoi(token);
        getline(ss, token, ',');
        p.review = stoi(token);

        products.push_back(p);
    }

    return products;

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
