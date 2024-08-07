#include <iostream>
#include <string>
#include "TreeBinary.h"
using namespace std;

int main() {
    TreeBinary<string, 100> arbol;
    int opcion;
    string valor;

    do {
        cout << "Menu:" << endl;
        cout << "1. Insertar elemento" << endl;
        cout << "2. Contar nodos" << endl;
        cout << "3. Calcular altura" << endl;
        cout << "4. Mostrar In Order" << endl;
        cout << "5. Mostrar Pre Order" << endl;
        cout << "6. Mostrar Post Order" << endl;
        cout << "7. Contar hojas del arbol" << endl;
        cout << "8. Invertir Hijos" << endl;
        cout << "9. Mostrar Por Niveles" << endl;
        cout << "10. Buscar" << endl;
        cout << "11. Mostrar Menor" << endl;
        cout << "12. Mostrar Mayor" << endl;
        cout << " primera modificacion "<<endl; 
        cout << "segunda modificacion"<<endl;
        cout<< "tercera modificacion" <<endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Ingrese el valor a insertar: ";
            cin >> valor;
            arbol.Insertar(valor);
            break;
        case 2:
            cout << "Cantidad de nodos: " << arbol.ContarNodos() << endl;
            break;
        case 3:
            cout << "Altura del arbol: " << arbol.CalcularAltura() << endl;
            break;
        case 4:
            cout << "Recorrido In Order: " << endl;
            arbol.MostrarInOrder();
            break;
        case 5:
            cout << "Recorrido Pre Order: " << endl;
            arbol.MostrarPreOrder();
            break;
        case 6:
            cout << "Recorrido Post Order: " << endl;
            arbol.MostrarPostOrder();
            break;
        case 7:
            cout << "Cantidad de hojas del arbol: " << arbol.ContarHojas() << endl;
            break;
        case 8:
            arbol.InvertirHijos();
            cout << "Se han invertido los hijos." << endl;
            break;
        case 9:
            cout << "Mostrando por niveles: " << endl;
            arbol.MostrarPorNiveles();
            break;
        case 10:
            cout << "Ingrese el valor a buscar: ";
            cin >> valor;
            if (arbol.Buscar(valor)) {
                cout << "El elemento " << valor << " esta presente en el arbol." << endl;
            }
            else {
                cout << "El elemento " << valor << " no esta presente en el arbol." << endl;
            }
            break;
        case 11:
            cout << "El elemento menor en el arbol es: " << arbol.MostrarMenor() << endl;
            break;
        case 12:
            cout << "El elemento mayor en el arbol es: " << arbol.MostrarMayor() << endl;
            break;
        case 0:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
            break;
        }

    } while (opcion != 0);

    return 0;
}
