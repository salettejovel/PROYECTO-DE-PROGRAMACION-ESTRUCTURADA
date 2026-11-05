#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <windows.h>

using namespace std;

int opcion, opcionCat;
const int anioActual = 2026;

struct Libro {
    string codigo;
    string titulo;
    string autor;
    string categoria;
    int anio;
    int ejemplares;
};

struct Estudiante {
    string nombre;
    string apellidos;
    string carnet;
};

struct Prestamo {
    string carnet;
    string codigoLibro;
};

vector<Libro> libros;
vector<Estudiante> estudiantes;
vector<Prestamo> prestamos;

void mostrarMenu();
void registrarLibro();
void registrarEstudiante();
void consultarLibros();
void consultarEstudiantes();
void realizarPrestamo();
void devolverLibro();
void modificarLibro();
void eliminarLibro();
void modificarEstudiante();
void eliminarEstudiante();
void agregarStock();

int buscarLibro(string codigo) {
    for (int i = 0; i < libros.size(); ++i) {
        // Si se encuentra un libro, se devuelve su índice
        if (libros[i].codigo == codigo) {
            return i;
        }
    }
    // Si no se encuentra, se devuelve -1
    return -1;
}

int buscarEstudiante(string carnet) {
    for (int i = 0; i < estudiantes.size(); ++i) {
        if (estudiantes[i].carnet == carnet) {
            return i;
        }
    }
    return -1;
}

int buscarPrestamo(string carnet, string codigoLibro) {
    for (int i = 0; i < prestamos.size(); ++i) {
        if (prestamos[i].carnet == carnet && prestamos[i].codigoLibro == codigoLibro) {
            return i;
        }
    }
    return -1;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    do {
        mostrarMenu();

        cout << "Seleccione una opción (1-12): ";
        cin >> opcion;

        cin.clear();
        cin.ignore(1000, '\n');

        switch (opcion) {
            case 1: registrarLibro(); break;
            case 2: registrarEstudiante(); break;
            case 3: consultarLibros(); break;
            case 4: consultarEstudiantes(); break;
            case 5: modificarLibro(); break;
            case 6: eliminarLibro(); break;
            case 7: modificarEstudiante(); break;
            case 8: eliminarEstudiante(); break;
            case 9: realizarPrestamo(); break;
            case 10: devolverLibro(); break;
            case 11: agregarStock(); break;
            case 12: cout << "\n[INFO] Saliendo del sistema...\n"; break;
            default: cout << "\n[ERROR] Opción no válida.\n";
        }
    } while (opcion != 12);
    return 0;
}

void mostrarMenu() {
    cout << "\n========================================";
    cout << "\n    SISTEMA DE GESTIÓN BIBLIOTECARIA    ";
    cout << "\n========================================\n";
    cout << "1. Registrar libro\n";
    cout << "2. Registrar estudiante\n";
    cout << "3. Consultar libros\n";
    cout << "4. Consultar estudiantes\n";
    cout << "5. Modificar libro\n";
    cout << "6. Eliminar libro\n";
    cout << "7. Modificar estudiante\n";
    cout << "8. Eliminar estudiante\n";
    cout << "9. Registrar préstamo\n";
    cout << "10. Devolver libro\n";
    cout << "11. Agregar Stock a un Libro\n";
    cout << "12. Salir";
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
        } else if (buscarLibro(nuevoLibro.codigo) != -1) {
            cout << "[ERROR] El código del libro ya está registrado (repetido).\n";
        }
    } while (nuevoLibro.codigo.empty() || buscarLibro(nuevoLibro.codigo) != -1);

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
            case 1: nuevoLibro.categoria = "Ficción"; break;
            case 2: nuevoLibro.categoria = "No Ficción"; break;
            case 3: nuevoLibro.categoria = "Ciencia"; break;
            case 4: nuevoLibro.categoria = "Historia"; break;
            case 5: nuevoLibro.categoria = "Tecnología"; break;
            case 6: nuevoLibro.categoria = "Otra"; break;
            default:
                cout << "[ERROR] Debe elegir un número del 1 al 6.\n";
                break;
        }
    } while (opcionCat < 1 || opcionCat > 6);

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
    bool carnetValido = false;

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
        } else if (buscarEstudiante(nuevoEstudiante.carnet) != -1) {
            cout << "[ERROR] El carnet del estudiante ya está registrado (repetido).\n";
        } else {
            carnetValido = true;
        }
    } while (!carnetValido);

    estudiantes.push_back(nuevoEstudiante);

    cout << "\n[INFO] ¡Estudiante registrado exitosamente!\n";

}

