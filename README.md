# Project-1_Strukdat_Kelompok-5
### Kelompok 5
5027241001 Ahmad Wildan Fawwaz <br>
5027241053 Oscaryavat Viryavan <br>
5027241062 Angga Firmansyah <br>
5027241099 Muhammad Ahsani Taqwiim <br>
5027241118 Naufal Ardhana <br>

## Skyline Query Problem
1. Buatlah implementasi sederhana dari Skyline Query dengan studi kasus pemilihan baju terbaik. Gunakan 6 jenis struktur data berikut untuk mengelola dan memproses data:  
a. Array  
b. Linked List  
c. Stack  
d. Queue  
e. Hash Table  
f. Map  
Setiap anggota kelompok wajib mengimplementasikan satu jenis struktur data.  
2. Diberikan dataset berisi 1000 baris data baju dengan atribut harga dan nilai ulasan. 
Gunakan dataset ini sebagai input dalam program C++ Anda, ukur waktu komputasinya, dan bandingkan performa ke-6 struktur data dalam menjalankan skyline query.  
3. Analisis hasil dari performa struktur data. Kaitkan dengan kompleksitas BigO Notation.  
a. Manakah struktur data yang paling efisien dalam memproses skyline query?  
b. Mengapa?  
4. Buat laporan sederhana menggunakan Ms Word atau Github Markdown yang mencakup:  
a. Hasil performa 6 struktur data  
b. Analisis hasil performa 6 struktur data  
c. Screenshot input program  
d. Screenshot output program



