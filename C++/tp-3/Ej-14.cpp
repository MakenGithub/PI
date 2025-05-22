// Generar una lista con los datos personales de los alumnos de un colegio (legajo, apellido y nombre, DNI) y las
// notas de tres MATERIAS: matemática, literatura y geografía (para cada alumno se cargarán las tres MATERIAS). Las
// notas pueden ir de 1 a 10 y se debe validar que el usuario no ingrese notas incorrectas, volviendo a pedir una
// nueva nota cada vez que ingrese una incorrecta, hasta que ingrese un valor en el rango indicado. Se pide
// informar la cantidad de alumnos que aprobaron las tres MATERIAS (se aprueba con 7) y el porcentaje que
// representan los aprobados sobre el total de alumnos.

// META DATA
#include <iostream>
#include <limits>       // Para std::numeric_limits
#include <string>      // Para el uso de strings
#include <fstream>      //Para manejo de archivos

using namespace std;

// VARIABLES GLOBALES Y CONSTANTES
float cantidadDeAlumnos = 0;
float aprobados = 0;
const string MATERIAS[3] = {"Matemática", "Literatura", "Geografía"};

// ESTRUCTURAS
    //Alumnos
    struct Alumno
    {
        int legajo;
        string nombre;      //Para nombre y apellido
        int dni;
        int notas[3];
    };
    
    //Nodo
    struct Nodo
    {
        Alumno alumnos;
        Nodo* siguiente;
    };
    
// DECLARACIÓN DE FUNCIONES
//Carga en un nuevo nodo la información de cada alumno por individual
void agregar_a_lista(Nodo* &lista, Alumno alumnos);

//Verifica que la nota ingresada esté en el rango de [1 - 10]
int verificar_nota(int nota);

//Retorna verdadero si el alumno aprueba con 7 o más todas las MATERIAS
bool comprobar_estado(Alumno alumnos);

//Informa cantidad de alumnos aprobados y qué porcentaje representan sobre el total
float generar_informe(Nodo* lista);

// FUNCION PRINCIPAL
int main() {
    // Variables
    Nodo* lista = nullptr;
    Alumno alumnos;
    int legajo;
    int nota;

    cout<<"Agregar alumnos a la lista..."<<endl
        <<"N° legajo 0 para salir."<<endl;

    cout<<"\nLegajo ";
    cin>>legajo;

    while (legajo != 0)
    {
        alumnos.legajo = legajo;

        cout<<"Nombre y apellido: ";
        getline(cin >> ws, alumnos.nombre);

        cout<<"DNI: ";
        cin>>alumnos.dni;

        cout<<"Nota (1/10):"<<endl;
        for (int i = 0; i < 3; i++)
        {
            cout<<"Nota en "<<MATERIAS[i]<<": ";
            cin>>nota;
            alumnos.notas[i] = verificar_nota(nota);
        }

        agregar_a_lista(lista, alumnos);

        cout<<"\nLegajo ";
        cin>>legajo;
    }

    //Generar informe de aprobados -----------------------------
    cout << "Generando informe de aprobados..."<<endl;
    aprobados = generar_informe(lista);
    if (cantidadDeAlumnos > 0) {
        float porcentaje = (aprobados / cantidadDeAlumnos) * 100;
        cout<<aprobados<<" alumnos aprobaron las tres MATERIAS de un total de "<<cantidadDeAlumnos<<endl
             <<"Esto representa el "<<porcentaje<<"% del total."<<endl;
    } else {
        cout <<"No se ingresaron alumnos."<<endl;
    }

    return 0;
}

//DEFINICIÓN DE FUNCIONES
//Carga en un nuevo nodo la información de cada alumno por individual
void agregar_a_lista(Nodo* &lista, Alumno alumnos){
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->alumnos = alumnos;
    nuevoNodo->siguiente = lista;
    lista = nuevoNodo;
    cantidadDeAlumnos++;
}

//Verifica que la nota ingresada esté en el rango de [1 - 10]
int verificar_nota(int nota){
    while (nota < 1 || nota > 10)
    {
        cout<<"Ingresar número válido: ";
        cin>>nota;
    }
    return nota;
}

//Retorna verdadero si el alumno aprueba con 7 o más todas las MATERIAS
bool comprobar_estado(Alumno alumnos){
    for (int i = 0; i < 3; i++)
    {
        if (alumnos.notas[i] < 7)
        {
            return false;
        }
    }
    return true;
    
}

//Informa cantidad de alumnos aprobados y qué porcentaje representan sobre el total
float generar_informe(Nodo* lista){
    float aprobados = 0;
    Nodo* actual = lista;

    while (actual != nullptr)
    {
        if (comprobar_estado(actual->alumnos))
        {
            aprobados++;
        }
        actual = actual->siguiente;
    }
    
    return aprobados;
}
//------------------------------------------------------------------------