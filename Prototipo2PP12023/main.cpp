/*Nombre: Giovanni Steve Cifuentes Palencia
  carné: 9959-22-1822*/
//Programa para el segundo Parcial
//El programa consiste en Control de Inventarios, tienen un Login con archivos secunciales, um menu para ingresar nuevos usuarios, menu para acceder al memu de catalogos
//otros submenus para el CRUD y el informe
#include <iostream>
#include "usuario.h"
#include "menuCrud.h"

#define USER "Administrador2"
#define PASS "admin"

using namespace std;

int main()
{
    string usuario, contrasena;
    Usuario ingreso(usuario, contrasena);
    bool usuarioCorrecto = ingreso.verificarUsuario();

    string id, nombre, precio, cantidad, fecha;
    menuCrud catalogos(id, nombre, precio, cantidad, fecha);

    if (usuarioCorrecto) {
    int choice;
	char x;
	do
    {
	system("cls");

    cout <<"\t\t\t--------------------------------------------"<<endl;
    cout <<"\t\t\t |       BIENVENIDO AL MENU PRINCIPAL      |"<<endl;
    cout <<"\t\t\t |Nombre: Giovanni Steve Cifuentes Palencia|"<<endl;
    cout <<"\t\t\t |Carné: 9959-22-1822                      |"<<endl;
    cout <<"\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso Al Menu de Usurios"<<endl;
	cout<<"\t\t\t 2. Ingreso Al Menu de Catalogos"<<endl;
	cout<<"\t\t\t 3. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;
    switch(choice){
    case 1:
        ingreso.menuUsuarios();//ingresa al menu de usuarios
        break;
    case 2:
        catalogos.menu();//ingresa el submenu del catalogos
        break;
    case 3:
        exit(0);
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
        break;
    }
    }while(choice!= 3);
}
    return 0;
}
