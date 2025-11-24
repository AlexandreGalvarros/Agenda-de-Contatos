#include <stdio.h>

int main()
{
 int numero, valido = 1, arroba = 0, i;
 char email[50], nome[30]; //Aqui, nós declamarmos os tipos e os nomes das variáveis

 printf("Digite seu nome: ");
 scanf("%s", nome); 

 printf("Digite seu email: ");
 scanf("%s", email);  //Logo em seguida, entramos e guardamos os dados fornecidos do tipo char

 printf("Digite seu número: ");
 scanf("%d", &numero); //Já aqui, nós entramos e guardamos os dados fornecidos do tipo inteiro
 
 if (nome[0] == '\0') {
        printf("Erro: Não foi preenchido esse espaço, refaça o Cadastrado!\n");
        valido = 0;
    }
    
 if (numero <= 0) {
        printf("Erro: Não foi preenchido corretamente esse espaço!\n");
        valido = 0;
    }
    
 for (i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            arroba = 1;
            break;
        }
    }
    
 if(!arroba) {
        printf("Erro: Não foi preenchido corretamente a parte do e-mail. Por vafor, insira '@' no seu endereço de e-mail\n");
        valido = 0;  //Nesssas três estruturas de decição, verificamos se os dados estão válidos
}
 switch (valido) {
        case 1:

 printf("\nContato Cadastrado:\n");
 printf("-------------------\n");
 printf("Nome: %s\n", nome);
 printf("Telefone: %d\n", numero);
 printf("E-mail: %s", email); //Enquanto ao final, fornecemos ao usuário as suas informações por meio de uma saída(output)
 
 return 0;
}
}