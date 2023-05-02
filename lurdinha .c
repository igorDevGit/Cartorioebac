#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respos�vel por cuidar das string

int registro()//fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
    char cargo[40];
	//final da cria��o de variaveis/string
	
	printf("Digite o CPF a ser cadastrado;");//Coletando informa��es do usu�rio
	scanf("%s", cpf); //"%s" refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salva o valor da variavel 
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo,"a"); //Cria o arquivo e o "a" significa atualizar
	fprintf(file,","); //salva o valor da variavel
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s",nome); //"%s" refere-se a string
	
	file = fopen(arquivo,"a"); //Cria o arquivo e o "a" significa atualizar
	fprintf(file,nome); //Salva o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Cria o arquivo e o "a" significa atualizar
	fprintf(file, ","); //Salva o valor da variavel
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s", sobrenome); //"%s" refere-se a string 
	
	file = fopen(arquivo, "a"); //Cria o arquivo e o "a" significa atualizar
	fprintf(file,sobrenome); //salva o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Cria o arquivo e o "a" significa atualizar
	fprintf(file, ","); //Salva o valor da variavel
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado; "); //Coletando informa��es do usu�rio
	scanf("%s", cargo); //"%s" refere-se a string
	
	file = fopen(arquivo, "a"); //Cria o arquivo e o "a" significa atualizar
	fprintf(file,cargo); //Salva o valora da variavel
	fclose(file); //Fecha o arquivo
	
	system("pause"); //Pausa a tela
	
	
	
	
}

int consulta()
{
	setlocale(LC_ALL, "portuguese"); //definindo a linguagem
	
	//inicio cria��o de variavel /string
	char cpf[40];
	char conteudo[200];
	//Fim da cria��o de variavel /string
	printf("Digite o CPF a ser consultado: "); //Coletando informa��es do usu�rio
	scanf("%s",cpf); //"%s" refere-se a string
	
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�p localizado!.\n");
	}
	
    while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");	
	}
	system("pause");
	
}

int main()
{
	int opcao=0; //definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
	
    	setlocale(LC_ALL, "portuguese"); //definindo a linguagem
	
	    printf("### Cartorio da EBAC ###\n\n"); // Inicio do menu
	    printf("escolha a opcao desejada no menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n"); 
	    printf("op��o: "); //Fim do menu
	    
    	scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
    	system("cls"); //Responsavel por limpar a tela
    	
    	
    	switch(opcao) //Inicio da sele��o do menu
    	{
    		case 1:
    		registro(); //Chamada de fun��es
		    break;
		    
		    case 2:
		    consulta();
		    break;
		    
		    case 3:
		   deletar();  	
		    break;
		    
		    case 4:
		    printf("Obrigado por utilizar o sistema\n");
		    return 0;	
		    break;
		    
		    default:
		    printf("Essa op��o n�o est� disponivel!\n");
	        system("pause");
	        break;
		}
	
	   

    }
 
}
