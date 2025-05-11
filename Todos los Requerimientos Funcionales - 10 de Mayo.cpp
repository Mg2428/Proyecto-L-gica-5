#include <iostream>
using namespace std;

struct juego
{
    // atributos
    int idJuego;
    string nombre;
    string categoria;
    float tamaño;
    float precio;
    int cantidadlicenciasdisponibles;
    int cantidadlicenciasvendidas;

    // métodos
    void mostrarnombre() {
        cout << "Nombre del juego: " << nombre << endl;
    }
    void mostraridJuego() {
        cout << "ID del juego: " << idJuego << endl;
    }
    void mostrarcategoria() {
        cout << "Categoria: " << categoria << endl;
    }
    void mostrartamano() {
        cout << "Tamaño: " << tamaño << " MB" << endl;
    }
    void mostrarprecio() {
        cout << "Precio: $" << precio << endl;
    }
    void mostrarcantidadlicenciasdiponibles() {
        cout << "Licencias disponibles: " << cantidadlicenciasdisponibles << endl;
    }
    void mostrarcantidadlicenciasvendidas() {
        cout << "Licencias vendidas: " << cantidadlicenciasvendidas << endl;
    }
};

int main()
{
    int z, licenciasdeseadas, idJuego, i, confirmacion;
    string nombrejuego;
    string categoria;
    float precio, totalpagar;

    cout << "Bienvenido a la Appstore" << endl;
    cout << "¿Qué desea realizar en la Appstore? Digite un número de caso" << endl;

    //Lista de juegos
    juego listaJuego[4] = {
        {1, "Haikyuu", "Deportes", 500, 9.99, 100, 50},
        {2, "Jigsawscapes", "Rompecabezas", 200, 4.99, 150, 80},
        {3, "Bullet Echo", "Acción", 600, 7.99, 200, 120},
        {4, "WSC", "Aventura", 300, 5.99, 250, 150}
    };

    do
    {
        cout << "1 para visualizar información de cada juego" << endl;
        cout << "2 para comprar licencias de un juego" << endl;
        cout << "3 para vender las licencias de un juego" << endl;
        cout << "4 para consultar el juego más vendido" << endl;
        cout << "5 para consultar los descuentos aplicados por volumen de compra" << endl;
        cout << "6 para salir" << endl;
        cin >> z;

        switch (z)
        {
        case 1:
        //Requerimiento Funcional 1 - Consultar información de un juego
            cout << "Visualizar la información detallada de cada juego" << endl;
            cout << "Ingresa ID del juego: ";
            cin >> idJuego;

            for (i = 0; i < 4; i++)
            {
                if (listaJuego[i].idJuego == idJuego)
                {
                    listaJuego[i].mostrarnombre();
                    listaJuego[i].mostraridJuego();
                    listaJuego[i].mostrarcategoria();
                    listaJuego[i].mostrartamano();
                    listaJuego[i].mostrarprecio();
                    listaJuego[i].mostrarcantidadlicenciasdiponibles();
                    listaJuego[i].mostrarcantidadlicenciasvendidas();
                    break;
                }
            }

            if (i==4)
            {
                cout << "No se encontró un juego con ese ID." << endl;
            }
            break;
        case 2:
        //Requerimiento Funcional 2 - Comprar Licencias
            cout << "Comprar licencias de un juego" << endl;
            cout<<"Ingrese ID del juego del que desea comprar licencias"<< endl;
            cin>>idJuego;
            for (i = 0; i < 4; i++)
            {
             if( listaJuego[i].idJuego == idJuego )
             {
                 listaJuego[i].mostrarnombre();
                 listaJuego[i].mostrarcategoria();
                 listaJuego[i].mostrarcantidadlicenciasdiponibles();
                 listaJuego[i].mostrarprecio();
                 cout<<"Ingrese la cantidad de licencias que desea comprar";
                 cin>>licenciasdeseadas;
                 if(licenciasdeseadas > listaJuego[i].cantidadlicenciasdisponibles)
                 {
                     cout<<"No hay suficientes licencias"<<endl;
                     break;
                 }
                 //Descuentos
                 else if(idJuego == 2 and licenciasdeseadas >= 25)
                 {
                     cout<<"Por haber comprado al menos 25 licencias de juegos en la sección de Rompecabezas, recibirás un descuento del 20%"<<endl;
                     totalpagar = -(0.2 * (licenciasdeseadas*listaJuego[i].precio)) + (licenciasdeseadas*listaJuego[i].precio);
                     cout<<"Su total a pagar es de: $"<<totalpagar<<endl;
                     break;
                 }
                 
                 else if(idJuego == 1 and licenciasdeseadas >= 20)
                 {
                     cout <<"Hemos detectado en tu compra que posees 20 o más licencias de juegos en la sección de deportes"<<endl;
                     cout <<"Puedes optar por un descuento según nuestras políticas del 15% si compras 15 o más licencias de juegos en la sección de acción"<<endl;
                     cout <<"En caso de aceptar, específica cuántas licencias del juego de acción Bullet Echo deseas adquirir, caso contrario, persiona 0"<<endl;
                     cin>>confirmacion;
                     if(confirmacion<15)
                     {
                         totalpagar = (licenciasdeseadas * listaJuego[i].precio) + (confirmacion * 7.99);
                         cout<<"Sin el descuento, su total a pagar será: $"<<totalpagar<<endl;
                         break;
                     }
                     else if(confirmacion>=15)
                     {
                         totalpagar = -(0.15*((licenciasdeseadas*listaJuego[i].precio) + (confirmacion * 7.99))) + ((licenciasdeseadas*listaJuego[i].precio) + (confirmacion * 7.99));
                         cout<<"Con el descuento, su total a pagar será: $"<<totalpagar<<endl;
                         break;
                     }
                 }
                 
                 else if(idJuego == 3 and licenciasdeseadas >= 15)
                 {
                     cout <<"Hemos detectado en tu compra que posees 15 o más licencias de juegos en la sección de acción"<<endl;
                     cout <<"Puedes optar por un descuento según nuestras políticas del 15% si compras 20 o más licencias de juegos en la sección de deportes"<<endl;
                     cout <<"En caso de aceptar, específica cuántas licencias del juego de deportes Haikyuu deseas adquirir, caso contrario, presiona 0"<<endl;
                     cin>>confirmacion;
                     if(confirmacion<20)
                     {
                         totalpagar = (licenciasdeseadas * listaJuego[i].precio) + (confirmacion * 9.99);
                         cout<<"Sin el descuento, su total a pagar será: $"<<totalpagar<<endl;
                         break;
                     }
                     else if(confirmacion>=20)
                     {
                         totalpagar = -(0.15*((licenciasdeseadas*listaJuego[i].precio) + (confirmacion * 9.99))) + ((licenciasdeseadas*listaJuego[i].precio) + (confirmacion * 9.99));
                         cout<<"Con el descuento, su total a pagar será: $"<<totalpagar<<endl;
                         break;
                     }
                 }
                 
                 
                 else
                 {
                 totalpagar = licenciasdeseadas * listaJuego[i].precio;
                 cout<<"Su total a pagar es de $"<<totalpagar<< endl;
                 break;
                 }
             }
            } if(i == 4)
             {
                 cout<<"No se encontró Juego para esa ID\n";} 
                 break;
                 
        case 3:
        //Requerimiento Funcional 3 - Vender licencias
            cout << "Vender licencias de un juego" << endl;
            cout<<"Ingrese ID del juego del que desea vender licencias"<< endl;
            cin>>idJuego;
            for (i = 0; i < 4; i++)
            {
             if( listaJuego[i].idJuego == idJuego )
             {
                 listaJuego[i].mostrarnombre();
                 listaJuego[i].mostrarcantidadlicenciasvendidas();
                 cout<<"Ingrese la cantidad de licencias que desea vender";
                 cin>>licenciasdeseadas;
                 totalpagar = licenciasdeseadas * listaJuego[i].precio;
                 cout<<"Su total de venta es $"<<totalpagar<< endl;
                 break;
             }
            } if(i >= 4)
             {
                 cout<<"No se encontró Juego para esa ID\n";}  
            break;
        case 4:
        //Requerimiento Funcional 4 - Consultar Juego más Vendido
            {
                cout << "Consultar el juego más vendido" << endl;
                juego* masVendido = &listaJuego[0]; // Inicializamos con el primer juego
                
                for (i = 1; i < 4; i++) {
                    if (listaJuego[i].cantidadlicenciasvendidas > masVendido->cantidadlicenciasvendidas) {
                        masVendido = &listaJuego[i];
                    }
                }
                
                cout << "\n--- JUEGO MAS VENDIDO ---" << endl;
                masVendido->mostrarnombre();
                masVendido->mostraridJuego();
                cout << "Licencias vendidas: " << masVendido->cantidadlicenciasvendidas << endl;
                cout << "------------------------" << endl;
            }
            break;
        case 5: // Requerimiento Funcional 5 - Consultar Política de Descuentos
            cout << "Consultar los descuentos aplicados por volumen de compra" << endl;
            cout << "Si solicitas al menos 25 licencias de juegos de rompecabezas sin importar la cantidad de juegos que solicites de otras categorías, se te dará el 20% de descuento sobre el total del pedido"<<endl;
            cout << "Si solicitas al menos 20 licencias de juegos de deportes y 15 licencias de juegos de acción, se dará el 15% de descuento sobre el valor total del pedido"<< endl;
            cout << "En caso de que se cumplan ambas condiciones, se otorgará el descuento del 20%"<<endl;
            
            break;
        case 6:
            cout << "Has salido de la aplicación" << endl;
            break;
        default:
            cout << "Escoge nuevamente una opción válida" << endl;
        }

    } while (z != 6);

    cout << "Gracias por usar la app" << endl;

    return 0;
}
