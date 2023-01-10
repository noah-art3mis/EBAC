#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

int registrar()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	char c;
	
	printf("Digite o CPF: ");
	scanf("%s", cpf);
	strcpy(arquivo, cpf);
	
	FILE *file;	
	file = fopen(arquivo, "w");
	fprintf(file, cpf);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
}

int consultar()
{
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF do usuário a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;	
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("CPF não encontrado.\n");
		system("pause");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEstas são as informações do usuário:\n\n");
		printf("%s", conteudo);
		printf("\n\n");
		system("pause");
	}
}

int remover()
{
	char cpf[40];
	
	printf("Digite o CPF a ser removido: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL)
	{
		printf("\nCPF não encontrado no sistema.\n");
		system("pause");
	}
	else
	{
		remove(cpf);
		printf("\nUsuário removido com sucesso.\n");
		system("pause");
	}
}

int main() 
{
	//definição de variáveis
	int opcao = 0;
	
	// definindo a lingua
	setlocale(LC_ALL, "Portuguese"); 
	
	while (true)
	{
		//menu
		system("cls");
		printf("=== Cartório da EBAC ===\n\n");
		printf("Escolha umas das opções:\n\n");
		
		printf("\t1 - Adicionar usuário\n");
		printf("\t2 - Consultar usuário\n");
		printf("\t3 - Remover usuário\n");
		printf("\nOpção: ");
		
		//pergunta
		scanf("%d", &opcao);
		
		system("cls");
		
		//resposta
		switch(opcao)
		{
			case 1:
			registrar();	
			break;
			
			case 2: 
			consultar();
			break;
			
			case 3:
			remover();
			break;
			
			default:
			printf("essa opção não está disponível\n");
			system("pause");
			break;
		}
	}
}


