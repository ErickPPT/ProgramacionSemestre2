#include"funciones.h"
#include <stdio.h>
# define MAXIMO 10
#define MINIMO 0
int main(int argc, char const *argv[])
{
    char nombres[MAXIMO][30];
    float precios[MAXIMO];
    char NombreBuscado[30];
    int cantidad=0;
    float precio=0;
    cantidad=IngresarCantidad("Ingrese la cantidad de productos (maximo 10):\n", MAXIMO, MINIMO);
    for (int i = 0; i < cantidad; i++)
    {
        char mensajeNombre[50];
        sprintf(mensajeNombre, "Ingrese el nombre del producto %d: ", i + 1); // Construye el mensaje dinámico
        IngresarProductos(mensajeNombre, nombres[i], 30);
    }
    
    for (int i = 0; i < cantidad; i++)
    {
        char mensajePrecio[50];
        sprintf(mensajePrecio, "Ingrese el precio del producto %d: ", i + 1); // Construye el mensaje dinámico
        precios[i] = IngresarPrecio(mensajePrecio);
    }
    printf("El total del inventario es: %.2f\n", CalcularTotal(precios, cantidad));
    printf("El promedio de los precios es: %.2f\n", CalcularPromedio(precios, cantidad));
    printf("El producto mas barato es: %s con un valor de %.2f\n", nombres[MostrarMasBarato(precios, cantidad)], precios[MostrarMasBarato(precios, cantidad)]);
    printf("El producto mas caro es: %s con un valor de %.2f\n", nombres[MostrarMasCaro(precios, cantidad)], precios[MostrarMasCaro(precios, cantidad)]);
    EncontrarProducto(nombres, precios, cantidad, NombreBuscado);
    return 0;
}
