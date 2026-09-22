#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <windows.h>

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
    int ejemplares;
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
void registrarLibro();
void registrarEstudiante();
void consultarLibros();
void consultarEstudiantes();
void buscarPrestamo();

int main() {
    // Configurar la consola para mostrar tildes y letra ñ
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    do {
        mostrarMenu();

        cout << "Seleccione una opción (1-6): ";
        cin >> opcion;

        cin.clear();
        cin.ignore(1000, '\n');

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
                buscarPrestamo();
                break;
            case 6:
                cout << "\n[INFO] Saliendo del sistema...\n";
                break;
            default:
                cout << "\n[ERROR] Opción no válida.\n";
        }
    } while (opcion != 6);
    return 0;
}

void mostrarMenu() {
    cout << "\n========================================";
    cout << "\n    SISTEMA DE GESTIÓN BIBLIOTECARIA    ";
    cout << "\n========================================\n";
    cout << "1. Registrar libros\n";
    cout << "2. Registrar estudiantes\n";
    cout << "3. Consultar libros\n";
    cout << "4. Consultar estudiantes\n";
    cout << "5. Buscar préstamo\n";
    cout << "6. Salir";
    cout << "\n========================================\n";
}

void registrarLibro() {
    cout << "\n=== REGISTRO DE NUEVO LIBRO ===\n";
    Libro nuevoLibro;

    do {
        cout << "Ingrese el código del libro: ";
        getline(cin, nuevoLibro.codigo);

        if (nuevoLibro.codigo.empty()) {
            cout << "[ERROR] El código no puede estar vacío.\n";
        }
    } while (nuevoLibro.codigo.empty());

    do {
        cout << "Ingrese el título: ";
        getline(cin, nuevoLibro.titulo);

        if (nuevoLibro.titulo.empty()) {
            cout << "[ERROR] El título no puede estar vacío.\n";
        }
    } while (nuevoLibro.titulo.empty());

    do {
        cout << "Ingrese el autor: ";
        getline(cin, nuevoLibro.autor);

        if (nuevoLibro.autor.empty()) {
            cout << "[ERROR] El autor no puede estar vacío.\n";
        }
    } while (nuevoLibro.autor.empty());

    do {
        cout << "Ingrese el año de publicación: ";
        cin >> nuevoLibro.anio;
        cin.clear();
        cin.ignore(1000, '\n');

        if (nuevoLibro.anio <= 0 || nuevoLibro.anio > anioActual) {
            cout << "[ERROR] Ingrese un año válido (entre 1 y " << anioActual << ").\n";
        }
    } while (nuevoLibro.anio <= 0 || nuevoLibro.anio > anioActual);

    do {
        cout << "Ingresa la categoría: ";
        getline(cin, nuevoLibro.categoria); // CAMBIAR: Debe ser un menú de opciones predefinidas (Ficción, No Ficción, Ciencia, Historia, etc.)

        if (nuevoLibro.categoria.empty()) {
            cout << "[ERROR] La categoria no puede estar vacía.\n";
        }
    } while (nuevoLibro.categoria.empty());

    do {
        cout << "Ingrese la cantidad de ejemplares: ";
        cin >> nuevoLibro.ejemplares;
        cin.clear();
        cin.ignore(1000, '\n');

        if (nuevoLibro.ejemplares <= 0) {
            cout << "[ERROR] La cantidad debe ser mayor a cero.\n";
        }
    } while (nuevoLibro.ejemplares <= 0);

    libros.push_back(nuevoLibro);

    cout << "\n[INFO] ¡Libro registrado exitosamente!\n";
}

void registrarEstudiante() {
    cout << "\n=== REGISTRO DE NUEVO ESTUDIANTE ===\n";
    Estudiante nuevoEstudiante;

    // Registrar datos del estudiante con validaciones
    do {
        cout << "Ingrese los nombres del estudiante: ";
        getline(cin, nuevoEstudiante.nombre);

        if (nuevoEstudiante.nombre.empty()) {
            cout << "[ERROR] El nombre no puede estar vacío.\n";
        }
    } while (nuevoEstudiante.nombre.empty());

    do {
        cout << "Ingrese los apellidos del estudiante: ";
        getline(cin, nuevoEstudiante.apellidos);

        if (nuevoEstudiante.apellidos.empty()) {
            cout << "[ERROR] Los apellidos no pueden estar vacíos.\n";
        }
    } while (nuevoEstudiante.apellidos.empty());

    do {
        cout << "Ingrese el carnet del estudiante: ";
        getline(cin, nuevoEstudiante.carnet);

        if (nuevoEstudiante.carnet.empty()) {
            cout << "[ERROR] El carnet no puede estar vacío.\n";
        }
    } while (nuevoEstudiante.carnet.empty());

    // Guardar en el vector
    estudiantes.push_back(nuevoEstudiante);

    cout << "\n[INFO] ¡Estudiante registrado exitosamente!\n";
}

void consultarLibros() {
    cout << "\n=== CONSULTA DE LIBROS REGISTRADOS ===\n";
    cout << "----------------------------------------\n";
    for (size_t i = 0; i < libros.size(); ++i) {
        cout << "[Libro #" << (i + 1) << "]\n";
        cout << "  Código:     " << libros[i].codigo << "\n";
        cout << "  Título:     " << libros[i].titulo << "\n";
        cout << "  Autor:      " << libros[i].autor << "\n";
        cout << "  Año:        " << libros[i].anio << "\n";
        cout << "  Categoría:  " << libros[i].categoria << "\n";
        cout << "  Ejemplares: " << libros[i].ejemplares << "\n";
        cout << "----------------------------------------\n";
    }
}

void consultarEstudiantes() {

    // Mostrar estudiantes registrados
}

void buscarPrestamo() {
    // Buscar estudiante por carne
    // Buscar libro por codigo
    // Mostrar resultados
}