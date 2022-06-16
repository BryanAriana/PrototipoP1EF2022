#include "menus.h"
#include "productos.h"
#include "clientes.h"
#include "vendedores.h"
#include "marcas.h"
#include "lineas.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;
menus::menus()
{
    //ctor
}

menus::~menus()
{
    //dtor
}
void menus::menuGeneral(){
    system("cls");
    int choice;
	//char x;
	do
    {
	system("cls");
	cout << "\t\t\t *******************************************************************"<<endl;
    cout << "\t\t\t    | Menu General - Bryan Alejandro Ariana Juarez 9959-21-2832 |"<<endl;
    cout << "\t\t\t *******************************************************************"<<endl;
    cout << "\t\t\t  1. Catalogos"<<endl;
    cout << "\t\t\t  2. Informes"<<endl;
    cout << "\t\t\t  3. Salir"<<endl;

    cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t Opcion a escoger : [1/2/3/4]"<<endl;
    cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t Selecciona tu opcion: ";
    cin>>choice;

 switch(choice)
    {
    case 1:
    	catalogo();
		break;
	case 2:
		/*genera.menuprincipalgeneracionnomina();*/
		break;
    case 3:
	    exit(0);
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		cin.get();
	}
    }while(choice!= 4);
}
void menus::catalogo(){
    int choice;
    char s;
    do
    {


    system ("cls");

        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t      | Catalogos |"<<endl;
        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t  1. Productos"<<endl;
        cout << "\t\t\t  2. Clientes"<<endl;
        cout << "\t\t\t  3. Vendedores"<<endl;
        cout << "\t\t\t  4. Marcas"<<endl;
        cout << "\t\t\t  5. Lineas"<<endl;
        cout << "\t\t\t  6. Salir"<<endl;

        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t Opcion a escoger : [1/2/3/4/5/6]"<<endl;
        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t Selecciona tu opcion: ";
        cin>>choice;
        productos gomu;
        clientes po;
        vendedores ven;
        marcas mar;
        lineas lin;
 switch(choice)
        {
    case 1:
    	gomu.menu();
		break;
    case 2:
		po.menu();
		break;
	case 3:
		ven.menu();
		break;
	case 4:
		mar.menu();
		break;
	case 5:
		lin.menu();
		break;
	case 6:
		menuGeneral();
	default:
		cout << "\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
    }while(choice!= 6);

}
