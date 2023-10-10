#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"

int main() {
    Cliente clientes[1000];
    int numClientes = 0;
    int opcao;

    do {
        printf("==== MENU ====\n");
        printf("1. Novo cliente\n");
        printf("2. Apaga cliente\n");
        printf("3. Listar clientes\n");
        printf("4. Débito\n");
        printf("5. Depósito\n");
        printf("6. Extrato\n");
        printf("7. Transferência Entre Contas\n");
        printf("0. Sair\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                novoCliente(clientes, &numClientes);
                break;
            case 2:
                apagaCliente(clientes, &numClientes);
                break;
            case 3:
                listarClientes(clientes, numClientes);
                break;
            case 4:
                debito(clientes, numClientes);
                break;
            case 5:
                deposito(clientes, numClientes);
                break;
            case 6:
                extrato(clientes, numClientes);
                break;
            case 7:
                transferencia(clientes, numClientes);
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
