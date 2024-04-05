# Robot BNMO 2
BNMO adalah sebuah robot video game console berbasis _command-line interface_ (CLI) yang dimiliki oleh Indra dan Doni. BNMO pernah mengalami kerusakan dan telah berhasil diperbaiki. Sayangnya, setelah diperbaiki, BNMO justru mendapatkan lebih banyak bug dalam sistemnya sehingga masih memerlukan perbaikan lagi dan pemrograman ulang untuk dapat digunakan kembali. BNMO kemudian juga mengalami pengembangan lebih lanjut dengan menambahkan berbagai fitur dan permainan yang menyenangkan.

# Deskripsi BNMO
Program BNMO yang menggunakan bahasa C ini memiliki beberapa permainan dan fitur untuk menjalankan permainan. Di dalam BNMO, terdapat beberapa game yang dapat dimainkan, yaitu sebagai berikut.
- RNG

  RNG yang merupakan singkatan dari _Random Number Generator_, adalah permainan menebak angka acak. Setiap permainan dimulai dengan program yang sudah menentukan sebuah angka acak. Pemain diberi kesempatan untuk menebak angka tersebut. Program akan memberitahu apakah angka acak tersebut dibandingkan dengan tebakan pemain lebih besar atau lebih kecil. Skor untuk game ini bergantung pada seberapa cepat pemain dapat menebak angka tersebut dengan benar.
- Diner DASH

  Diner DASH merupakan permainan strategi bertema restoran, yang mengantar makanan secara terurut berdasarkan prioritasnya. Terdapat 3 command yang dapat dilakukan pada game, yaitu Cook, Serve, dan Skip. Cook bertujuan untuk memasak makanan, Serve untuk menyajikan makanan kepada pelanggan, dan Skip untuk menyelesaikan 1 putaran tanpa melakukan apapun. Permainan akan selesai apabila antrian melebihi 7 pelanggan atau jumlah pelanggan yang telah dilayani mencapai 15 pelanggan. Skor akhir dari pemain adalah total uang yang diterima oleh pemain.
- Hangman

  Hangman adalah permainan tebak kata. Pada awal permainan, program menentukan sebuah kata yang harus ditebak oleh pemain berdasarkan file daftar kata _listofwords.txt_. Pemain juga dapat menambahkan kata ke dalam daftar kata tersebut. Pada permainan ini, pemain diberikan 10 kesempatan salah dalam menebak huruf pada kata. Pada setiap giliran, pemain dapat menebak satu huruf yang belum pernah ditebak sebelumnya untuk kata tersebut. Apabila huruf tebakan terdapat dalam kata, maka huruf yang berhasil ditebak ditampilkan. Sebaliknya, apabila tebakan salah, pemain kehilangan satu kesempatan. Setelah berhasil menebak kata, pemain akan mendapatkan poin sebanyak panjang kata yang berhasil ditebak. Permainan akan terus berlanjut dengan kata baru lainnya sampai pemain kehilangan kesempatan untuk menebak huruf yang salah.
- Tower of Hanoi

  Pada permainan ini, terdapat tiga tiang A, B, dan C yang posisinya terurut dari kiri ke kanan. Pada tiang A, terdapat sejumlah piringan, dengan piringan paling bawah merupakan piringan paling besar dan piringan paling atas merupakan piringan paling kecil. Seluruh piringan tersebut harus dipindahkan ke tiaang C dengan posisi yang sama. Dalam memindahkan piringan tersebut, berlaku aturan bahwa piringan yang diletakkan di bawah tidak boleh lebih besar dari piringan di atasnya. Skor pada game ini bergantung dengan jumlah piringan dan seberapa optimal langkah yang diambil oleh pemain untuk memindahkan piringan tersebut.
