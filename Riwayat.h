#include "iostream"
#include "ctime"
#include "Pasien.h"
using namespace std;

class Riwayat : public Pasien
{
  public:
    void inputRiwayat()
    {
        int _noCode, kembali;
        string desc, date;
        time_t now;
        cout << "Masukkan Kode Pasien:";
        cin >> _noCode;
        int index = search(_noCode);
        if (index == -1)
        {
            cout << "Data Tidak Ditemukan";
            inputRiwayat();
        }
        cout << "\n============================================================";
        cout << "\nKode Registrasi : " << this->noCode[index];
        cout << "\nNomor Identitas : " << this->idNumber[index];
        cout << "\nNama Lengkap :" << this->fullname[index];
        cout << "\nAlamat :" << this->address[index];
        cout << "\n============================================================";
        cout << "\nMasukkan Keterangan :\n";
        cin.ignore();
        getline(cin, desc);
        cout << "Masukkan Tanggal Kunjungan:";
        getline(cin, date);

        riwayat.noCode.push_back(_noCode);
        riwayat.keterangan.push_back(desc);
        riwayat.tanggal.push_back(date);

        cout << "Data Berhasil di tambahlkan";
    }

  public:
    void lihatRiwayat()
    {
        int choise, index;
        do
        {
            cout << "\n[1] Tampilkan Berdasarkan Pasien \n[2] Tampilkan Semua Riwayat Kunjungan \n[0] Kembali";
            cout << "\nMasukkan Pilihan:";
            cin >> choise;
            switch (choise)
            {
            case 1:
                int _noCode;
                cout << "Masukkan Kode Pasien :";
                cin >> _noCode;
                index = search(_noCode);
                if (index != -1)
                {
                    cout << "\n============================================================";
                    cout << "\nKode Registrasi : " << this->noCode[index];
                    cout << "\nNomor Identitas : " << this->idNumber[index];
                    cout << "\nNama Lengkap :" << this->fullname[index];
                    cout << "\nAlamat :" << this->address[index];
                    cout << "\n============================================================";
                    cout << "\n|===================|======================================|";
                    cout << "\n|      Tanggal      |              Keterangan              |";
                    cout << "\n|===================|======================================|\n";
                    for (int i = 0; i < riwayat.noCode.size(); i++)
                    {
                        if (_noCode == riwayat.noCode[i])
                        {
                            cout << setw(19) << riwayat.noCode[i];
                            cout << setw(38) << riwayat.keterangan[i] << endl;
                        }
                        else
                        {
                            cout << setw(40) << "\nBelum Ada Riwayat Kunjungan Pasien";
                        }
                    }
                    cout << "\n|===================|======================================|";
                }
                else
                {
                    cout << "\nData Pasien Tidak Ditemukan";
                }
                break;
            case 2:
                cout << "\n|===================|============|======================================|";
                cout << "\n|      Tanggal      | Kode Pasien |             Keterangan              |";
                cout << "\n|===================|============|======================================|\n";
                if (riwayat.noCode.size() != 0)
                {
                    for (int i = 0; i < riwayat.noCode.size(); i++)
                    {

                        cout << setw(19) << riwayat.tanggal[i];
                        cout << setw(12) << riwayat.noCode[i];
                        cout << setw(38) << riwayat.keterangan[i] << endl;
                    }
                }
                else
                {
                    cout << setw(40) << "Belum Ada Riwayat Kunjungan Pasien";
                }
                cout << "\n|===================|============|======================================|\n";
                break;
            default:
                break;
            }
        } while (choise != 0);
    }
};