## Linked List
output:
![Screenshot 2025-04-23 130136](https://github.com/user-attachments/assets/2d7d6bb7-33ba-477b-8e9d-50fb4403c5a2)
percobaan pertama = 1.584 detik

percobaan kedua = 1.509 detik

percobaan ketiga = 0.885 detik

rata2 = 1.326 detik

berdasarkan gambar diatas telah dilakukan implementasi skyline query dengan cara linked list, implmentasi ini memiliki kompleksitas O(n²), linked list ini tidak terlalu efisien untuk data yang besar Karena Linked List tidak mendukung indexing cepat atau area pruning, sehingga harus membandingkan satu-satu (brute-force), juga Tidak efisien untuk dataset besar karena operasi penghapusan (remove_if) membutuhkan O(n).

## Stack
### Penjelasan Stack secara singkat 
- Stack merupakan tipe struktur data yang menggunakan konsep LIFO (Last in First Out) berupa tumpukan data.

Dokumentasi : 

![WhatsApp Image 2025-04-23 at 15 42 53_c6606da2](https://github.com/user-attachments/assets/52d44631-655b-4c2a-bfd9-de608490653d)


Dapat ditinjau pada dokumentasi tersebut bahwa efisiensi waktu menggunakan struktur data Stack memakan waktu sebesar :
- Percobaan pertama = 0.002653 detik
![WhatsApp Image 2025-04-23 at 15 42 42_68043ef1](https://github.com/user-attachments/assets/34b1545c-7675-4f10-87d9-1c04ebbdedb0)

- Percobaan kedua = 0.002005 detik

![WhatsApp Image 2025-04-23 at 15 42 38_3b6fccb6](https://github.com/user-attachments/assets/9b29521f-fd08-4474-a71d-25c95a45c9c6)

- Percobaan ketiga = 0.001452 detik

![WhatsApp Image 2025-04-23 at 15 42 48_d71c7cd6](https://github.com/user-attachments/assets/10ebde31-da52-48b1-8007-9b628e705425)


 Implementasi skyline querry dengan struktur data Stack memiliki kompleksitas O(n^2),  Operasi stack (push/pop) sendiri adalah O(1), tapi karena dilakukan dalam loop bersarang, totalnya O(n^2). Kesimpulannya stack cocok untuk analisis data file kecil, namun apabila ukuran data besar maka kurang direkomendasikan dikarenakan kompleksitas waktu dalam big O notation yang cukup besar

## Hash Table
Implementasi hash table di C++ menggunakan `unprdered_map`. `unordered_map` adalah bagian dari Standard Template Library (STL) C++, dan dapat disimpan tanpa urutan tertentu.
<img src="https://github.com/user-attachments/assets/1e4719dd-8f61-4eaa-89fa-227e195dea72" width = "600"> <br>
Berdasarkan gambar di atas, telah dilakukan sebanyak tiga kali uji coba pemrosesan data pada file .csv menggunakan metode Hash Table. Hasil waktu pemrosesan dari masing-masing uji coba adalah sebagai berikut: <br>
Uji coba pertama: 0.00088687 detik <br>
Uji coba kedua: 0.0015121 detik <br>
Uji coba ketiga: 0.00112224 detik <br>
Jika dirata-ratakan, waktu pemrosesan data tersebut adalah 0.00117374 detik.


## Array
Pada Array Linear search dan traversal mudah dilakukan, namun butuh waktu lebih lama dalam pengecekan dominasi karena tidak ada efisiensi dalam pencarian.
![WhatsApp Image 2025-04-23 at 15 43 38_2dbc422c](https://github.com/user-attachments/assets/07e16ddf-72fb-48e9-b718-014410865327)
Kode menggunakan array untuk menyimpan `n` item data yang berupa O(n). Kemudian Array `skyline[]` untuk menyimpan hasil (maksimal berisi `n` yang sama). Ini berarti 2 loop berada di `for i in n`, lalu `for j in n` yang merupakan kompleksitas O(n).

![WhatsApp Image 2025-04-23 at 15 43 22_7306ed22](https://github.com/user-attachments/assets/5ccb25b7-78ec-4613-a25c-3e97f71f8fc9)

Kode ini nanatinya akan membaca `dataset.csv` yang berada dalam folder yang sama. Menyimpan setiap item ke dalam array struct Baju. Skyline Query akan membandingkan setiap pasangan baju berdasarkan 2 kriteria yaitu harga lebih murah dan ulasana lebih tinggi. Array akan cocok pada ukuran dataset yang lebih kecil karena semua data dibandingkan satu persatau melalui `nested loop`. Kompleksitasnya kurang efisien untuk data yang lebih besar.

Berdasarkan 3 kali hasil uji performa pada struktur dat array terhadap 1000 baris data dataset. Didapatkan waktu eksekusi yang sangat cepat dan bervariasi mulai dari sekitar 0.00089 detik hingga 0.00383 detik. Perbedaan kecil ini kemungkinan besar dipengaruhi oleh beban sistem saat program dijalankan. Array masih mampu menyelesaikan proses secara efisien karena
- Operasi perbandingan lebih sederhana
- Tidak ada alokasi memori dinamis atau kompleks
- Overhead sistem termasuk minimal dalam dataset ini

Kesimpulan:
Array sudah cocok digunakan untuk penggunaan skyline pada dataset yang kecil hingga menengah. Namun untuk dataset besar array dirasa kurang efisien secara waktu eksekusinya.




## Queue
### Konsep Dasar Queue
Queue adalah struktur data akses sekuensial dengan prinsip:   

> FIFO (First In First Out) 
---
Artinya: Elemen yang pertama masuk, akan menjadi yang pertama keluar.  
Elemen ditambahkan di belakang (tail) dan dikeluarkan dari depan (head).  

### Logika Algoritma 
1. Data dibaca dari file CSV dan dimasukkan ke vector<Baju> data.
2. data disalin ke queue (vector<Baju> juga).
3. Selama queue tidak kosong:
- Ambil elemen paling depan (front() → FIFO).
- Bandingkan dengan semua elemen skyline:
- Jika dikalahkan→ abaikan.
- Jika mengalahkan, tambahkan ke skyline, dan buang elemen skyline yang dikalahkan olehnya.

### Analisis Kompleksitas
- Ketika program membuka dan membaca file CSV (ifstream, getline, parsing stringstream), setiap baris dibaca sekali saja, dan hasilnya disimpan ke dalam vector<Baju> data. Kompleksitas: O(n)
Alasan: karena ada n baris produk, dan setiap baris diproses satu kali.
- Setiap kali loop dijalankan, program mengambil elemen pertama dari antrian dengan:
```kandidat = queue.front();```
Ini hanya membaca data pada indeks ke-0 dari vector.
Kompleksitas: O(1)
Alasan: karena akses elemen di indeks tertentu pada vector sangat cepat (constant time).
- Setelah mengambil elemen, elemen tersebut dihapus dari queue dengan:
```queue.erase(queue.begin());```
Di sini vector akan menggeser seluruh elemen setelah indeks ke-0 satu posisi ke kiri, karena vector tidak mendukung pop_front() seperti deque.
Kompleksitas: O(n)
Alasan: karena tiap penghapusan memicu pergeseran semua elemen setelahnya.
- Setiap kandidat dicek satu per satu dengan elemen di skyline, apakah ada produk lain yang lebih baik dari kandidat:
```cpp
for (auto& s : skyline) {
    if (Domination(s, kandidat)) {
        ...
    }
}
```
Kompleksitas: O(n)
Alasan: karena kita melakukan loop sebanyak (n) jumlah elemen dalam skyline
- Jika kandidat tidak dikalahkan, maka kita membangun ulang skyline:
Hanya mempertahankan produk yang tidak dikalahkan oleh kandidat.
Kemudian menambahkan kandidat.
```cpp
vector<Baju> baru;
for (auto& s : skyline) {
    if (!domination(kandidat, s)) {
        baru.push_back(s);
    }
}
baru.push_back(kandidat);
skyline = baru;
```
Kompleksitas: O(n)
Alasan: karena kita mengecek ulang semua elemen di skyline untuk menentukan siapa yang kalah.
- Karena semua langkah di atas dilakukan untuk setiap elemen dalam queue (n data):  
a. Loop utama dilakukan n kali.  
b. Di dalamnya terdapat operasi erase(begin()) = O(n).  
c. Ditambah dua loop terhadap skyline = maksimal O(n)
Jadi total kompleksitas waktu keseluruhan:
> O(n²)


![WhatsApp Image 2025-04-23 at 15 40 40_83999b26](https://github.com/user-attachments/assets/4129b247-686b-4a43-857f-0edbc9ebc6a5)
![WhatsApp Image 2025-04-23 at 15 40 40_2d7d9669](https://github.com/user-attachments/assets/b60b6ebf-3a51-45d6-a9de-37320e7348cf)
![WhatsApp Image 2025-04-23 at 15 40 41_494fe982](https://github.com/user-attachments/assets/8dca0219-117f-449c-af46-ac0c6910ff80)

### Uji Coba Running
Saat menjalankan proses running, didapatkan dari 1000 data csv. Dimana ada 9 data yang terbaik (berdasarkan harga dan ulasannya) yang masuk ke skyline.  
Sementara waktu eksekusinya saya melakukan percobaan 3 kali, dan didapatkan 0.341ms, 0.293ms, dan 0.280ms. Jika dirata-rata maka waktu eksekusinya sekitar 0.304ms atau 0.000304 detik.

##Map
output:
![Screenshot 2025-04-23 201018](https://github.com/user-attachments/assets/e373a362-4402-4782-b2b9-c832ec284aa8)

percobaan pertama: 1.748

percobaan kedua: 0.837

percobaan ketiga:0.966

rata2: 1.183

pada gambar diatas telah dilakukan implementasi skyline query secara map, map ini sendiri memiliki kompleksitas O(n log n) untuk `insert` dan `lower_bound`, map cukup efisien untuk menstruktur data yang besar karena memiliki pencarian biner, juga karena map menyimpan data dalam bentuk terurut (berdasarkan harga), sehingga pemeriksaan dominasi lebih cepat, tetpi map memiliki keterbatasan seperti Jika ada banyak produk dengan harga sama, hanya yang dengan ulasan tertinggi yang disimpan.

