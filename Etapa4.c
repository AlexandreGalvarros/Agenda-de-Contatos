#include <stdio.h>
#include <string.h> // Foi-se adicionado essa biblioteca para comparação de strings

#define MAX_CONTATOS 100

typedef struct {
    int numero;
    char nome[100];
    char email[100];
} Contato;

Contato contatos[MAX_CONTATOS];

int main()
{
    int valido = 0, arroba, i, qtd = 0, opcao;
    char busca[100];
    int encontrado;//Aqui, nós declamarmos os tipos e os nomes das variáveis

    do {
        printf("\n===== MENU DE CONTATOS =====\n");
        printf("1 - Cadastrar novo contato\n");
        printf("2 - Listar todos os contatos\n");
        printf("3 - Buscar contato por nome\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); //Definimos um tela com entrará com o input de umas das opções escolhidas pelo o usuário

        switch (opcao) {
            case 1:
                if (qtd >= MAX_CONTATOS) {
                    printf("Limite suportado é de apenas 100!\n");
                    break;
                }

                valido = 1;
                arroba = 0;

                printf("Digite seu nome: ");
                scanf("%s", contatos[qtd].nome); 

                printf("Digite seu e-mail: ");
                scanf("%s", contatos[qtd].email); 

                printf("Digite seu número: ");
                scanf("%d", &contatos[qtd].numero);  //Entrada de dados

                // Verificação duplicadas
                for (i = 0; i < qtd; i++) {
                    if (strcmp(contatos[i].nome, contatos[qtd].nome) == 0) {
                        printf("Erro: Já existe um contato com esse nome\n");
                        valido = 0;
                        break;
                    }
                    if (contatos[i].numero == contatos[qtd].numero) {
                        printf("Erro: Já existe um contato com esse número\n");
                        valido = 0;
                        break;
                    }
                    if (strcmp(contatos[i].email, contatos[qtd].email) == 0) {
                        printf("Erro: Já existe um contato com esse e-mail\n");
                        valido = 0;
                        break;
                    }
                }

                // Verificação simples
                if (contatos[qtd].nome[0] == '\0') {
                    printf("Erro: Não foi preenchido esse espaço corretamente\n");
                    valido = 0;
                }
                // Verificação do número
                if (contatos[qtd].numero <= 0) {
                    printf("Erro: Número inválido!\n");
                    valido = 0;
                }

                // Verificação do arroba
                for (i = 0; contatos[qtd].email[i] != '\0'; i++) { // ALTERAÇÃO
                    if (contatos[qtd].email[i] == '@') {
                        arroba = 1;
                        break;
                    }
                }

                if (!arroba) {
                    printf("Erro: E-mail inválido, insira '@'.\n");
                    valido = 0;
                }

                if (valido) {
                    printf("\nContato Cadastrado:\n");
                    printf("-------------------\n");
                    printf("Nome: %s\n", contatos[qtd].nome);
                    printf("Telefone: %d\n", contatos[qtd].numero);
                    printf("E-mail: %s\n", contatos[qtd].email);
                    qtd++;
                }
                break;

            case 2: //Verificação de contats já existentes
                if (qtd == 0) {
                    printf("Não foi encontrado nenhum contato cadastrado.\n");
                } else {
                    printf("\n===== LISTA DE CONTATOS =====\n");
                    for (i = 0; i < qtd; i++) {
                        printf("%d. Nome: %s | Telefone: %d | E-mail: %s\n",
                               i + 1,
                               contatos[i].nome,
                               contatos[i].numero,
                               contatos[i].email);
                    }
                }
                break;

            case 3: //Busca de contatos já existentes
                if (qtd == 0) {
                    printf("Nenhum contato cadastrado para buscar.\n");
                } else {
                    printf("Digite o nome que deseja buscar: ");
                    scanf("%s", busca);
                    encontrado = 0;

                    for (i = 0; i < qtd; i++) {
                        if (strcmp(contatos[i].nome, busca) == 0) {
                            printf("\nContato encontrado:\n");
                            printf("Nome: %s\nTelefone: %d\nE-mail: %s\n",
                                   contatos[i].nome,
                                   contatos[i].numero,
                                   contatos[i].email);
                            encontrado = 1;
                        }
                    }
                    if (!encontrado)
                        printf("Contato não encontrado.\n");
                }
                break;

            case 0:
                printf("Programa Encerrado!\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 0);

   return 0;
}