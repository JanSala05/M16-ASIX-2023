#pragma once
#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

void agregarObjeto(map<string, map<string, string>>& inventario) {
    string nombreProducto;
    int cantidadProducto;
    string categoriaProducto;

    cout << "Escribe el nombre del producto: ";
    cin.ignore();
    getline(cin, nombreProducto);
    transform(nombreProducto.begin(), nombreProducto.end(), nombreProducto.begin(), ::toupper);

    cout << "Escribe la cantidad del producto: ";
    cin >> cantidadProducto;


    map<string, string> objeto = { {"nombre", nombreProducto}, {"cantidad", to_string(cantidadProducto)} };
    inventario[nombreProducto] = objeto;

    cout << "El producto " << nombreProducto << " ha sido agregado a la lista de la compra." << endl;
}

void eliminarObjeto(map<string, map<string, string>>& inventario) {
    string nombreObjeto;

    cout << "Escribe el nombre del producto: ";
    cin.ignore();
    getline(cin, nombreObjeto);
    transform(nombreObjeto.begin(), nombreObjeto.end(), nombreObjeto.begin(), ::toupper);

    if (inventario.find(nombreObjeto) != inventario.end()) {
        inventario.erase(nombreObjeto);
        cout << "El producto " << nombreObjeto << " ha sido eliminado de la lista de la compra." << endl;
    }
    else {
        cout << "El producto " << nombreObjeto << " no esta en la lista de la compra." << endl;
    }
}

void mostrarInventario(const map<string, map<string, string>>& inventario) {
    cout << "Tu inventario es:" << endl;
    for (const auto& par : inventario) {
        cout << par.first << ": " << par.second.at("cantidad") << endl;
    }
}

void gestionInventario(map<string, map<string, string>>& inventario) {
    while (true) {
        cout << "\n1. Agregar/Modificar un producto a la lista de la compra" << endl;
        cout << "2. Eliminar un producto de la lista de la compra" << endl;
        cout << "3. Mostrar lista de la compra" << endl;
        cout << "4. Terminar programa" << endl;

        int opcion;
        cout << "Escribe tu opcion (1, 2, 3, 4): ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            agregarObjeto(inventario);
            break;
        case 2:
            eliminarObjeto(inventario);
            break;
        case 3:
            mostrarInventario(inventario);
            break;
        case 4:
            cout << "Fin del programa." << endl;
            return;
        default:
            cout << "Opcion no valida. Intentalo de nuevo." << endl;
        }
    }
}
