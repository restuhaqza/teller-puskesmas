#include "iostream"
#include "Queue.h"
#include "Pasien.h"
using namespace std;

Queue q;
Pasien p;

int main()
{
    int menu;
    do
    {
        cout << "\n|================================================|";
        cout << "\n|            Layanan Sistem Puskesmas            |";
        cout << "\n|================================================|";
        cout << "\n[1] Antrian \n[2] Tambahkan Data Pasien \n[3] Tampilkan Data Pasien \n[0] Keluar";
        cout << "\nMasukkan Pilihan:";
        cin >> menu;
        switch (menu)
        {
        case 1:
            q.main();
            break;
        case 2:
            p.createPasien();
            break;
        case 3:
            p.getAllPasiens();
            break;
        default:
            break;
        }
    } while (menu != 0);
}