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

![nc1](/img/si_nc1.jpg)

Stack kosong, `push` 5 ke `myStack`

![nc2](/img/si_nc2.jpg)

4 kurang dari `stack_top`, `push` 4 ke `myStack`

![nc3a](/img/si_nc3a.jpg)
![nc3b](/img/si_nc3b.jpg)

7 lebih dari `stack_top`, `pop` terus `myStack` hingga `stack_top` >= 7 atau `stack_isEmpty`

![nc4](/img/si_nc4.jpg)

2 kurang dari `stack_top`, `push` 2 ke `myStack`

![nc5](/img/si_nc5.jpg)

1 kurang dari `stack_top`, `push` 1 ke `myStack`

![nc6](/img/si_nc6.jpg)

Salin nilai elemen stack ke array `arr` secara terbalik.
Kemudian, print anggota arr

Output:
```
Susunan blok yang disusun Nadut dan Cayo adalah : 7 2 1
```

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

![gg0](/img/si_gg0.jpg)

Inisialisasi priority queue `myPque`

![gg1](/img/si_gg1.jpg)

`1012` genap, `myPque` kosong, dimasukkan ke depan dan belakang

![gg2](/img/si_gg2.jpg)

`222` genap, dimasukkan ke depan

![gg3](/img/si_gg3.jpg)

`1001` ganjil, dimasukkan ke belakang

![gg4](/img/si_gg4.jpg)

`1002` genap, dimasukkan ke depan

![gg5](/img/si_gg5.jpg)

`6969` ganjil, dimasukkan ke belakang

Output:
```
Urutan Mobil Roy : 1002 222 1012 1001 6969
```

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

![bp1](/img/si_bp1.jpg)

Isi stack `Ray` dengan banyak roti

![bp2](/img/si_bp2.jpg)

Pindahkan 1 roti ke stack `Kakak`

![bp3](/img/si_bp3.jpg)

Pindahkan 2 roti ke stack `Kakak`

![bp4](/img/si_bp4.jpg)

Pindahkan 1 roti ke stack `Kakak`

![bp5](/img/si_bp5.jpg)

Pindahkan 1 roti ke stack `Ray`

![bp6](/img/si_bp6.jpg)

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
AC saat perbaikan
#### Bukti
![verdict_mara](/img/verdict_mara.jpg)
### Penjelasan Soal
Diberikan tumpukan buku dengan banyak soalnya. Program diminta untuk mengeluarkan buku dengan jumlah soal paling sedikit dan banyak buku yang harus dipindahkan untuk bisa mengeluarkan buku tersebut dari tumpukan.
### Penjelasan Solusi
Solusi yang diberikan adalah dengan menggunakan `priority queue` dengan modifikasi agar tetap menyimpan data urutan data dimasukkan.
Pertama, program akan menerima berapa banyak testcase yang akan diberikan, disimpan dalam variabel `tc`. Lalu, diadakan looping sebanyak `tc`. Di dalam loop, diterima input yang dapat berupa `-1` untuk mengeluarkan buku atau angka lainnya yang merupakan jumlah soal. Input disimpan dalam variabel `cmd`. Apabila `cmd!=-1` atau merupakan jumlah soal, maka terima input nama mata pelajaran (`mapel`). Apabila banyak soal adalah 0, lewati iterasi. Selain 0, push banyak soal dan nama mata pelajaran ke pqueue `buku`.

Pada fungsi `push`, terjadi beberapa evaluasi. Program dibuat untuk memprioritaskan data dengan `soal` paling sedikit sehingga secara program akan terurut dari `soal` tersedikit sampai terbanyak. Namun, `node` tetap dapat menyimpan bagaimana tumpukan dalam dunia nyata dengan informasi `loc`. Fungsi `moveEachElement(pqueue, "DOWN")` berfungsi layaknya pemberi informasi ke `node` yang sudah ada bahwa ada `node` yang akan ditumpuk di atas mereka, dengan menambahkan `loc` tiap elemen dengan 1.

Jika `cmd==-1`, maka elemen terdepan pqueue `buku` akan dikeluarkan (`loc` kemudian `mapel`nya). Kemudian, `nodes` yang ada dibelakang `top` secara program, tapi di atas dalam kenyataan, dihapuskan (`free`). Hal ini dilakukan dengan mengecek `loc` masing-masing elemen, di mana jika kurang dari `loc` `top`, maka akan dihapus. Jika `loc` elemen lebih dari `loc` `top`, maka `loc`nya dikurangi sebanyak buku yang ada di atas `top`+1. Terakhir, `pop``buku` agar `top` dihapus.

### Visualisasi Solusi
Untuk mempermudah visualisasi solusi dari permasalahan Malur Rajin, digunakan sample input berikut:

```
6
9 enggres
6 matematika
8 geo
-1
3 fisika
-1
```

![mr1](/img/si_mr1.jpg)

`enggres` dimasukkan, diletakkan pertama pada `buku`. Banyak soal dan lokasi disimpan pada var `.soal` dan `.loc`

![mr2](/img/si_mr2.jpg)

`matematika` dimasukkan, diletakkan pertama pada `buku`, karena soalnya lebih sedikit dibandingkan `enggres`. Lokasinya 0, lokasi `enggres`+1

![mr3](/img/si_mr3.jpg)

`geo` dimasukkan, diletakkan kedua pada `buku`, karena soalnya lebih banyak dibandingkan `matematika`. Lokasinya 0 karena pada keadaan sebenarnya terletak paling atas, lokasi `enggres` dan `matematika` + 1

![mr4](/img/si_mr4.jpg)

Command `-1` meminta `matematika` dikeluarkan, maka dilakukan `pop` dan me`remove` segala elemen dengan `loc` < `loc` `matematika` (dalam hal ini `geo`).
Lokasi lainnya `-2`

![mr5](/img/si_mr5.jpg)

`fisika` dimasukkan, diletakkan pertama pada `buku`, karena soalnya lebih sedikit dibandingkan `enggres`. Lokasinya 0, lokasi `enggres`+1

![mr6](/img/si_mr6.jpg)

Command `-1` meminta `fisika` dikeluarkan, maka dilakukan `pop` dan me`remove` segala elemen dengan `loc` < `loc` `fisika` (dalam hal ini __tidak ada__).
Lokasi lainnya `-1` (`enggres`)

Output:
```
1 matematika
0 fisika
```