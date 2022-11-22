#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// Teste note
typedef int TipoChave;
typedef int TipoValor;
struct TipoListaSimples
{
    TipoChave chave;
    TipoValor valorQualquer;
    struct TipoListaSimples *prox;
};
typedef struct TipoListaSimples TipoListaSimples;

TipoListaSimples *insereInicioListaSimples(TipoListaSimples **prim, TipoChave k, TipoValor v);
void atualizaValor(TipoListaSimples *prim, TipoValor novoValor);
void removePrimeiroNo(TipoListaSimples **prim);
TipoListaSimples *pesquisaNo(TipoListaSimples *prim, TipoChave chave);
TipoListaSimples *insereFimListaSimples(TipoListaSimples **prim, TipoChave chave);
void imprimeLista(TipoListaSimples *prim);
void removeUltimoNo(TipoListaSimples **prim);
void removeNo(TipoListaSimples **prim, TipoChave chave);
void liberaNos(TipoListaSimples **prim);

int main()
{
    TipoListaSimples *prim = NULL;
    TipoListaSimples *busca = NULL;
    TipoListaSimples *ultimoNo = NULL;
    prim = insereInicioListaSimples(&prim, 10, 5);
    prim = insereInicioListaSimples(&prim, 15, 5);
    prim = insereInicioListaSimples(&prim, 1, 5);
    prim = insereInicioListaSimples(&prim, 25, 5);
    prim = insereInicioListaSimples(&prim, 30, 5);
    imprimeLista(prim);
    printf("================================================================\n");
    removeNo(&prim, 30);
    imprimeLista(prim);
    printf("================================================================\n");
    liberaNos(&prim);
    printf("Imprimindo ultima lista\n");
    imprimeLista(prim);
}

TipoListaSimples *insereInicioListaSimples(TipoListaSimples **prim, TipoChave k, TipoValor v)
{
    if (!(*prim))
    {
        *prim = (TipoListaSimples *)malloc(sizeof(TipoListaSimples));
        (*prim)->prox = NULL;
        (*prim)->chave = k;
        (*prim)->valorQualquer = v;
        if (!(*prim))
            return NULL;
        return *prim;
    }
    TipoListaSimples *novo = NULL;
    novo = (TipoListaSimples *)malloc(sizeof(TipoListaSimples));
    if (!novo)
        return NULL;
    novo->prox = *prim;
    novo->chave = k;
    novo->valorQualquer = v;
    *prim = novo;
    return *prim;
}

void atualizaValor(TipoListaSimples *prim, TipoValor novoValor)
{
    if (!prim)
        return;
    prim->valorQualquer = novoValor;
}

void removePrimeiroNo(TipoListaSimples **prim)
{
    if (!(*prim))
        return;
    TipoListaSimples *novo = NULL;
    novo = (*prim)->prox;
    free(*prim);
    *prim = novo;
}

TipoListaSimples *pesquisaNo(TipoListaSimples *prim, TipoChave chave)
{
    if (!prim)
        return NULL;
    TipoListaSimples *buscaChave = NULL;
    buscaChave = prim;
    while (buscaChave->chave != chave)
    {
        if (buscaChave->prox == NULL)
            return NULL;
        buscaChave = buscaChave->prox;
    }
    return buscaChave;
}

TipoListaSimples *insereFimListaSimples(TipoListaSimples **prim, TipoChave chave)
{
    if (!(*prim))
        return NULL;
    TipoListaSimples *noFinal = NULL;
    noFinal = *prim;
    while (noFinal->prox != NULL)
    {
        noFinal = noFinal->prox;
    }
    noFinal->prox = (TipoListaSimples *)malloc(sizeof(TipoListaSimples));
    noFinal->prox->prox = NULL;
    noFinal->prox->chave = chave;
    return noFinal->prox;
}

void imprimeLista(TipoListaSimples *prim)
{
    if (prim)
        while (prim)
        {
            printf("%d\n", prim->chave);
            prim = prim->prox;
        }
    else
        printf("Lista vazia!\n");
}

void removeUltimoNo(TipoListaSimples **prim)
{
    assert(*prim);
    TipoListaSimples *aux = NULL;
    aux = *prim;
    while (aux->prox->prox)
        aux = aux->prox;
    free(aux->prox);
    aux->prox = NULL;
}

void removeNo(TipoListaSimples **prim, TipoChave chave)
{
    assert(*prim);
    TipoListaSimples *aux1 = NULL;
    TipoListaSimples *aux2 = NULL;
    aux1 = *prim;
    if ((*prim)->chave == chave)
    {
        aux1 = *prim;
        *prim = aux1->prox;
        free(aux1);
        aux1 = NULL;
        return;
    }
    while (aux1->prox->chave != chave)
        aux1 = aux1->prox;
    aux2 = aux1;
    aux1 = aux1->prox;
    aux2->prox = aux1->prox;
    free(aux1);
    aux1 = NULL;
}

void liberaNos(TipoListaSimples **prim)
{
    if (!(*prim))
    {
        prim = NULL;
        return;
    }
    liberaNos(&(*prim)->prox);
    free(*prim);
    *prim = NULL;
}