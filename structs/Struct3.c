#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct conta
{
    int numero;
    float saldo;
} ContaBancaria;

ContaBancaria *aloca();
void opcao(ContaBancaria *pconta);

void main()
{
    ContaBancaria *p = NULL;
    p = aloca();
    printf("\nInforme o numero de sua conta:");
    scanf("%d", &(p->numero));
    printf("\nInforme seu saldo inicial:");
    scanf("%f", &(p->saldo));
    opcao(p);
}

ContaBancaria *aloca()
{
    ContaBancaria *pc = NULL;
    pc = (ContaBancaria *)malloc(sizeof(ContaBancaria));
    if (!pc)
        return NULL;
    return pc;
}

void opcao(ContaBancaria *pconta)
{
    int op;
    while (op)
    {
        printf("\nSelecione uma opcao: ");
        printf("\n0 - Encerrar.");
        printf("\n1 - Depositar valor.");
        printf("\n2 - Sacar valor.");
        printf("\n3 - Imprimir saldo.");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
        {
            float valor = 0;
            printf("\nInforme o valor a ser depositado:");
            scanf("%f", &valor);
            pconta->saldo += valor;
            printf("\nFoi adicionado R$%f a sua conta!", valor);
        }
        break;

        case 2:
        {
            float valor = 0;
            printf("\nInforme o valor a ser sacado:");
            scanf("%f", &valor);
            pconta->saldo -= valor;
            printf("\nFoi retirado R$%f da sua conta!", valor);
        }
        break;

        case 3:
        {
            printf("\nSeu saldo eh de R$%f", pconta->saldo);
        }
        break;
        }
    }
}