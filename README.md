# Robot BNMO 2
BNMO adalah sebuah robot video game console berbasis _command-line interface_ (CLI) yang dimiliki oleh Indra dan Doni. BNMO pernah mengalami kerusakan dan telah berhasil diperbaiki. Sayangnya, setelah diperbaiki, BNMO justru mendapatkan lebih banyak bug dalam sistemnya sehingga masih memerlukan perbaikan lagi dan pemrograman ulang untuk dapat digunakan kembali. BNMO kemudian juga mengalami pengembangan lebih lanjut dengan menambahkan berbagai fitur dan permainan yang menyenangkan.

# Deskripsi BNMO
Program BNMO yang menggunakan bahasa C ini memiliki beberapa fungsional. Di dalam BNMO, terdapat beberapa game yang dapat dimainkan, yaitu RNG (tebak angka acak), Diner DASH (permainan strategi bertema restoran), Hangman, Tower of Hanoi, dan Snake on Meteor. BNMO memiliki beberapa fitur untuk menjalankan  permainan yang ada, antara lain membaca file konfigurasi sistem (start), membaca file penyimpanan berbasis txt berdasarkan masukan pemain (load), menambahkan permainan baru pada daftar game (create game), menghapus permainan pada daftar game yang tersedia (delete game), melihat daftar permainan yang tersedia (list game), pembuatan antrian permainan (queue game) berdasarkan daftar permainan yang tersedia, kemampuan untuk melewati beberapa permainan pada antrian permainan (skip game), memainkan permainan yang berada di antrian game paling awal (play game), bantuan untuk menampilkan daftar command yang dapat dipanggil (help), menyimpan state game pemain ke dalam suatu file (save), dan keluar dari program (quit).

## K01 Kelompok 9

| Nama | NIM |
| --- | --- |
| Silvester Kresna W. P. P. | 18221049 |
| Jessica | 18221073 |
| Nalendro N.U.A.R.F. | 18221085 |
| Muhammad Aliefnaufal P. | 18221105 |
| Rayhan Nugraha Putra | 18221149 |

## Cara Menjalankan Program
Jika memiliki git bash, dapat gunakan command berikut di Command Prompt atau terminal lainnya
```
sh compile.sh

BNMO
```

Jika memiliki git bash, dapat gunakan command berikut di Command Promt atau terminal lainnya
```
gcc -o BNMO ./src/mainprogram.c ./src/ADT/Array/array.c ./src/ADT/MesinKarakter/mesinkarakter.c ./src/ADT/MesinKata/mesinkata.c ./src/ADT/Queue/queue.c ./src/ADT/Stack/stack.c ./src/ADT/Stack/stackToH.c ./src/ADT/Map/map.c ./src/ADT/ArrayOfMap/arrayofmap.c ./src/ADT/ListLinier/listdp.c ./src/ADT/Matriks/matriks.c ./src/Command/load.c ./src/Command/save.c ./src/Command/start.c ./src/DeleteGame/deletegame.c ./src/CreateGame/creategame.c ./src/DinerDash/DD2.c ./src/DinerDash/diner_dash.c ./src/Hangman/hangman.c ./src/Help/help.c ./src/ListGame/listgame.c ./src/PlayGame/playgame.c ./src/QueueGame/queuegame.c ./src/Quit/quit.c ./src/RNGgame/rnggame.c ./src/SkipGame/skipgame.c ./src/SkorGame/skorgame.c ./src/TowerOfHanoi/towerofhanoi.c ./src/SnakeOnMeteor/snakeonmeteor.c ./src/Scoreboard/scoreboard.c ./src/History/history.c

BNMO
```
