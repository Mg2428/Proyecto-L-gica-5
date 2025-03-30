#include <iostream>
using namespace std;

int main ()

{
    int z, tamañokb, licenciasd, licenciasv, ID;
    string nombrejuego;
    string categoria;
    float precio;
    
    cout<<"Bienvenido a la Appstore"<<endl;
    cout<<"Que desea realizar en la Appstore, digite un numero de caso"<<endl;

 do
  {
    cout<<" 1 para visualizar información de cada juego"<<endl;
    cout<<" 2 para comprar licencias de un juego"<<endl;
    cout<<" 3 para vender las licencias de un juego"<<endl;
    cout<<" 4 para consultar el juego más vendido"<<endl;
    cout<<" 5 para consultar los descuentos aplicados por volumen de compra"<<endl; 
    cout<<" 6 para salir"<<endl;      
    cin>>z;
    switch(z)
    {
    case 1:
    cout<<"Visualizar la información detallada de cada juego"<<endl;
    break;
    case 2:
    cout<<"Comprar licencias de un juego"<<endl;
    break;
    case 3:
    cout<<"Vender licencias de un juego"<<endl;
    break;
    case 4:
    cout<<"Consultar el juego mas vendido"<<endl;
    break;
    case 5:
    cout<<"Consultar los descuentos aplicados por un volumen de compra"<<endl;
    break;
    case 6:
    cout<<"Has salido de la aplicación"<<endl;
    break;
    default:
    cout<<"Escoje nuevamente una opción válida"<<endl;
  
   }    
 
  }  while(z != 6);

    
   cout<<"Gracias por usar la app"; 
    
    
}