/*Nombre: Giovanni Steve Cifuentes Palencia
  carné: 9959-22-1822*/

#include "menuCrud.h"

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;

menuCrud::menuCrud(string id, string nombre, string precio, string cantidad, string fecha)
{
    this->id = id;
    this->nombre = nombre;
    this->precio = precio;
    this->cantidad = cantidad;
    this->fecha = fecha;
}

// set y get para id
string menuCrud::setId(string id) {
    this->id = id;;
}
string menuCrud::getId() {
    return this->id;
}

// set y get para nombre
string menuCrud::setNombre(string nombre) {
    this->nombre = nombre;
}
string menuCrud::getNombre() {
    return this->nombre;
}

// set y get para precio
string menuCrud::setPrecio(string precio) {
    this->precio = precio;
}
string menuCrud::getPrecio() {
    return this->precio;
}

// set y get para cantidad
string menuCrud::setCantidad(string cantidad) {
    this->cantidad = cantidad;
}
string menuCrud::getCantidad() {
    return this->cantidad;
}

// set y get para fecha
string menuCrud::setFecha(string fecha) {
    this->fecha = fecha;
}
string menuCrud::getFecha() {
    return this->fecha;
}

void menuCrud::menu(){//metodo para ingresar al submenu de catalogos
    bool salir = false;
    int choice;
	do
    {
	system("cls");

    cout <<"\t\t\t----------------------------------"<<endl;
    cout <<"\t\t\t|       MENU DE CATALOGOS         |"<<endl;
    cout <<"\t\t\t----------------------------------"<<endl;
	cout<<"\t\t\t 1. CRUD CATALOGOS"<<endl;
	cout<<"\t\t\t 2. INFORMES"<<endl;
	cout<<"\t\t\t 3. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        submenu();
		break;
	case 2:
		desplegar();
		break;
	case 3:
	    salir = true;
    default:
        cout<<"\t\t\t\nSaliendo del menu";
	}
    }while(choice!= 3);
}

