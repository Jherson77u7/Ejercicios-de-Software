#include "TreeBinary.h"

template<typename T, int N>
int TreeBinary<T, N>::CalcularNodo(int pos) {
    if (!Arr[pos].existe) return 0;
    int c1 = CalcularNodo(pos * 2);
    int c2 = CalcularNodo(pos * 2 + 1);
    return c1 + c2 + 1;
}

template<typename T, int N>
int TreeBinary<T, N>::CalcularAltura(int pos) {
    if (!Arr[pos].existe) return 0;
    int izq = CalcularAltura(pos * 2);
    int der = CalcularAltura(pos * 2 + 1);
    return std::max(izq, der) + 1;
}

template<typename T, int N>
void TreeBinary<T, N>::MostrarInOrder(int pos) {
    if (Arr[pos].existe) {
        MostrarInOrder(pos * 2);
        std::cout << "Posicion: " << pos << ", Elemento: " << Arr[pos].elem << std::endl;
        MostrarInOrder(pos * 2 + 1);
    }
}

template<typename T, int N>
void TreeBinary<T, N>::MostrarPreOrder(int pos) {
    if (Arr[pos].existe) {
        std::cout << "Posicion: " << pos << ", Elemento: " << Arr[pos].elem << std::endl;
        MostrarPreOrder(pos * 2);
        MostrarPreOrder(pos * 2 + 1);
    }
}

template<typename T, int N>
void TreeBinary<T, N>::MostrarPostOrder(int pos) {
    if (Arr[pos].existe) {
        MostrarPostOrder(pos * 2);
        MostrarPostOrder(pos * 2 + 1);
        std::cout << "Posicion: " << pos << ", Elemento: " << Arr[pos].elem << std::endl;
    }
}

template<typename T, int N>
int TreeBinary<T, N>::ContarHojas(int pos) {
    if (!Arr[pos].existe) return 0;
    if (!Arr[pos * 2].existe && !Arr[pos * 2 + 1].existe) return 1;
    return ContarHojas(pos * 2) + ContarHojas(pos * 2 + 1);
}

template<typename T, int N>
void TreeBinary<T, N>::InvertirHijos(int pos) {
    if (!Arr[pos].existe) return;

    int pos_hijo_izquierdo = pos * 2;
    int pos_hijo_derecho = pos * 2 + 1;

    if (Arr[pos_hijo_izquierdo].existe && Arr[pos_hijo_derecho].existe) {
        std::swap(Arr[pos_hijo_izquierdo], Arr[pos_hijo_derecho]);
    }

    InvertirHijos(pos_hijo_izquierdo);
    InvertirHijos(pos_hijo_derecho);
}

template<typename T, int N>
void TreeBinary<T, N>::MostrarPorNiveles(int pos) {
    int altura = CalcularAltura();

    int inicioNivel = 1;
    for (int i = 0; i < altura; i++) {
        int numNodosNivel = inicioNivel;

        for (int j = 0; j < numNodosNivel; j++) {
            int indiceActual = inicioNivel + j;

            if (indiceActual < N && Arr[indiceActual].existe) {
                std::cout << Arr[indiceActual].elem << " ";
            }
            else {
                std::cout << "- ";
            }
        }
        std::cout << std::endl;

        inicioNivel *= 2;
    }
}

template<typename T, int N>
void TreeBinary<T, N>::InsertarRecursivo(int pos, const T& elem) {
    if (!Arr[pos].existe) {
        Arr[pos].elem = elem;
        Arr[pos].existe = true;
        return;
    }

    if (elem < Arr[pos].elem) {
        InsertarRecursivo(pos * 2, elem);
    }
    else {
        InsertarRecursivo(pos * 2 + 1, elem);
    }
}

template<typename T, int N>
void TreeBinary<T, N>::Insertar(const T& elem) {
    InsertarRecursivo(1, elem);
}

template<typename T, int N>
int TreeBinary<T, N>::ContarNodos() {
    return CalcularNodo(1);
}

template<typename T, int N>
int TreeBinary<T, N>::CalcularAltura() {
    return CalcularAltura(1);
}

template<typename T, int N>
void TreeBinary<T, N>::MostrarInOrder() {
    MostrarInOrder(1);
    std::cout << std::endl;
}

template<typename T, int N>
void TreeBinary<T, N>::MostrarPreOrder() {
    MostrarPreOrder(1);
    std::cout << std::endl;
}

template<typename T, int N>
void TreeBinary<T, N>::MostrarPostOrder() {
    MostrarPostOrder(1);
    std::cout << std::endl;
}

template<typename T, int N>
int TreeBinary<T, N>::ContarHojas() {
    return ContarHojas(1);
}

template<typename T, int N>
void TreeBinary<T, N>::InvertirHijos() {
    InvertirHijos(1);
}

template<typename T, int N>
void TreeBinary<T, N>::MostrarPorNiveles() {
    MostrarPorNiveles(1);
    std::cout << std::endl;
}

template<typename T, int N>
bool TreeBinary<T, N>::Buscar_ABB(int pos, const T& elem) {
    if (!Arr[pos].existe) {
        return false;
    }

    if (Arr[pos].elem == elem) {
        return true;
    }
    else if (elem < Arr[pos].elem) {
        return Buscar_ABB(pos * 2, elem);
    }
    else {
        return Buscar_ABB(pos * 2 + 1, elem);
    }
}

template<typename T, int N>
bool TreeBinary<T, N>::Buscar(const T& elem) {
    return Buscar_ABB(1, elem);
}

template<typename T, int N>
T TreeBinary<T, N>::MostrarMenor() {
    int pos = 1;
    while (Arr[pos * 2].existe) {
        pos = pos * 2;
    }
    return Arr[pos].elem;
}

template<typename T, int N>
T TreeBinary<T, N>::MostrarMayor() {
    int pos = 1;
    while (Arr[pos * 2 + 1].existe) {
        pos = pos * 2 + 1;
    }
    return Arr[pos].elem;
}