- Snake on Meteor

  Snake on Meteor menjadi game andalan pada BNMO. Game ini mirip dengan game snake pada berbagai console lama, namun dipersulit dengan adanya kehadiran meteor yaang dapat mengenai snake tersebut. Apabila snake terkena serangan meteor, maka panjang snake akan berkurang sebanyak 1 unit. Permainan akan berakhir apabila kepala dari snake terkena meteor atau ekor baru snake tidak dapat di-spawn karena tidak ada area di sekitar ekor lama. Skor akhir permainan dihhitung berdasarkan panjang snake, dengan satu unit komponen snake dikonversi menjadi 2 poin.

BNMO juga memiliki beberapa fitur untuk menjalankan  permainan yang ada, antara lain sebagai berikut.
| Fitur | Keterangan |
| --- | --- |
| START | Membaca file konfigurasi program _konfigurasi.txt_ |
| LOAD <file> | Membaca file penyimpanan berbasis txt berdasarkan masukan pemain, yang berisi daftar game, daftar history game, dan daftar scoreboard setiap game |
| CREATE GAME | Menambahkan permainan baru pada daftar game |
| LIST GAME | Menampilkan daftar game yang tersedia |
| DELETE GAME | Menghapus permainan dari daftar game |
| QUEUE GAME | Mendaftarkan permainan ke dalam daftar antrian game |
| PLAY GAME | Memainkan game pertama pada antrian game |
| SKIPGAME <n> | Melewatkan permainan sebanyak n pada antrian permainan |
| SCOREBOARD | Menampilkan daftar scoreboard setiap game |
| RESET SCOREBOARD | Melakukan reset terhadap scoreboard game |
| HISTORY <n> | Menampilkan daftar history game sebanyak n |
| RESET HISTORY | Menghapus semua history game yang dimainkan |
| HELP | Bantuan untuk menampilkan daftar _command_ yang dapat dipanggil |
| SAVE <file> | Menyimpan state game pemain ke dalam suatu file |
| QUIT | Keluar dari program |

## Implementasi Struktur Data
Dalam mengimplementasikan program, digunakan beberapa model ADT (Abstract Data Type) berikut.
- ADT Mesin Karakter
- ADT Mesin Kata
- ADT Array
- ADT Queue
- ADT Stack of Word
- ADT Stack of Integer
- ADT Map
- ADT Array of Map
- ADT Matriks
- ADT Linked List

## Cara Menjalankan Program
- Apabila memiliki _git bash_, dapat menjalankan _command _ berikut ini pada _command prompt_ atau _terminal_ lainnya.

  ```
  sh compile.sh
  BNMO
  ```

- Apabila tidak memiliki _git bash_, dapat menjalankan _command_ berikut ini pada _command prompt_ atau _terminal_ lainnya.

  ```
  gcc -o BNMO ./src/mainprogram.c ./src/ADT/Array/array.c ./src/ADT/MesinKarakter/mesinkarakter.c ./src/ADT/MesinKata/mesinkata.c ./src/ADT/Queue/queue.c ./src/ADT/Stack/stack.c ./src/ADT/Stack/stackToH.c ./src/ADT/Map/map.c ./src/ADT/ArrayOfMap/arrayofmap.c ./src/ADT/ListLinier/listdp.c ./src/ADT/Matriks/matriks.c ./src/Command/load.c ./src/Command/save.c ./src/Command/start.c ./src/DeleteGame/deletegame.c ./src/CreateGame/creategame.c ./src/DinerDash/DD2.c ./src/DinerDash/diner_dash.c ./src/Hangman/hangman.c ./src/Help/help.c ./src/ListGame/listgame.c ./src/PlayGame/playgame.c ./src/QueueGame/queuegame.c ./src/Quit/quit.c ./src/RNGgame/rnggame.c ./src/SkipGame/skipgame.c ./src/SkorGame/skorgame.c ./src/TowerOfHanoi/towerofhanoi.c ./src/SnakeOnMeteor/snakeonmeteor.c ./src/Scoreboard/scoreboard.c ./src/History/history.c

  BNMO
  ```

## Anggota Tim

| Nama |
| --- |
| Silvester Kresna W. P. P. |
| Jessica |
| Nalendro N.U.A.R.F. |
| Muhammad Aliefnaufal P. |
| Rayhan Nugraha Putra |
