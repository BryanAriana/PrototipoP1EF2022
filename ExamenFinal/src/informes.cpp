#include <iostream>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include "informes.h"
#include "productos.h"
#include "clientes.h"
#include "vendedores.h"
#include "marcas.h"
#include "lineas.h"
#include "menus.h"

using namespace std;

informes::informes()
{
    //ctor
}

informes::~informes()
{
    //dtor
}
void informes::menu()
{
    int choice;
    char x;
    do
    {
    system ("cls");

        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t                 | INFORMES|                    "<<endl;
        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t  1. Informe Productos"<<endl;
        cout << "\t\t\t  2. Informe Clientes"<<endl;
        cout << "\t\t\t  3. Informe Vendedores"<<endl;
        cout << "\t\t\t  4. Informe Marcas"<<endl;
        cout << "\t\t\t  5. Informe Lineas"<<endl;
        cout << "\t\t\t  6. Salir"<<endl;

        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t Opcion a escoger : [1/2/3/4/5/6]"<<endl;
        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t Selecciona tu opcion: "<<endl;
        cin>>choice;
        productos gomu;
        clientes po;
        vendedores ven;
        marcas mar;
        lineas lin;
        menus info;

    switch(choice)
        {
    case 1:
        gomu.display();
		break;
    case 2:
		po.display();
		break;
    case 3:
		ven.display();
		break;
    case 4 :
		mar.display();
		break;
    case 5 :
		lin.display();
		break;
	case 6:
		info.menuGeneral();
	default:
		cout << "\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 5);
}
