#include <iostream>
#include <vector>
#include <stdlib.h>
#include <iomanip>
using namespace std;

class Pasien
{
  protected:
    vector<int> noCode;
    vector<int> idNumber;
    vector<string> fullname;
    vector<string> address;

  protected:
    struct riwayat
    {
        vector<int> noCode;
        vector<string> keterangan;
        vector<string> tanggal;
    } riwayat;

  public:
    void
    createPasien()
    {
        int _idNumber;
        string _fullname, _address;

        cout << "Masukkan No. Identitas (KTP) :";
        cin >> _idNumber;
        cout << "Masukkan Nama Lengkap :";
        cin.ignore();
        getline(cin, _fullname);
        cout << "Masukkan Alamat:";
        getline(cin, _address);

        this->noCode.push_back(this->createNoCode());
        this->idNumber.push_back(_idNumber);
        this->fullname.push_back(_fullname);
        this->address.push_back(_address);

        cout << "\n============================================================";
        cout << "\nData Berhasil Di Tambahkkan!";
        cout << "\nKode Registrasi : " << this->noCode[this->noCode.size() - 1];
        cout << "\nNomor Identitas : " << this->idNumber[this->idNumber.size() - 1];
        cout << "\nNama Lengkap :" << this->fullname[this->fullname.size() - 1];
        cout << "\nAlamat :" << this->address[this->address.size() - 1];
        cout << "\n============================================================\n\n\n3";
    }

  private:
    int createNoCode()
    {
        int noCodeTemp = rand() % 1000 + 9999;
        if (this->noCode.size() != 0)
        {
            for (int i = 0; i < this->noCode.size(); i++)
            {
                if (this->noCode[i] == noCodeTemp)
                {
                    createNoCode();
                }
                else
                {
                    return noCodeTemp;
                }
            }
        }
        else
        {
            return noCodeTemp;
        }
        return noCodeTemp;
    }

  protected:
    int search(int noCode)
    {
        int index = -1;
        for (int i = 0; i < this->noCode.size(); i++)
        {
            if (this->noCode[i] == noCode)
            {
                index = i;
            }
        }
        return index;
    }

  public:
    void getDetailPasien()
    {
        int index;
        int _code;
        cout << "Masukkan Kode Pasien :";
        cin >> _code;
        index = search(_code);
        if (index != -1)
        {
            cout << "\n============================================================";
            cout << "\nKode Registrasi : " << this->noCode[index];
            cout << "\nNomor Identitas : " << this->idNumber[index];
            cout << "\nNama Lengkap :" << this->fullname[index];
            cout << "\nAlamat :" << this->address[index];
            cout << "\n============================================================";
        }
        else
        {
            cout << "\n|===================================================|";
            cout << "\n|             Data Tidak Di Temukan                 |";
            cout << "\n|===================================================|\n\n";
        }
    }

  public:
    void getAllPasiens()
    {
        int choise;
        do
        {
            cout << "\n\n DAFTAR PASIEN TERDAFTAR";
            cout << "\n|====|===================|===========================|====================|";
            cout << "\n| No |    Kode Pasien    |         Nama Lengkap      |        Alamat      |";
            cout << "\n|====|===================|===========================|====================|";

            for (int i = 0; i < this->noCode.size(); i++)
            {
                cout << "\n"
                     << setw(4) << i + 1
                     << setw(19) << this->noCode[i]
                     << setw(27) << this->fullname[i]
                     << setw(20) << this->address[i];
            }
            cout << "\n|====|===================|===========================|====================|";
            cout << "\n [1] Sorting by Name Ascending \n [2] Sorting by Name Descending \n \[3] Pencarian Data \n [0] Kembali ke menu utama \n";
            cout << "======================" << endl;
            cout << "Masukan Pilihan : ";
            cin >> choise;
            cout << "======================" << endl;
            switch (choise)
            {
            case 1:
                sortByNameAsc();
                break;
            case 2:
                sortByNameDsc();
                break;
            case 3:
                getDetailPasien();
                break;
            default:
                break;
            }
        } while (choise != 0);
    }

  private:
    void sortByNameAsc()
    {
        int tempNoCode, tempId;
        string tempName, tempAddress;
        for (int i = 1; i < this->fullname.size(); i++)
        {
            for (int j = 0; j < (this->fullname.size() - 1); j++)
            {
                if (this->fullname[j] > this->fullname[j + 1])
                {
                    tempNoCode = this->noCode[j];
                    this->noCode[j] = this->noCode[j + 1];
                    this->noCode[j + 1] = tempNoCode;

                    tempId = this->idNumber[j];
                    this->idNumber[j] = this->idNumber[j + 1];
                    this->idNumber[j + 1] = tempId;

                    tempName = this->fullname[j];
                    this->fullname[j] = this->fullname[j + 1];
                    this->fullname[j + 1] = tempName;

                    tempAddress = this->address[j];
                    this->address[j] = this->address[j + 1];
                    this->address[j + 1] = tempAddress;
                }
            }
        }
    }

  private:
    void sortByNameDsc()
    {
        int tempNoCode, tempId;
        string tempName, tempAddress;
        for (int i = 1; i < this->fullname.size(); i++)
        {
            for (int j = 0; j < (this->fullname.size() - 1); j++)
            {
                if (this->fullname[j] < this->fullname[j + 1])
                {
                    tempNoCode = this->noCode[j];
                    this->noCode[j] = this->noCode[j + 1];
                    this->noCode[j + 1] = tempNoCode;

                    tempId = this->idNumber[j];
                    this->idNumber[j] = this->idNumber[j + 1];
                    this->idNumber[j + 1] = tempId;

                    tempName = this->fullname[j];
                    this->fullname[j] = this->fullname[j + 1];
                    this->fullname[j + 1] = tempName;

                    tempAddress = this->address[j];
                    this->address[j] = this->address[j + 1];
                    this->address[j + 1] = tempAddress;
                }
            }
        }
    }
};