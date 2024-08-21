#include <stdio.h>
#include "banco.h"
int main()
{
    tBanco *banco = CriaBanco();
    char op;
    while (1)
    {
        scanf("%c\n", &op);
        if (op == 'F')
        {
            DestroiBanco(banco);
            break;
        }
        else if (op == 'A')
        {
            AbreContaBanco(banco);
        }
        else if (op == 'T')
        {
            TransferenciaContaBanco(banco);
        }
        else if (op == 'D')
        {
            DepositoContaBanco(banco);
        }
        else if (op == 'R')
        {
            ImprimeRelatorioBanco(banco);
        }
        else if (op == 'S')
        {
            SaqueContaBanco(banco);
        }
    }

    return 0;
}