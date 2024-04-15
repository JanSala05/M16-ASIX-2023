#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include "Header.h"

using namespace std;

int main() {
    map<string, map<string, string>> inventario;
    gestionInventario(inventario);
    return 0;
}
