#include <iostream>
using namespace std;

struct juego
{
    int idJuego;
    string nombre;
    string categoria;
    float tamaño;
    float precio;
    int cantidadlicenciasdisponibles;
    int cantidadlicenciasvendidas;

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
    void mostrarcantidadlicenciasdisponibles() {
        cout << "Licencias disponibles: " << cantidadlicenciasdisponibles << endl;
    }
    void mostrarcantidadlicenciasvendidas() {
        cout << "Licencias vendidas: " << cantidadlicenciasvendidas << endl;
    }
};

int main()
{
    int z, licenciasdeseadas, idJuego, i, confirmacion, continuar;
    float totalpagar = 0, montoPagado, cambio;
    int carrito[6] = {0, 0, 0, 0, 0, 0}; // Arreglo para almacenar licencias por juego en el carrito
    int deportesLicencias = 0, accionLicencias = 0, rompecabezasLicencias = 0;

    cout << "Bienvenido a la Appstore" << endl;
    cout << "¿Qué desea realizar en la Appstore? Digite un número de caso" << endl;

    // Lista de juegos
    juego listaJuego[6] = {
        {1, "Haikyuu", "Deportes", 500, 9.99, 100, 50},
        {2, "Jigsawscapes", "Rompecabezas", 200, 4.99, 150, 80},
        {3, "Bullet Echo", "Acción", 600, 7.99, 200, 120},
        {4, "WSC", "Aventura", 300, 5.99, 250, 150},
        {5, "FIFA 17", "Deportes", 700, 12.49, 180, 90},
        {6, "Candy Crush", "Rompecabezas", 150, 3.99, 300, 200}
    };

    do
    {
        cout << "1 para visualizar información de cada juego" << endl;
        cout << "2 para comprar licencias de un juego" << endl;
        cout << "3 para vender las licencias de un juego" << endl;
        cout << "4 para consultar el juego más vendido" << endl;
        cout << "5 para consultar los descuentos aplicados por volumen de compra" << endl;
        cout << "6 para consultar la compatibilidad de los juegos en distintas plataformas" << endl;
        cout << "7 para salir" << endl;
        cin >> z;

        switch (z)
        {
        case 1:
            cout << "Visualizar la información detallada de cada juego" << endl;
            cout << "Ingresa ID del juego: ";
            cin >> idJuego;

            for (i = 0; i < 6; i++)
            {
                if (listaJuego[i].idJuego == idJuego)
                {
                    listaJuego[i].mostrarnombre();
                    listaJuego[i].mostraridJuego();
                    listaJuego[i].mostrarcategoria();
                    listaJuego[i].mostrartamano();
                    listaJuego[i].mostrarprecio();
                    listaJuego[i].mostrarcantidadlicenciasdisponibles();
                    listaJuego[i].mostrarcantidadlicenciasvendidas();
                    break;
                }
            }
            if (i == 6)
            {
                cout << "No se encontró un juego con ese ID." << endl;
            }
            break;

        case 2:
            do
            {
                cout << "Comprar licencias de un juego" << endl;
                cout << "Ingrese ID del juego del que desea comprar licencias" << endl;
                cin >> idJuego;
                for (i = 0; i < 6; i++)
                {
                    if (listaJuego[i].idJuego == idJuego)
                    {
                        listaJuego[i].mostrarnombre();
                        listaJuego[i].mostrarcategoria();
                        listaJuego[i].mostrarcantidadlicenciasdisponibles();
                        listaJuego[i].mostrarprecio();
                        cout << "Ingrese la cantidad de licencias que desea comprar: ";
                        cin >> licenciasdeseadas;
                        if (licenciasdeseadas > listaJuego[i].cantidadlicenciasdisponibles)
                        {
                            cout << "No hay suficientes licencias" << endl;
                            return 0;
                        }
                        carrito[i] += licenciasdeseadas; // Agregar al carrito
                        cout << licenciasdeseadas << " licencias de " << listaJuego[i].nombre << " agregadas al carrito." << endl;
                        break;
                    }
                }
                if (i == 6)
                {
                    cout << "No se encontró juego para esa ID" << endl;
                    return 0;
                }
                cout << "Desea agregar otro juego al carrito? (1 para sí, 0 para no): ";
                cin >> continuar;
                if (continuar != 0 && continuar != 1)
                {
                    cout << "Has ingresado una opción no válida" << endl;
                    return 0; // Forzar salida del bucle si la entrada es inválida
                }
                
            } while (continuar == 1);

            // Calcular total y aplicar descuentos
            totalpagar = 0;
            deportesLicencias = 0;
            accionLicencias = 0;
            rompecabezasLicencias = 0;
            cout << "\n--- Contenido del Carrito ---" << endl;
            for (i = 0; i < 6; i++)
            {
                if (carrito[i] > 0)
                {
                    cout << "Juego: " << listaJuego[i].nombre << ", Licencias: " << carrito[i] << ", Subtotal: $" << carrito[i] * listaJuego[i].precio << endl;
                    totalpagar += carrito[i] * listaJuego[i].precio;
                    if (listaJuego[i].categoria == "Deportes")
                        deportesLicencias += carrito[i];
                    else if (listaJuego[i].categoria == "Acción")
                        accionLicencias += carrito[i];
                    else if (listaJuego[i].categoria == "Rompecabezas")
                        rompecabezasLicencias += carrito[i];
                }
            }
            cout << "Total sin descuento: $" << totalpagar << endl;

            // Verificar políticas de descuento
            if (rompecabezasLicencias >= 25)
            {
                cout << "Por haber comprado al menos 25 licencias de juegos en la sección de Rompecabezas, recibirás un descuento del 20%" << endl;
                totalpagar = 0.8 * totalpagar;
            }
            else if (deportesLicencias >= 20 && accionLicencias >= 15)
            {
                cout << "Por haber comprado al menos 20 licencias de juegos en la sección de Deportes y 15 de Acción, recibirás un descuento del 15%" << endl;
                totalpagar = 0.85 * totalpagar;
            }
            cout << "Total a pagar con descuentos: $" << totalpagar << endl;

            // Proceso de pago
            cout << "Ingrese la cantidad de dinero con la que pagará: $";
            cin >> montoPagado;
            if (montoPagado < totalpagar)
            {
                cout << "El monto ingresado no es suficiente para cubrir el total a pagar." << endl;
            }
            else
            {
                cambio = montoPagado - totalpagar;
                cout << "Pago exitoso! Su cambio es: $" << cambio << endl;
                // Actualizar licencias disponibles y vendidas
                for (i = 0; i < 6; i++)
                {
                    if (carrito[i] > 0)
                    {
                        listaJuego[i].cantidadlicenciasdisponibles -= carrito[i];
                        listaJuego[i].cantidadlicenciasvendidas += carrito[i];
                        carrito[i] = 0; // Limpiar carrito
                    }
                }
            }
            break;

        case 3:
            cout << "Vender licencias de un juego" << endl;
            cout << "Ingrese ID del juego del que desea vender licencias" << endl;
            cin >> idJuego;
            for (i = 0; i < 6; i++)
            {
                if (listaJuego[i].idJuego == idJuego)
                {
                    listaJuego[i].mostrarnombre();
                    listaJuego[i].mostrarcantidadlicenciasvendidas();
                    cout << "Ingrese la cantidad de licencias que desea vender: ";
                    cin >> licenciasdeseadas;
                    totalpagar = licenciasdeseadas * listaJuego[i].precio;
                    cout << "Su total de venta es $" << totalpagar << endl;
                    break;
                }
            }
            if (i == 6)
            {
                cout << "No se encontró juego para esa ID" << endl;
            }
            break;

        case 4:
        {
            cout << "Consultar el juego más vendido" << endl;
            juego* masVendido = &listaJuego[0];
            for (i = 1; i < 6; i++) {
                if (listaJuego[i].cantidadlicenciasvendidas > masVendido->cantidadlicenciasvendidas) {
                    masVendido = &listaJuego[i];
                }
            }
            cout << "\n--- JUEGO MAS VENDIDO ---" << endl;
            masVendido->mostrarnombre();
            masVendido->mostraridJuego();
            cout << "Licencias vendidas: " << masVendido->cantidadlicenciasvendidas << endl;
            cout << "------------------------" << endl;
            break;
        }

        case 5:
            cout << "Consultar los descuentos aplicados por volumen de compra" << endl;
            cout << "Si solicitas al menos 25 licencias de juegos de rompecabezas, se dará un 20% de descuento sobre el total del pedido." << endl;
            cout << "Si solicitas al menos 20 licencias de juegos de deportes y 15 de acción, se hará un 15% de descuento." << endl;
            cout << "Si se cumplen ambas condiciones, se aplicará solo el descuento del 20%." << endl;
            break;

        case 6:
        {
            // Matriz de compatibilidad para 6 juegos y 4 plataformas
            // Columnas: 0 = PC, 1 = Teléfono, 2 = Tablet, 3 = Consola
            int compatibilidad[6][4] = {
                {1, 0, 0, 1}, // Haikyuu
                {1, 1, 1, 0}, // Jigsawscapes
                {1, 1, 1, 1}, // Bullet Echo
                {1, 0, 0, 1}, // WSC
                {1, 0, 1, 1}, // FIFA 17
                {0, 1, 1, 1}  // Candy Crush
            };

            string plataformas[4] = {"PC", "Teléfono", "Tablet", "Consola"};

            cout << "\n--- Compatibilidad de Juegos con Plataformas ---" << endl;
            for (int i = 0; i < 6; i++) {
                cout << "Juego: " << listaJuego[i].nombre << " => Compatible con: ";
                for (int j = 0; j < 4; j++) {
                    if (compatibilidad[i][j] == 1) {
                        cout << plataformas[j] << " ";
                    }
                }
                cout << endl;
            }
            break;
        }

        case 7:
            cout << "Has salido de la aplicación" << endl;
            break;

        default:
            cout << "Has ingresado una opción no válida" << endl;
            // Regresar al menú inicial
            continue;
        }

    } while (z != 7);

    cout << "Gracias por usar la app" << endl;
    return 0;
}