#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "aluno.h"
#include "entrada.h"
#include "arquivo.h"

// ----- VETOR DE ALUNOS -----
// Aqui as variaveis sao criadas de verdade (no aluno.h so foram anunciadas)
struct Aluno alunos[MAX_ALUNOS];
int totalAlunos = 0;

// =====================================================
// FUNCOES DE APOIO (usadas so aqui dentro)
// =====================================================

// ----- PROCURAR POR MATRICULA -----
// Devolve a posicao do aluno no vetor, ou -1 se nao achar
static int procurarPorMatricula(int matricula) {
    for (int i = 0; i < totalAlunos; i++) {
        if (alunos[i].matricula == matricula) {
            return i;
        }
    }
    return -1;
}

// ----- MOSTRAR UM ALUNO -----
static void mostrarAluno(int posicao) {
    printf("Nome: %s\n", alunos[posicao].nome);
    printf("Matricula: %d\n", alunos[posicao].matricula);
    printf("Nota: %.2f\n", alunos[posicao].nota);
}

// ----- DEIXAR MINUSCULO -----
// Copia um texto trocando todas as letras por minusculas.
// Serve para a busca por nome nao ligar para maiuscula/minuscula.
static void paraMinusculo(const char *origem, char *destino) {
    int i;
    for (i = 0; origem[i] != '\0'; i++) {
        destino[i] = tolower((unsigned char)origem[i]);
    }
    destino[i] = '\0';
}

// =====================================================
// RF02 - CADASTRAR
// =====================================================
void cadastrar() {
    // Verifica se o vetor ja esta cheio
    if (totalAlunos >= MAX_ALUNOS) {
        printf("Limite de alunos atingido!\n");
        return;
    }

    struct Aluno novo;

    // A matricula e o identificador: nao pode repetir nem ser negativa
    while (1) {
        novo.matricula = lerInteiro("Digite a matricula do aluno: ");

        if (novo.matricula <= 0) {
            printf("A matricula precisa ser um numero maior que zero.\n");
        } else if (procurarPorMatricula(novo.matricula) != -1) {
            printf("Ja existe um aluno com essa matricula!\n");
        } else {
            break; // matricula valida, sai do laco
        }
    }

    lerTexto("Digite o nome completo do aluno: ", novo.nome, TAM_NOME);
    novo.nota = lerNota("Digite a nota do aluno (0 a 10): ");

    // Guarda na proxima posicao livre e atualiza o contador
    alunos[totalAlunos] = novo;
    totalAlunos++;

    salvarDados();
    printf("\nAluno cadastrado com sucesso!\n");
}

