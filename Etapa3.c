#include <stdio.h>
#include <string.h> // Foi-se adicionado essa biblioteca para comparação de strings

#define MAX_CONTATOS 100 //Aqui foi delimitado a quantidade máxima de contatos que poderão ser cadastrados

int main()
{
    int numero[MAX_CONTATOS], valido = 0, arroba, i, qtd = 0, opcao;
    char email[MAX_CONTATOS][100], nome[MAX_CONTATOS][100];
    char busca[100];
    int encontrado; //Aqui nós declaramos os tipos e os nomes das variáveis que iremos utilizar

    do {
        printf("\n===== MENU DE CONTATOS =====\n");
        printf("1 - Cadastrar novo contato\n");
        printf("2 - Listar todos os contatos\n");
        printf("3 - Buscar contato por nome\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: "); //Temos aqui o menu pricipal onde o usuário optará por uma das opções
        scanf("%d", &opcao);
        getchar(); // Tag usada para limpar o buffer

        switch (opcao) {
            case 1: // Cadastro
                if (qtd >= MAX_CONTATOS) {
                    printf("Limite suportado é de apenas 100!\n");
                    break;
                }

                valido = 1;
                arroba = 0;

                printf("Digite seu nome: ");
                scanf("%s", nome[qtd]);

                printf("Digite seu e-mail: ");
                scanf("%s", email[qtd]);

                printf("Digite seu número: ");
                scanf("%d", &numero[qtd]);

                for (i = 0; i < qtd; i++) { // Verificação de igualdasde entre strings
                    if (strcmp(nome[i], nome[qtd]) == 0) {
                        printf("Erro: Já existe um contato com esse nome\n");
                        valido = 0;
                        break;
                    }
                    if (numero[i] == numero[qtd]) {
                        printf("Erro: Já existe um contato com esse número\n");
                        valido = 0;
                        break;
                    }
                    if (strcmp(email[i], email[qtd]) == 0) {
                        printf("Erro: Já existe um contato com esse e-mail\n");
                        valido = 0;
                        break;
                    }// Nesse bloco verifica se o nome, número ou e-mail já estão sendo usados por outro usuário
                }

                if (nome[qtd][0] == '\0') {
                    printf("Erro: Não foi preenchido esse espaço corretamente\n");
                    valido = 0;
                }

                if (numero[qtd] <= 0) {
                    printf("Erro: Não foi preenchido esse espaço corretamente\n");
                    valido = 0;
                }

                for (i = 0; email[qtd][i] != '\0'; i++) {
                    if (email[qtd][i] == '@') {
                        arroba = 1;
                        break;
                    }
                }

                if (!arroba) {
                    printf("Erro: E-mail inválido, insira '@' no seu endereço.\n");
                    valido = 0;
                }
                // Nesse bloco verificamos se os dados estão de acordo com que o sistema espera

                if (valido) {
                    printf("\nContato Cadastrado:\n");
                    printf("-------------------\n");
                    printf("Nome: %s\n", nome[qtd]);
                    printf("Telefone: %d\n", numero[qtd]);
                    printf("E-mail: %s\n", email[qtd]);
                    qtd++;
                }
                break; // Mostra para o usuário que o contato foi salvo, apenas se for válido.

            case 2: // Lista de Contatos
                if (qtd == 0) {
                    printf("Não foi encontrado nenhum contato cadastrado\n");
                } else {
                    printf("\n===== LISTA DE CONTATOS =====\n");
                    for (i = 0; i < qtd; i++) {
                        printf("%d. Nome: %s | Telefone: %d | E-mail: %s\n",
                               i + 1, nome[i], numero[i], email[i]);
                    }
                }
                break; // Exibe todos os contatos cadastrados

            case 3: // Busca por Contatos
                if (qtd == 0) {
                    printf("Nenhum contato cadastrado para buscar.\n");
                } else {
                    printf("Digite o nome que deseja buscar: ");
                    scanf("%s", busca);
                    encontrado = 0;

                    for (i = 0; i < qtd; i++) {
                        if (strcmp(nome[i], busca) == 0) {
                            printf("\nContato encontrado:\n");
                            printf("Nome: %s\nTelefone: %d\nE-mail: %s\n",
                                   nome[i], numero[i], email[i]);
                            encontrado = 1;
                        }
                    }
                    if (!encontrado) {
                        printf("Contato não encontrado.\n");
                    }
                }
                break; //Permite ao usuário buscar contatos pelo nome que já foram salvos

            case 0:
                printf("Programa Encerrado!\n");
                break;

            default:
                printf("Opção inválida!\n"); //Enquanto aqui nós adicionamos a função de caso o usuário não queira nem cadastrar nem consultar
        }

    } while (opcao != 0);

    return 0;
}