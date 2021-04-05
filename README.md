# struktur-data-h-praktikum-1-2021
## Air Bendungan
### Verdict
AC saat praktikum
#### Bukti
![ab_bukti_ac](/img/ab_bukti_ac.jpg)
### Penjelasan Soal
Diminta menentukan jumlah air maksimum yang dapat ditampung oleh bendungan di Sungai Kapuas dengan data tinggi tembok-tembok dari bendungan tersebut.
### Penjelasan Solusi
Pertama, program akan menerima jumlah blok dalam bendungan dan menyimpannya dalam variabel `n`. Kedua, program akan menerima `n` buah bilangan yang menyatakan tinggi tembok-tembok dalam bendungan. Ketiga, program akan memanggil fungsi `maxWater()` untuk menghitung jumlah air maksimum yang dapat ditampung oleh bendungan. Dalam fungsi `maxWater()`, pertama terdapat inisialisasi variabel `maxHeight` dan `sum` keduanya dengan nilai 0. Selanjutnya, jelajahi array `column` dari kiri ke kanan. Untuk setiap elemen yang dikunjungi, cari nilai terbesar antara `maxHeight` dan `column[i]` dan simpan nilai terbesar tersebut dalam `leftMax[i]` dan perbarui nilai `maxHeight` dengan nilai terbesar tersebut. Lalu reset nilai `maxHeight` menjadi 0 dan jelajahi array `column` dari kanan ke kiri. Untuk setiap elemen yang dikunjungi, cari nilai terbesar antara `maxHeight` dan `column[i]` dan simpan nilai terbesar tersebut dalam `rightMax[i]` dan perbarui nilai `maxHeight` dengan nilai terbesar tersebut. Terakhir, iterasi dari `i = 0` sampai `i = n - 1`. Pada iterasi ke-`i`, tambahkan nilai `sum` dengan nilai terkecil antara `leftMax[i]` dan `rightMax[i]` dikurangi dengan `column[i]`.
### Visualisasi Solusi
Untuk mempermudah visualisasi solusi dari permasalahan Air Bendungan, digunakan sample input berikut:

```
6
3 0 0 2 0 4
```

![ab_1](/img/ab_1.jpg)

Isi `leftMax`

![ab_2](/img/ab_2.jpg)


Isi `rightMax`

![ab_3](/img/ab_3.jpg)

`sum` = min(3, 4) - 3 + min(3, 4) - 0 + min(3, 4) - 0 + min(3, 4) - 2 + min(3, 4) - 0 + min(4, 4) - 4

`sum` = 3 - 3 + 3 - 0 + 3 - 0 + 3 - 2 + 3 - 0 + 4 - 4

`sum` = 3 + 3 + 1 + 3 = 10

![ab_fs](/img/ab_fs.jpg)