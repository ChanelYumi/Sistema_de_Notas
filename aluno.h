#ifndef ALUNO_H
#define ALUNO_H

// ----- CONSTANTES -----
#define MAX_ALUNOS 5      // quantos alunos o sistema aguenta guardar
#define TAM_NOME 50        // tamanho maximo do nome
#define NOTA_MINIMA 6.0    // nota minima para ser aprovado

// ----- STRUCT -----
// A "caixinha" que junta nome, matricula e nota de um aluno
struct Aluno {
    char nome[TAM_NOME];
    int matricula;
    float nota;
};

// ----- VARIAVEIS GLOBAIS -----
// "extern" avisa que essas variaveis existem, mas foram criadas no aluno.c
extern struct Aluno alunos[MAX_ALUNOS];
extern int totalAlunos;

// ----- FUNCOES (o "cardapio" do aluno.c) -----
void cadastrar();
void listar();
void buscar();
void editar();
void remover();
void relatorio();

#endif
