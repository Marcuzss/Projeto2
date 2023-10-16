#ifndef CABECALHO_H
#define CABECALHO_H

typedef struct {
    char nome[100];
    char cpf[12];
    char tipoConta[10];
    double saldo;
    char senha[20];
} Cliente;

void novoCliente(Cliente *clientes, int *numClientes);
void apagaCliente(Cliente *clientes, int *numClientes);
void listarClientes(Cliente *clientes, int numClientes);
void debito(Cliente *clientes, int numClientes);
void deposito(Cliente *clientes, int numClientes);
void extrato(Cliente *clientes, int numClientes);
void transferencia(Cliente *clientes, int numClientes);

#endif
