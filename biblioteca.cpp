#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

// Variables generales

int opcion;
int totalLibros = 0;
int totalEstudiantes = 0;
int anioActual = 2026;

// Datos de libros

struct Libro {
    string codigo;
    string titulo;
    string autor;
    int anio;
    string categoria;
    int cantidad;
};

// Datos de estudiantes

struct Estudiante {
    string nombre;
    string apellidos;
    string carnet;
};

vector<Libro> libros;
vector<Estudiante> estudiantes;

// Funciones

void mostrarMenu();
void registrarLibro();          // Integrante 1
void registrarEstudiante();     // Integrante 2
void consultarLibros();         // Integrante 3
void consultarEstudiantes();    // Integrante 4
void buscarPrestamo();          // Integrante 5


int main() {

    do {

        mostrarMenu();

        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {

            case 1:
                registrarLibro();
                break;

            case 2:
                registrarEstudiante();
                break;

            case 3:
                consultarLibros();
                break;

            case 4:
                consultarEstudiantes();
                break;

            case 5:
                cout << "Saliendo del sistema...\n";
                break;

            default:
                cout << "Opcion no valida.\n";
        }
    } while (opcion != 5);
    return 0;
}


void mostrarMenu() {
    cout << "\n--- SISTEMA DE BIBLIOTECA ---\n";
    cout << "1. Registrar libros\n";
    cout << "2. Registrar estudiantes\n";
    cout << "3. Consultar libros\n";
    cout << "4. Consultar estudiantes\n";
    cout << "5. Salir\n";
}



void registrarLibro() {
    if (libros.size() >= 100) {
        cout << "\n[ERROR] Limite de capacidad alcanzado (maximo 100 libros).\n";
        return;
    }

    Libro nuevoLibro;

    cout << "\n--- REGISTRO DE LIBRO (" << libros.size() + 1 << "/100) ---\n";

    cout << "Codigo del libro: ";
    cin >> nuevoLibro.codigo;
    cin.ignore();

    do {
        cout << "Titulo: ";
        getline(cin, nuevoLibro.titulo);
        if (nuevoLibro.titulo.empty()) {
            cout << "[ERROR] El titulo no puede estar vacio.\n";
        }
    } while (nuevoLibro.titulo.empty());

    do {
        cout << "Autor: ";
        getline(cin, nuevoLibro.autor);
        if (nuevoLibro.autor.empty()) {
            cout << "[ERROR] El autor no puede estar vacio.\n";
        }
    } while (nuevoLibro.autor.empty());

    cout << "Año de publicacion: ";
    while (!(cin >> nuevoLibro.anio) || nuevoLibro.anio <= 0 || nuevoLibro.anio > anioActual) {
        cout << "[ERROR] Ingrese un año valido (entre 1 y " << anioActual << "): ";
        cin.clear();
        cin.ignore();
    }
    cin.ignore();

    do {
        cout << "Categoria: ";
        getline(cin, nuevoLibro.categoria);
        if (nuevoLibro.categoria.empty()) {
            cout << "[ERROR] La categoria no puede estar vacia.\n";
        }
    } while (nuevoLibro.categoria.empty());

    cout << "Cantidad disponible: ";
    while (!(cin >> nuevoLibro.cantidad) || nuevoLibro.cantidad <= 0) {
        cout << "[ERROR] Debe ingresar un numero entero mayor a 0.\n";
        cin.clear();
        cin.ignore();
    }

    libros.push_back(nuevoLibro);

    cout << "\n¡Libro registrado exitosamente!\n";
}


// Integrante 2
void registrarEstudiante() {

    // Registrar datos del estudiante
    // Validar campos
}


// Integrante 3
void consultarLibros() {

    // Mostrar libros registrados
}


// Integrante 4
void consultarEstudiantes() {

    // Mostrar estudiantes registrados
}


// Integrante 5
void buscarPrestamo() {

    // Buscar estudiante por carne
    // Buscar libro por codigo
    // Mostrar resultados
}