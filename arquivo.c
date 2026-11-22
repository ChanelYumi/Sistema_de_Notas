#include <stdio.h>
#include "aluno.h"
#include "arquivo.h"

// O arquivo alunos.txt guarda um aluno por linha, assim:
//     matricula;nota;nome
// Exemplo:
//     1001;8.50;Maria Silva

// ----- FUNCAO CARREGAR DADOS -----
// Le o arquivo quando o programa abre e coloca os alunos no vetor
void carregarDados() {
    FILE *arquivo = fopen(NOME_ARQUIVO, "r"); // "r" = abrir para ler

    // Na primeira vez que o programa roda, o arquivo ainda nao existe.
    // Nesse caso o sistema so comeca vazio, sem dar erro.
    if (arquivo == NULL) {
        printf("Nenhum arquivo de dados encontrado. Comecando com a lista vazia.\n");
        return;
    }

    totalAlunos = 0;
    struct Aluno lido;

    // fscanf le uma linha no formato matricula;nota;nome
    // Ele devolve quantos campos conseguiu ler: tem que ser 3
    while (totalAlunos < MAX_ALUNOS &&
           fscanf(arquivo, "%d;%f;%49[^\n]\n", &lido.matricula, &lido.nota, lido.nome) == 3) {
        alunos[totalAlunos] = lido;
        totalAlunos++;
    }

    fclose(arquivo);
    printf("%d aluno(s) carregado(s) do arquivo.\n", totalAlunos);
}

// ----- FUNCAO SALVAR DADOS -----
// Grava todos os alunos do vetor no arquivo (apaga o conteudo antigo)
void salvarDados() {
    FILE *arquivo = fopen(NOME_ARQUIVO, "w"); // "w" = abrir para escrever

    if (arquivo == NULL) {
        printf("Erro: nao foi possivel salvar os dados no arquivo!\n");
        return;
    }

    for (int i = 0; i < totalAlunos; i++) {
        fprintf(arquivo, "%d;%.2f;%s\n", alunos[i].matricula, alunos[i].nota, alunos[i].nome);
    }

    fclose(arquivo);
}
