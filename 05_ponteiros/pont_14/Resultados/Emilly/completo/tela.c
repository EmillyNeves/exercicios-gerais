#include "botao.h"
#include "tela.h"
#include<stdio.h>

Tela CriarTela(int altura, int largura)
{
    Tela t;
    t.altura = altura;
    t.largura = largura;
    t.qntBotoes = 0;
    return t;
}

void RegistraBotaoTela(Tela *t, Botao b)
{
    if (t->qntBotoes < MAX_BOTOES)
    {
        t->botoes[t->qntBotoes] = b;
        t->qntBotoes++;
    }
}

void DesenhaTela(Tela t)
{
    int i;
    printf("##################\n");
    for (i = 0; i < t.qntBotoes; i++)
    {
        DesenhaBotao(t.botoes[i], i);
    }
    printf("##################\n");
}

void OuvidorEventosTela(Tela t)
{
    int b;
    printf("- Escolha sua acao: ");
    scanf("%d", &b);
    if (b >= 0 && b < t.qntBotoes)
    {
        ExecutaBotao(t.botoes[b]);
    }
}