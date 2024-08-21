#include<stdio.h>
#include "tela.h"
void b0(){
    printf("- Botao de SALVAR dados ativado!\n");
}
void b1(){
    printf("- Botao de EXCLUIR dados ativado!\n");
}
void b2(){
    printf("- Botao de OPCOES ativado!\n");
}

int main(){
    Tela t;
    Botao b;
    char text0[30] = "Salvar", text1[30] = "Excluir", text2[30] = "Opcoes"; 
    int alt = 200, lar = 400;
    
    t = CriarTela(alt, lar);
    
    b = CriarBotao("Salvar", 12, "FFF", 1, b0);
    RegistraBotaoTela(&t, b);
    
    b = CriarBotao("Excluir", 18, "000", 1, b1);
    RegistraBotaoTela(&t, b);
    
    b = CriarBotao("Opcoes", 10, "FF0000", 2, b2);
    RegistraBotaoTela(&t, b);

    DesenhaTela(t);
    OuvidorEventosTela(t);
    
    return 0;
}