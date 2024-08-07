#pragma once

#include <iostream>
#include <string>
#include <algorithm> 
#include <cstdlib>   

#include "Nodo.h"

template<typename T, int N>
class TreeBinary {

private:
    Nodo<T> Arr[N];

    int CalcularNodo(int pos);
    int CalcularAltura(int pos);
    void MostrarInOrder(int pos);
    void MostrarPreOrder(int pos);
    void MostrarPostOrder(int pos);
    int ContarHojas(int pos);
    void InvertirHijos(int pos);
    void MostrarPorNiveles(int pos);

public:
    void InsertarRecursivo(int pos, const T& elem);
    void Insertar(const T& elem);
    int ContarNodos();
    int CalcularAltura();
    void MostrarInOrder();
    void MostrarPreOrder();
    void MostrarPostOrder();
    int ContarHojas();
    void InvertirHijos();
    void MostrarPorNiveles();
    bool Buscar_ABB(int pos, const T& elem);
    bool Buscar(const T& elem);
    T MostrarMenor();
    T MostrarMayor();
};

