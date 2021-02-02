/*
 * Two Knights
 * https://cses.fi/problemset/task/1072
 */

#include <iostream>
#include <cstring>
#define MAX_SIZE 10001

using namespace std;



int main(int argc, char const *argv[]) {
    int chess_size;

    cin >> chess_size;

    for (uint size = 1; size <= chess_size; size++) {
        long long n = size * size;
        // Número de formas en que pueden ser colocados dos caballos
        // en el tablero sin considerar si se atacan o no
        // Combinación (n, 2) = n! / (2! - (n - 2)!)
        long long ways_to_put_all = n * (n - 1) / 2;
        // Formas en que se puede colocar dos caballos atacándose
        // Dos Caballos atacándose forman un rectangulo de 3x2 o 2x3
        // Para el mismo rectángulo los caballos se pueden colocar de dos formas
        // (intercambiandolos de esquinas)
        // Contamos el número de formas en que se puede colocar estos rectángulos
        // en el tablero
        long long ways_to_attack = (size-1) * (size -2) * 4;

        cout << ways_to_put_all - ways_to_attack << "\n";
    }

    return 0;
}
