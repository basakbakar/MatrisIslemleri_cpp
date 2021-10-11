/****************************************************************************
**					SAKARYA ÜNÝVERSÝTESÝ
**			         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI…...:3
**				ÖÐRENCÝ ADI...............:Baþak BAKAR
**				ÖÐRENCÝ NUMARASI.:B171210075
**				DERS GRUBU…………:D
****************************************************************************/

#include <iostream>
#include <process.h>
#include<stdlib.h>

using namespace std;

struct Islem
{

	int giris[5][5] = { 3,2,5,1,4,
						6,2,1,0,7,
						3,0,0,2,0,
						1,1,3,2,2,
						0,3,1,0,0 };//I defined a struct called giris here.
	int uzunluk = sizeof(giris) / 4;	//This operation gives the number of giris matrix's elements number.
	int cekirdek[5][5];
	int cekirdek_boyutu;
	int kayma_miktari;
	int result_size;

};

bool calculate(int  giris, int boyut, int kayma);//In here I showed the function that I defined after int main.
int main()
{
	Islem islem;
	int lenght = islem.uzunluk;

	int size = islem.cekirdek_boyutu;
	cout << "Cekirdek boyutunu giriniz: ";
	cin >> size;

	if (size >= 2 && size <= 5)//I wanted the size of cekirdek to be between 2 and 5.
	{
		int kayma = islem.kayma_miktari;
		cout << "Kayma miktarini giriniz: ";
		cin >> kayma;
		cout << endl;

		calculate(lenght, size, kayma);//I called the function I defined after int main here.


		for (int x = 0; x < size; x++)
		{
			for (int y = 0; y < size; y++)
			{
				cout << "Cekirdek[" << x << "][" << y << "]=: ";//In here, I wanted the user to enter the elements of the cekirdek matrix.
				cin >> islem.cekirdek[x][y];
				cout << endl;
			}
		}
		cout << endl;
		islem.result_size = ((sqrt(lenght) - size) / kayma) + 1;//I made the program calculate the size of the result matrix.
		for (int line = 0; line < islem.result_size; line++)//I made the two for loops inside's operation repeated with these first two for loops. 
		{
			for (int column = 0; column < islem.result_size; column++)
			{
				int total = 0;
				int a = 0;
				for (int x = 0 + line * kayma; x < size + line * kayma; x++)//With these two for loops I made the A=B*C operation.
				{
					int b = 0;
					for (int y = 0 + column * kayma; y < size + column * kayma; y++)
					{

						int sonuc = 0;
						sonuc = (islem.giris[x][y] * islem.cekirdek[a][b]);
						total += sonuc;
						b++;
					}
					a++;
				}
				cout << total << "\t";
			}
			cout << endl;
		}



	}
	else
		cout << "Bu islem yapilamaz" << endl;

	system("pause");
	return 0;
}

bool calculate(int  giris, int boyut, int kayma) //This function will calculate if the main operation can be happened. 
{
	int x = (giris - boyut) % kayma;
	if (x == 0)
		return true;
	else
	{
		cout << "Bu islem yapilamaz";
		exit(3);
		return 3;
	}
}

