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
    int z, licenciasdeseadas, idJuego, i;
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
            cout << "Visualizar la información detallada de cada juego" << endl;
            cout << "Ingresa ID del juego: ";
            cin >> idJuego;

            // Buscar el juego por ID y mostrar su información completa (Requerimiento funcional 1)
           
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
        case 2: // Buscar el juego por ID y comprar sus licencias según lo que se desee (Requerimiento funcional 2)
            cout << "Comprar licencias de un juego" << endl;
            cout<<"Ingrese ID del juego del que desea comprar licencias"<< endl;
            cin>>idJuego;
            for (i = 0; i < 4; i++)
            {
             if( listaJuego[i].idJuego == idJuego )
             {
                 listaJuego[i].mostrarnombre();
                 listaJuego[i].mostrarcantidadlicenciasdiponibles();
                 cout<<"Ingrese la cantidad de licencias que desea comprar";
                 cin>>licenciasdeseadas;
                 if(licenciasdeseadas > listaJuego[i].cantidadlicenciasdisponibles)
                 {
                     cout<<"No hay suficientes licencias"<<endl;
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
            cout << "Vender licencias de un juego" << endl;
            cout<<"Ingrese ID del juego del que desea vender licencias"<< endl;
            cin>>idJuego;
            // Implementar venta de licencias
            break;
        case 4:
            cout << "Consultar el juego más vendido" << endl;
            // Implementar consulta del juego más vendido
            break;
        case 5:
            cout << "Consultar los descuentos aplicados por volumen de compra" << endl;
            // Implementar consulta de descuentos
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
