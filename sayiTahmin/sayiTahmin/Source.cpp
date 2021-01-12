#include <stdlib.h>
#include <stdio.h>
void StartGame(void);
void parcala(int dizi[4], int);
int CheckFunc(int CheckArray[4]);
/*CeckFunc : Fonksiyon tahmin sayýsýnýn ilk rakamý sýfýrsa veya tekrar eden rakam varmý diye konrol ediyor.
Parcala : Fonksiyon sayýyý basamaklarýna ayýrýyor.
StartGame : Oyunu Baslatan Fonksiyon
*/

int main() {
	StartGame();
	system("PAUSE");
} // main son


void parcala(int dizi[4], int gizli) {
	int i = 3;
	while (gizli > 0)
	{
		dizi[i] = gizli % 10;
		gizli /= 10;
		i--;
	}

}

int CheckFunc(int CheckArray[4]) {
	int Check = 0;

	if (CheckArray[0] == 0)
	{
		Check = 1;
	}
	for (int f = 0; f < 4; f++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (f != j && CheckArray[f] == CheckArray[j])
			{
				Check = 2;
			}

		}
	}

	return Check;
}
void StartGame(void) {
	int hidden_numbers[4] = {}, hidden = 0, guess = 0;
	int  guess_numbers[4] = {}, TrueGuess = 0, FalseGuess = 0;
	printf("Merhaba sayi tahmin oyununa hosgeldiniz. \n");
	printf("Lutfen dort basamakli bir sayi giriniz. \n");
	scanf_s("%d", &hidden);

	parcala(hidden_numbers, hidden);

	for (; ;)
	{

		printf("************************************************ \n");
		printf("************************************************ \n");
		printf("Lutfen tahmininizi giriniz. \n");
		scanf_s("%d", &guess);
		parcala(guess_numbers, guess);
		CheckFunc(guess_numbers);
		int Check = CheckFunc(guess_numbers);
		if (Check == 1 || Check == 2)
		{
			printf("Girdi Uygun Degil Lutfen Farkli Deger giriniz \n");
			continue;
		}
		for (int i = 0; i < 4; i++)
		{
			for (int k = 0; k < 4; k++)
			{
				if ((hidden_numbers[i] == guess_numbers[k]) && i == k)
				{
					TrueGuess++;
				}
				if (i != k && hidden_numbers[i] == guess_numbers[k])
				{

					FalseGuess--;
				}

			} // iç for son

		} // dýþ for son

		if (TrueGuess == 4)
		{

			break;
		}

		printf("+%d  %d \n", TrueGuess, FalseGuess);
		FalseGuess = 0;
		TrueGuess = 0;

	} //sonsuz for son

	printf(" TEBRIKLER!! DOGRU TAHMIN SAYIYI BULDUNUZ!!! Gizli Sayi: %d \n", hidden);
}