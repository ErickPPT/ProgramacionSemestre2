#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 3
#define DATA "actualizable.txt"

void ingresarDatos();
void imprimirDatos();
void menu();
int ingresoentero(char* mensaje, int min, int max);
int codigounico(int codigo);
float promedio(float notas[3]);
void buscarEstudiante();
void editarEstudiante();
void borrarEstudiante();

struct Estudiante {
    char nombre[100];
    int codigo;
    float notas[3];
};

int ingresoentero(char* mensaje, int min, int max) {
    int valor;
    printf("%s", mensaje);
    while (scanf("%d", &valor) != 1 || valor < min || valor > max) {
        printf("Error, ingrese datos válidos\n");
        while (getchar() != '\n');
        printf("%s", mensaje);
    }
    while (getchar() != '\n');
    return valor;
}

int codigounico(int codigo) {
    FILE *datos = fopen(DATA, "r");
    if (datos == NULL) {
        return ingresoentero("Ingrese el codigo del estudiante: ", 0, 9999);
    }

    struct Estudiante estudiante;
    int valido = 0;
    while (!valido) {
        codigo = ingresoentero("Ingrese el codigo del estudiante: ", 0, 9999);
        valido = 1;
        while (fscanf(datos, "%d %s %f %f %f", &estudiante.codigo, estudiante.nombre,
                      &estudiante.notas[0], &estudiante.notas[1], &estudiante.notas[2]) == 5) {
            if (estudiante.codigo == codigo) {
                printf("El codigo ya existe, ingrese otro codigo\n");
                valido = 0;
                break;
            }
        }
        rewind(datos); // Reiniciar la lectura del archivo
    }
    fclose(datos);
    return codigo;
}

void ingresarDatos() {
    FILE *datos = fopen(DATA, "a"); // Abrir archivo en modo agregar texto
    if (datos == NULL) {
        printf("No se pudo abrir el archivo");
        return;
    }
    fprintf(datos, "%10s%10s%10s%10s%10s%10s\n", "Codigo", "Nombre", "Nota1", "Nota2", "Nota3", "Promedio");
    for (int i = 0; i < MAX; i++) {
        struct Estudiante estudiante;
        memset(&estudiante, 0, sizeof(struct Estudiante)); // Inicializar estructura

        printf("Datos del estudiante %d\n", i + 1);
        estudiante.codigo = codigounico(0);
        printf("Ingrese el nombre del estudiante: ");
        scanf("%s", estudiante.nombre);
        for (int j = 0; j < 3; j++) {
            estudiante.notas[j] = ingresoentero("Ingrese la nota del estudiante: ", 0, 10);
        }
        float promedio_notas = promedio(estudiante.notas);
        // Escribir datos en formato texto
        fprintf(datos, "%10d%10s%10.2f%10.2f%10.2f%10.2f\n", estudiante.codigo, estudiante.nombre,
                estudiante.notas[0], estudiante.notas[1], estudiante.notas[2], promedio_notas);
    }

    fclose(datos);
}

void imprimirDatos() {
    FILE *datos = fopen(DATA, "r"); // Abrir archivo en modo lectura texto
    if (datos == NULL) {
        printf("No se pudo abrir el archivo");
        return;
    }

    struct Estudiante estudiante;
    float promedio_archivo;
    char buffer[256];
    fgets(buffer, sizeof(buffer), datos);

    printf("%10s%10s%10s%10s%10s%10s\n", "Codigo", "Nombre", "Nota1", "Nota2", "Nota3", "Promedio");

    while (fscanf(datos, "%d %s %f %f %f %f", &estudiante.codigo, estudiante.nombre,
                  &estudiante.notas[0], &estudiante.notas[1], &estudiante.notas[2], &promedio_archivo) == 6) {
        printf("%10d%10s", estudiante.codigo, estudiante.nombre);
        for (int j = 0; j < 3; j++) {
            printf("%10.2f", estudiante.notas[j]);
        }
        printf("%10.2f\n", promedio(estudiante.notas));
    }

    fclose(datos);
}

float promedio(float notas[3]) {
    float suma = 0;
    for (int i = 0; i < 3; i++) {
        suma += notas[i];
    }
    return suma / 3;
}

