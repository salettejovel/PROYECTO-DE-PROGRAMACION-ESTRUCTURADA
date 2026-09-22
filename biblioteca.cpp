#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <windows.h>

using namespace std;

// Variables generales
int opcion, opcionCat;
int totalLibros = 0;
int totalEstudiantes = 0;
int anioActual = 2026;

// Datos de libros con variables nativas (arreglos paralelos, sin structs)
vector<string> libroCodigo;
vector<string> libroTitulo;
vector<string> libroAutor;
vector<int> libroAnio;
vector<string> libroCategoria;
vector<int> libroEjemplares;

// Datos de estudiantes con variables nativas (arreglos paralelos, sin structs)
vector<string> estudianteNombre;
vector<string> estudianteApellidos;
vector<string> estudianteCarnet;

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
    string codigo, titulo, autor, categoria;
    int anio = 0;
    int ejemplares = 0;

    do {
        cout << "Ingrese el código del libro: ";
        getline(cin, codigo);

        if (codigo.empty()) {
            cout << "[ERROR] El código no puede estar vacío.\n";
        }
    } while (codigo.empty());

    do {
        cout << "Ingrese el título: ";
        getline(cin, titulo);

        if (titulo.empty()) {
            cout << "[ERROR] El título no puede estar vacío.\n";
        }
    } while (titulo.empty());

    do {
        cout << "Ingrese el autor: ";
        getline(cin, autor);

        if (autor.empty()) {
            cout << "[ERROR] El autor no puede estar vacío.\n";
        }
    } while (autor.empty());

    do {
        cout << "Ingrese el año de publicación: ";
        cin >> anio;
        cin.clear();
        cin.ignore(1000, '\n');

        if (anio <= 0 || anio > anioActual) {
            cout << "[ERROR] Ingrese un año válido (entre 1 y " << anioActual << ").\n";
        }
    } while (anio <= 0 || anio > anioActual);

    do {
        cout << "\nSeleccione la categoría del libro:\n";
        cout << "1. Ficción\n";
        cout << "2. No Ficción\n";
        cout << "3. Ciencia\n";
        cout << "4. Historia\n";
        cout << "5. Tecnología\n";
        cout << "6. Otra\n";
        cout << "Ingrese una opción (1-6): ";
        cin >> opcionCat;
        cin.clear();
        cin.ignore(1000, '\n');

        switch (opcionCat) {
            case 1: categoria = "Ficción"; break;
            case 2: categoria = "No Ficción"; break;
            case 3: categoria = "Ciencia"; break;
            case 4: categoria = "Historia"; break;
            case 5: categoria = "Tecnología"; break;
            case 6: categoria = "Otra"; break;
            default: 
                cout << "[ERROR] Debe elegir un número del 1 al 6.\n";
                break;
        }
    } while (opcionCat < 1 || opcionCat > 6);

    do {
        cout << "Ingrese la cantidad de ejemplares: ";
        cin >> ejemplares;
        cin.clear();
        cin.ignore(1000, '\n');

        if (ejemplares <= 0) {
            cout << "[ERROR] La cantidad debe ser mayor a cero.\n";
        }
    } while (ejemplares <= 0);

    libroCodigo.push_back(codigo);
    libroTitulo.push_back(titulo);
    libroAutor.push_back(autor);
    libroAnio.push_back(anio);
    libroCategoria.push_back(categoria);
    libroEjemplares.push_back(ejemplares);
    totalLibros++;

    cout << "\n[INFO] ¡Libro registrado exitosamente!\n";
}

void registrarEstudiante() {
    cout << "\n=== REGISTRO DE NUEVO ESTUDIANTE ===\n";
    string nombre, apellidos, carnet;

    // Registrar datos del estudiante con validaciones
    do {
        cout << "Ingrese los nombres del estudiante: ";
        getline(cin, nombre);

        if (nombre.empty()) {
            cout << "[ERROR] El nombre no puede estar vacío.\n";
        }
    } while (nombre.empty());

    do {
        cout << "Ingrese los apellidos del estudiante: ";
        getline(cin, apellidos);

        if (apellidos.empty()) {
            cout << "[ERROR] Los apellidos no pueden estar vacíos.\n";
        }
    } while (apellidos.empty());

    do {
        cout << "Ingrese el carnet del estudiante: ";
        getline(cin, carnet);

        if (carnet.empty()) {
            cout << "[ERROR] El carnet no puede estar vacío.\n";
        }
    } while (carnet.empty());

    // Guardar en los vectores paralelos
    estudianteNombre.push_back(nombre);
    estudianteApellidos.push_back(apellidos);
    estudianteCarnet.push_back(carnet);
    totalEstudiantes++;

    cout << "\n[INFO] ¡Estudiante registrado exitosamente!\n";
}

void consultarLibros() {
    if (totalLibros == 0) {
        cout << "\n[INFO] No hay libros registrados.\n";
        return;
    }
    
    cout << "\n=== CONSULTA DE LIBROS REGISTRADOS ===\n";
    cout << "----------------------------------------\n";
    for (size_t i = 0; i < totalLibros; ++i) {
        cout << "[Libro #" << (i + 1) << "]\n";
        cout << "Código:     " << libroCodigo[i] << "\n";
        cout << "Título:     " << libroTitulo[i] << "\n";
        cout << "Autor:      " << libroAutor[i] << "\n";
        cout << "Año:        " << libroAnio[i] << "\n";
        cout << "Categoría:  " << libroCategoria[i] << "\n";
        cout << "Ejemplares: " << libroEjemplares[i] << "\n";
        cout << "----------------------------------------\n";
    }
}

void consultarEstudiantes() {
    if (totalEstudiantes == 0) {
        cout << "\n[INFO] No hay estudiantes registrados.\n";
        return;
    }
    
    cout << "\n=== CONSULTA DE ESTUDIANTES REGISTRADOS ===\n";
    cout << "------------------------------------------\n";
    for (size_t i = 0; i < totalEstudiantes; ++i) {
        cout << "[Estudiante #" << (i + 1) << "]\n";
        cout << "Nombres:    " << estudianteNombre[i] << "\n";
        cout << "Apellidos:  " << estudianteApellidos[i] << "\n";
        cout << "Carnet:     " << estudianteCarnet[i] << "\n";
        cout << "------------------------------------------\n";
    }
}

void buscarPrestamo() {
    // Buscar estudiante por carne
    // Buscar libro por codigo
    // Mostrar resultados
}