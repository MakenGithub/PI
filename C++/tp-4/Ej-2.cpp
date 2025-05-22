// Graficar la pila de llamadas (colocando parámetros y valores de retorno): 
#include <iostream>
using namespace std;

int sumatoria(int num) { 
    if (num == 0) 
        return 0; 
    return sumatoria(num-1) + num; // 5, 4, 3, 2, 1
} 

int main() { 
    cout << sumatoria(5); // 15
    return 0; 
}