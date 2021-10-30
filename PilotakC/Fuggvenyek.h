#pragma once
#include "Strukturak.h"
#include <stdlib.h>
#include <stdio.h>

Lista* feltoltes(Lista* lista, Adatok adat)
{
	Lista* temp = (Lista*)malloc(sizeof(Lista));
	temp->adat = adat;
	temp->kovetkezo = NULL;
	lista->kovetkezo = temp;
	return temp;
}

void felszabaditas(Lista* adat)
{
	Lista* temp, * elem;
	elem = adat;
	do
	{
		temp = elem;
		elem = elem->kovetkezo;
		free(temp);
	}while (elem != NULL);
}