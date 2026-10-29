#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <windows.h>

using namespace std;

int opcion, opcionCat;
int totalLibros = 0;
int totalEstudiantes = 0;
int anioActual = 2026;

vector<string> libroCodigo;
vector<string> libroTitulo;
vector<string> libroAutor;
vector<int> libroAnio;
vector<string> libroCategoria;
vector<int> libroEjemplares;

vector<string> estudianteNombre;
vector<string> estudianteApellidos;
vector<string> estudianteCarnet;

void mostrarMenu();
void registrarLibro();
void registrarEstudiante();
void consultarLibros();
void consultarEstudiantes();
void buscarPrestamo();
void modificarLibro();
void eliminarLibro();
void modificarEstudiante();
void eliminarEstudiante();
void agregarStock(); 

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    do {
        mostrarMenu();

        cout << "Seleccione una opción (1-11): ";
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
                modificarLibro();
                break;
            case 6:
                eliminarLibro();
                break;
            case 7:
                modificarEstudiante();
                break;
            case 8:
                eliminarEstudiante();
                break;
            case 9:
                buscarPrestamo();
                break;
            case 10:
                agregarStock(); // NUEVO: Llamada a la función de stock
                break;
            case 11:
                cout << "\n[INFO] Saliendo del sistema...\n";
                break;
            default:
                cout << "\n[ERROR] Opción no válida.\n";
                system("pause");
                system("cls");
        }
    } while (opcion != 11); // Modificado para salir con 11
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
    cout << "9. Buscar préstamo\n";
    cout << "10. Agregar Stock a un Libro\n"; 
    cout << "11. Salir";
    cout << "\n========================================\n";
}

