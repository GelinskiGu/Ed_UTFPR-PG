#include <stdio.h>
#include <stdlib.h>

void tamanhoInt(int *ponteiro)
{
    int size = sizeof(int);
    printf("%d\n", size);
}
void tamanhoFloat(float *ponteiro)
{
    int size = sizeof(float);
    printf("%d\n", size);
}
void tamanhoChar(char *ponteiro)
{
    int size = sizeof(char);
    printf("%d\n", size);
}

void conteudoInt(int *ponteiro)
{
    printf("%d\n", *ponteiro);
}
void conteudoChar(char *ponteiro)
{
    printf("%c\n", *ponteiro);
}
void conteudoFloat(float *ponteiro)
{
    printf("%f\n", *ponteiro);
}

int main()
{
    int a = 32;
    int size;
    float b = 10.6;
    char c = 'w';
    int *pa = &a;
    float *pb = &b;
    char *pc = &c;
    tamanhoInt(pa);
    tamanhoFloat(pb);
    tamanhoChar((char *)pc);
    conteudoInt(pa);
    conteudoFloat(pb);
    conteudoChar(pc);
}