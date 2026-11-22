#ifndef ENTRADA_H
#define ENTRADA_H

// Funcoes que leem o que o usuario digita, sempre conferindo se e valido.
// Elas ficam repetindo a pergunta ate o usuario digitar algo certo.

int lerInteiro(const char *mensagem);
float lerNota(const char *mensagem);
void lerTexto(const char *mensagem, char *destino, int tamanho);
int confirmar(const char *mensagem);

#endif
