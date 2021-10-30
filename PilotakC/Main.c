#include<string.h>
#include<locale.h>
#include "Fuggvenyek.h"
#define locale setlocale(LC_ALL, "")
int main()
{
	char* nyelv = locale;
	Adatok adat, *adatok;
	Lista* elso, * lista, * temp;
	lista = (Lista*)malloc(sizeof(Lista));
	FILE* beolvas;
	beolvas = fopen("pilotak.csv", "r");
	char fejlec[60], rajtTomb[50];
	int a;
	fgets(fejlec, sizeof(fejlec), beolvas);
	fscanf(beolvas, "%[^;];%d.%d.%d;%[^;];%[^A-Z][^a-z]",
		adat.nev, &adat.szulDatum.ev, &adat.szulDatum.honap, &adat.szulDatum.nap, adat.nemzetiseg, rajtTomb);
	adat.rajtszam = atoi(rajtTomb);
	lista = feltoltes(lista, adat);
	elso = lista;
	int count = 1;
	while (fscanf(beolvas, "\n%[^;];%d.%d.%d;%[^;];%[^A-Z][^a-z]",
		adat.nev, &adat.szulDatum.ev, &adat.szulDatum.honap, &adat.szulDatum.nap, adat.nemzetiseg, rajtTomb)!=EOF)
	{
		adat.rajtszam = atoi(rajtTomb);
		lista = feltoltes(lista, adat);
		count++;
	}
	int i=0, j;
	Lista *elem;
	adatok = (Adatok*)malloc(count * sizeof(Adatok));
	for (elem = elso; elem!=NULL; elem = elem->kovetkezo)
	{
		
		adatok[i] = elem->adat;
		i++;
		
	}
	fclose(beolvas);
	
	felszabaditas(elso);
	printf("3. feladat: %d\n", count);
	printf("4. feladat: %s\n", adatok[count-1].nev);
	puts("5. feladat:");
	for ( i = 0; i < count; i++)
	{
		if (adatok[i].szulDatum.ev < 1901)
		{
			printf("\t%s (%d. %02d. %02d.)\n", adatok[i].nev, adatok[i].szulDatum.ev, adatok[i].szulDatum.honap, adatok[i].szulDatum.nap);
		}
	}
	Adatok minimum = adatok[0];

	for ( i = 1; i < count; i++)
	{
		if (minimum.rajtszam > adatok[i].rajtszam && adatok[i].rajtszam!=0)
		{
			minimum = adatok[i];
		}
	}
	printf("6. feladat: %s\n", minimum.nemzetiseg);
	printf("7. feladat: ");
	int* rajtszamok = malloc(50 * sizeof(int));
	int rajt = 1, szamol;
	int volt;
	rajtszamok[0] = adatok[0].rajtszam;
	for ( i = 1; i < count; i++)
	{
		volt = 0;
		if (adatok[i].rajtszam != 0)
		{
			for ( j = 0; j < rajt; j++)
			{
				if (adatok[i].rajtszam == rajtszamok[j])
				{
					volt = 1;
				}
			}
			if (volt == 0)
			{
				rajtszamok[rajt] = adatok[i].rajtszam;
				rajt++;
				
			}
		}
	}
	volt = 0;
	for ( i = 0; i < rajt; i++)
	{
		szamol = 0;
		for ( j = 0; j < count; j++)
		{
			if (rajtszamok[i] == adatok[j].rajtszam && rajtszamok[i]!=0)
			{
				
				szamol++;
			}
		}
		if (szamol > 1 && volt == 0)
		{
			printf("%d", rajtszamok[i]);
			volt = 1;

		}
		else if (szamol > 1 && volt == 1)
		{
			printf(", %d", rajtszamok[i]);
		}

	}
	return 0;
}