void buscarEstudiante() {
    FILE *datos = fopen(DATA, "r"); // Abrir archivo en modo lectura texto
    if (datos == NULL) {
        printf("No se pudo abrir el archivo\n");
        return;
    }

    struct Estudiante estudiante;
    int codigo_buscado = ingresoentero("Ingrese el codigo del estudiante a buscar: ", 0, 9999);

    while (fscanf(datos, "%d %s %f %f %f", &estudiante.codigo, estudiante.nombre,
                  &estudiante.notas[0], &estudiante.notas[1], &estudiante.notas[2]) == 5) {
        if (estudiante.codigo == codigo_buscado) {
            printf("Estudiante encontrado:\n");
            printf("Codigo: %d\n", estudiante.codigo);
            printf("Nombre: %s\n", estudiante.nombre);
            printf("Notas: %.2f, %.2f, %.2f\n", estudiante.notas[0], estudiante.notas[1], estudiante.notas[2]);
            printf("Promedio: %.2f\n", promedio(estudiante.notas));
            fclose(datos);
            return;
        }
    }

    printf("No se encontro el estudiante con el codigo %d\n", codigo_buscado);
    fclose(datos);
}
void editarEstudiante() {
    FILE *datos = fopen(DATA, "r");
    if (datos == NULL) {
        printf("No se pudo abrir el archivo\n");
        return;
    }

    struct Estudiante estudiantes_temp[MAX];
    float promedios[MAX];
    int total = 0;

    char buffer[256];
    fgets(buffer, sizeof(buffer), datos); // Saltar cabecera

    while (fscanf(datos, "%d %s %f %f %f %f",
                  &estudiantes_temp[total].codigo,
                  estudiantes_temp[total].nombre,
                  &estudiantes_temp[total].notas[0],
                  &estudiantes_temp[total].notas[1],
                  &estudiantes_temp[total].notas[2],
                  &promedios[total]) == 6) {
        total++;
    }
    fclose(datos);

    int codigo_buscado = ingresoentero("Ingrese el codigo del estudiante a editar: ", 0, 9999);
    int index = -1;

    for (int i = 0; i < total; i++) {
        if (estudiantes_temp[i].codigo == codigo_buscado) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("No se encontró el estudiante con el código %d.\n", codigo_buscado);
        return;
    }

    printf("Editar datos del estudiante (deje igual si no desea cambiar):\n");
    printf("Nombre actual: %s\n", estudiantes_temp[index].nombre);
    printf("Ingrese el nuevo nombre: ");
    scanf("%s", estudiantes_temp[index].nombre);

    for (int j = 0; j < 3; j++) {
        printf("Nota %d actual: %.2f\n", j + 1, estudiantes_temp[index].notas[j]);
        estudiantes_temp[index].notas[j] = ingresoentero("Ingrese la nueva nota: ", 0, 10);
    }
    promedios[index] = promedio(estudiantes_temp[index].notas);

    datos = fopen(DATA, "w");
    if (datos == NULL) {
        printf("No se pudo abrir el archivo\n");
        return;
    }
    fprintf(datos, "%10s%10s%10s%10s%10s%10s\n", "Codigo", "Nombre", "Nota1", "Nota2", "Nota3", "Promedio");

    for (int i = 0; i < total; i++) {
        fprintf(datos, "%10d%10s%10.2f%10.2f%10.2f%10.2f\n",
            estudiantes_temp[i].codigo,
            estudiantes_temp[i].nombre,
            estudiantes_temp[i].notas[0],
            estudiantes_temp[i].notas[1],
            estudiantes_temp[i].notas[2],
            promedios[i]);
    }

    fclose(datos);
    printf("Estudiante con código %d editado exitosamente.\n", codigo_buscado);
}

void borrarEstudiante() {
    FILE *datos = fopen(DATA, "r"); // Abrir archivo en modo lectura texto
    if (datos == NULL) {
        printf("No se pudo abrir el archivo\n");
        return;
    }

    struct Estudiante estudiantes_temp[MAX];
    float promedios[MAX];
    int total = 0;

    char buffer[256];
    fgets(buffer, sizeof(buffer), datos);

    while (fscanf(datos, "%d %s %f %f %f %f", &estudiantes_temp[total].codigo, estudiantes_temp[total].nombre,
                  &estudiantes_temp[total].notas[0], &estudiantes_temp[total].notas[1],
                  &estudiantes_temp[total].notas[2], &promedios[total]) == 6) {
        total++;
    }
    fclose(datos);

    int codigo_buscado = ingresoentero("Ingrese el codigo del estudiante a borrar: ", 0, 9999);
    int index = -1;

    for (int i = 0; i < total; i++) {
        if (estudiantes_temp[i].codigo == codigo_buscado) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("No se encontró el estudiante con el código %d.\n", codigo_buscado);
        return;
    }

    datos = fopen(DATA, "w"); // Abrir archivo en modo escritura texto
    if (datos == NULL) {
        printf("No se pudo abrir el archivo\n");
        return;
    }
    fprintf(datos, "%10s%10s%10s%10s%10s%10s\n", "Codigo", "Nombre", "Nota1", "Nota2", "Nota3", "Promedio");

    for (int i = 0; i < total; i++) {
        if (i != index) {
            fprintf(datos, "%10d%10s%10.2f%10.2f%10.2f%10.2f\n",
                estudiantes_temp[i].codigo,
                estudiantes_temp[i].nombre,
                estudiantes_temp[i].notas[0],
                estudiantes_temp[i].notas[1],
                estudiantes_temp[i].notas[2],
                promedios[i]);
        }
    }

    fclose(datos);
    printf("Estudiante con código %d borrado exitosamente.\n", codigo_buscado);
}

void menu() {
    int opcion;
    do {
        printf("Menu:\n");
        printf("1. Ingresar datos de estudiantes\n");
        printf("2. Buscar estudiante por su ID\n");
        printf("3. Borrar estudiante por su ID\n");
        printf("4. Editar estudiante por su ID\n");
        printf("5. Imprimir datos de estudiantes\n");
        printf("6. Salir\n");
        opcion = ingresoentero("Seleccione una opcion: ", 1, 6);
        switch (opcion) {
            case 1:
                ingresarDatos();
                break;
            case 2:
                buscarEstudiante();
                break;
            case 3:
                borrarEstudiante();
                break;
            case 4:
                editarEstudiante();
                break;
            case 5:
                imprimirDatos();
                break;
            case 6:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 6);
}

int main(int argc, char const *argv[]) {
    menu();
    return 0;
}
