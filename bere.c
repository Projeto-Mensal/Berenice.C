#include <stdio.h>
#include <stdlib.h>

// Variáveis globais para armazenar os totais de cada categoria e o troco total
float totalMaterialLimpeza = 0.0;
float totalAlimentos = 0.0;
float totalPadaria = 0.0;
float totaldoDIA = 0.0;
float trocodado = 0.0;
int numeroClientes = 0;


// Função para exibir o menu principal
void exibirMenu() {
    printf("\n==== Menu Principal ====\n");
    printf("1. Material de Limpeza\n");
    printf("2. Venda de Alimentos\n");
    printf("3. Padaria\n");
    printf("4. Pagamento\n");
    printf("5. Sair\n");
    printf("Escolha uma opcao: ");
}

// Função para processar a compra de um item

void processarCompra(float preco, float *totalCategoria) {
    int quantidade;
    printf("Digite a quantidade: ");
    scanf("%d", &quantidade);

    float subtotal = quantidade * preco;
    *totalCategoria += subtotal;

    printf("Subtotal: R$%.2f\n", subtotal);
    printf("Total acumulado: R$%.2f\n", *totalCategoria);
}

// Função para o menu de Material de Limpeza
void menuMaterialLimpeza() {
    int opcao;
    do {
        printf("\n==== Material de Limpeza ====\n");
        printf("11. Detergente - R$1.99\n");
        printf("12. Sabao em Po (1kg) - R$8.99\n");
        printf("13. Esponja - R$1.50\n");
        printf("14. Amaciante (1Lt) - R$15.00\n");
        printf("15. Voltar ao Menu Principal\n");
        printf("Escolha um item: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 11: processarCompra(1.99, &totalMaterialLimpeza); break;
            case 12: processarCompra(8.99, &totalMaterialLimpeza); break;
            case 13: processarCompra(1.50, &totalMaterialLimpeza); break;
            case 14: processarCompra(15.00, &totalMaterialLimpeza); break;
            case 15: break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 15);
}

// Função para o menu de Alimentos
void menuAlimentos() {
    int opcao;
    do {
        printf("\n==== Venda de Alimentos ====\n");
        printf("21. Cafe - R$19.99\n");
        printf("22. Leite (cx) - R$5.90\n");
        printf("23. Arroz (1kg) - R$4.50\n");
        printf("24. Feijao Preto (1kg) - R$8.00\n");
        printf("25. Acucar (1kg) - R$5.00\n");
        printf("26. Voltar ao Menu Principal\n");
        printf("Escolha um item: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 21: processarCompra(19.99, &totalAlimentos); break;
            case 22: processarCompra(5.90, &totalAlimentos); break;
            case 23: processarCompra(4.50, &totalAlimentos); break;
            case 24: processarCompra(8.00, &totalAlimentos); break;
            case 25: processarCompra(5.00, &totalAlimentos); break;
            case 26: break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 26);
}

// Função para o menu da Padaria
void menuPadaria() {
    int opcao;
    do {
        printf("\n==== Padaria ====\n");
        printf("31. Pao de Forma - R$9.50\n");
        printf("32. Pao Integral - R$12.50\n");
        printf("33. Pao Frances (Unid) - R$1.90\n");
        printf("34. Sonho - R$8.50\n");
        printf("35. Voltar ao Menu Principal\n");
        printf("Escolha um item: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 31: processarCompra(9.50, &totalPadaria); break;
            case 32: processarCompra(12.50, &totalPadaria); break;
            case 33: processarCompra(1.90, &totalPadaria); break;
            case 34: processarCompra(8.50, &totalPadaria); break;
            case 35: break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 35);
}

// Função para processar o pagamento
void pagamento() {
    float totalGeral = totalMaterialLimpeza + totalAlimentos + totalPadaria;
    int metodoPagamento;
    
    printf("\n==== Pagamento ====\n");
    printf("Total geral: R$%.2f\n", totalGeral);

    if (totalGeral == 0) {
        printf("Nenhuma compra foi realizada!\n");
        return;
    }

    printf("\nEscolha a forma de pagamento:\n");
    printf("1. Dinheiro (com desconto)\n");
    printf("2. Cartao\n");
    scanf("%d", &metodoPagamento);

    if (metodoPagamento == 1) {  
        float desconto = 0.0;
        if (totalGeral <= 50.00) {
            desconto = totalGeral * 0.05;
        } else if (totalGeral < 100.00) {
            desconto = totalGeral * 0.10;
        } else {
            desconto = totalGeral * 0.18;
        }

        float totalComDesconto = totalGeral - desconto;
        float valorRecebido, troco;

        printf("Total a pagar com desconto: R$%.2f\n", totalComDesconto);
        
        do {
            printf("Digite o valor recebido: ");
            scanf("%f", &valorRecebido);

            if (valorRecebido < totalComDesconto) {
                printf("Valor insuficiente! Digite novamente.\n");
            }
        } while (valorRecebido < totalComDesconto);

        troco = valorRecebido - totalComDesconto;
        
        printf("Troco: R$%.2f\n", troco);
        trocodado += troco;
    
        
    } else if (metodoPagamento == 2) {  // Pagamento por cartão
        int confirmacao;
        printf("Pagamento na maquina realizado? (1 - Sim, 0 - Não): ");
        scanf("%d", &confirmacao);

        if (confirmacao != 1) {
            printf("Pagamento nao concluído. Escolha outra forma de pagamento.\n");
            pagamento();  // Chama a função novamente para tentar outro pagamento
            return;
        }
    } else {
        printf("Opcao invalida! Escolha novamente.\n");
        pagamento();
        return;
    }

    totaldoDIA += totalGeral;
    numeroClientes++;

    // Zera os totais após o pagamento ser concluído
    totalMaterialLimpeza = 0.0;
    totalAlimentos = 0.0;
    totalPadaria = 0.0;

    printf("Pagamento concluído! O total foi zerado para novas compras.\n");
}

int main() {
    int opcao;
    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: menuMaterialLimpeza(); break;
            case 2: menuAlimentos(); break;
            case 3: menuPadaria(); break;
            case 4: pagamento(); break;
            case 5:
                printf("\nEncerrando o sistema...\n");
                printf("Lucro do dia: R$%.2f\n", totaldoDIA);
                printf("Saida de caixa: R$%.2f\n", trocodado);
                printf("Total de clientes durante o dia:%d\n", numeroClientes);
                break;
            default: printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}