void consultarLibros() {
    if (!libros.empty()) {
        cout << "\n=== CONSULTA DE LIBROS REGISTRADOS ===\n";
        cout << "----------------------------------------\n";
        for (int i = 0; i < libros.size(); ++i) {
            cout << "[Libro #" << (i + 1) << "]\n";
            cout << "Código:     " << libros[i].codigo << "\n";
            cout << "Título:     " << libros[i].titulo << "\n";
            cout << "Autor:      " << libros[i].autor << "\n";
            cout << "Año:        " << libros[i].anio << "\n";
            cout << "Categoría:  " << libros[i].categoria << "\n";
            cout << "Ejemplares: " << libros[i].ejemplares << "\n";
            cout << "----------------------------------------\n";
        }
    } else {
        cout << "\n[INFO] No hay libros registrados.\n";
    }
}

void consultarEstudiantes() {
    if (!estudiantes.empty()) {
        cout << "\n=== CONSULTA DE ESTUDIANTES REGISTRADOS ===\n";
        cout << "------------------------------------------\n";
        for (int i = 0; i < estudiantes.size(); ++i) {
            cout << "[Estudiante #" << (i + 1) << "]\n";
            cout << "Nombres:    " << estudiantes[i].nombre << "\n";
            cout << "Apellidos:  " << estudiantes[i].apellidos << "\n";
            cout << "Carnet:     " << estudiantes[i].carnet << "\n";
            cout << "------------------------------------------\n";
        }
    } else {
        cout << "\n[INFO] No hay estudiantes registrados.\n";
    }
}

void modificarLibro() {
    if (libros.empty()) {
        cout << "\n[INFO] No hay libros registrados para modificar.\n";
        return;
    }

    string codigoBusqueda;
    cout << "\n=== MODIFICAR LIBRO ===\n";
    cout << "Ingrese el código del libro a modificar: ";
    getline(cin, codigoBusqueda);

    int indice = buscarLibro(codigoBusqueda);

    if (indice == -1) {
        cout << "\n[ERROR] No se encontró ningún libro con el código proporcionado.\n";
        return;
    }

    cout << "\n--- Ingrese los nuevos datos del libro ---\n";
    Libro libroModificado = libros[indice];

    do {
        cout << "Nuevo título: ";
        getline(cin, libroModificado.titulo);
        if (libroModificado.titulo.empty()) {
            cout << "[ERROR] El título no puede estar vacío.\n";
        }
    } while (libroModificado.titulo.empty());

    do {
        cout << "Nuevo autor: ";
        getline(cin, libroModificado.autor);
        if (libroModificado.autor.empty()) {
            cout << "[ERROR] El autor no puede estar vacío.\n";
        }
    } while (libroModificado.autor.empty());

    do {
        cout << "Nuevo año de publicación: ";
        cin >> libroModificado.anio;
        cin.clear();
        cin.ignore(1000, '\n');
        if (libroModificado.anio <= 0 || libroModificado.anio > anioActual) {
            cout << "[ERROR] Ingrese un año válido.\n";
        }
    } while (libroModificado.anio <= 0 || libroModificado.anio > anioActual);

    do {
        cout << "\nSeleccione la nueva categoría:\n";
        cout << "1. Ficción\n2. No Ficción\n3. Ciencia\n4. Historia\n5. Tecnología\n6. Otra\n";
        cout << "Opción: ";
        cin >> opcionCat;
        cin.clear();
        cin.ignore(1000, '\n');

        switch (opcionCat) {
            case 1: libroModificado.categoria = "Ficción"; break;
            case 2: libroModificado.categoria = "No Ficción"; break;
            case 3: libroModificado.categoria = "Ciencia"; break;
            case 4: libroModificado.categoria = "Historia"; break;
            case 5: libroModificado.categoria = "Tecnología"; break;
            case 6: libroModificado.categoria = "Otra"; break;
            default:
                cout << "[ERROR] Opción no válida.\n";
                break;
        }
    } while (opcionCat < 1 || opcionCat > 6);

    do {
        cout << "Nueva cantidad de ejemplares: ";
        cin >> libroModificado.ejemplares;
        cin.clear();
        cin.ignore(1000, '\n');
        if (libroModificado.ejemplares <= 0) {
            cout << "[ERROR] La cantidad debe ser mayor a cero.\n";
        }
    } while (libroModificado.ejemplares <= 0);

    libros[indice] = libroModificado;

    cout << "\n[INFO] ¡Libro modificado exitosamente!\n";

}

