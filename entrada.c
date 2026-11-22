#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "entrada.h"

// ----- FUNCAO LER LINHA -----
// Le uma linha inteira do teclado e tira o "Enter" do final.
// Usamos fgets em vez de scanf porque o scanf trava quando o usuario
// digita letra no lugar de numero.
static void lerLinha(char *destino, int tamanho) {
    if (fgets(destino, tamanho, stdin) == NULL) {
        destino[0] = '\0';
        return;
    }

    // Se a linha tem '\n', troca por '\0' (fim do texto)
    char *enter = strchr(destino, '\n');
    if (enter != NULL) {
        *enter = '\0';
    } else {
        // Se nao tem '\n', o usuario digitou mais do que cabia:
        // jogamos fora o resto da linha
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
}

// ----- FUNCAO LER INTEIRO -----
// Pergunta ate o usuario digitar um numero inteiro valido
int lerInteiro(const char *mensagem) {
    char linha[100];
    int numero;
    char sobra;

    while (1) {
        printf("%s", mensagem);
        lerLinha(linha, sizeof(linha));

        // sscanf tenta tirar um numero da linha.
        // Se sobrar alguma coisa depois (ex.: "12abc"), e invalido.
        if (sscanf(linha, "%d %c", &numero, &sobra) == 1) {
            return numero;
        }
        printf("Valor invalido! Digite apenas numeros inteiros.\n");
    }
}

// ----- FUNCAO LER NOTA -----
// Pergunta ate o usuario digitar uma nota entre 0 e 10
float lerNota(const char *mensagem) {
    char linha[100];
    float nota;
    char sobra;

    while (1) {
        printf("%s", mensagem);
        lerLinha(linha, sizeof(linha));

        // Aceita virgula tambem (ex.: 7,5 vira 7.5)
        char *virgula = strchr(linha, ',');
        if (virgula != NULL) {
            *virgula = '.';
        }

        if (sscanf(linha, "%f %c", &nota, &sobra) == 1) {
            if (nota >= 0 && nota <= 10) {
                return nota;
            }
            printf("A nota precisa estar entre 0 e 10.\n");
        } else {
            printf("Valor invalido! Digite uma nota, por exemplo 7.5\n");
        }
    }
}

// ----- FUNCAO LER TEXTO -----
// Pergunta ate o usuario digitar um texto que nao seja vazio
void lerTexto(const char *mensagem, char *destino, int tamanho) {
    while (1) {
        printf("%s", mensagem);
        lerLinha(destino, tamanho);

        // Confere se tem pelo menos uma letra/numero (nao so espacos)
        int temConteudo = 0;
        for (int i = 0; destino[i] != '\0'; i++) {
            if (!isspace((unsigned char)destino[i])) {
                temConteudo = 1;
            }
        }

        // O ';' e proibido porque usamos ele para separar os dados no arquivo
        if (strchr(destino, ';') != NULL) {
            printf("O texto nao pode conter ';'.\n");
        } else if (temConteudo) {
            return;
        } else {
            printf("Este campo nao pode ficar vazio.\n");
        }
    }
}

// ----- FUNCAO CONFIRMAR -----
// Pergunta "s/n" e devolve 1 se for sim e 0 se for nao
int confirmar(const char *mensagem) {
    char linha[100];

    while (1) {
        printf("%s (s/n): ", mensagem);
        lerLinha(linha, sizeof(linha));

        if (linha[0] == 's' || linha[0] == 'S') {
            return 1;
        }
        if (linha[0] == 'n' || linha[0] == 'N') {
            return 0;
        }
        printf("Responda apenas s ou n.\n");
    }
}
