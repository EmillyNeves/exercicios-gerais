#include "biblioteca.h"
#include "livro.h"
#include <stdio.h>
#include <string.h>

tBiblioteca inicializarBiblioteca()
{
    tBiblioteca b;
    b.tamanho = 0;

    return b;
}

tBiblioteca adicionarLivroNaBiblioteca(tBiblioteca biblioteca, tLivros livro)
{
    if (biblioteca.tamanho < MAX_LIVROS)
    {
        biblioteca.livros[biblioteca.tamanho] = livro;
        biblioteca.tamanho++;
        printf("Livro adicionado com sucesso!\n");
    }
    else
    {
        printf("A biblioteca esta cheia. Nao eh possivel adicionar mais livros.\n");
    }

    return biblioteca;
}

tBiblioteca removerLivroDaBiblioteca(tBiblioteca biblioteca, char *titulo)
{
    int i, j;
    for (i = 0; i < biblioteca.tamanho; i++)
    {
        if (verificaTituloDoLivroNaBiblioteca(biblioteca.livros[i], titulo) == 0)
        {
            for (j = i; j < biblioteca.tamanho; j++)
            {
                biblioteca.livros[j] = biblioteca.livros[j + 1];
            }
            printf("Livro removido com sucesso!\n");
            biblioteca.tamanho--;
            return biblioteca;
        }
    }
    printf("Livro nao encontrado na biblioteca.\n");

    return biblioteca;
}

int verificaTituloDoLivroNaBiblioteca(tLivros livro, char *titulo)
{
    return (strcmp(livro.titulo, titulo));
}

void listarLivrosDaBiblioteca(tBiblioteca biblioteca)
{
    if (biblioteca.tamanho == 0)
        printf("A biblioteca esta vazia!\n");
    else
    {
        printf("\nLista de Livros na Biblioteca:\n");
        for (int i = 0; i < biblioteca.tamanho; i++)
        {
            imprimeLivro(biblioteca.livros[i]);
        }
    }
}
