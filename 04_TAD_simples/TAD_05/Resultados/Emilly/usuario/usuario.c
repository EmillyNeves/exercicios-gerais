#include"usuario.h"
#include<stdio.h>
#include"string.h"
tUsuario CriaUsuario(char nome[20], char cpf[15]){
    tUsuario user;
    strcpy(user.nome, nome);
    strcpy(user.cpf, cpf);

    return user;
}
void ImprimeUsuario(tUsuario user){
    printf("Nome: %s\n", user.nome);
    printf("CPF: %s\n\n", user.cpf);
}
