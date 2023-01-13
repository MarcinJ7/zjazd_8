#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#pragma warning(disable: 4996)
#define TABSIZE 5

void wypisz(double* poczatekTablicy, int liczbaElementow)
{
	for (int i = 0; i < liczbaElementow; i++)
	{
		printf("%lf\t", *(poczatekTablicy+i));
	}
}

void zamien(double *first, double *second)
{
	double temp = *first;
	*first = *second;
	*second = temp;
}

void save(double tab[], FILE* out, int lElementow)
{
	for (int i = 0; i < lElementow; i++)
	{
		fprintf(out, "%d element: %lf\n", i, tab[i]);
	}
	printf("\n\nZapisano!");
}

int main(int argc, char* argv[])
{
	double tablica[TABSIZE];
	srand((unsigned int)time(NULL));
	
	// uzupełnienie tablicy wartościami losowymi
	for (int i = 0; i < TABSIZE; i++)
	{
		tablica[i] = (double)rand() / RAND_MAX;
	}

	//wypisz tablice
	printf("Tablica przed sortowaniem:\n");
	wypisz(tablica, TABSIZE);
	printf("\n\nSortowanie:\n ");

	// liczba porownan
	for (int i = 0; i < (TABSIZE-1); i++)
	{
		// powonywane elementy (za kazdym razem o jeden mniej, bo ustawiony w poprzedniej iteracji)
		for (int j = 0; j < (TABSIZE - 1 - i); j++)
		{
			//zamiana (jesli j-ty element wiekszy od nastepnika)
			if (tablica[j] > tablica[j + 1])
			{
				zamien(&tablica[j], &tablica[j + 1]);
			}
			//wypisz tablice
			wypisz(tablica, TABSIZE);
			printf("\n\n");
		}
	}

	// zapis do pliku
	FILE* out;
	char* file_name = "daneWyj.txt";
	out = fopen(file_name, "w");
	save(tablica, out, TABSIZE);
}
