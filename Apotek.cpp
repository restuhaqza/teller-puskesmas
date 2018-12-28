#include "iostream"
#include "Queue.h"
// #include "Pasien.h"
#include "Riwayat.h"

using namespace std;

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