/*Nombre: Giovanni Steve Cifuentes Palencia
  carné: 9959-22-1822*/

#include "Usuario.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

#define USER "Administrador2"
#define PASS "admin"

Usuario::Usuario(string usuario, string contrasena) // Se define el constructor de la clase Usuario, que recibe como parámetros un usuario y una contraseña
{
    this->usuario=usuario; // Se asigna el valor del parámetro usuario al atributo usuario de la clase
    this->contrasena=contrasena; // Se asigna el valor del parámetro contrasena al atributo contrasena de la clase
}

string Usuario::setUusuario(string usuario) { // Se define el método setUsuario, que recibe como parámetro un usuario
    this->usuario = usuario; // Se asigna el valor del parámetro usuario al atributo usuario de la clase
}

string Usuario::getUusuario() { // Se define el método getUsuario
    return this->usuario; // Se devuelve el valor del atributo usuario de la clase
}

string Usuario::setContrasena(string contrasena) { // Se define el método setContrasena, que recibe como parámetro una contraseña
    this->contrasena = contrasena; // Se asigna el valor del parámetro contrasena al atributo contrasena de la clase
}

string Usuario::getSontrasena(){ // Se define el método getContrasena
    return this->contrasena; // Se devuelve el valor del atributo contrasena de la clase
}

void Usuario::menuUsuarios(){
    int choice; // Se declara la variable choice para almacenar la opción elegida por el usuario
	char x; // Se declara la variable x para almacenar la respuesta del usuario al preguntar si quiere agregar otra persona
	bool repetir = true; // Se inicializa la variable repetir en true

	do
    {
	system("cls"); // Se limpia la pantalla

    cout <<"\t\t\t----------------------------------"<<endl; // Se imprime un mensaje de bienvenida al menú de usuarios
    cout <<"\t\t\t|        MENU DE USUARIOS         |"<<endl;
    cout <<"\t\t\t----------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso Nuevos Usuarios"<<endl; // Se imprime la opción para ingresar nuevos usuarios
	cout<<"\t\t\t 2. Despliegue De Usuarios"<<endl; // Se imprime la opción para desplegar los usuarios
	cout<<"\t\t\t 3. Exit"<<endl; // Se imprime la opción para salir

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/]"<<endl; // Se imprime una línea indicando que se debe elegir una opción
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice; // Se lee la opción elegida por el usuario

    switch(choice) // Se utiliza un switch para ejecutar el código correspondiente a la opción elegida por el usuario
    {
    case 1:
    	do // Se utiliza un do-while para permitir al usuario agregar más de una persona
    	{
    		ingresarUsuarios(); // Se llama al método para ingresar nuevos usuarios
    		cout<<"\n\t\t\t Agrega otra persona(Y,N): ";
    		cin>>x; // Se pregunta al usuario si desea agregar otra persona
		}while(x=='y'||x=='Y'); // Se repite el ciclo mientras la respuesta del usuario sea afirmativa
		break;
	case 2:
	    verificarUsuario();
		desplegarUsurios(); // Se llama al método para desplegar los usuarios
		break;
	case 3:
	    repetir=false; // Se cambia el valor de repetir a false para salir del menú
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez.."; // Se imprime un mensaje de error si la opción elegida es inválida
	}
    }while(choice!= 3); // Se repite el ciclo mientras la opción elegida por el usuario sea diferente a 6 (salida del menú)
}

