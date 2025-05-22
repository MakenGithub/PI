// Escribir una función recursiva que, dado un número entero, lo imprima en orden inverso. 
// Ejemplo: si el número es 5182, la función debe imprimir 2815. 

#include <iostream>
using namespace std;

// Función recursiva para imprimir un número en orden inverso
void imprimirInverso(int numero) {
    if (numero == 0) {
        return;
    }
    // Obtener el último dígito
    int digito = numero % 10;
    
    // Imprimir el dígito
    cout << digito;
    
    // Llamar recursivamente con el número reducido
    imprimirInverso(numero / 10);
}

int main() {
    int numero;
    cout << "Ingresa un número entero: ";
    cin >> numero;
    
    if (numero == 0) {
        cout << 0;
    } else {
        // Si el número es negativo, imprimir el signo y usar su valor absoluto
        if (numero < 0) {
            cout << "-";
            numero = abs(numero); // Convertimos a positivo para procesar
        }
        
        // Llamar a la función
        imprimirInverso(numero);
    }
    
    cout << endl;
    return 0;
}