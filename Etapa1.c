#include <stdio.h>
int main()
{

 int numero;

 char email[50], nome[30]; //Aqui, nós declamarmos os tipos e os nomes das variáveis



 printf("Digite seu nome: ");

 scanf("%s", nome); 



 printf("Digite seu email: ");

 scanf("%s", email);  //Logo em seguida, entramos e guardamos os dados fornecidos do tipo char

  

 printf("Digite seu número: ");

 scanf("%d", &numero); //Já aqui, nós entramos e guardamos os dados fornecidos do tipo inteiro



 printf("\nContato Cadastrado:\n");

 printf("-------------------\n");

 printf("Nome: %s\n", nome);

 printf("Telefone: %d\n", numero)

 printf("E-mail: %s", email); //Enquanto ao final, fornecemos ao usuário as suas informações por meio de uma saída(output)



 return 0;



}