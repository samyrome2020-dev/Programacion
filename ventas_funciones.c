#include <stdio.h>

#if defined(__has_include)
#if __has_include("ventas_funciones.h")
#include "ventas_funciones.h"
#else
#ifndef max_pro
#define max_pro 100
#endif
#ifndef max_red
#define max_red 3
#endif
#endif
#else
#ifndef max_pro
#define max_pro 100
#endif
#ifndef max_red
#define max_red 3
#endif
#endif

void registrarPro(char productos[max_pro][50], float *precios, int (*ventas)[max_red], int *cantidad)
{
    if (*cantidad >= max_pro)
    {
        printf("No hay mas espacios para productos.\n");
        return;
    }

    printf("\n=====Registrar producto: =====\n");
    printf("Ingrese el nombre del producto: ");
    scanf(" %49[^\n]", productos[*cantidad]);
    printf("Ingrese el precio del producto: ");
    scanf("%f", &precios[*cantidad]);
    printf("Ingrese la cantidad de unidades vendidas:\n");
    printf("Facebook: ");
    scanf("%d", &ventas[*cantidad][0]);
    printf("Instagram: ");
    scanf("%d", &ventas[*cantidad][1]);
    printf("Twitter: ");
    scanf("%d", &ventas[*cantidad][2]);

    (*cantidad)++;
    printf("Producto registrado exitosamente.\n");
}

void mostrarPro(char productos[max_pro][50], float *precios, int (*ventas)[max_red], int *cantidad)
{
    if (*cantidad == 0)
    {
        printf("No hay productos registrados.\n");
        return;
    }

    printf("\n=====Lista de productos: =====\n");
    for (int i = 0; i < *cantidad; i++)
    {
        printf("Producto %d: %s\n", i + 1, productos[i]);
        printf("Precio: %.2f\n", precios[i]);
        printf("Ventas:\n");
        printf("Facebook: %d unidades\n", ventas[i][0]);
        printf("Instagram: %d unidades\n", ventas[i][1]);
        printf("Twitter: %d unidades\n", ventas[i][2]);
        printf("\n");
    }
}