// =====================================================
// RF03 - LISTAR
// =====================================================
void listar() {
    if (totalAlunos == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    // Cabecalho da tabela
    printf("\n%-10s | %-30s | %-5s | %s\n", "MATRICULA", "NOME", "NOTA", "SITUACAO");
    printf("-----------+--------------------------------+-------+----------\n");

    for (int i = 0; i < totalAlunos; i++) {
        const char *situacao;
        if (alunos[i].nota >= NOTA_MINIMA) {
            situacao = "Aprovado";
        } else {
            situacao = "Reprovado";
        }
        printf("%-10d | %-30s | %5.2f | %s\n",
               alunos[i].matricula, alunos[i].nome, alunos[i].nota, situacao);
    }

    printf("\nTotal: %d aluno(s)\n", totalAlunos);
}

// =====================================================
// RF04 - BUSCAR (por matricula ou por parte do nome)
// =====================================================
void buscar() {
    if (totalAlunos == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    printf("\n1 - Buscar por matricula\n");
    printf("2 - Buscar por nome (ou parte do nome)\n");
    int tipo = lerInteiro("Escolha o tipo de busca: ");

    if (tipo == 1) {
        int matricula = lerInteiro("Digite a matricula: ");
        int posicao = procurarPorMatricula(matricula);

        if (posicao == -1) {
            printf("Aluno nao encontrado.\n");
        } else {
            printf("\n");
            mostrarAluno(posicao);
        }
    }
    else if (tipo == 2) {
        char trecho[TAM_NOME];
        char trechoMinusculo[TAM_NOME];
        char nomeMinusculo[TAM_NOME];

        lerTexto("Digite o nome ou parte dele: ", trecho, TAM_NOME);
        paraMinusculo(trecho, trechoMinusculo);

        int encontrados = 0;
        for (int i = 0; i < totalAlunos; i++) {
            paraMinusculo(alunos[i].nome, nomeMinusculo);

            // strstr procura um texto dentro do outro.
            // Ex.: "ana" esta dentro de "mariana souza"
            if (strstr(nomeMinusculo, trechoMinusculo) != NULL) {
                printf("\n");
                mostrarAluno(i);
                encontrados++;
            }
        }

        if (encontrados == 0) {
            printf("Nenhum aluno encontrado com esse nome.\n");
        } else {
            printf("\n%d aluno(s) encontrado(s).\n", encontrados);
        }
    }
    else {
        printf("Opcao de busca invalida!\n");
    }
}

// =====================================================
// RF05 - EDITAR
// =====================================================
void editar() {
    if (totalAlunos == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    int matricula = lerInteiro("Digite a matricula do aluno que deseja editar: ");
    int posicao = procurarPorMatricula(matricula);

    if (posicao == -1) {
        printf("Aluno nao encontrado.\n");
        return;
    }

    printf("\nDados atuais:\n");
    mostrarAluno(posicao);

    // Lemos os novos dados numa copia, sem mexer no vetor ainda.
    // A matricula nao muda, porque e o identificador do aluno.
    struct Aluno editado = alunos[posicao];

    printf("\nDigite os novos dados:\n");
    lerTexto("Novo nome: ", editado.nome, TAM_NOME);
    editado.nota = lerNota("Nova nota (0 a 10): ");

    // So salva se o usuario confirmar
    if (confirmar("Confirma a alteracao?")) {
        alunos[posicao] = editado;
        salvarDados();
        printf("Aluno alterado com sucesso!\n");
    } else {
        printf("Alteracao cancelada. Nada foi mudado.\n");
    }
}

// =====================================================
// RF06 - REMOVER
// =====================================================
void remover() {
    if (totalAlunos == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    int matricula = lerInteiro("Digite a matricula do aluno que deseja remover: ");
    int posicao = procurarPorMatricula(matricula);

    if (posicao == -1) {
        printf("Aluno nao encontrado.\n");
        return;
    }

    printf("\n");
    mostrarAluno(posicao);

    if (!confirmar("Tem certeza que deseja remover este aluno?")) {
        printf("Remocao cancelada.\n");
        return;
    }

    // Para nao deixar "buraco" no vetor, cada aluno depois do removido
    // anda uma posicao para a esquerda.
    // Ex.: [A, B, C, D] removendo B -> [A, C, D]
    for (int i = posicao; i < totalAlunos - 1; i++) {
        alunos[i] = alunos[i + 1];
    }
    totalAlunos--;

    salvarDados();
    printf("Aluno removido com sucesso!\n");
}

// =====================================================
// RF08 - REGRA DE NEGOCIO: RELATORIO DA TURMA
// =====================================================
void relatorio() {
    if (totalAlunos == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    float soma = 0;
    int aprovados = 0;
    int posMaior = 0; // posicao do aluno com maior nota
    int posMenor = 0; // posicao do aluno com menor nota

    for (int i = 0; i < totalAlunos; i++) {
        soma = soma + alunos[i].nota;

        if (alunos[i].nota >= NOTA_MINIMA) {
            aprovados++;
        }
        if (alunos[i].nota > alunos[posMaior].nota) {
            posMaior = i;
        }
        if (alunos[i].nota < alunos[posMenor].nota) {
            posMenor = i;
        }
    }

    float media = soma / totalAlunos;
    int reprovados = totalAlunos - aprovados;

    printf("\n===== RELATORIO DA TURMA =====\n");
    printf("Total de alunos: %d\n", totalAlunos);
    printf("Media da turma: %.2f\n", media);
    printf("Maior nota: %.2f (%s)\n", alunos[posMaior].nota, alunos[posMaior].nome);
    printf("Menor nota: %.2f (%s)\n", alunos[posMenor].nota, alunos[posMenor].nome);
    printf("Aprovados (nota >= %.1f): %d\n", NOTA_MINIMA, aprovados);
    printf("Reprovados: %d\n", reprovados);
    printf("Taxa de aprovacao: %.1f%%\n", (aprovados * 100.0) / totalAlunos);
}
