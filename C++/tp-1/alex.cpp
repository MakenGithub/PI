#include <iostream>
using namespace std;

const int N = 3;  // Tamaño de la matriz (puedes modificarlo para matrices de otro tamaño)

void snail(int array[N][N], int result[]) {
    int top = 0, bottom = N - 1;
    int left = 0, right = N - 1;
    int idx = 0;  // Índice para el array result
    
    while (top <= bottom && left <= right) {
        // Recorrer la fila superior de izquierda a derecha
        for (int i = left; i <= right; ++i) {
            result[idx++] = array[top][i];
        }
        top++;  // Mover la fila superior hacia abajo
        
        // Recorrer la columna derecha de arriba a abajo
        for (int i = top; i <= bottom; ++i) {
            result[idx++] = array[i][right];
        }
        right--;  // Mover la columna derecha hacia la izquierda
        
        if (top <= bottom) {
            // Recorrer la fila inferior de derecha a izquierda
            for (int i = right; i >= left; --i) {
                result[idx++] = array[bottom][i];
            }
            bottom--;  // Mover la fila inferior hacia arriba
        }
        
        if (left <= right) {
            // Recorrer la columna izquierda de abajo hacia arriba
            for (int i = bottom; i >= top; --i) {
                result[idx++] = array[i][left];
            }
            left++;  // Mover la columna izquierda hacia la derecha
        }
    }
}

int main() {
    int array[N][N] = {
        {1, 2, 3},
        {8, 9, 4},
        {7, 6, 5}
    };
    
    int result[N * N];  // Array para almacenar el resultado
    
    snail(array, result);
    
    // Imprimir el resultado
    for (int i = 0; i < N * N; ++i) {
        cout << result[i] << " ";
    }
    
    return 0;
}