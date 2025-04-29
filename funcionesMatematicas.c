#include<stdio.h>
void suma();
void resta(int a, int b);
int multiplicacion();
int division(int, int);

int main(int argc, char const *argv[]){
    int num1, num2, resultado;
    printf("*******SUMA******\n");
    suma();
    printf("*******RESTA******\n");
    printf("Ingresa un numero: ");
    scanf("%d", &num1);
    printf("Ingresa otro numero: ");
    scanf("%d", &num2);
    resta(num1, num2);
    printf("*******DIVISION******\n");
    printf("%d / %d = %d\n", num1, num2, division(num1, num2));
    resultado = multiplicacion();
    printf("*******MULTIPLICACION******\n");
    printf("La variable resultado tiene %d\n", resultado);
    return 0;
}
 void suma(){
    int a, b;
    printf("Ingresa un numero: ");
    scanf("%d", &a);
    printf("Ingresa otro numero: ");
    scanf("%d", &b);
    printf("La suma de %d y %d es: %d\n", a, b, (a+b));
 }

 void resta(int a, int b){
    printf("%d - %d = %d\n", a,b, (a-b));
 }
 int multiplicacion(){
    int a, b;
    printf("Ingresa un numero:");
    scanf("%d", &a);
    printf("Ingresa otro numero:");
    scanf("%d", &b);
    return a*b;
 }
int division(int a, int b){
    return a/b;
 }