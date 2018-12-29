#include "iostream"
#include "Queue.h"
// #include "Pasien.h"
#include "Riwayat.h"

using namespace std;

/*
@Author
Name : 
1. Restu Haqqi Muzakir (17.62.0106)
2. Bayu Afrizal (17.62.0100)

Title : Sistem Teller di Puskesmas

Materi:
1.OOP : Class dan Object, Enkapsulasi, Inheritance
2.Struktur Data : Array, Struct, Queue, Searching (Sequential Search), Bubble Sort

Last Update : 28/11/2017 - 19:44 WIB

Git Repository : https://gitlab.com/restuhaqza/apotik-cpp
*/

Queue q;
// Pasien p;
Riwayat r;

int main()
{
    int menu;
    do
    {
        cout << "\n|================================================|";
        cout << "\n|            Layanan Sistem Puskesmas            |";
        cout << "\n|================================================|";
        cout << "\n[1] Antrian \n[2] Tambahkan Data Pasien \n[3] Tampilkan Data Pasien \n[4] Pencarian Data Pasien\n[5] Tambahkan Riwayat Kunjungan\n[6] Lihat Riwayat Kunjungan \n[0] Keluar";
        cout << "\nMasukkan Pilihan:";
        cin >> menu;
        switch (menu)
        {
        case 1:
            q.main();
            break;
        case 2:
            r.createPasien();
            break;
        case 3:
            r.getAllPasiens();
            break;
        case 4:
            r.getDetailPasien();
            break;
        case 5:
            r.inputRiwayat();
            break;
        case 6:
            r.lihatRiwayat();
            break;
        default:
            break;
        }
    } while (menu != 0);
}