void eliminarLibro() {
    if (libros.empty()) {
        cout << "\n[INFO] No hay libros registrados para eliminar.\n";
        return;
    }

    string codigoBusqueda;
    cout << "\n=== ELIMINAR LIBRO ===\n";
    cout << "Ingrese el código del libro a eliminar: ";
    getline(cin, codigoBusqueda);

    int indice = buscarLibro(codigoBusqueda);

    if (indice == -1) {
        cout << "\n[ERROR] No se encontró ningún libro con el código proporcionado.\n";
        return;
    } else {
        libros.erase(libros.begin() + indice);

        cout << "\n[INFO] ¡Libro eliminado exitosamente!\n";
    }

}

void modificarEstudiante() {
    if (estudiantes.empty()) {
        cout << "\n[INFO] No hay estudiantes registrados para modificar.\n";
        return;
    }

    string carnetBusqueda;
    cout << "\n=== MODIFICAR ESTUDIANTE ===\n";
    cout << "Ingrese el carnet del estudiante a modificar: ";
    getline(cin, carnetBusqueda);

    int indice = buscarEstudiante(carnetBusqueda);

    if (indice == -1) {
        cout << "\n[ERROR] No se encontró ningún estudiante con el carnet proporcionado.\n";
        return;
    }

    cout << "\n--- Ingrese los nuevos datos del estudiante ---\n";
    Estudiante estudianteModificado = estudiantes[indice];

    do {
        cout << "Nuevos nombres: ";
        getline(cin, estudianteModificado.nombre);
        if (estudianteModificado.nombre.empty()) {
            cout << "[ERROR] El nombre no puede estar vacío.\n";
        }
    } while (estudianteModificado.nombre.empty());

    do {
        cout << "Nuevos apellidos: ";
        getline(cin, estudianteModificado.apellidos);
        if (estudianteModificado.apellidos.empty()) {
            cout << "[ERROR] Los apellidos no pueden estar vacíos.\n";
        }
    } while (estudianteModificado.apellidos.empty());

    estudiantes[indice] = estudianteModificado;

    cout << "\n[INFO] ¡Estudiante modificado exitosamente!\n";

}

void eliminarEstudiante() {
    if (estudiantes.empty()) {
        cout << "\n[INFO] No hay estudiantes registrados para eliminar.\n";
        return;
    }

    string carnetBusqueda;
    cout << "\n=== ELIMINAR ESTUDIANTE ===\n";
    cout << "Ingrese el carnet del estudiante a eliminar: ";
    getline(cin, carnetBusqueda);

    int indice = buscarEstudiante(carnetBusqueda);

    if (indice == -1) {
        cout << "\n[ERROR] No se encontró ningún estudiante con el carnet proporcionado.\n";
        return;
    } else {
        estudiantes.erase(estudiantes.begin() + indice);

        cout << "\n[INFO] ¡Estudiante eliminado exitosamente!\n";
    }

}

void realizarPrestamo() {
    if (estudiantes.empty() || libros.empty()) {
        cout << "\n[INFO] No hay estudiantes o libros para realizar el préstamo.\n";
        return;
    }

    cout << "\n=== REGISTRAR PRÉSTAMO ===\n";
    string carnetBusqueda, codigoBusqueda;

    do {
        cout << "Ingrese el carnet del estudiante: ";
        getline(cin, carnetBusqueda);

        if (carnetBusqueda.empty()) {
            cout << "[ERROR] El carnet no puede estar vacío.\n";
        }
    } while (carnetBusqueda.empty());

    do {
        cout << "Ingrese el código del libro: ";
        getline(cin, codigoBusqueda);

        if (codigoBusqueda.empty()) {
            cout << "[ERROR] El código no puede estar vacío.\n";
        }
    } while (codigoBusqueda.empty());

    int indiceEstudiante = buscarEstudiante(carnetBusqueda);
    int indiceLibro = buscarLibro(codigoBusqueda);

    if (indiceEstudiante == -1 || indiceLibro == -1) {
        cout << "\n[ERROR] No se encontró al estudiante o al libro con los datos proporcionados.\n";
        return;
    }

    if (libros[indiceLibro].ejemplares <= 0) {
        cout << "\n[ERROR] No hay ejemplares disponibles de '" << libros[indiceLibro].titulo << "'.\n";
        return;
    }

    if (buscarPrestamo(carnetBusqueda, codigoBusqueda) != -1) {
        cout << "\n[ERROR] El estudiante ya tiene un préstamo activo de este libro.\n";
        return;
    }

    Prestamo nuevoPrestamo;
    nuevoPrestamo.carnet = carnetBusqueda;
    nuevoPrestamo.codigoLibro = codigoBusqueda;
    prestamos.push_back(nuevoPrestamo);

    // Restamos un ejemplar disponible al prestar el libro
    libros[indiceLibro].ejemplares--;

    cout << "\n[INFO] ¡Préstamo registrado exitosamente!\n";
    cout << "-----------------------------------------\n";
    cout << "Estudiante: \n";
    cout << "Nombres:   " << estudiantes[indiceEstudiante].nombre << "\n";
    cout << "Apellidos: " << estudiantes[indiceEstudiante].apellidos << "\n";
    cout << "Carnet:    " << estudiantes[indiceEstudiante].carnet;
    cout << "\n-----------------------------------------\n";
    cout << "Libro: \n";
    cout << "Título:     " << libros[indiceLibro].titulo << "\n";
    cout << "Código:     " << libros[indiceLibro].codigo << "\n";
    cout << "Autor:      " << libros[indiceLibro].autor << "\n";
    cout << "Año:        " << libros[indiceLibro].anio << "\n";
    cout << "Categoría:  " << libros[indiceLibro].categoria << "\n";
    cout << "Ejemplares disponibles: " << libros[indiceLibro].ejemplares;
    cout << "\n-----------------------------------------\n";

}

