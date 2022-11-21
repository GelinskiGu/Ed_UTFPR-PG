#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct aluno
{
    char nome[50];
    int ra;
    int idade;
} TipoAluno;

TipoAluno *aloca(int n);
void alterar(TipoAluno *paluno, int n);
void opcao(TipoAluno *paluno, int n);

void main()
{
    TipoAluno *p;
    int n;
    printf("\nInforme o numero de alunos:");
    scanf("%d", &n);
    p = aloca(n);
    alterar(p, n);
    for (int i = 0; i < n; i++)
        printf("\nAluno %s inserido!", (p + i)->nome);
    opcao(p, n);
}

TipoAluno *aloca(int n)
{
    TipoAluno *pa = NULL;
    pa = (TipoAluno *)malloc(sizeof(TipoAluno) * n);
    if (!pa)
        return NULL;
    return pa;
}

void alterar(TipoAluno *paluno, int n)
{
    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        printf("\nInforme nome(%d):", i + 1);
        fgets((paluno + i)->nome, 50, stdin);
        printf("\nInforme RA(%d):", i + 1);
        scanf("%d", &((paluno + i)->ra));
        printf("\nInforme idade(%d):", i + 1);
        scanf("%d", &((paluno + i)->idade));
    }
}

void opcao(TipoAluno *paluno, int n)
{
    int op, op2;
    while (op)
    {
        printf("\nSelecione qual aluno deseja ver:");
        for (int i = 0; i < n; i++)
            printf("\n%d - %s", i + 1, (paluno + i)->nome);
        scanf("%d", &op2);
        op2--;
        printf("\nSelecione uma opcao: ");
        printf("\n0 - Encerrar.");
        printf("\n1 - Ver nome.");
        printf("\n2 - Ver idade.");
        printf("\n3 - Ver RA.");
        printf("\n4 - Escolher outro aluno.");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\n%s", (paluno + (op2))->nome);
            break;
        case 2:
            printf("\n%d", (paluno + (op2))->idade);
            break;
        case 3:
            printf("\n%d", (paluno + (op2))->ra);
            break;
        default:
            break;
        }
    }
}