#include <iostream>
#include "arreglodinamico.h"

using namespace std;

main()
{
    Arreglodinamico<string> arreglo;

    arreglo.insertar_final("Tacos");
    arreglo.insertar_final("Posole");
    arreglo.insertar_inicio("Mexicana:");
    arreglo.insertar_inicio("comida");

    for (size_t i = 0; i < arreglo.size(); i++){
        cout << arreglo[i] << "  ";
    }
    cout << endl;

    arreglo.insertar("Enchiladas", 2);

    for (size_t i = 0; i < arreglo.size(); i++){
        cout << arreglo[i] << "  ";
    }
    cout << endl;

    arreglo.eliminar_inicio();
    arreglo.eliminar_final();
    arreglo.eliminar(1);

    for (size_t i = 0; i < arreglo.size(); i++){
        cout << arreglo[i] << " ";
    }
    cout << endl;

    return 0;
}