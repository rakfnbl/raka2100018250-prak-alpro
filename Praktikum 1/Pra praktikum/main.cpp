#include <iostream>
using namespace std;

int main () {
	
	float a, b;
	int pil1, pil2;
l:	cout<<"Kalkulator Sederhana"<<endl;
	cout<<"--------------------"<<endl;
	cout<<"1. Penjumlahan"<<endl;
	cout<<"2. Pengurangan"<<endl;
	cout<<"3. Perkalian"<<endl;
	cout<<"4. Pembagian"<<endl;
	cout<<"--------------------"<<endl;
	cout<<"Masukkan pilihan : "; cin>>pil1;
	
	switch (pil1) {
		case 1:
			cout<<"Masukkan angka pertama : "; cin>>a;
			cout<<"Masukkan angka kedua   : "; cin>>b;
			cout<<"Hasil penjumlahan dari "<< a <<" dengan "<< b <<" adalah "<< a + b<<endl;
			break;
		case 2:
			cout<<"Masukkan angka pertama : "; cin>>a;
			cout<<"Masukkan angka kedua   : "; cin>>b;
			cout<<"Hasil pengurangan dari "<< a <<" dengan "<< b <<" adalah "<< a - b<<endl;
			break;
		case 3:
			cout<<"Masukkan angka pertama : "; cin>>a;
			cout<<"Masukkan angka kedua   : "; cin>>b;
			cout<<"Hasil perkalian dari "<< a <<" dengan "<< b <<" adalah "<< a * b<<endl;
			break;
		case 4:
			cout<<"Masukkan angka pertama : "; cin>>a;
			cout<<"Masukkan angka kedua   : "; cin>>b;
			cout<<"Hasil pembagian dari "<< a <<" dengan "<< b <<" adalah "<< a / b<<endl;
			break;
		default:
			cout<<"Pilihan tidak tersedia."<<endl;
	}
	cout<<"--------------------"<<endl;
	cout<<"1. Ulangi?"<<endl;
	cout<<"2. Keluar"<<endl;
	cout<<"Pilihan : "; cin>>pil2;
	if (pil2 == 1) {
		cout<<endl;
		goto l;
	} else {
		return 0;
	}
}
