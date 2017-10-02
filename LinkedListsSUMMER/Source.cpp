#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

struct Promo
{
	Promo*Anterior;
	Promo*Siguiente;
	char Nombre[20];
	char Categoria[20];
	char Motivo[30];
	char Alarma[_MAX_PATH];
	short Descuento;
};

Promo*Inicio;
Promo*Final;
Promo*Auxiliar;

bool Salir = 0;

char NombreBusqueda[20];

short MENU;

void Menu();
void Agregar();
void Modificar();
void Borrar();
void Buscar();
void Lista();

int main()
{
	printf("Summer C++ Linked Lists Practice\n");

	_getch();

	Menu();

	_getch();
	return 0;
};

void Menu()
{
	do
	{
		printf("ADD - 1\nDELETE - 2\nLIST - 3\nSEARCH - 4\nMODIFY - 5\n");

		cin >> MENU;

		switch (MENU)
		{
		case 1:
			system("cls");
			Agregar();
			break;
		case 2:
			system("cls");
			Borrar();
			break;
		case 3:
			system("cls");
			Lista();
			break;
		case 4:
			system("cls");
			Buscar();
			break;
		case 5:
			system("cls");
			Modificar();
			break;
		default:
			system("cls");
			printf("NO");
			Salir = 1;
			break;
		};
	} while (Salir == 0);
};

void Agregar()

{
	if (Inicio == NULL )
	{
		Inicio = new Promo;
		Inicio->Siguiente = NULL;
		Inicio->Anterior = NULL;
		printf("Nombre\n");
		cin >> Inicio->Nombre;
		printf("Categoria\n");
		cin >> Inicio->Categoria;
		printf("Motivo\n");
		cin >> Inicio->Motivo;
		printf("Descuento\n");
		cin >> Inicio->Descuento;
		Final = Inicio;
	}
	else {
		Auxiliar = new Promo;
		Auxiliar->Anterior = Final;
		Final->Siguiente = Auxiliar;
		Auxiliar->Siguiente = NULL;
		printf("Nombre\n");
		cin >> Auxiliar->Nombre;
		printf("Categoria\n");
		cin >> Auxiliar->Categoria;
		printf("Motivo\n");
		cin >> Auxiliar->Motivo;
		printf("Descuento\n");
		cin >> Auxiliar->Descuento;
		Final = Auxiliar;
	};

	_getch();
	system("cls");
	Menu();
};

void Modificar()
{
	if (Inicio != NULL) {
		Auxiliar = Inicio;

		printf("Que vas a modificar?\n");

		cin >> NombreBusqueda;

		while (Auxiliar != NULL && strcmp(Auxiliar->Nombre, NombreBusqueda) != 0) {
			Auxiliar = Auxiliar->Siguiente;
		};
		if (Auxiliar == NULL) {
			printf("Elemento no encontrado");
		}
		else {
			printf("Encontrado\n%s\n%s\n%s\n%d\n\n", Auxiliar->Nombre, Auxiliar->Categoria, Auxiliar->Motivo, Auxiliar->Descuento);
			printf("Nuevo Nombre\n");
			cin >> Auxiliar->Nombre;
			printf("Nueva Categoria\n");
			cin >> Auxiliar->Categoria;
			printf("Nuevo Motivo\n");
			cin >> Auxiliar->Motivo;
			printf("Nuevo Descuento\n");
			cin >> Auxiliar->Descuento;
		};
	}
	else {
		printf("Lista Vacia");
	};

	_getch();
	system("cls");
	Menu();
};

void Buscar()
{
	if (Inicio != NULL) {
		Auxiliar = Inicio;

		printf("Que vas a buscar?\n");

		cin >> NombreBusqueda;

		while (Auxiliar != NULL && strcmp(Auxiliar->Nombre, NombreBusqueda) != 0) {
			Auxiliar = Auxiliar->Siguiente;
		};
		if (Auxiliar == NULL) {
			printf("Elemento no encontrado");
		}
		else {
			printf("Encontrado\n%s\n%s\n%s\n%d\n\n", Auxiliar->Nombre, Auxiliar->Categoria, Auxiliar->Motivo, Auxiliar->Descuento);
		};
	}
	else {
		printf("Lista Vacia");
	};

	_getch();
	system("cls");
	Menu();
}

void Borrar()
{
	if (Inicio != NULL) {
		Auxiliar = Inicio;

		printf("Que vas a borrar?\n");

		cin >> NombreBusqueda;

		while (Auxiliar != NULL && strcmp(Auxiliar->Nombre, NombreBusqueda) != 0) {
			Auxiliar = Auxiliar->Siguiente;
		};
		if (Auxiliar == NULL) {
			printf("Elemento no encontrado");
		}
		else {
			if (Auxiliar == Inicio && Inicio == Final)
			/*if (Auxiliar->Siguiente == NULL && Auxiliar->Anterior == NULL)*/ {			
				Inicio = NULL;
				Final = NULL;
				delete Auxiliar;	
			}
			else {
				if (Auxiliar == Inicio)
				/*if (Auxiliar->Anterior == NULL && Auxiliar->Siguiente != NULL)*/ {
					Auxiliar->Siguiente->Anterior = NULL;
					Inicio = Auxiliar->Siguiente;
					delete Auxiliar;
				}
				else {
					if (Auxiliar == Final)
					/*if (Auxiliar->Anterior != NULL && Auxiliar->Siguiente == NULL)*/ {					
						Auxiliar->Anterior->Siguiente = NULL;
						Final = Auxiliar->Anterior;
						delete Auxiliar;	
					}
					else {
						Auxiliar->Anterior->Siguiente = Auxiliar->Siguiente;
						Auxiliar->Siguiente->Anterior = Auxiliar->Anterior;
						delete Auxiliar;
					}
				}
			}
		}
	}
	else {
		printf("Lista Vacia");
	};

	_getch();
	system("cls");
	Menu();
};

void Lista()

{
	if (Inicio != NULL) {
		Auxiliar = Inicio;

		while (Auxiliar != NULL) {
			printf("%s\n%s\n%s\n%d\n\n", Auxiliar->Nombre, Auxiliar->Categoria, Auxiliar->Motivo, Auxiliar->Descuento);
			Auxiliar = Auxiliar->Siguiente;
		};
		if (Auxiliar == NULL) {
			printf("Fin de la Lista\n");
		};
	}
	else {
		printf("Lista Vacia");
	};

	_getch();
	system("cls");
	Menu();
};