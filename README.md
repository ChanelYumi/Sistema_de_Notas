# Sistema de Notas

Mini sistema em C para cadastro, consulta e gerenciamento de notas de alunos.

**Integrantes:** Chanel Yumi, Leandro Gonçalves, Mateus Lopes, Pedro Lucca, Marcio Gabriel.

## Objetivo

Sistema completo para cadastrar, listar, buscar, editar e remover alunos, com os dados salvos em arquivo e um relatório da turma (média, maior e menor nota, aprovados e reprovados).

## Funcionalidades

| ID   | Funcionalidade | Como funciona |
|------|----------------|---------------|
| RF01 | Menu principal | Repete até escolher "0 - Sair"; trata opções inválidas e letras |
| RF02 | Cadastrar      | Valida matrícula (positiva e sem repetir), nome (não vazio) e nota (0 a 10) |
| RF03 | Listar         | Tabela com matrícula, nome, nota e situação; avisa se não há alunos |
| RF04 | Buscar         | Por matrícula ou por parte do nome (sem diferenciar maiúscula/minúscula) |
| RF05 | Editar         | Altera nome e nota, com confirmação antes de salvar |
| RF06 | Remover        | Pede confirmação e reorganiza o vetor sem deixar buracos |
| RF07 | Persistência   | Carrega `alunos.txt` ao iniciar e grava a cada alteração e ao sair |
| RF08 | Regra de negócio | Relatório da turma; aprovado com nota maior ou igual a 6,0 |

## Estrutura dos arquivos

| Arquivo | Responsabilidade |
|---------|------------------|
| `main.c` | Menu principal |
| `aluno.h` / `aluno.c` | Struct Aluno, vetor e funções de cadastro, listagem, busca, edição, remoção e relatório |
| `arquivo.h` / `arquivo.c` | Ler e gravar o arquivo `alunos.txt` |
| `entrada.h` / `entrada.c` | Ler o que o usuário digita, com validação |

## Como compilar e executar

```bash
gcc -o sistema main.c aluno.c arquivo.c entrada.c
./sistema
```

No Windows: `gcc -o sistema.exe main.c aluno.c arquivo.c entrada.c` e depois `sistema.exe`.

## Formato do arquivo de dados

Um aluno por linha, no formato `matricula;nota;nome`:

```
1001;8.50;Maria Silva
1002;4.50;Joao Pereira
```
