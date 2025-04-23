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
![Screenshot 2025-04-23 130136](https://github.com/user-attachments/assets/d9af57c3-5fd8-45fa-bb6d-cabfcfe59971) <br>
berdasarkan gambar diatas telah dilakukan implementasi skyline query dengan cara linked list, implmentasi ini memiliki kompleksitas O(n²), linked list ini tidak terlalu efisien Karena Linked List tidak mendukung indexing cepat atau area pruning, sehingga harus membandingkan satu-satu (brute-force), juga Tidak efisien untuk dataset besar karena operasi penghapusan (remove_if) membutuhkan O(n).

## Stack
### Penjelasan Stack secara singkat 
- Stack merupakan tipe struktur data yang menggunakan konsep LIFO (Last in First Out) berupa tumpukan data.

Dokumentasi : 

![image](https://github.com/user-attachments/assets/112332bb-a524-47ec-b622-396ec0924290)

Dapat ditinjau pada dokumentasi tersebut bahwa efisiensi waktu menggunakan struktur data Stack memakan waktu sebesar :
- Percobaan pertama = 0.002653 detik
![image](https://github.com/user-attachments/assets/e7178c1a-3896-47b2-a821-e4e9b9b2fdff)

- Percobaan kedua = 0.002005 detik

![image](https://github.com/user-attachments/assets/48ba0f2a-1fc5-4807-80f9-99ddb7e1501b)

- Percobaan ketiga = 0.001452 detik

![image](https://github.com/user-attachments/assets/c64ff9ab-a2d1-4ce4-b769-59715611417e)

 Implementasi skyline querry dengan struktur data Stack memiliki kompleksitas O(n^2),  Operasi stack (push/pop) sendiri adalah O(1), tapi karena dilakukan dalam loop bersarang, totalnya O(n^2). Kesimpulannya stack cocok untuk analisis data file kecil, namun apabila ukuran data besar maka kurang direkomendasikan dikarenakan kompleksitas waktu dalam big O notation yang cukup besar

## Hash Table
<img src="https://github.com/user-attachments/assets/1e4719dd-8f61-4eaa-89fa-227e195dea72" width = "600"> <br>
Berdasarkan gambar di atas, telah dilakukan sebanyak tiga kali uji coba pemrosesan data pada file .csv menggunakan metode Hash Table. Hasil waktu pemrosesan dari masing-masing uji coba adalah sebagai berikut: <br>
Uji coba pertama: 0.00088687 detik <br>
Uji coba kedua: 0.0015121 detik <br>
Uji coba ketiga: 0.00112224 detik <br>
Jika dirata-ratakan, waktu pemrosesan data tersebut adalah 0.00117374 detik.

## Array
Pada Array Linear search dan traversal mudah dilakukan, namun butuh waktu lebih lama dalam pengecekan dominasi karena tidak ada efisiensi dalam pencarian.
![image](https://github.com/user-attachments/assets/446b627f-f908-47a2-8843-beb88156324b)
![image](https://github.com/user-attachments/assets/44f40d3a-d53c-4231-a645-4be36108a6c4)
Kode ini nanatinya akan membaca dataset.csv yang berada dalam folder yang sama. Menyimpan setiap item ke dalam array struct Baju. Skyline Query akan membandingkan setiap pasangan baju berdasarkan 2 kriteria yaitu harga lebih murah dan ulasana lebih tinggi. Array akan cocok pada ukuran dataset yang lebih kecil karena semua data dibandingkan satu persatau melalui nested loop. Kompleksitasnya kurang efisien untuk data yang lebih besar.



## Queue
### Konsep Dasar Queue
Queue adalah struktur data akses sekuensial dengan prinsip:   

> FIFO (First In First Out) 
---
Artinya: Elemen yang pertama masuk, akan menjadi yang pertama keluar.  
Elemen ditambahkan di belakang (tail) dan dikeluarkan dari depan (head).  

### Implementasi
- Inisialisasi Queue
- Mengambil head
- Memeriksa yg terbaik
- Menghapus dari skyline jika ada kandidat baru yang lebih baik
- Mengulangi proses hingga queue kosong


![Image](https://github.com/user-attachments/assets/d7c0a3eb-50c4-49d7-9718-0d747c12a384)
![Image](https://github.com/user-attachments/assets/cd2c6d75-7d27-4041-be0d-470f75328089)
![Image](https://github.com/user-attachments/assets/a6a277eb-e658-43cd-88a6-86044a191f07)
