#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
	
	int menu, del, total, beli, bayar, diskon, jarak, ongkir; //deklarasi tipe data dan variabel yang digunakan
	int jumlah[50], harga[50], sub_total[50];
	string nama[50];
	char keluar;
	
	cout << "------- KEDAI AYAM -------" << endl; //header
	cout << "===========================" << endl;
	
	do {
		cout << endl;
		cout << "Menu Utama :" << endl; //pilihan menu utama
		cout << "1. Memasukkan pilihan menu" << endl;
		cout << "2. Keluar" << endl << endl;
		cout << "Pilih menu utama : "; cin >> menu; //input pilihan menu utama
		cout << "---------------------------" << endl;
		switch (menu) {
			case 1:
				cout << "Menu : " << endl; //pilihan menu yang dapat dipesan
				cout << "Ayam Geprek		Rp 21.000" << endl;
				cout << "Ayam Goreng		Rp 17.000" << endl;
				cout << "Udang Goreng		Rp 19.000" << endl;
				cout << "Cumi Goreng		Rp 20.000" << endl;
				cout << "Ayam Bakar		Rp 25.000" << endl;
				cout << "\nJumlah Pesanan : "; cin >> beli; //input jumlah pesanan
				cout << "---------------------------" << endl;
				for (int i = 0; i < beli; i++) { //input pesanan
					cout << "Pesanan ke " << i+1 << endl; fflush(stdin);
					cout << "Nama pesanan	: "; getline (cin, nama[i]);
					cout << "Jumlah pilihan pesanan	: "; cin >> jumlah[i];
					cout << "Harga 		: "; cin >> harga[i];
					cout << endl;
					sub_total[i] = jumlah[i] * harga[i];
					total += sub_total[i];
				}
				cout << "Apakah anda ingin menggunakan jasa delivery order? (1 : Ya | 0 : n) = "; cin >> del;
					if (del == 1)
					{
						cout << "Masukkan jarak rumah anda dari rumah makan (KM) : "; cin >> jarak;
						cout << endl;
						cout << "Silahkan keluar dari program untuk mencetak struk!" << endl;
						if (jarak < 3)
						{
							ongkir = 15000;
						}
						else
						{
							ongkir = 25000;
						}
					}
					else if (del == 0)
					{
						ongkir = 0;
					}
				if (total < 25000) //penghitungan diskon dan ognkir
				{
					diskon = 0;
				}
				if (total > 25000 && total < 50000)
				{
					ongkir = ongkir - 3000;
					total = total + ongkir;
					diskon = 0;
				}
				else if (total > 50000 && total < 150000)
				{
					ongkir = ongkir - 5000;
					diskon = total * 0.15;
					total = total - diskon + ongkir;
				}
				else if (total > 150000)
				{
					ongkir = ongkir - 8000;
					diskon = total * 0.35;
					total = total - diskon + ongkir;
				}
				break;
			case 2:
				cout << "Keluar dari program? (y|n) = "; cin >> keluar;
				cout << endl;
				break;
			default:
				cout << "Error" << endl << endl;
		}
	} while (keluar != 'y');
	system ("cls");
		cout << "\t\t==========================" << endl; //cetak struk
		cout << "\t\t|    STRUK PEMBAYARAN    |" << endl;
		cout << "\t\t==========================" << endl;
		cout << "No\t| Pesanan\t| Jumlah | Harga\t| Sub total" << endl;
		for (int i = 0; i < beli; i++) {
			cout << i+1 << "\t| " << nama[i] << "  \t| " << jumlah[i] << "\t | Rp. " << harga[i] << "\t| Rp. " << sub_total[i] << endl;
		}
		cout << "============================================================" << endl;
		cout << "Ongkir\t\t= Rp. " << ongkir << endl;
		cout << "Diskon\t\t= Rp. " << diskon << endl;
		cout << "Total bayar\t= Rp. " << total << endl;
		cout << "Bayar\t\t= Rp. "; cin >> bayar;
		cout << "Kembali\t\t= Rp. " << bayar - total << endl;
	
	
	ofstream file; //cetak struk dalam .txt
	file.open("Struk.txt");
	file << "\t\t==========================" << endl;
	file << "\t\t|    STRUK PEMBAYARAN    |" << endl;
	file << "\t\t==========================" << endl;
	file << "No\t| Pesanan\t| Jumlah | Harga\t| Sub total" << endl;
	for (int i = 0; i < beli; i++) {
		file << i+1 << "\t| " << nama[i] << "   \t| " << jumlah[i] << "\t | Rp. " << harga[i] << "\t| Rp. " << sub_total[i] << endl;
	}
	file << "============================================================" << endl;
	file << "Total bayar\t= Rp. " << total << endl;
	file << "Bayar\t\t= Rp. "; file << bayar << endl;
	file << "Kembali\t\t= Rp. " << bayar - total << endl;
	file.close();
	
	return 0;
}
