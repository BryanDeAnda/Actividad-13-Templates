#ifndef ARREGLODINAMICO_H
#define ARREGLODINAMICO_H

#include <iostream>
using namespace std;

template <class T>

class Arreglodinamico 
{
    T *arreglo;
    size_t tam;
    size_t cont;
    const static size_t MAX = 5;

public:
    Arreglodinamico();
    ~Arreglodinamico();
    void insertar_final(const T& s);
    void insertar_inicio(const T& s);
    void insertar(const T& s,size_t p);

    void eliminar_final();
    void eliminar_inicio();
    void eliminar(size_t p);
    
    size_t size();

    T operator[](size_t p)
    {
        return arreglo[p];
    }
private:
    void expandir();
};

template <class T> 
Arreglodinamico<T>::Arreglodinamico()
{
    arreglo = new T[MAX];
    cont = 0;
    tam = MAX;
}

template <class T>
Arreglodinamico<T>::~Arreglodinamico()
{
    delete[] arreglo;
}

template <class T>
void Arreglodinamico<T>::insertar_final(const T& s)
{
    if (cont == tam){
        expandir();
    }
    arreglo[cont] = s;
    cont++;
}

template <class T>
void Arreglodinamico<T>::insertar_inicio(const T& s)
{
    if (cont == tam){
        expandir();
    }
    for(size_t i=cont; i>0; i--){
        arreglo[i] = arreglo[i-1];
    }
    arreglo[0] = s;
    cont++;
}

template <class T>
void Arreglodinamico<T>::insertar(const T& s, size_t p)
{
    if (p >= cont){
        cout << "Posicion no valida"<< endl;
        return;
    }
    if (cont == tam){
        expandir();
    }
    for (size_t i = cont; i > p; i--)
    {
        arreglo[i] = arreglo[i-1];
    }
    arreglo[p] = s;
    cont++;

}

template <class T>
void Arreglodinamico<T>::eliminar_final()
{
    if(cont==0){
        cout << "Arreglo vacío"<<endl;
        return;
    }
    cont--;
}

template <class T>
void Arreglodinamico<T>::eliminar_inicio()
{
    if(cont==0){
        cout << "Arreglo vacío"<<endl;
        return;
    }
    for (size_t i = 0; i < cont-1; i++)
    {
        arreglo[i] = arreglo[i+1];
    }
    cont--;  
}

template <class T>
void Arreglodinamico<T>::eliminar(size_t p)
{
    if(cont==0){
        cout << "Arreglo vacío"<<endl;
        return;
    }
    for(size_t i=p; i < cont-1; i++)
    {
        arreglo[i] = arreglo[i+1];

    }
    cont--;
}

template <class T>
size_t Arreglodinamico<T>::size()
{
    return cont;
}

template <class T>
void Arreglodinamico<T>::expandir()
{
    T *nuevo = new T[tam+MAX];

    for(size_t i=0; i<cont; i++){
        nuevo[i] = arreglo[i];
    }
    delete[] arreglo;
    arreglo = nuevo;
    tam = tam + MAX;
}

#endif