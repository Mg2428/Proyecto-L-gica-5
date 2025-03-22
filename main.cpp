#include <iostream>
#include <cmath>
using namespace std;

int main ()

{
    int z;
    string juego1, juego2, juego3, juego4;
    cout<<"Bienvenido a la Appstore"<<endl;
    cout<<"Que desea realizar en la Appstore, digite un numero de caso"<<endl;
    cout<<"Presione 1 para visualizar información de cada juego"<<endl;
    cout<<"Presione 2 para comprar licencias de un juego"<<endl;
    cout<<"Presione 3 para vender las licencias de un juego"<<endl;
    cout<<"Presione 4 para consultar el juego más vendido"<<endl;
    cout<<"Presione 5 para consultar los descuentos aplicados por volumen de compra"<<endl;
    cin>>z;
    switch(z)
    {case 1:
    cout<<"Visualizar la información detallada de cada juego";
    break;
    case 2:
    cout<<"Comprar licencias de un juego";
    break;
    case 3:
    cout<<"Vender licencias de un juego";
    break;
    case 4:
    cout<<"Consultar el juego mas vendido";
    break;
    case 5:
    cout<<"Consultar los descuentos aplicados por un volumen de compra";
    break;
    default:
    cout<<"Error función no disponible";}
    
    return 0;
    
    
    
    
}