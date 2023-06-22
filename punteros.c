#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "punteros.h"

int main() {
    int num1, num2;
    int opcion;
    int resultado_entero;
    float resultado_flotante;
    int t;
    
    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &t);

    float *arreglo = malloc(t * sizeof(float));

    if (arreglo == NULL) {
        printf("Error al asignar memoria dinámica.\n");
        return 1;
    }
    
    for (int i = 0; i < t; i++) {
        printf("Ingrese el elemento %d del arreglo: ", i + 1);
        scanf("%f", &arreglo[i]);
    }

    for (int i = 0; i < t; i++) {
        printf("%0.2f\n", arreglo[i]);
    }

    float escalar;
    printf("Ingrese el escalar por el que quiera sumar el arreglo: ");
    scanf("%f", &escalar);

    sumaArregloEscalar(arreglo, t, escalar);

    for (int i = 0; i < t; i++) {
        printf("%0.2f\n", arreglo[i]);
    }

    printf("Calculadora básica\n");
    printf("Ingrese el primer número: ");
    scanf("%d", &num1);

    printf("Ingrese el segundo número: ");
    scanf("%d", &num2);

    printf("Seleccione la operación:\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicación\n");
    printf("4. División\n");
    printf("Opción: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            sumar(&num1, &num2, &resultado_entero);
            printf("El resultado de la suma es: %d\n", resultado_entero);
            break;
        case 2:
            restar(&num1, &num2, &resultado_entero);
            printf("El resultado de la resta es: %d\n", resultado_entero);
            break;
        case 3:
            multiplicar(&num1, &num2, &resultado_entero);
            printf("El resultado de la multiplicación es: %d\n", resultado_entero);
            break;
        case 4:
            dividir(&num1, &num2, &resultado_flotante);
            printf("El resultado de la división es: %.2f\n", resultado_flotante);
            break;
        default:
            printf("Opción inválida\n");
            break;
    }

    char cadena1[15], cadena2[15]; 
    int tc1 = 0, tc2 = 0;
    printf("Ingrese la primera cadena: ");
    scanf("%s", cadena1);
    printf("Ingrese la segunda cadena: ");
    scanf("%s", cadena2);
    tc1 = strlen(cadena1);
    tc2 = strlen(cadena2);
    compararCadena(tc1, tc2, cadena1, cadena2);

    free(arreglo);
    return 0;
}
