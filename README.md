# struktur-data-h-praktikum-1-2021
## Nadut & Cayo
### Verdict
AC saat revisi
#### Bukti
![verdict_naca](/img/verdict_naca.jpg)
### Penjelasan Soal
Diberikan beberapa angka yang dianggap sebagai blok angka yang ditumpuk, di mana jika blok yang baru dimasukkan lebih besar dari blok yang sudah ada, maka blok lama dikeluarkan dari tumpukan. Diminta mengeluarkan tumpukan akhir.
### Penjelasan Solusi
Pertama, program menerima banyak testcase yang disimpan dalam variabel `T`. Lalu, dilakukan loop sebanyak `T`. Di dalam `loop`, program menerima banyak blok angka yang akan disusun dan disimpan dalam variabel `P`. Lalu, program akan menerima angka-angka pada blok yang disimpan dalam array `Q`. Kemudian, nilai-nilai dari index dari array `Q` akan dievaluasi dengan bantuan stack `myStack`di dalam loop sebanyak P :
1. Jika nilai `Q[index] <= stack_top(&myStack)`(kurang dari elemen teratas stack) atau `stack_isEmpty(&myStack)` (stack kosong) maka `Q[index]` akan dimasukkan ke dalam stack (`stack_push`).
2. Jika nilai `Q[index]` lebih dari elemen teratas (`Q[j]>stack_top(&myStack)`), maka elemen teratas akan dikeluarkan 
`stack_pop(&myStack)`. Hal ini akan dilakukan terus menerus sampai elemen teratas lebih dari nilai `Q[index]` atau stack kosong (`myStack._top==NULL`).
Apabila sudah dilakukan loop sebanyak `P`, elemen dari stack akan disimpan ke dalam array baru `arr`. Elemen dimasukkan secara terbalik, dengan cara mengassign index dari `size-1` sampai `0` dan melalukan pop pada stack.
Terakhir, keluarkan `Susunan blok yang disusun Nadut dan Cayo adalah : ` diikuti oleh nilai anggota `arr` berurutan dari `index 0` sampai terakhir.
Proses diulang sebanyak `T`.

### Visualisasi Solusi
Untuk mempermudah visualisasi solusi dari permasalahan Nadut & Cayo, digunakan sample input berikut:

```
1
5
5 4 7 2 1
```

Maka outputnya adalah
```
Susunan blok yang disusun Nadut dan Cayo adalah : 7 2 1
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

## Genjil Ganap
### Verdict
AC saat revisi
#### Bukti
![verdict_gega](/img/verdict_gega.jpg)
### Penjelasan Soal
Diminta untuk menyusun nomor plat mobil, yaitu nomor plat genap disusun di tumpukan depan dan nomor plat ganjil disusun di tumpukan belakang.
Kemudian, susunan tersebut dikeluarkan (print).
### Penjelasan Solusi
Pertama, program akan menerima input berupa jumlah nomor plat yang akan diinput, disimpan dalam variabel `N`. Lalu, dilakukan looping sebanyak `N` kali. Pada setiap loop:
- Menerima input nomor plat yang disimpan sementara di variabel `plat`.
- Push nilai `plat` ke priority queue `myPque`.
    - Fungsi push yang sudah dimodifikasi ini akan memprioritaskan nomor genap (`value%2==0`) untuk diletakkan di depan, sedangkan nomor ganjil akan diletakkan paling belakang.

Setelah loop selesai, isi priority queue dikeluarkan diawali dengan
```
printf("Urutan Mobil Roy : ");
```
lalu dengan loop:
```
while (!pqueue_isEmpty(&myPque)) 
{
    printf("%d ", pqueue_top(&myPque));
    pqueue_pop(&myPque);
}
```
### Visualisasi Solusi
Untuk mempermudah visualisasi solusi dari permasalahan Genjil Ganap, digunakan sample input berikut:

```
5
1012
222
1001
1002
6969
```
Maka keluarannya
```
Urutan Mobil Roy : 1002 222 1012 1001 6969
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

