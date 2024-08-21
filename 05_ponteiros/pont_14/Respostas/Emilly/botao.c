#include "botao.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
void SetarTexto(Botao *b, char *novoTexto)
{
    if (strlen(novoTexto) == MAX_TAM_TEXTO)
        exit(1);
    strcpy(b->texto, novoTexto);
}

void SetarTamFonte(Botao *b, int novoTamFonte)
{
    if (novoTamFonte < 1)
        exit(1);
    b->tamFonte = novoTamFonte;
}

void SetarCor(Botao *b, char *novaCor)
{
    strcpy(b->corHex, novaCor);
}

void SetarTipo(Botao *b, int novoTipo)
{
    if (novoTipo < 1 || novoTipo > 3)
        exit(1);
    b->tipo = novoTipo;
}

Botao CriarBotao(char *texto, int tamFonte, char *cor, int tipo, void (*executa)(void))
{
    Botao b;
    SetarTexto(&b, texto);
    SetarTamFonte(&b, tamFonte);
    SetarCor(&b, cor);
    SetarTipo(&b, tipo);
    b.executa = executa;

    return b;
}
void ExecutaBotao(Botao b)
{
    if (b.tipo == LONGO_CLICK)
        printf("- Executando o botao com evento de longo click\n");
    else if (b.tipo == CLICK)
        printf("- Executando o botao com evento de click\n");
    else if (b.tipo == HOVER)
        printf("- Executando o botao com evento de hover\n");
    b.executa();
}

void DesenhaBotao(Botao b, int idx){
    printf("-------------\n- Botao [%d]:\n(%s | %s | %d | %d)\n-------------\n\n", idx, b.texto, b.corHex, b.tamFonte, b.tipo);
}