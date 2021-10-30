#pragma once
typedef struct Datum
{
	int ev;
	int honap;
	int nap;
}Datum;

typedef struct Adatok
{
	char nev[25];
	Datum szulDatum;
	char nemzetiseg[25];
	int rajtszam;

}Adatok;

typedef struct Lista
{
	Adatok adat;
	struct Lista* kovetkezo;
}Lista;
