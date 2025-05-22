// Escribir una función recursiva que, dado un número entero, retorne la cantidad de dígitos que tiene. 
// Ejemplo: si el número es 650, la función debe retornar 3.

#include <iostream>
using namespace std;

int cantidad_de_numeros(int numero);

int main(){

    //Variables
    int numero;

    cout<<"Ingresar número: ";
    cin>>numero;

    cout<<cantidad_de_numeros(numero);
    return 0;
}

int cantidad_de_numeros(int numero){
    if (numero == 0) {
        return 0;
    }

    return 1 + cantidad_de_numeros(numero / 10);
}