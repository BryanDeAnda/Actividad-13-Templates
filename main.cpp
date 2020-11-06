#include <iostream>
#include "arreglodinamico.h"
#include "computadora.h"

using namespace std;

main()
{
    Arreglodinamico<Computadora> computadoras;

    Computadora c01("Windows", "Lenovo", "Inteli9", 4);
    Computadora c02("Mac", "Apple", "Inteli7", 16);
    Computadora c03("Linux", "Huawei", "Rizen7", 32);
    Computadora c04("Windows", "HP", "inteli5", 4);
    Computadora c05("Windows", "Xtreme", "Rizen5", 8);

    computadoras << c01 << c02 << c03 << c04 << c05;
    Computadora c06("Mac", "Apple", "Inteli7", 16);
    Computadora c07("MacIOS", "Lenovo", "Inteli7", 4);
    Computadora c08("Windows", "Lenovo", "Inteli9", 4);

    Computadora *ptr = computadoras.buscar(c06);

    if(ptr != nullptr){
        cout << *ptr << endl;
    }
    else{
        cout << "No existe"<<endl;
    }
    
    Computadora *ptrl = computadoras.buscar(c07);
    if(ptrl != nullptr){
        cout << *ptrl << endl;
    }
    else{
        cout << "No existe"<<endl;
    }

    Arreglodinamico<Computadora*> ptrs = computadoras.buscar_todos(c08);

    if(ptrs.size()>0){
        for (size_t i = 0; i < ptrs.size(); i++)
        {
            Computadora *c = ptrs[i];
            cout <<*c <<endl;
        }
    }
    else{
        cout << "No existen coincidencias"<<endl;
    }

    /*Arreglodinamico<string> arreglo;

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

    string *v = arreglo.buscar("Mexicana:");
    cout << v << " " << *v << endl;
    *v = "tortas";
    
    for (size_t i = 0; i < arreglo.size(); i++){
        cout << arreglo[i] << " ";
    }
    cout << endl;*/

    return 0;
}