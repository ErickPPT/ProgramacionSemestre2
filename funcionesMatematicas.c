#include<stdio.h>
void suma();
void resta(int a, int b);
int multiplicacion();
int division(int, int);
int leerNumero(char*);

int main(int argc, char const *argv[]){
    int num1, num2, resultado;
    printf("*******SUMA******\n");
    suma();
    printf("*******RESTA******\n");
    num1 = leerNumero("Ingres un operando: ");
    num2 = leerNumero("Ingrese un operando: ");
    resta(num1, num2);
    printf("*******DIVISION******\n");
    num1 = leerNumero("Ingrese un operando: ");
    num2 = leerNumero("Ingrese un operando: ");
    printf("%d / %d = %d\n", num1, num2, division(num1, num2));
    printf("*******MULTIPLICACION******\n");
    resultado = multiplicacion();
    printf("La variable resultado tiene %d\n", resultado);
    return 0;
}
 void suma(){
    int a, b;
      a = leerNumero("Ingrese un numero: ");
      b = leerNumero("Ingrese un numero: ");
    printf("La suma de %d y %d es: %d\n", a, b, (a+b));
 }

 void resta(int a, int b){
    printf("%d - %d = %d\n", a,b, (a-b));
 }
 int multiplicacion(){
    int a, b;
    a = leerNumero("Ingrese un numero: ");
    b = leerNumero("Ingrese un numero: ");
    return a*b;
 }
int division(int a, int b){
    return a/b;
 }
 int leerNumero(char* mensaje){
   int valor;
   printf("%s: ", mensaje);
   while (scanf("%d", &valor)!=1)
   {
      printf("Dato mal ingresado\n");
      while(getchar()!='\n');
      printf("%s: ", mensaje);
   }
   return valor;
   
 }
