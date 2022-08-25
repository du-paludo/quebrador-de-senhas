/* Trabalho feito por: Eduardo Paludo (GRR20210581) e Inaiê Moscal (GRR20210578) */

#include "string.h"
#include "biblioteca.h"
#include "quebrador-senha.h"
#define N 6

/* Vetor gerado aleatoriamente com todos os caracteres permitidos */
const char caracteres[] = "tlcv1jmx8fs2kypig9w4uroe3abh67dqz05n";
const int num_caracteres = 36;

int exaustivo(char senha[], int indice)
{
	/* Retorna o resultado da tentativa de login quando ultrapassar o tamanho da senha */
	if (indice == N)
		return (login(senha));

	for (int k = 0; k < num_caracteres; k++)
	{
		/* Atribui a cada índice da senha um valor diferente do vetor de caracteres */
		senha[indice] = caracteres[k];

		/* Se encontrar a senha, retorna 1 */
		if (exaustivo(senha, indice + 1))
			return 1;
	}

	/* Se não encontrar, retorna 0 */
	return 0;
}

int poda(char aux[], char senha[], int indice, int letras, int numeros)
{
	/* Retorna o resultado da tentativa de login quando ultrapassar o tamanho da senha */
	if (indice == N)
		return (login(senha));

	for (int k = 0; k < num_caracteres; k++)
	{
		/* Testa se o caracter já foi utilizado na senha */
		if (aux[k] != '-')
		{
			senha[indice] = aux[k];

			/* Sobrescreve o caracter original com um sinalizador */
			aux[k] = '-';

			/* Testa se o caracter é uma letra */
			if (senha[indice] >= 97)
			{
				/* Testa se o número máximo de letras foi ultrapassado */
				if (letras < 4)
					if (poda(aux, senha, indice + 1, letras + 1, numeros))
						return 1;
			}

			/* Se não for letra, é um número */
			else
			{
				/* Testa se o número máximo de números foi ultrapassado */
				if (numeros < 4)
					if (poda(aux, senha, indice + 1, letras, numeros + 1))
						return 1;
			}

			/* Remove o caracter sinalizador (backtracking) */
			aux[k] = senha[indice];
		}
	}
	return 0;
}

/* Retorna 1 caso tenha encontrado a senha e 0 caso contrário */
int quebrador_senha_exaustivo()
{
	char senha[N+1];
	int indice;

	/* Procura a senha pelo método da força bruta, com índice inicializado em 0 */
	return (exaustivo(senha, 0));
}

/* Retorna 1 caso tenha encontrado a senha e 0 caso contrário */
int quebrador_senha_poda()
{
	char senha[N+1];
	int indice, letras, numeros;

	/* Declara um vetor auxiliar idêntico ao original, para mantê-lo inalterado */
	char aux[num_caracteres+1];
	strcpy(aux, caracteres);

	/* Procura a senha pelo método da poda de árvore,
	com todas as variáveis inicializadas em 0 */
	return (poda(aux, senha, 0, 0, 0));
}