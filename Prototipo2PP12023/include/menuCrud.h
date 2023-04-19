/*Nombre: Giovanni Steve Cifuentes Palencia
  carné: 9959-22-1822*/

#ifndef MENUCRUD_H
#define MENUCRUD_H

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;

//Aqui se definen las variables y los metodos publicos y privados que sirven para el CRUD y Informes

class menuCrud
{
    public:
        menuCrud();
        menuCrud(string id, string nombre, string precio, string cantidad, string fecha);

        // Get y set de las variables
        string setId(string id);
        string getId();
        string setNombre(string nombre);
        string getNombre();
        string setPrecio(string precio);
        string getPrecio();
        string setCantidad(string cantidad);
        string getCantidad();
        string setFecha(string fecha);
        string getFecha();

        void menu(); // La funcion menu() muestra un menu en consola para que el usuario pueda elegir entre diferentes opciones.
        void submenu(); // La funcion menu() muestra un submenu en consola para que el usuario pueda elegir entre diferentes opciones.
		void insertar(); // La funci�n insertar() permite al usuario ingresar informaci�n para crear un nuevo registro y lo guarda en un archivo.
		void desplegar(); // La funci�n desplegar() lee y muestra todos los registros almacenados en el archivo.
		void modificar(); // La funci�n modificar() permite al usuario seleccionar un registro por ID y modificar su informaci�n.
		void buscar(); // La funci�n buscar() permite al usuario buscar un registro por ID y mostrar su informaci�n.
		void borrar(); // La funci�n borrar() permite al usuario eliminar un registro por ID.



    protected:

    private:
        string id, nombre, precio, cantidad, fecha;
};

#endif // MENUCRUD_H
