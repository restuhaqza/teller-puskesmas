#include "iostream"
#include "cstdlib"
#define MAX 100

using namespace std;

class Queue
{

  private:
	struct queue
	{
		string data[MAX];
		int awal, akhir;
	} antrian;

  private:
	void init()
	{
		antrian.awal = -1;
		antrian.akhir = -1;
	}

  private:
	bool full()
	{
		if (antrian.akhir == MAX - 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

  private:
	bool empty()
	{
		if (antrian.akhir == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

  private:
	void deQueue()
	{
		int i;
		if (!empty())
		{
			for (i = antrian.awal; i < antrian.akhir; i++)
			{
				antrian.data[i] = antrian.data[i + 1];
			}
			antrian.akhir--;
		}
		else
		{
			cout << "Antrian Kosong" << endl;
		}
	}

  private:
	void clear()
	{
		antrian.awal = -1;
		antrian.akhir = -1;
	}

  private:
	void setQueue()
	{
		int jml;
		cout << "Masukan jumlah Antrian untuk hari ini : ";
		cin >> jml;

		this->clear();
		for (int i = 0; i < jml; ++i)
		{
			antrian.data[antrian.akhir] = i + 1;
			antrian.akhir++;
		}

		cout << jml << " Antrian berhasil ditambahkan !" << endl;
	}

  private:
	void queueNow()
	{
		int i;
		if (!empty())
		{

			for (i = antrian.awal; i < antrian.akhir; i++)
			{
				cout << antrian.data[i] << " <= ";
			}
		}
		cout << "\n";
	}

  private:
	void inQueue()
	{
		string elemen;

		if (!full())
		{
			cout << "Nama Pasien  :";
			cin >> elemen;
			cout << "Data berhasil ditambahkan\n";

			antrian.data[antrian.akhir] = elemen;
			antrian.akhir++;
		}
		else
		{
			cout << "Antrian penuh\n";
		}
		getchar();
	}

  public:
	void main()
	{
		int menu;
		do
		{
			queueNow();
			cout << "\n [1] Ambil No Antrian \n [2] Panggil Antrian \n [3] Clear Antrian \n [0] Menu Utama \n";
			cout << "======================" << endl;
			cout << "[Menu Antrian] Masukan Pilihan : ";
			cin >> menu;
			cout << "======================" << endl;
			switch (menu)
			{
			case 1:
				this->inQueue();
				break;
			case 2:
				this->deQueue();
				break;
			case 3:
				this->clear();
				break;
			}
		} while (menu != 0);
	}
};