#include <string>
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
	char Descripcion[30];
	short Precio;
};

Promo*Inicio;
Promo*Final;
Promo*Auxiliar;

string X;

bool Salir = 0;

char NombreBusqueda[20];

short MENU;

void Menu();
void Agregar();
void Modificar();
void Eliminar();
void Buscar();
void Lista();
void Guardar();
void Cargar();

int main()
{
	Cargar();
	cout << X << endl;
	Menu();

	_getch();
	return 0;
};

void Menu()
{
	do
	{
		printf("Agregar - 1\nEliminar - 2\nMostrar Lista - 3\nBuscar Elemento - 4\nMofidicar Elemento - 5\nSalir - 6\n");

		cin >> MENU;

		switch (MENU)
		{
		case 1:
			system("cls");
			Agregar();
			break;
		case 2:
			system("cls");
			Eliminar();
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
			Guardar();
			printf("Adios");
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
		printf("Descripcion\n");
		cin >> Inicio->Descripcion;
		printf("Precio\n");
		cin >> Inicio->Precio;
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
		printf("Descripcion\n");
		cin >> Auxiliar->Descripcion;
		printf("Precio\n");
		cin >> Auxiliar->Precio;
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
			system("cls");
			printf("Elemento no encontrado\n");
		}
		else {
			printf("Encontrado\n%s\n%s\n%s\n%d\n\n", Auxiliar->Nombre, Auxiliar->Categoria, Auxiliar->Descripcion, Auxiliar->Precio);
			printf("Nuevo Nombre\n");
			cin >> Auxiliar->Nombre;
			printf("Nueva Categoria\n");
			cin >> Auxiliar->Categoria;
			printf("Nuevo Descripcion\n");
			cin >> Auxiliar->Descripcion;
			printf("Nuevo Precio\n");
			cin >> Auxiliar->Precio;
			printf("Cambios Realizados\n");
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
			system("cls");
			printf("Elemento no encontrado\n");
		}
		else {
			printf("Encontrado\n%s\n%s\n%s\n%d\n\n", Auxiliar->Nombre, Auxiliar->Categoria, Auxiliar->Descripcion, Auxiliar->Precio);
		};
	}
	else {
		printf("Lista Vacia");
	};

	_getch();
	system("cls");
	Menu();
}

void Eliminar()
{
	if (Inicio != NULL) {
		Auxiliar = Inicio;

		printf("Que vas a Eliminar?\n");

		cin >> NombreBusqueda;

		while (Auxiliar != NULL && strcmp(Auxiliar->Nombre, NombreBusqueda) != 0) {
			Auxiliar = Auxiliar->Siguiente;
		};
		if (Auxiliar == NULL) {
			system("cls");
			printf("Elemento no encontrado\n");
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
			printf("Elemento \"%s\" eliminado\n", NombreBusqueda);
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
			printf("%s\n%s\n%s\n%d\n\n", Auxiliar->Nombre, Auxiliar->Categoria, Auxiliar->Descripcion, Auxiliar->Precio);
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

void Guardar() {
	if (Inicio!=NULL) {
		ofstream file("Archivo.bin", ios::binary, ios::trunc);
		if (file.is_open()) {
			Auxiliar = Inicio;
			while (Auxiliar != NULL) {
				file << Auxiliar->Nombre;
				file << Auxiliar->Categoria;
				file << Auxiliar->Descripcion;
				file << Auxiliar->Precio;
				Auxiliar = Auxiliar->Siguiente;
			}file.close();
		}
		else { printf("No se pudo abrir el archivo\n"); }
	}
};

void Cargar() {
	ifstream file("Archivo.bin", ios::binary);
		if (file.is_open()) {
			getline(file, X);
			file.close();
		}
};