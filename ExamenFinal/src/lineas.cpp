#include <iostream>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include "lineas.h"
#include "menus.h"

using namespace std;

lineas::lineas()
{
    //ctor
}

lineas::~lineas()
{
    //dtor
}
void lineas::menu()
{
    int choice;
    char x;
    do
    {
    system ("cls");

        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t                 | LINEAS|                    "<<endl;
        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t  1. Agregar nueva linea"<<endl;
        cout << "\t\t\t  2. Ver Lineas"<<endl;
        cout << "\t\t\t  3. Borrar Lineas"<<endl;
        cout << "\t\t\t  4. Modificar Lineas"<<endl;
        cout << "\t\t\t  5. Salir"<<endl;

        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t Opcion a escoger : [1/2/3/4/5]"<<endl;
        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t Selecciona tu opcion: "<<endl;
        cin>>choice;
        menus lin;

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
		lin.menuGeneral();
	default:
		cout << "\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 5);
}
void lineas::insert()
{
string codigo,nombre,status;
	system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar datos de la linea ---------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa codigo de la linea         : ";
	cin>>codigo;
	cout<<"\t\t\tIngresa Nombre de la linea      : ";
	cin>>nombre;
	cout<<"\t\t\tIngresa el status de la linea     : ";
	cin>>status;
    file.open("registroDeLineas.dat", ios::binary | ios::app | ios::out);
	file<<std::left<<std::setw(15)<< codigo <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< status<< "\n";
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
        reinterpret_cast<const char*>(&status),
        sizeof( status ) );
    }
}
void lineas::display()
{
string codigo,nombre,status;
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n------------------------------------------------Marcas ----------------------------------------------------------"<<endl;
	file.open("registroDeLineas.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> codigo >> nombre >> status;
		while(!file.eof())
		{
			total++;
			cout<<"\t\t\t Codigo de la linea : "<<codigo<<endl;
			cout<<"\t\t\t Nombre de la linea : "<<nombre<<endl;
			cout<<"\t\t\t Status de la linea : "<<status<<endl;
			cout<<"\n------------------------------------------------------------------------------------------------------------------------";
			file >> codigo >> nombre >> status;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
}
void lineas::delet()
{
string codigo,nombre,status;
	system("cls");
	fstream file,file1;
	string participant_codigo;
	int found=0;
	cout<<"\n-------------------------linea  a Borrar-------------------------"<<endl;
	file.open("registroDeLineas.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Codigo de la linea  que quiere borrar: ";
		cin>>participant_codigo;
		file1.open("registro.dat",ios::binary|ios::app | ios::out);
		file >> codigo >> nombre >> status;
		while(!file.eof())
		{
			if(participant_codigo!= codigo)
			{
				file<<std::left<<std::setw(15)<< codigo <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< status<< "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> codigo >> nombre >> status;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Codigo de linea  no encontrado...";
		}
		file1.close();
		file.close();
		remove("registroDeLineas.dat");
		rename("registro.dat","registroDeLineas.dat");
	}
}
void lineas::modify()
{
string codigo,nombre,status;
	system("cls");
	fstream file,file1;
	string participant_codigo;
	int found=0;
	cout<<"\n-------------------------Modificacion de Informacion de lineas-------------------------"<<endl;
	file.open("registroDeLineas.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese codigo de la linea que quiere modificar: ";
		cin>>participant_codigo;
		file1.open("registro.dat",ios::binary|ios::app | ios::out);
		file >> codigo >> nombre >> status;
		while(!file.eof())
		{
			if(participant_codigo!=codigo)
			{
			 file<<std::left<<std::setw(15)<< codigo <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< status<< "\n";
			}
			else
			{
				cout<<"\t\t\tIngrese Codigo de la linea : ";
				cin>>codigo;
				cout<<"\t\t\tIngrese Nombre de la linea : ";
				cin>>nombre;
				cout<<"\t\t\tIngrese status de la linea : ";
				cin>>status;
				file1<<std::left<<std::setw(15)<< codigo <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< status<< "\n";
				found++;
			}
			file >> codigo >> nombre >> status;

		}
		file1.close();
		file.close();
		remove("registroDeLineas.dat");
		rename("registro.dat","registroDeLineas.dat");
	}
}
