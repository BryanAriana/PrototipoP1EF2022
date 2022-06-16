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
	cout << "\t\t\t *******************************************************************"<<endl;
    cout << "\t\t\t    | Menu General - Bryan Alejandro Ariana Juarez 9959-21-2832 |"<<endl;
    cout << "\t\t\t *******************************************************************"<<endl;
    cout << "\t\t\t  1. Catalogos"<<endl;
    cout << "\t\t\t  2. Procesos"<<endl;
    cout << "\t\t\t  3. Informes"<<endl;
    cout << "\t\t\t  4. Salir"<<endl;

    cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t Opcion a escoger : [1/2/3/4]"<<endl;
    cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t Selecciona tu opcion: ";
    cin>>choice;
 switch(choice)
    {
    case 1:
    	/*do
    	{*/
    		/*mantenimientos();*/
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
	    exit(0);
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		cin.get();
	}
    }while(choice!= 4);
}
