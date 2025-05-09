#include<stdio.h>
#include<string.h>
#include"funciones.h"
#define MAXIMO 10
#define MINIMO 0

int IngresarCantidad(char*mensaje, int minimo, int maximo){
    int cantidad;
    printf("%s", mensaje);
    while(scanf("%d", &cantidad)!=1 || cantidad >MAXIMO || cantidad < MINIMO){
        printf("Error, ingrese datos validos\n");
        while(getchar()!='\n');
        printf("%s", mensaje);
    }
    while (getchar() != '\n');
    return cantidad;
    
}
float IngresarPrecio(char*mensaje){
    float precio;
    printf("%s", mensaje);
    while(scanf("%f", &precio)!=1 ||precio < MINIMO){
        printf("Error, ingrese datos validos\n");
        while(getchar()!='\n');
        printf("%s", mensaje);
    }
    while (getchar() != '\n');
    return precio;
}
void IngresarProductos (char*mensaje, char cadena[], int longitud){
    printf("%s", mensaje);
    fgets(cadena, longitud, stdin);
    cadena[strcspn(cadena, "\n")] = '\0';
    
}

float CalcularTotal(float precios[10], int cantidad){
    float total=0;
    for (int i = 0; i < cantidad; i++)
    {
        total+=precios[i];
    }
    return total;
}
float CalcularPromedio(float precios[10], int cantidad){
    float promedio=0;
    for (int i = 0; i < cantidad; i++)
    {
        promedio+=precios[i];
    }
    return promedio/cantidad;
    
}
int MostrarMasBarato(float precios[10], int cantidad){
    int Min=0;
    for (int i = 1; i < cantidad; i++)
    {
        if(precios[i]<precios[Min]){
            Min=i;
        }
    }
    return Min;
}
int MostrarMasCaro(float precios[10], int cantidad){
    float Max=precios[0];
    for (int i = 1; i < cantidad; i++)
    {
        if(precios[i]>Max){
            Max=i;
        }
    }
    return Max;
}
void EncontrarProducto(char nombres[][30], float precios[10], int cantidad, char NombreBuscado[]){
    IngresarProductos("Ingrese el nombre del producto a buscar:\n", NombreBuscado, 30);
    for (int i = 0; i < cantidad; i++)
    {
        if(strcmp(nombres[i], NombreBuscado)==0){
            printf("El producto %s tiene un precio de %.2f\n", nombres[i], precios[i]);
        } 
            printf("El producto %s no se encuentra en la lista\n", nombres[i]);
    
    }
    
}