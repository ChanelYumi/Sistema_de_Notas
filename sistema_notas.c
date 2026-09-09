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
// Realiza o cadastro de um novo aluno e armazena as informações em um vetor

void cadastrar() {
    
	// Verifica se o limite maximo de alunos foi atingido
	if (totalAlunos >= MAX_ALUNOS) {
        printf("Limite de alunos atingido!\n");
        return;
    }

    // Cria uma variavel temporária para armazenar os dados do novo aluno
	struct Aluno novo;
	
	
    // Solicita os dados do aluno
    printf("Digite o nome completo do aluno: ");
    scanf(" %[^\n]", novo.nome);
    
    printf("Digite a matricula do aluno: ");
    scanf("%d", &novo.matricula);
    
    printf("Digite a nota do aluno: ");
    scanf("%f", &novo.nota);
    
    
	// Armazena o novo aluno na posição disponível do vetor
	alunos[totalAlunos] = novo;
	
	// Atualiza a quantidade de alunos cadastrados
	totalAlunos = totalAlunos + 1;
    
    printf("\nAluno cadastrado com sucesso!");

}

// ----- FUNCAO LISTAR -----
// Exibe os dados de todos os alunos cadastrados

void listar (){
	
	// Verifica se existem alunos cadastrados
	if(totalAlunos == 0){
		printf("Nenhum aluno cadastrado.\n");
		return;
	}
	
	for (int i = 0; i < totalAlunos; i++){
		
		printf("\n--- ALUNO %d ---\n", i + 1);
		printf("Nome: %s\n", alunos[i].nome);
		printf("Matricula: %d\n", alunos[i].matricula);
		printf("Nota: %.2f\n", alunos[i].nota);
		
	}
			
}

// ----- FUNCAO BUSCAR -----
// Busca um aluno cadastrado através da matricula


void buscar(){
	
	
	// Variavel que armazena a matricula que sera procurada
	int matriculaBusca;
	
	printf("Digite a matricula do aluno: ");
	scanf("%d", &matriculaBusca);
	
	// Controla se o Aluno foi encontrado
	// 0 = não encontrado | 1 = encontrado
	int encontrou = 0;
	
	
	// Percorre os alunos cadastrados
	for (int i = 0; i < totalAlunos; i++ ) {
		
		
		// Compara a matricula buscada com a do aluno atual
		if (alunos[i].matricula == matriculaBusca){
			
			
			// Exibe os dados do aluno caso tenha encontrado
			printf("Nome: %s\n", alunos[i].nome);
			printf("Matricula: %d\n", alunos[i].matricula);
			printf("Nota: %.2f\n", alunos[i].nota);
			
			encontrou = 1;
		}
		
	} 
	
	// Caso nenhum aluno tenha sido encontrado
	if (encontrou == 0) {
		printf("Aluno não encontrado.");
	}
			
}
    // ----- FEITO -----
    // - Colega 1: Criada a struct Aluno (guarda nome, matricula e nota)
    // e começada a funcao cadastrar() (ja tem a verificacao de limite
    // e a variavel "novo" pronta pra usar).
    
    // - colega 2: terminar a funcao cadastrar() (perguntar nome, matricula,
    // nota, e guardar o aluno na lista) + fazer a funcao listar()
    // e fazer a funcao buscar()
    
	// ----- FALTA -----
	// - Colega 3:
	//funcao main() (menu principal)
