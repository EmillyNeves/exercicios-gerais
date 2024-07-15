#include <stdio.h>
#include "biblioteca.h"

int main()
{
    int op, acao;

    scanf("%d", &op);
    tBiblioteca biblioteca;
    biblioteca = inicializarBiblioteca();

    printf("Lista de operacoes:\n");
    printf("1 - Cadastrar livros.\n");
    printf("2 - Remover livros.\n");
    printf("3 - Listar todos os livros cadastrados.\n\n");
    for (int i = 0; i < op; i++)
    {

        scanf("%d\n", &acao);
        if (acao == 1)
        {
            tLivros livro;
            livro = lerLivro();
            biblioteca = adicionarLivroNaBiblioteca(biblioteca, livro);
        }
        else if (acao == 2)
        {
            tLivros livro;
            scanf("%[^\n]\n", livro.titulo);
            biblioteca = removerLivroDaBiblioteca(biblioteca, livro.titulo);
        }
        else if (acao == 3)
        {
            listarLivrosDaBiblioteca(biblioteca);
        }
        else{
            printf("Operacao invalida!\n");
            return 1;
        }
    }

    return 0;
}