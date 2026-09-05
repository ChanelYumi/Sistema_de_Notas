#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 50

// ----- STRUCT -----
// Aqui a gente "junta" nome, matricula e nota em uma caixinha só chamada Aluno
struct Aluno {
    char nome[50];
    int matricula;
    float nota;
};

// ----- Vetor (lista) que vai guardar todos os alunos cadastrados
struct Aluno alunos[MAX_ALUNOS];
int totalAlunos = 0; // quantos alunos já foram cadastrados

// ----- FUNCAO CADASTRAR -----
void cadastrar() {
    if (totalAlunos >= MAX_ALUNOS) {
        printf("Limite de alunos atingido!\n");
        return;
    }

    struct Aluno novo;

}

    // ----- A PARTIR DAQUI -----
    // Pessoal, ja criei a struct Aluno (guarda nome, matricula e nota)
    // e comecei a funcao cadastrar() (ja tem a verificacao de limite
    // e a variavel "novo" pronta pra usar).
    // Falta:
    // - colega 1: terminar a funcao cadastrar() (perguntar nome, matricula,
    //   nota, e guardar o aluno na lista) + fazer a funcao listar()
    // - colega 2: fazer a funcao buscar() + a funcao main() (menu principal)



