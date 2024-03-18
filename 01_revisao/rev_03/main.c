#include <stdio.h>
void LeIDLivros(int qtdLivros, int idLivros[qtdLivros])
{
    for (int i = 0; i < qtdLivros; i++)
    {
        scanf("%d", &idLivros[i]);
    }
}
void OrdenaVetor(int qtdLivros, int idLivros[qtdLivros])
{
    int aux = 0;
    for (int i = 0; i < qtdLivros; i++)
    {
        for (int j = 0; j < qtdLivros; j++)
        {
            if (idLivros[j] > idLivros[i])
            {
                aux = idLivros[j];
                idLivros[j] = idLivros[i];
                idLivros[i] = aux;
            }
        }
    }
}
void ImprimeCopias(int qtdLivros, int idLivros[qtdLivros])
{
    int teveCopia, verificador= 0;
    for (int i = 0; i < qtdLivros; i++)
    {
        teveCopia = 0;
        for (int j = 0; j < qtdLivros; j++)
        {
            if (idLivros[j] == idLivros[i])
            {
                teveCopia++;
            }
        }
        if (teveCopia == 1){
            printf("%d ", idLivros[i]);
            verificador=1;
        }
    }
    if (!verificador)
        printf("NENHUM");
}
int main()
{
    int qtdLivros = 0;
    scanf("%d", &qtdLivros);

    int idLivros[qtdLivros];

    LeIDLivros(qtdLivros, idLivros);
    OrdenaVetor(qtdLivros, idLivros);
    ImprimeCopias(qtdLivros, idLivros);

    return 0;
}