#include <stdio.h>
#include <stdlib.h>

float perimetro(float *a, float *b);

int main()
{
    float base, altura, *b = NULL, *h = NULL;
    float per;
    b = &base;
    h = &altura;
    scanf("%f", &base);
    scanf("%f", &altura);
    per = perimetro(b, h);
    *b = 2 * (*b);
    *h = 2 * (*h);
    printf("Perimetro: %f\n", per);
    printf("Altura: %f\n", altura);
    printf("Base: %f\n", base);
}

float perimetro(float *a, float *b)
{
    int perimetro;
    perimetro = 2 * (*a) + 2 * (*b);
    return perimetro;
}