## Bread Problemo
### Verdict
AC saat revisi
#### Bukti
![verdict_brpr](/img/verdict_brpr.jpg)
### Penjelasan Soal
Program akan memindah-mindahkan roti sebanyak N dari tumpukan roti Ray ke tumpukan roti kakaknya dan sebaliknya. Tumpukan akhir roti Ray dan kakaknya akan menentukan output yang akan dikeluarkan.
### Penjelasan Solusi
Permasalahan akan diselesaikan dengan implementasi ADT stack.
Pertama, program menginisialisasi stack Ray dan kakak.
```
stack_init(&Ray);
stack_init(&Kakak);
```
Lalu, program akan menerima input banyak roti yang disimpan dalam variabel `N`. Langsung dilakukan pengujian apakah `N == 0`, jika iya output `Ray SangaT MaraH!`. Jika tidak, diterima input jumlah dapat memindahkan roti dan stack diisi dengan nilai dari `N` (terbawah) sampai `1` (teratas) dengan fungsi `stack_initialise(&Ray, N);`. Kemudian, dilakukan looping sebanyak `T` kali. Tiap loop menerima command, `Ai` menentukan asal-tujuan roti (1 berarti dari Ray ke kakak, 2 berarti sebaliknya) dan `Bi` menentukan seberapa banyak roti yang dipindah. Jika input `Ai` tidak sesuai, maka akan dikeluarkan `TumpukAnnya saLah! :(` dan program berhenti (`return 0`).

Dalam memindahkan roti, dilakukan satu-satu, sehingga dilakukan `push` ke stack tujuan dan `pop` pada stack asal sebanyak roti yang ingin dipindahkan. Eksekusi `push-pop` ini disederhanakan melalui fungsi `moveStack`:
```
void moveStack(Stack *_destination, Stack *_source){
    if(!stack_isEmpty(_source)){
        stack_push(_destination, stack_top(_source));
        stack_pop(_source);
        return;
    }
}
```
Menerima parameter alamat `stack` tujuan dan alamat `stack` asal, fungsi ini mem`push` nilai teratas dari `stack` asal ke `stack` tujuan lalu mem`pop` stack asal tersebut JIKA `stack` asal tidak kosong.
Jika program sudah selesai looping, dikeluarkan output sebagai berikut:
- Jika tinggi stack berbeda:
Keluarkan top dari stack Ray dan kakak, kemudian pop, diulang sebanyak tinggi stack yang lebih kecil (variabel `small`), lalu
    - Jika tinggi stack Ray lebih dari kakak (`stack_size(&Ray) > stack_size(&Kakak)`):
    Keluarkan top dari stack Ray didampingi dengan `:(`.
    - Jika tinggi stack Kakak lebih dari Ray (`stack_size(&Kakak) > stack_size(&Ray)`):
    Keluarkan `-` didampingi top dari stack kakak.
Kemudian, keluarkan sisa stack yang lebih tinggi dengan top dan pop sebanyak `dif-1`, dimana dif adalah variabel yang menyimpan selisih tinggi stack.
- Jika tinggi stack sama: keluarkan top kedua stack secara berdampingan kemudian pop diulang sebanyak ukuran stack.


### Visualisasi Solusi
Untuk mempermudah visualisasi solusi dari permasalahan Bread Problemo, digunakan sample input berikut:

```
5
5
1 1
1 2
1 1
2 1
2 2
```

![ab_1](/img/si_bp1.jpg)
Isi stack `Ray` dengan banyak roti

![ab_2](/img/si_bp2.jpg)
Pindahkan 1 roti ke stack `Kakak`

![ab_3](/img/si_bp3.jpg)
Pindahkan 2 roti ke stack `Kakak`

![ab_1](/img/si_bp4.jpg)

Pindahkan 1 roti ke stack `Kakak`

![ab_2](/img/si_bp5.jpg)
Pindahkan 1 roti ke stack `Ray`

Isi `rightMax`

![ab_3](/img/si_bp6.jpg)
Pindahkan 2 roti ke stack `Ray`

stack `Ray` = `[2,3,4,5]`
stack `Kakak` = `[1]`

Output:
```
2 1
3 :(
4
5
```

# Tambahan
## MALUR RAJIN
### Verdict
WA
#### Bukti
![verdict_mara](/img/verdict_mara.jpg)
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