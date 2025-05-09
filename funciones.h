void IngresarProductos (char*mensaje, char cadena[], int longitud);
float IngresarPrecio(char*mensaje);
int IngresarCantidad(char*mensaje, int minimo, int maximo);
float CalcularTotal (float precios[10], int cantidad);
float CalcularPromedio (float precios[10], int cantidad);
int MostrarMasBarato(float precios[10], int cantidad);
int MostrarMasCaro(float precios[10], int cantidad);
void EncontrarProducto(char nombres[][30], float precios[10], int cantidad, char NombreBuscado[]);
