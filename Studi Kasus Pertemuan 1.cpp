#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
	
	int menu, total, beli, bayar, diskon; //deklarasi tipe data dan variabel yang digunakan
	int jumlah[50], harga[50], sub_total[50];
	string nama[50];
	char keluar;
	
	cout << "------- KEDAI AYAM -------" << endl; //header
	cout << "===========================" << endl;
	
	do {
		cout << "Menu Utama :" << endl; //pilihan menu utama
		cout << "1. Memasukkan pilihan menu" << endl;
		cout << "2. Keluar" << endl << endl;
		cout << "Pilih menu utama : "; cin >> menu; //input pilihan menu utama
		cout << "---------------------------" << endl;
		switch (menu) {
			case 1:
				cout << "Menu : " << endl; //pilihan menu yang dapat dipesan
				cout << "Ayam Goreng		Rp 17.000" << endl;
				cout << "Ayam Bakar		Rp 21.000" << endl;
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
					if (total >= 45000) //penghitungan diskon
					{
						diskon = total * 0.1;
						total = total - diskon;
					}
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
		cout << "\t\t==========================" << endl; //cetak struk
		cout << "\t\t|    STRUK PEMBAYARAN    |" << endl;
		cout << "\t\t==========================" << endl;
		cout << "No\t| Pesanan\t| Jumlah | Harga\t| Sub total" << endl;
		for (int i = 0; i < beli; i++) {
			cout << i+1 << "\t| " << nama[i] << "  \t| " << jumlah[i] << "\t | Rp. " << harga[i] << "\t| Rp. " << sub_total[i] << endl;
		}
		cout << "============================================================" << endl;
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
