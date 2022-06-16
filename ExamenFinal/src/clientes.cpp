#include "clientes.h"
#include <iostream>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include "menus.h"
using namespace std;
clientes::clientes()
{
    //ctor
}

clientes::~clientes()
{
    //dtor
}
void clientes::menu()
{
    int choice;
    char x;
    do
    {


    system ("cls");

        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t                 | Clientes |"<<endl;
        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t  1. Agregar nuevo Cliente"<<endl;
        cout << "\t\t\t  2. Ver Clientes"<<endl;
        cout << "\t\t\t  3. Borrar Clientes"<<endl;
        cout << "\t\t\t  4. Modificar Clientes"<<endl;
        cout << "\t\t\t  5. Salir"<<endl;

        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t Opcion a escoger : [1/2/3/4/5]"<<endl;
        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t Selecciona tu opcion: "<<endl;
        cin>>choice;
        menus po;

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
		po.menuGeneral();
	default:
		cout << "\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 5);
}
void clientes::insert()
{
string id,nombre,direccion,nit,telefono;
	system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar datos del Cliente ---------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa ID del Cliente         : ";
	cin>>id;
	cout<<"\t\t\tIngresa Nombre del Cliente     : ";
	cin>>nombre;
	cout<<"\t\t\tIngresa Direccion del Cliente   : ";
	cin>>direccion;
	cout<<"\t\t\tIngresa NIT del Cliente   : ";
	cin>>nit;
	cout<<"\t\t\tIngresa Telefono del Cliente   : ";
	cin>>telefono;
    file.open("registroDeClientes.dat", ios::binary | ios::app | ios::out);
	file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< direccion<<std::left<<std::setw(15)<< nit<<std::left<<std::setw(15)<< telefono<< "\n";
	file.close();
	 for( int i = 0; i < 50; i++ ){
      file.write(
         reinterpret_cast<const char*>(&id),
         sizeof( id ) );
    }

    for( int i = 0; i < 50; i++ ){
      file.write(
         reinterpret_cast<const char*>(&nombre),
         sizeof( nombre ) );
    }

    for( int i = 0; i < 50; i++ ){
      file.write(
         reinterpret_cast<const char*>(&direccion),
         sizeof( direccion ) );
    }

    for( int i = 0; i < 50; i++ ){
      file.write(
         reinterpret_cast<const char*>(&nit),
         sizeof( nit ) );
    }

    for( int i = 0; i < 50; i++ ){
      file.write(
        reinterpret_cast<const char*>(&telefono),
        sizeof( telefono ) );
    }
}
void clientes::display()
{
string id,nombre,direccion,nit,telefono;
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n------------------------------------------------Productos ----------------------------------------------------------"<<endl;
	file.open("registroDeClientes.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> id >> nombre >> direccion >> nit >> telefono;
		while(!file.eof())
		{
			total++;
			cout<<"\t\t\t ID del cliente: "<<id<<endl;
			cout<<"\t\t\t Nombre del Cliente: "<<nombre<<endl;
			cout<<"\t\t\t Direccion del Cliente: "<<direccion<<endl;
			cout<<"\t\t\t NIT del Cliente: "<<nit<<endl;
			cout<<"\t\t\t Telefono del Cliente: "<<telefono<<endl;
			cout<<"\n------------------------------------------------------------------------------------------------------------------------";
			file >> id >> nombre >> direccion >> nit >> telefono;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
}
void clientes::delet()
{
string id,nombre,direccion,nit,telefono;
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Cliente a Borrar-------------------------"<<endl;
	file.open("registroDeClientes.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el ID del Cliente que quiere borrar: ";
		cin>>participant_id;
		file1.open("registro.dat",ios::binary|ios::app | ios::out);
		file >> id >> nombre >> direccion >> nit >> telefono;
		while(!file.eof())
		{
			if(participant_id!= id)
			{
            file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< direccion<<std::left<<std::setw(15)<< nit<<std::left<<std::setw(15)<< telefono<< "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> id >> nombre >> direccion >> nit >> telefono;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t ID del Cliente no encontrado...";
		}
		file1.close();
		file.close();
		remove("registroDeClientes.dat");
		rename("registro.dat","registroDeClientes.dat");
	}
}
void clientes::modify()
{
    string id,nombre,direccion,nit,telefono;
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Modificacion de Informacion de Clientes-------------------------"<<endl;
	file.open("registroDeClientes.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese ID del Cliente que quiere modificar: ";
		cin>>participant_id;
		file1.open("registro.dat",ios::binary|ios::app | ios::out);
		file >> id >> nombre >> direccion >> nit >> telefono;
		while(!file.eof())
		{
			if(participant_id!=id)
			{
			 file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< direccion<<std::left<<std::setw(15)<< nit<<std::left<<std::setw(15)<< telefono<< "\n";
			}
			else
			{
				cout<<"\t\t\tIngrese ID del Cliente: ";
				cin>>id;
				cout<<"\t\t\tIngrese Nombre del Cliente: ";
				cin>>nombre;
				cout<<"\t\t\tIngrese direccion del Cliente: ";
				cin>>direccion;
				cout<<"\t\t\tIngrese nit del Cliente: ";
				cin>>nit;
				cout<<"\t\t\tIngrese telefono del Cliente: ";
				cin>>telefono;
				file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< direccion<<std::left<<std::setw(15)<< nit<<std::left<<std::setw(15)<< telefono<< "\n";
				found++;
			}
			file >> id >> nombre >> direccion >> nit >> telefono;

		}
		file1.close();
		file.close();
		remove("registroDeClientes.dat");
		rename("registro.dat","registroDeClientes.dat");
	}
}