void devolverLibro() {
    if (prestamos.empty()) {
        cout << "\n[INFO] No hay préstamos activos para devolver.\n";
        return;
    }

    cout << "\n=== DEVOLUCIÓN DE LIBRO ===\n";
    string carnetBusqueda, codigoBusqueda;

    do {
        cout << "Ingrese el carnet del estudiante: ";
        getline(cin, carnetBusqueda);

        if (carnetBusqueda.empty()) {
            cout << "[ERROR] El carnet no puede estar vacío.\n";
        }
    } while (carnetBusqueda.empty());

    do {
        cout << "Ingrese el código del libro a devolver: ";
        getline(cin, codigoBusqueda);

        if (codigoBusqueda.empty()) {
            cout << "[ERROR] El código no puede estar vacío.\n";
        }
    } while (codigoBusqueda.empty());

    int indicePrestamo = buscarPrestamo(carnetBusqueda, codigoBusqueda);

    if (indicePrestamo == -1) {
        cout << "\n[ERROR] No existe un préstamo activo con el carnet y código proporcionados.\n";
        return;
    }

    int indiceEstudiante = buscarEstudiante(carnetBusqueda);
    int indiceLibro = buscarLibro(codigoBusqueda);

    prestamos.erase(prestamos.begin() + indicePrestamo);

    cout << "\n[INFO] ¡Libro devuelto exitosamente!\n";
    if (indiceEstudiante != -1) {
        cout << "Estudiante: " << estudiantes[indiceEstudiante].nombre << " " << estudiantes[indiceEstudiante].apellidos << "\n";
    }
    if (indiceLibro != -1) {
        // Sumamos el ejemplar devuelto al stock disponible
        libros[indiceLibro].ejemplares++;
        cout << "Libro:      " << libros[indiceLibro].titulo << " (Código: " << libros[indiceLibro].codigo << ")\n";
        cout << "Ejemplares actuales disponibles: " << libros[indiceLibro].ejemplares << "\n";
    }

}

void agregarStock() {
    if (libros.empty()) {
        cout << "\n[INFO] No hay libros registrados para gestionar stock.\n";
        return;
    }

    string codigoBusqueda;
    cout << "\n=== AGREGAR STOCK A UN LIBRO ===\n";
    cout << "Ingrese el código del libro: ";
    getline(cin, codigoBusqueda);

    int indice = buscarLibro(codigoBusqueda);

    if (indice == -1) {
        cout << "\n[ERROR] No se encontró ningún libro con el código proporcionado.\n";
        return;
    } else {
        int nuevosEjemplares = 0;
        cout << "\nLibro encontrado: " << libros[indice].titulo << "\n";
        cout << "Stock actual: " << libros[indice].ejemplares << " ejemplares.\n";

        do {
            cout << "\nIngrese la cantidad de libros nuevos a agregar al stock: ";
            cin >> nuevosEjemplares;
            cin.clear();
            cin.ignore(1000, '\n');

            if (nuevosEjemplares <= 0) {
                cout << "[ERROR] La cantidad a agregar debe ser mayor a cero.\n";
            }
        } while (nuevosEjemplares <= 0);

        libros[indice].ejemplares += nuevosEjemplares;

        cout << "\n[INFO] ¡Stock actualizado exitosamente!\n";
        cout << "El nuevo stock de '" << libros[indice].titulo << "' es de " << libros[indice].ejemplares << " ejemplares.\n";
    }

}
