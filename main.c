#include <stdio.h>
#include "aluno.h"
#include "arquivo.h"
#include "entrada.h"

// =====================================================
// SISTEMA DE NOTAS - Entrega 2
// Integrantes: Chanel Yumi, Leandro Goncalves, Mateus Lopes
// =====================================================

int main() {
    int opcao;

    // RF07: ao abrir, carrega o que estava salvo no arquivo
    carregarDados();

    // RF01: menu em laco que so termina com "Sair"
    do {
        printf("\n===== SISTEMA DE NOTAS =====\n");
        printf("1 - Cadastrar aluno\n");
        printf("2 - Listar alunos\n");
        printf("3 - Buscar aluno\n");
        printf("4 - Editar aluno\n");
        printf("5 - Remover aluno\n");
        printf("6 - Relatorio da turma\n");
        printf("0 - Sair\n");

        opcao = lerInteiro("Digite uma opcao: ");

        if (opcao == 1) {
            cadastrar();
        }
        else if (opcao == 2) {
            listar();
        }
        else if (opcao == 3) {
            buscar();
        }
        else if (opcao == 4) {
            editar();
        }
        else if (opcao == 5) {
            remover();
        }
        else if (opcao == 6) {
            relatorio();
        }
        else if (opcao == 0) {
            // RF07: grava tudo antes de sair
            salvarDados();
            printf("Dados salvos. Saindo...\n");
        }
        else {
            printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
