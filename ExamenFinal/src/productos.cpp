#include <iostream>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include "productos.h"
#include "menus.h"

using namespace std;

productos::productos()
{
    //ctor
}

productos::~productos()
{
    //dtor
}
void productos::menu()
{
    int choice;
    char x;
    do
    {


    system ("cls");

        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t                 | Productos |"<<endl;
        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t  1. Crear Producto"<<endl;
        cout << "\t\t\t  2. Ver Productos"<<endl;
        cout << "\t\t\t  3. Borrar Productos"<<endl;
        cout << "\t\t\t  4. Modificar Productos"<<endl;
        cout << "\t\t\t  5. Salir"<<endl;

        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t Opcion a escoger : [1/2/3/4/5]"<<endl;
        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t Selecciona tu opcion: "<<endl;
        cin>>choice;
        menus gomu;

    switch(choice)
        {
    case 1:
        do
        {
        insert();
        cout<<"\n\t\t\t Agrega otro producto(Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');
		break;
    case 2:
		display();
		break;
    case 3:
		delet();
		break;
    case 4 :
		modify();
		break;
	case 5:
		gomu.menuGeneral();
	default:
		cout << "\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 5);
}
void productos::insert()
{
string codigo,nombre,marca,existencia,status;
	system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar datos del producto ---------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa codigo del Producto         : ";
	cin>>codigo;
	cout<<"\t\t\tIngresa Nombre del Producto     : ";
	cin>>nombre;
	cout<<"\t\t\tIngresa marca del Producto   : ";
	cin>>marca;
	cout<<"\t\t\tIngresa la existencia del Producto   : ";
	cin>>existencia;
	cout<<"\t\t\tIngresa el status del producto (agotado/disponible)   : ";
	cin>>status;
    file.open("registroDeProductos.dat", ios::binary | ios::app | ios::out);
	file<<std::left<<std::setw(15)<< codigo <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< marca<<std::left<<std::setw(15)<< existencia<<std::left<<std::setw(15)<< status<< "\n";
	file.close();
	 for( int i = 0; i < 50; i++ ){
      file.write(
         reinterpret_cast<const char*>(&codigo),
         sizeof( codigo ) );
    }

    for( int i = 0; i < 50; i++ ){
      file.write(
         reinterpret_cast<const char*>(&nombre),
         sizeof( nombre ) );
    }

    for( int i = 0; i < 50; i++ ){
      file.write(
         reinterpret_cast<const char*>(&marca),
         sizeof( marca ) );
    }

    for( int i = 0; i < 50; i++ ){
      file.write(
         reinterpret_cast<const char*>(&existencia),
         sizeof( existencia ) );
    }

    for( int i = 0; i < 50; i++ ){
      file.write(
        reinterpret_cast<const char*>(&status),
        sizeof( status ) );
    }
}
void productos::display()
{
string codigo,nombre,marca,existencia,status;
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n------------------------------------------------Productos ----------------------------------------------------------"<<endl;
	file.open("registroDeProductos.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> codigo >> nombre >> marca >> existencia >> status;
		while(!file.eof())
		{
			total++;
			cout<<"\t\t\t Codigo del Producto: "<<codigo<<endl;
			cout<<"\t\t\t Nombre del Producto: "<<nombre<<endl;
			cout<<"\t\t\t Marca del Producto: "<<marca<<endl;
			cout<<"\t\t\t Existencia del Procucto: "<<existencia<<endl;
			cout<<"\t\t\t Status del Producto: "<<status<<endl;
			cout<<"\n------------------------------------------------------------------------------------------------------------------------";
			file >> codigo >> nombre >> marca >> existencia >> status;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
}
void productos::delet()
{
string codigo,nombre,marca,existencia,status;
	system("cls");
	fstream file,file1;
	string participant_codigo;
	int found=0;
	cout<<"\n-------------------------Producto a Borrar-------------------------"<<endl;
	file.open("registroDeProducto.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Codigo del Producto que quiere borrar: ";
		cin>>participant_codigo;
		file1.open("registro.dat",ios::binary|ios::app | ios::out);
		file >> codigo >> nombre >> marca >> existencia >> status;
		while(!file.eof())
		{
			if(participant_codigo!= codigo)
			{
				file<<std::left<<std::setw(15)<< codigo <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< marca<<std::left<<std::setw(15)<< existencia<<std::left<<std::setw(15)<< status<< "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> codigo >> nombre >> marca >> existencia >> status;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Codigo del Producto no encontrado...";
		}
		file1.close();
		file.close();
		remove("registroDeProductos.dat");
		rename("registro.dat","registroDeProductos.dat");
	}
}
void productos::modify()
{
    string codigo,nombre,marca,existencia,status;
	system("cls");
	fstream file,file1;
	string participant_codigo;
	int found=0;
	cout<<"\n-------------------------Modificacion de Informacion de Productos-------------------------"<<endl;
	file.open("registroDeProductos.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese codigo del producto que quiere modificar: ";
		cin>>participant_codigo;
		file1.open("registro.dat",ios::binary|ios::app | ios::out);
		file >> codigo >> nombre >> marca >> existencia >> status;
		while(!file.eof())
		{
			if(participant_codigo!=codigo)
			{
			 file<<std::left<<std::setw(15)<< codigo <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< marca<<std::left<<std::setw(15)<< existencia<<std::left<<std::setw(15)<< status<< "\n";
			}
			else
			{
				cout<<"\t\t\tIngrese Codigo del Producto: ";
				cin>>codigo;
				cout<<"\t\t\tIngrese Nombre del Producto: ";
				cin>>nombre;
				cout<<"\t\t\tIngrese Marca del Producto: ";
				cin>>marca;
				cout<<"\t\t\tIngrese Existencia del Producto: ";
				cin>>existencia;
				cout<<"\t\t\tIngrese statys del Producto (agotado/disponible): ";
				cin>>status;
				file1<<std::left<<std::setw(15)<< codigo <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< marca<<std::left<<std::setw(15)<< existencia<<std::left<<std::setw(15)<< status<< "\n";
				found++;
			}
			file >> codigo >> nombre >> marca >> existencia >> status;

		}
		file1.close();
		file.close();
		remove("registroDeProductos.dat");
		rename("registro.dat","registroDeProductos.dat");
	}
}