void registrarLibro() {
    inicioRegistrarLibro:
    cout << "\n=== REGISTRO DE NUEVO LIBRO ===\n";
    string codigo, titulo, autor, categoria;
    int anio = 0;
    int ejemplares = 0;
    bool codigoRepetido = false;

    do {
        codigoRepetido = false;
        cout << "Ingrese el código del libro: ";
        getline(cin, codigo);

        if (codigo.empty()) {
            cout << "[ERROR] El código no puede estar vacío.\n";
            system("pause");
            system("cls");
            goto inicioRegistrarLibro;
        } else {
            for (int i = 0; i < totalLibros; ++i) {
                if (libroCodigo[i] == codigo) {
                    cout << "[ERROR] El código del libro ya está registrado (repetido).\n";
                    codigoRepetido = true;
                    system("pause");
                    system("cls");
                    goto inicioRegistrarLibro;
                }
            }
        }
    } while (codigo.empty() || codigoRepetido);

    do {
        cout << "Ingrese el título: ";
        getline(cin, titulo);

        if (titulo.empty()) {
            cout << "[ERROR] El título no puede estar vacío.\n";
            system("pause");
            system("cls");
            goto inicioRegistrarLibro;
        }
    } while (titulo.empty());

    do {
        cout << "Ingrese el autor: ";
        getline(cin, autor);

        if (autor.empty()) {
            cout << "[ERROR] El autor no puede estar vacío.\n";
            system("pause");
            system("cls");
            goto inicioRegistrarLibro;
        }
    } while (autor.empty());

    do {
        cout << "Ingrese el año de publicación: ";
        cin >> anio;
        cin.clear();
        cin.ignore(1000, '\n');

        if (anio <= 0 || anio > anioActual) {
            cout << "[ERROR] Ingrese un año válido (entre 1 y " << anioActual << ").\n";
            system("pause");
            system("cls");
            goto inicioRegistrarLibro;
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
                system("pause");
                system("cls");
                goto inicioRegistrarLibro;
        }
    } while (opcionCat < 1 || opcionCat > 6);

    do {
        cout << "Ingrese la cantidad de ejemplares: ";
        cin >> ejemplares;
        cin.clear();
        cin.ignore(1000, '\n');

        if (ejemplares <= 0) {
            cout << "[ERROR] La cantidad debe ser mayor a cero.\n";
            system("pause");
            system("cls");
            goto inicioRegistrarLibro;
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

    system("pause");
    system("cls");
}

void registrarEstudiante() {
    inicioRegistrarEstudiante:
    cout << "\n=== REGISTRO DE NUEVO ESTUDIANTE ===\n";
    string nombre, apellidos, carnet;
    bool carnetRepetido = false;

    do {
        cout << "Ingrese los nombres del estudiante: ";
        getline(cin, nombre);

        if (nombre.empty()) {
            cout << "[ERROR] El nombre no puede estar vacío.\n";
            system("pause");
            system("cls");
            goto inicioRegistrarEstudiante;
        }
    } while (nombre.empty());

    do {
        cout << "Ingrese los apellidos del estudiante: ";
        getline(cin, apellidos);

        if (apellidos.empty()) {
            cout << "[ERROR] Los apellidos no pueden estar vacíos.\n";
            system("pause");
            system("cls");
            goto inicioRegistrarEstudiante;
        }
    } while (apellidos.empty());

    do {
        carnetRepetido = false;
        cout << "Ingrese el carnet del estudiante: ";
        getline(cin, carnet);

        if (carnet.empty()) {
            cout << "[ERROR] El carnet no puede estar vacío.\n";
            system("pause");
            system("cls");
            goto inicioRegistrarEstudiante;
        } else {
            for (int i = 0; i < totalEstudiantes; ++i) {
                if (estudianteCarnet[i] == carnet) {
                    cout << "[ERROR] El carnet del estudiante ya está registrado (repetido).\n";
                    carnetRepetido = true;
                    system("pause");
                    system("cls");
                    goto inicioRegistrarEstudiante;
                }
            }
        }
    } while (carnet.empty() || carnetRepetido);

    estudianteNombre.push_back(nombre);
    estudianteApellidos.push_back(apellidos);
    estudianteCarnet.push_back(carnet);
    totalEstudiantes++;

    cout << "\n[INFO] ¡Estudiante registrado exitosamente!\n";

    system("pause");
    system("cls");
}

void consultarLibros() {
    if (totalLibros > 0) {
        cout << "\n=== CONSULTA DE LIBROS REGISTRADOS ===\n";
        cout << "----------------------------------------\n";
        for (int i = 0; i < totalLibros; ++i) {
            cout << "[Libro #" << (i + 1) << "]\n";
            cout << "Código:     " << libroCodigo[i] << "\n";
            cout << "Título:     " << libroTitulo[i] << "\n";
            cout << "Autor:      " << libroAutor[i] << "\n";
            cout << "Año:        " << libroAnio[i] << "\n";
            cout << "Categoría:  " << libroCategoria[i] << "\n";
            cout << "Ejemplares: " << libroEjemplares[i] << "\n";
            cout << "----------------------------------------\n";
        } 
    } else {
        cout << "\n[INFO] No hay libros registrados.\n";
    }
    system("pause");
    system("cls");
}

void consultarEstudiantes() {
    if (totalEstudiantes > 0) {
        cout << "\n=== CONSULTA DE ESTUDIANTES REGISTRADOS ===\n";
        cout << "------------------------------------------\n";
        for (int i = 0; i < totalEstudiantes; ++i) {
            cout << "[Estudiante #" << (i + 1) << "]\n";
            cout << "Nombres:    " << estudianteNombre[i] << "\n";
            cout << "Apellidos:  " << estudianteApellidos[i] << "\n";
            cout << "Carnet:     " << estudianteCarnet[i] << "\n";
            cout << "------------------------------------------\n";
        }
    } else {
        cout << "\n[INFO] No hay estudiantes registrados.\n";
    }
    system("pause");
    system("cls");
}

void modificarLibro() {
    if (totalLibros == 0) {
        cout << "\n[INFO] No hay libros registrados para modificar.\n";
        system("pause");
        system("cls");
        return;
    }

    inicioModificarLibro:
    string codigoBusqueda;
    cout << "\n=== MODIFICAR LIBRO ===\n";
    cout << "Ingrese el código del libro a modificar: ";
    getline(cin, codigoBusqueda);

    int indice = -1;
    for (int i = 0; i < totalLibros; ++i) {
        if (libroCodigo[i] == codigoBusqueda) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        cout << "\n[ERROR] No se encontró ningún libro con el código proporcionado.\n";
        system("pause");
        system("cls");
        goto inicioModificarLibro;
    } else {
        cout << "\n--- Ingrese los nuevos datos del libro ---\n";

        do {
            cout << "Nuevo título: ";
            getline(cin, libroTitulo[indice]);
            if (libroTitulo[indice].empty()) {
                cout << "[ERROR] El título no puede estar vacío.\n";
                system("pause");
                system("cls");
                goto inicioModificarLibro;
            }
        } while (libroTitulo[indice].empty());

        do {
            cout << "Nuevo autor: ";
            getline(cin, libroAutor[indice]);
            if (libroAutor[indice].empty()) {
                cout << "[ERROR] El autor no puede estar vacío.\n";
                system("pause");
                system("cls");
                goto inicioModificarLibro;
            }
        } while (libroAutor[indice].empty());

        do {
            cout << "Nuevo año de publicación: ";
            cin >> libroAnio[indice];
            cin.clear();
            cin.ignore(1000, '\n');
            if (libroAnio[indice] <= 0 || libroAnio[indice] > anioActual) {
                cout << "[ERROR] Ingrese un año válido.\n";
                system("pause");
                system("cls");
                goto inicioModificarLibro;
            }
        } while (libroAnio[indice] <= 0 || libroAnio[indice] > anioActual);

        do {
            cout << "\nSeleccione la nueva categoría:\n";
            cout << "1. Ficción\n2. No Ficción\n3. Ciencia\n4. Historia\n5. Tecnología\n6. Otra\n";
            cout << "Opción: ";
            cin >> opcionCat;
            cin.clear();
            cin.ignore(1000, '\n');

            switch (opcionCat) {
                case 1: libroCategoria[indice] = "Ficción"; break;
                case 2: libroCategoria[indice] = "No Ficción"; break;
                case 3: libroCategoria[indice] = "Ciencia"; break;
                case 4: libroCategoria[indice] = "Historia"; break;
                case 5: libroCategoria[indice] = "Tecnología"; break;
                case 6: libroCategoria[indice] = "Otra"; break;
                default: 
                    cout << "[ERROR] Opción no válida.\n"; 
                    system("pause");
                    system("cls");
                    goto inicioModificarLibro;
            }
        } while (opcionCat < 1 || opcionCat > 6);

        do {
            cout << "Nueva cantidad de ejemplares: ";
            cin >> libroEjemplares[indice];
            cin.clear();
            cin.ignore(1000, '\n');
            if (libroEjemplares[indice] <= 0) {
                cout << "[ERROR] La cantidad debe ser mayor a cero.\n";
                system("pause");
                system("cls");
                goto inicioModificarLibro;
            }
        } while (libroEjemplares[indice] <= 0);

        cout << "\n[INFO] ¡Libro modificado exitosamente!\n";
    }

    system("pause");
    system("cls");
}

void eliminarLibro() {
    if (totalLibros == 0) {
        cout << "\n[INFO] No hay libros registrados para eliminar.\n";
        system("pause");
        system("cls");
        return;
    }

    inicioEliminarLibro:
    string codigoBusqueda;
    cout << "\n=== ELIMINAR LIBRO ===\n";
    cout << "Ingrese el código del libro a eliminar: ";
    getline(cin, codigoBusqueda);

    int indice = -1;
    for (int i = 0; i < totalLibros; ++i) {
        if (libroCodigo[i] == codigoBusqueda) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        cout << "\n[ERROR] No se encontró ningún libro con el código proporcionado.\n";
        system("pause");
        system("cls");
        goto inicioEliminarLibro;
    } else {
        libroCodigo.erase(libroCodigo.begin() + indice);
        libroTitulo.erase(libroTitulo.begin() + indice);
        libroAutor.erase(libroAutor.begin() + indice);
        libroAnio.erase(libroAnio.begin() + indice);
        libroCategoria.erase(libroCategoria.begin() + indice);
        libroEjemplares.erase(libroEjemplares.begin() + indice);
        totalLibros--;

        cout << "\n[INFO] ¡Libro eliminado exitosamente!\n";
    }

    system("pause");
    system("cls");
}

void modificarEstudiante() {
    if (totalEstudiantes == 0) {
        cout << "\n[INFO] No hay estudiantes registrados para modificar.\n";
        system("pause");
        system("cls");
        return;
    }

    inicioModificarEstudiante:
    string carnetBusqueda;
    cout << "\n=== MODIFICAR ESTUDIANTE ===\n";
    cout << "Ingrese el carnet del estudiante a modificar: ";
    getline(cin, carnetBusqueda);

    int indice = -1;
    for (int i = 0; i < totalEstudiantes; ++i) {
        if (estudianteCarnet[i] == carnetBusqueda) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        cout << "\n[ERROR] No se encontró ningún estudiante con el carnet proporcionado.\n";
        system("pause");
        system("cls");
        goto inicioModificarEstudiante;
    } else {
        cout << "\n--- Ingrese los nuevos datos del estudiante ---\n";

        do {
            cout << "Nuevos nombres: ";
            getline(cin, estudianteNombre[indice]);
            if (estudianteNombre[indice].empty()) {
                cout << "[ERROR] El nombre no puede estar vacío.\n";
                system("pause");
                system("cls");
                goto inicioModificarEstudiante;
            }
        } while (estudianteNombre[indice].empty());

        do {
            cout << "Nuevos apellidos: ";
            getline(cin, estudianteApellidos[indice]);
            if (estudianteApellidos[indice].empty()) {
                cout << "[ERROR] Los apellidos no pueden estar vacíos.\n";
                system("pause");
                system("cls");
                goto inicioModificarEstudiante;
            }
        } while (estudianteApellidos[indice].empty());

        cout << "\n[INFO] ¡Estudiante modificado exitosamente!\n";
    }

    system("pause");
    system("cls");
}

void eliminarEstudiante() {
    if (totalEstudiantes == 0) {
        cout << "\n[INFO] No hay estudiantes registrados para eliminar.\n";
        system("pause");
        system("cls");
        return;
    }

    inicioEliminarEstudiante:
    string carnetBusqueda;
    cout << "\n=== ELIMINAR ESTUDIANTE ===\n";
    cout << "Ingrese el carnet del estudiante a eliminar: ";
    getline(cin, carnetBusqueda);

    int indice = -1;
    for (int i = 0; i < totalEstudiantes; ++i) {
        if (estudianteCarnet[i] == carnetBusqueda) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        cout << "\n[ERROR] No se encontró ningún estudiante con el carnet proporcionado.\n";
        system("pause");
        system("cls");
        goto inicioEliminarEstudiante;
    } else {
        estudianteNombre.erase(estudianteNombre.begin() + indice);
        estudianteApellidos.erase(estudianteApellidos.begin() + indice);
        estudianteCarnet.erase(estudianteCarnet.begin() + indice);
        totalEstudiantes--;

        cout << "\n[INFO] ¡Estudiante eliminado exitosamente!\n";
    }

    system("pause");
    system("cls");
}

void buscarPrestamo() {
    if (totalEstudiantes == 0 || totalLibros == 0) {
        cout << "\n[INFO] No hay estudiantes o libros registrados para realizar la búsqueda.\n";
        system("pause");
        system("cls");
        return;
    }
    
    inicioBusquedaPrestamo:
    cout << "\n=== BÚSQUEDA DE PRÉSTAMO ===\n";
    string carnetBusqueda, codigoBusqueda;

    do {
        cout << "Ingrese el carnet del estudiante: ";
        getline(cin, carnetBusqueda);

        if (carnetBusqueda.empty()) {
            cout << "[ERROR] El carnet no puede estar vacío.\n";
            system("pause");
            system("cls");
            goto inicioBusquedaPrestamo;
        }
    } while (carnetBusqueda.empty());

    do {
        cout << "Ingrese el código del libro: ";
        getline(cin, codigoBusqueda);

        if (codigoBusqueda.empty()) {
            cout << "[ERROR] El código no puede estar vacío.\n";
            system("pause");
            system("cls");
            goto inicioBusquedaPrestamo;
        }
    } while (codigoBusqueda.empty());

    int indiceEstudiante = -1;
    for (int i = 0; i < totalEstudiantes; ++i) {
        if (estudianteCarnet[i] == carnetBusqueda) {
            indiceEstudiante = i;
            break;
        }
    }

    int indiceLibro = -1;
    for (int i = 0; i < totalLibros; ++i) {
        if (libroCodigo[i] == codigoBusqueda) {
            indiceLibro = i;
            break;
        }
    }

    if(indiceEstudiante == -1 || indiceLibro == -1) {
        cout << "\n[INFO] No se encontró el préstamo con los datos proporcionados.\n";
    } else {
        cout << "\n-----------------------------------------\n";
        cout << "Estudiante encontrado: \n";
        cout << "Nombres:   " << estudianteNombre[indiceEstudiante] << "\n";
        cout << "Apellidos: " << estudianteApellidos[indiceEstudiante] << "\n";
        cout << "Carnet:    " << estudianteCarnet[indiceEstudiante];
        cout << "\n-----------------------------------------\n";
        cout << "Libro encontrado: \n";
        cout << "Título:     " << libroTitulo[indiceLibro] << "\n";
        cout << "Código:     " << libroCodigo[indiceLibro] << "\n";
        cout << "Autor:      " << libroAutor[indiceLibro] << "\n";
        cout << "Año:        " << libroAnio[indiceLibro] << "\n";
        cout << "Categoría:  " << libroCategoria[indiceLibro] << "\n";
        cout << "Ejemplares: " << libroEjemplares[indiceLibro];
        cout << "\n-----------------------------------------\n";
    
    }
    
    inicioDevolucionLibro:
    cout << "\n=== DEVOLUCIÓN DE LIBRO ===\n";
    carnetBusqueda = "";
    codigoBusqueda = "";

    do {
        cout << "Ingrese el carnet del estudiante: ";
        getline(cin, carnetBusqueda);

        if (carnetBusqueda.empty()) {
            cout << "[ERROR] El carnet no puede estar vacío.\n";
            system("pause");
            system("cls");
            goto inicioDevolucionLibro;
        }
    } while (carnetBusqueda.empty());

    do {
        cout << "Ingrese el código del libro a devolver: ";
        getline(cin, codigoBusqueda);

        if (codigoBusqueda.empty()) {
            cout << "[ERROR] El código no puede estar vacío.\n";
            system("pause");
            system("cls");
            goto inicioDevolucionLibro;
        }
    } while (codigoBusqueda.empty());

    indiceEstudiante = -1;
    for (int i = 0; i < totalEstudiantes; ++i) {
        if (estudianteCarnet[i] == carnetBusqueda) {
            indiceEstudiante = i;
            break;
        }
    }

    indiceLibro = -1;
    for (int i = 0; i < totalLibros; ++i) {
        if (libroCodigo[i] == codigoBusqueda) {
            indiceLibro = i;
            break;
        }
    }

    if (indiceEstudiante == -1 || indiceLibro == -1) {
        cout << "\n[ERROR] No se encontró al estudiante o al libro con los datos proporcionados.\n";
        system("pause");
        system("cls");
        goto inicioDevolucionLibro;
    } else {
        // Incrementamos los ejemplares disponibles al devolver el libro
        libroEjemplares[indiceLibro]++;
        cout << "\n[INFO] ¡Libro devuelto exitosamente!\n";
        cout << "Estudiante: " << estudianteNombre[indiceEstudiante] << " " << estudianteApellidos[indiceEstudiante] << "\n";
        cout << "Libro:      " << libroTitulo[indiceLibro] << " (Código: " << libroCodigo[indiceLibro] << ")\n";
        cout << "Ejemplares actuales disponibles: " << libroEjemplares[indiceLibro] << "\n";
}
    system("pause");
    system("cls");
}


void agregarStock() {
    if (totalLibros == 0) {
        cout << "\n[INFO] No hay libros registrados para gestionar stock.\n";
        system("pause");
        system("cls");
        return;
    }

    inicioAgregarStock:
    string codigoBusqueda;
    cout << "\n=== AGREGAR STOCK A UN LIBRO ===\n";
    cout << "Ingrese el código del libro: ";
    getline(cin, codigoBusqueda);

    int indice = -1;
   
    for (int i = 0; i < totalLibros; ++i) {
        if (libroCodigo[i] == codigoBusqueda) {
            indice = i;
            break;
        }
    }

   
    if (indice == -1) {
        cout << "\n[ERROR] No se encontró ningún libro con el código proporcionado.\n";
        system("pause");
        system("cls");
        goto inicioAgregarStock;
    } else {
        int nuevosEjemplares = 0;
        cout << "\nLibro encontrado: " << libroTitulo[indice] << "\n";
        cout << "Stock actual: " << libroEjemplares[indice] << " ejemplares.\n";

        
        do {
            cout << "\nIngrese la cantidad de libros nuevos a agregar al stock: ";
            cin >> nuevosEjemplares;
            cin.clear();
            cin.ignore(1000, '\n');

            if (nuevosEjemplares <= 0) {
                cout << "[ERROR] La cantidad a agregar debe ser mayor a cero.\n";
                system("pause");
                system("cls");
                goto inicioAgregarStock;
            }
        } while (nuevosEjemplares <= 0);

        
        libroEjemplares[indice] += nuevosEjemplares;

        cout << "\n[INFO] ¡Stock actualizado exitosamente!\n";
        cout << "El nuevo stock de '" << libroTitulo[indice] << "' es de " << libroEjemplares[indice] << " ejemplares.\n";
    }

    system("pause");
    system("cls");
}
