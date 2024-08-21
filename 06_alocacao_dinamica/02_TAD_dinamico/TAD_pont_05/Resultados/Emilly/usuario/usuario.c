#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"

tUsuario *CriaUsuario()
{
    tUsuario *user = (tUsuario *)calloc(1, sizeof(tUsuario));
    if (user == NULL)
        exit(1);
    user->cpf[0] = '\0';
    user->nome[0] = '\0';
    return user;
}

void DestroiUsuario(tUsuario *user)
{
    free(user);
}

void LeUsuario(tUsuario *user)
{
    scanf("%s %s ", user->nome, user->cpf);
}

void ImprimeUsuario(tUsuario *user)
{
    printf("Nome: %s\n", user->nome);
    printf("CPF: %s\n", user->cpf);
}
