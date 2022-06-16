#include "menus.h"
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
	cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t    | Sistema de Recursos Humanos - Grupo 6 |"<<endl;
    cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t  1. Manteniminetos"<<endl;
    cout << "\t\t\t  2. Generacion de Nomina"<<endl;
    cout << "\t\t\t  3. Informes de Nomina"<<endl;
    cout << "\t\t\t  4. Transferencia bancaria"<<endl;
    cout << "\t\t\t  5. Generación de Poliza"<<endl;
    cout << "\t\t\t  6. Impuestos"<<endl;
    cout << "\t\t\t  7. Salir"<<endl;

    cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t Opcion a escoger : [1/2/3/4/5/6/7]"<<endl;
    cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t Selecciona tu opcion: ";
    cin>>choice;
 switch(choice)
    {
    case 1:
    	/*do
    	{*/
    		mantenimientos();
    		/*cout<<"\n\t\t\t Agrega otra persona(Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');*/
		break;
	case 2:
		/*genera.menuprincipalgeneracionnomina();*/
		break;
	case 3:
		/*gomu.menu();*/
		break;
	case 4:
		/*tilde.menu1();*/
		break;
    case 5:
       /*met.menu();*/
        break;
    case 6:
        /*punto.menu();*/
        break;
    case 7:
	    exit(0);
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		cin.get();
	}
    }while(choice!= 7);
}