void menuCrud::submenu()//metodo para ingresar al submenu CRUD
{
    bool salir = false;
    int choice;
    char x;
	do
    {
	system("cls");

    cout <<"\t\t\t----------------------------------"<<endl;
    cout <<"\t\t\t|       CRUD CATALOGOS            |"<<endl;
    cout <<"\t\t\t----------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso Datos Para Plantilla"<<endl;
	cout<<"\t\t\t 2. Modifice Datos"<<endl;
	cout<<"\t\t\t 3. Buscar Datos"<<endl;
	cout<<"\t\t\t 4. Borrar Datos"<<endl;
	cout<<"\t\t\t 5. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        do
    	{
    		insertar();
    		cout<<"\n\t\t\t Agrega otra persona(Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');
		break;
	case 2:
		modificar();
		break;
	case 3:
		buscar();
		break;
	case 4:
		borrar();
		break;
	case 5:
	    salir = true;
    default:
        cout<<"\t\t\t\nSaliendo del menu";
	}
	getch();
    }while(choice!= 5);
}
void menuCrud::insertar()//Este metodo ingresa los datos del producto
{
	system("cls");
	fstream file;
	cout<<"\n----------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar Inventario Del Catalogo ---------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa Id del Producto         : ";
	cin>>id;
	cout<<"\t\t\tIngresa Nombre del Producto     : ";
	cin>>nombre;
	cout<<"\t\t\tIngresa Precio del Producto   : ";
	cin>>precio;
	cout<<"\t\t\tIngresa Cantidad de Productos Ingresado: ";
	cin>>cantidad;
	cout<<"\t\t\tIngresa Fecha de Ingreso: ";
	cin>>fecha;
	file.open("Impresion.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< precio <<std::left<<std::setw(15)<< cantidad <<std::left<<std::setw(15)<< fecha << "\n";
	file.close();
}

void menuCrud::desplegar()//este metodo despliga al menu informes todo lo ingresado
{
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------Impresion de Inventario -------------------------"<<endl;
	file.open("Impresion.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> id >> nombre >> precio >> cantidad >> fecha;
		while(!file.eof())
		{
			total++;
            cout<<"\t\t\tIngresa Id del Producto         : " << id << endl;
	        cout<<"\t\t\tIngresa Nombre del Producto     : " << nombre << endl;
	        cout<<"\t\t\tIngresa Precio del Producto   : " << precio << endl;
	        cout<<"\t\t\tIngresa Cantidad de Productos Ingresado: " << cantidad << endl;
	        cout<<"\t\t\tIngresa Fecha de Ingreso: " << fecha << endl;
			file >> id >> nombre >> precio >> cantidad >> fecha;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
	system("pause");
}
void menuCrud::modificar()//Este metodo ayuda a modificar el producto desde la Id
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Modificacion Detalles Inventario-------------------------"<<endl;
	file.open("Impresion.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese Id de la personas que quiere modificar: ";
		cin>>participant_id;
		file1.open("Record.txt",ios::app | ios::out);
		file >> id >> nombre >> precio >> cantidad >> fecha;
		while(!file.eof())
		{
			if(participant_id!=id)
			{
			 file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< precio <<std::left<<std::setw(15)<< cantidad <<std::left<<std::setw(15)<< fecha << "\n";
			}
			else
			{
			    cout<<"\t\t\tIngresa Id del Producto         : ";
                cin>>id;
	            cout<<"\t\t\tIngresa Nombre del Producto     : ";
	            cin>>nombre;
                cout<<"\t\t\tIngresa Precio del Producto   : ";
	            cin>>precio;
	            cout<<"\t\t\tIngresa Cantidad de Productos Ingresado: ";
	            cin>>cantidad;
	            cout<<"\t\t\tIngresa Fecha de Ingreso: ";
	            cin>>fecha;
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< precio <<std::left<<std::setw(15)<< cantidad <<std::left<<std::setw(15)<< fecha << "\n";
				found++;
			}
			file >> id >> nombre >> precio >> cantidad >> fecha;

		}
		file1.close();
		file.close();
		remove("Impresion.txt");
		rename("Record.txt","Impresion.txt");
	}
}
void menuCrud::buscar()//Busca el producto
{
	system("cls");
	fstream file;
	int found=0;
	file.open("Impresion.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Inventario Duscado----------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n-------------------------Inventario Duscado------------------------"<<endl;
		cout<<"\nIngrese Id del producto a que quiere buscar: ";
		cin>>participant_id;
		file >> id >> nombre >> precio >> cantidad >> fecha;
		while(!file.eof())
		{
			if(participant_id==id)
			{
                cout<<"\t\t\tIngresa Id del Producto         : " << id << endl;
	            cout<<"\t\t\tIngresa Nombre del Producto     : " << nombre << endl;
	            cout<<"\t\t\tIngresa Precio del Producto   : " << precio << endl;
	            cout<<"\t\t\tIngresa Cantidad de Productos Ingresado: " << cantidad << endl;
	            cout<<"\t\t\tIngresa Fecha de Ingreso: " << fecha << endl;
				found++;
			}
			file >> id >> nombre >> precio >> cantidad >> fecha;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Persona no encontrada...";
		}
		file.close();
	}
}
void menuCrud::borrar()//Borra el Producto
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Productos del Inventario a Borrar-------------------------"<<endl;
	file.open("Impresion.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Id de la Persona que quiere borrar: ";
		cin>>participant_id;
		file1.open("Record.txt",ios::app | ios::out);
		file >> id >> nombre >> precio >> cantidad >> fecha;
		while(!file.eof())
		{
			if(participant_id!= id)
			{
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< precio <<std::left<<std::setw(15)<< cantidad <<std::left<<std::setw(15)<< fecha << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> id >> nombre >> precio >> cantidad >> fecha;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id Persona no encontrado...";
		}
		file1.close();
		file.close();
		remove("Impresion.txt");
		rename("Record.txt","Impresion.txt");
	}
}