void Usuario::ingresarUsuarios(){
    system("cls");
    fstream file;//objeto "fstream" para manejar archivos

    // Declaración de variables
    string usuario, contrasena;

    // Imprime mensaje y solicita al usuario que ingrese el nombre de usuario y la contraseña
    cout<<"\n------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n-------------------------------------------------Agregar Usuarios al Sistema--------------------------------------------"<<endl;
    cout << "\t\t\t\nIngrese el nombre de usuario:         ";
    cin >> usuario;
    cout << "\t\t\t\nIngrese la contrasena:         ";

// Inicia la entrada de caracteres uno por uno, ocultando la contraseña con asteriscos
char caracter;
caracter = getch();
contrasena = "";
while (caracter != 13){ // El bucle se ejecuta hasta que el usuario presiona la tecla "Enter" (código ASCII 13)
    if(caracter != 8) // Si el caracter ingresado no es "Backspace" (código ASCII 8)
    {
        contrasena.push_back(caracter); // Agrega el caracter ingresado al final de la cadena "contrasena"
        cout<< "*"; // Imprime un asterisco en la consola
    }else{ // Si el caracter ingresado es "Backspace"
        if(contrasena.length()>0) // Si la cadena "contrasena" tiene al menos un caracter
        {
            cout<<"\b \b"; // Borra el último caracter ingresado de la consola (mueve el cursor una posición a la izquierda, imprime un espacio en blanco y mueve el cursor de nuevo a la izquierda)
            contrasena = contrasena.substr(0, contrasena.length() - 1); // Elimina el último caracter ingresado de la cadena "contrasena"
        }
    }
    caracter = getch(); // Lee el siguiente caracter ingresado por el usuario
}

// Abre el archivo "Usuarios1.txt" en modo de apendizaje y escritura
file.open("Usuarios1.txt", ios::app | ios::out);

// Escribe en el archivo los datos del usuario ingresados por el usuario, con un ancho de 15 caracteres para cada campo
file<<std::left<<std::setw(15)<< usuario <<std::left<<std::setw(15)<< contrasena << "\n";

// Cierra el archivo
file.close();

// Imprime mensaje de éxito
cout << "\t\t\t\nUsuario registrado exitosamente.";
}
void Usuario::desplegarUsurios()
{
    system("cls"); // limpia la pantalla de la consola
	fstream file; // crea un objeto de archivo de la biblioteca fstream
	int total=0; // inicializa una variable para contar el número de usuarios

	// Imprime el encabezado para la tabla de usuarios registrados
	cout<<"\n-------------------------Tabla de Usuarios Registrados-------------------------"<<endl;

	file.open("Usuarios1.txt",ios::in); // abre el archivo "Usuarios1.txt" en modo lectura
	if(!file) // si no se pudo abrir el archivo
	{
		cout<<"\n\t\t\tNo hay información..."; // muestra un mensaje de error
		file.close(); // cierra el archivo
	}
	else // si se pudo abrir el archivo
	{
		file >> usuario >> contrasena; // lee el primer usuario del archivo

		// mientras no se llegue al final del archivo
		while(!file.eof())
		{
			total++; // incrementa el contador de usuarios
			cout<<"\t\t\t Nombre de usuario: "<<usuario<<endl; // muestra el nombre del usuario
			cout<<"\t\t\t Contraseña del usuario: "<<contrasena<<endl; // muestra la contraseña del usuario
			file >> usuario >> contrasena; // lee el siguiente usuario del archivo
		}

		if(total==0) // si no se encontró ningún usuario en el archivo
		{
			cout<<"\n\t\t\tNo hay informacion..."; // muestra un mensaje de error
		}
	}

	file.close(); // cierra el archivo
}

bool Usuario::verificarUsuario() {
// Declaración de variables locales
string usuario, contrasena;  // Almacenan el usuario y la contraseña ingresados
int contador = 0;  // Contador de intentos
bool encontrado = false;  // Indica si se encontró el usuario y la contraseña correctos

// El ciclo se repite mientras el número de intentos sea menor a 3 y no se haya encontrado un usuario válido
while (contador < 3 && !encontrado) {

    // Limpiar la pantalla y mostrar el título del login
    system("cls");
    cout <<"\t\t\t--------------------"<<endl;
    cout <<"\t\t\t| LONGIN DE USUARIO |"<<endl;
    cout <<"\t\t\t---------------------"<<endl;

    // Mostrar mensaje de advertencia
    cout <<"\n\tSolo tienes permitido 3 intentos"<<endl;
    cout <<"\t----------------------------------"<<endl;

    // Solicitar al usuario el nombre de usuario y la contraseña
    cout << "\t\t\t\nIngrese el nombre de usuario:         ";
    cin >> usuario;
    cout << "\t\t\t\nIngrese la contrasena:         ";
    char caracter;
    caracter = getch();

    // Ocultar la contraseña ingresada por el usuario
    contrasena = "";
    while (caracter != 13){
        if(caracter != 8)
        {
            contrasena.push_back(caracter);
            cout<< "*";
        }else{
            if(contrasena.length()>0)
            {
                cout<<"\b \b";
                contrasena = contrasena.substr(0, contrasena.length() - 1);
            }
        }
        caracter = getch();
    }

    if (usuario == USER && contrasena ==PASS) {
            encontrado = true;
            break;
    }else{
         // Abrir el archivo de usuarios y contraseñas
    ifstream file;
    file.open("Usuarios1.txt", ios::in);

    // Verificar si el archivo se abrió correctamente
    if (!file) {
        cout << "No se pudo abrir el archivo." << endl;
        file.close();
        return false;
    }

    // Buscar el usuario en el archivo
    string user, pass;
    while (file >> user >> pass) {
        if (user == usuario && pass == contrasena) {
            encontrado = true;
            break;
        }
    }
    file.close();
    }


    // Si no se encontró el usuario, se incrementa el contador
    if (!encontrado) {
        cout << "\n\tUSUARIO Y/O PASSWORD INCORRECTOS" << endl;
        cout << "\n\tPerdio un intento, Intente de nuevo" << endl;
        contador++;
        system("pause");
    }
}

// Si se encontró el usuario, se retorna true
if (encontrado) {
    cout << "\n\tBienvenido " << usuario << "!" << endl;
    return true;
} else {
    cout << "\n\tPERDIO LOS 3 INTENTOS" << endl;
    cout << "\n\tNO PODRA INGRESAR MAS INTENTOS" << endl;
    return false;
}
}
