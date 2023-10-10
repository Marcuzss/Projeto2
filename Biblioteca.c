#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Biblioteca.h"

void novoCliente(Cliente *clientes, int *numClientes) {
    if (*numClientes == 1000) {
        printf("Número máximo de clientes atingido.\n");
        return;
    }

    Cliente cliente;
    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", cliente.nome);
    printf("Digite o CPF do cliente: ");
    scanf(" %[^\n]", cliente.cpf);
    printf("Digite o tipo de conta (comum ou plus): ");
    scanf(" %[^\n]", cliente.tipoConta);
    printf("Digite o valor inicial da conta: ");
    scanf("%lf", &cliente.saldo);
    printf("Digite a senha do cliente: ");
    scanf(" %[^\n]", cliente.senha);

    clientes[*numClientes] = cliente;
    (*numClientes)++;

    printf("Novo cliente cadastrado com sucesso.\n");
}

void apagaCliente(Cliente *clientes, int *numClientes) {
    char cpf[12];
    printf("Digite o CPF do cliente a ser apagado: ");
    scanf(" %[^\n]", cpf);

    int i;
    for (i = 0; i < *numClientes; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {
            int j;
            for (j = i; j < *numClientes - 1; j++) {
                clientes[j] = clientes[j + 1];
            }
            (*numClientes)--;
            printf("Cliente apagado com sucesso.\n");
            return;
        }
    }

    printf("CPF não encontrado.\n");
}

void listarClientes(Cliente *clientes, int numClientes) {
    int i;
    for (i = 0; i < numClientes; i++) {
        printf("Nome: %s\n", clientes[i].nome);
        printf("CPF: %s\n", clientes[i].cpf);
        printf("Tipo de conta: %s\n", clientes[i].tipoConta);
        printf("Saldo: %.2lf\n", clientes[i].saldo);
        printf("---------------\n");
    }
}

void debito(Cliente *clientes, int numClientes) {
    char cpf[12], senha[20];
    double valor;

    printf("Digite o CPF do cliente: ");
    scanf(" %[^\n]", cpf);
    printf("Digite a senha: ");
    scanf(" %[^\n]", senha);
    printf("Digite o valor: ");
    scanf("%lf", &valor);

    int i;
    for (i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0 && strcmp(clientes[i].senha, senha) == 0) {
            if (strcmp(clientes[i].tipoConta, "comum") == 0) {
                if (valor <= clientes[i].saldo + 1000) {
                    clientes[i].saldo -= valor * 1.05;
                    printf("Débito realizado com sucesso.\n");
                } else {
                    printf("Saldo insuficiente.\n");
                }
            } else if (strcmp(clientes[i].tipoConta, "plus") == 0) {
                if (valor <= clientes[i].saldo + 5000) {
                    clientes[i].saldo -= valor * 1.03;
                    printf("Débito realizado com sucesso.\n");
                } else {
                    printf("Saldo insuficiente.\n");
                }
            } else {
                printf("Tipo de conta inválido.\n");
            }
            return;
        }
    }

    printf("CPF ou senha incorretos.\n");
}

void deposito(Cliente *clientes, int numClientes) {
    char cpf[12];
    double valor;

    printf("Digite o CPF do cliente: ");
    scanf(" %[^\n]", cpf);
    printf("Digite o valor: ");
    scanf("%lf", &valor);

    int i;
    for (i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {
            clientes[i].saldo += valor;
            printf("Depósito realizado com sucesso.\n");
            return;
        }
    }

    printf("CPF não encontrado.\n");
}

void extrato(Cliente *clientes, int numClientes) {
    char cpf[12], senha[20];

    printf("Digite o CPF do cliente: ");
    scanf(" %[^\n]", cpf);
    printf("Digite a senha: ");
    scanf(" %[^\n]", senha);

    int i;
    for (i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0 && strcmp(clientes[i].senha, senha) == 0) {
             char nomeArquivo[100];
            printf("Digite o nome do arquivo para salvar o extrato: ");
            scanf(" %[^\n]", nomeArquivo);

            FILE *arquivo = fopen(nomeArquivo, "w");
            if (arquivo == NULL) {
                printf("Erro ao abrir o arquivo.\n");
                return;
            }

            fprintf(arquivo, "Extrato do cliente: %s\n", clientes[i].nome);
            fprintf(arquivo, "--------------------\n");

            fclose(arquivo);
            printf("Extrato salvo com sucesso.\n");
            return;
        }
    }

    printf("CPF ou senha incorretos.\n");
}

void transferencia(Cliente *clientes, int numClientes) {
    char cpfOrigem[12], senhaOrigem[20], cpfDestino[12];
    double valor;

    printf("Digite o CPF da conta de origem: ");
    scanf(" %[^\n]", cpfOrigem);
    printf("Digite a senha da conta de origem: ");
    scanf(" %[^\n]", senhaOrigem);
    printf("Digite o CPF da conta de destino: ");
    scanf(" %[^\n]", cpfDestino);
    printf("Digite o valor: ");
    scanf("%lf", &valor);

    int i, indexOrigem = -1, indexDestino = -1;
    for (i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i].cpf, cpfOrigem) == 0 && strcmp(clientes[i].senha, senhaOrigem) == 0) {
            indexOrigem = i;
        }
        if (strcmp(clientes[i].cpf, cpfDestino) == 0) {
            indexDestino = i;
        }
    }

    if (indexOrigem != -1 && indexDestino != -1) {
        if (clientes[indexOrigem].saldo >= valor) {
            clientes[indexOrigem].saldo -= valor;
            clientes[indexDestino].saldo += valor;
            printf("Transferência realizada com sucesso.\n");
        } else {
            printf("Saldo insuficiente na conta de origem.\n");
        }
    } else {
        printf("CPF ou senha da conta de origem ou CPF da conta de destino incorretos.\n");
    }
}
