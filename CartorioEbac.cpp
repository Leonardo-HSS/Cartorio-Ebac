#include <stdio.h> // bliblioteca de comunica��o com o usuario
#include <stdlib.h> //bliblioteca de aloca��o de espa�o em momoria
#include <locale.h> //bliblioteca de aloca��o de texto por regi�o
#include <string.h> //bliblioteca responsavel nas strings


int registro()//fun��o responsavel por cadastrar o usuario no sistema
{
	//inicio da cria��o de variaveis/string
    char arquivo[30];
	char cpf[40];
    char nome[40];
    char sobrenome[80];
    char cargo[40];
    //final da cria��o de variaveis/string
    
    printf("Digite o CPF a ser cadastrado: ");//coletanto informa��o do usuario
    scanf("%s", cpf); //%s se refere a string
    
    strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); // "W" significa escrever
    fprintf(file,"CPF: ");//identa��o do arquivo
	fprintf(file,cpf); //salva o arquivo
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a"); // "a" para atualizar o arquivo
    fprintf(file,", Nome: ");//identa��o do arquivo
    fclose(file);//fecha o arquivo
    
    printf("Digite o NOME a ser cadastrado: ");//coletanto informa��o do usuario
    scanf("%s", nome);//armazena informa��o do usuario
    
    file = fopen(arquivo, "a");//abre o arquivo
    fprintf(file, nome);//salva a informa��o do usuario
    fclose(file);//fecha o arquivo
    
    file = fopen(arquivo, "a");//abre o arquivo
    fprintf(file,", Sobrenome: ");//identa��o do arquivo
    fclose(file);//fecha o arquivo
    
    printf("Digite o SOBRENOME a ser cadastrado: ");//coletanto informa��o do usuario
    scanf("%s", sobrenome);//armazena informa��o do usuario
    
    file = fopen(arquivo, "a");//abre o arquivo
    fprintf(file, sobrenome);
    fclose(file);//fecha o arquivo
    
    file = fopen(arquivo, "a");//abre o arquivo
    fprintf(file,", Cargo: ");//identa��o do arquivo
    fclose(file);//fecha o arquivo
    
    printf("Digite o CARGO a ser cadastrado: ");//coletanto informa��o do usuario
    scanf("%s", cargo);//armazena informa��o do usuario
    
    file = fopen(arquivo, "a");//abre o arquivo
    fprintf(file, cargo);
    fclose(file);//fecha o arquivo
}


int consultar()//fun��o responsavel por consultar o usuario no sistema
{
	setlocale(LC_ALL, "portuguese"); // para fazer uso da localiza��o em uma fun��o diferente e mesma deve ser posta dentro da nova fun��o
	
	//inicio da cria��o de string
    char cpf[40];
    char conteudo[200];
    //final da cria��o de string
    
	printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);//coletando informa��o do usuario
    
    FILE *file;//abrindo arquivo
    file = fopen(cpf,"r"); // "r" para ler o arquivo
    
    if(file == NULL)//arquivo n�o localizado
	{
	    printf("\nRegistro n�o encontrado\n\n");
	}
    
    while(fgets(conteudo, 200, file) != NULL)//arquivo localizado
	{
	    printf("\nInforma��es do usuario - ");
	    printf("%s", conteudo);
	    printf("\n\n");
	    
	}
	fclose(file);
	system("pause");
    
}


int excluir()//fun��o para excluir o usuario do sistema
{
    setlocale(LC_ALL, "portuguese");//localiza��o
   
	char cpf[40];//string
    
    
	printf("Digite o CPF do usuario que deseja excluir: ");
    scanf("%s",cpf);//coletando informa��o do usuario
    
	
	if(remove(cpf) != 0)//usuario n�o encontrado
	{
	    printf("Usuario n�o cadastrado\n");
	    system("pause");
	}else//usuario encontrado
	{
	    printf("Usuario: %s deletado com sucesso\n", cpf);
	    system("pause");
	}
  
}


int main()//fun��o principal
{
    int opcao=0; //variavel de escolha 1
	
	int laco=1; //variavel de repeti��o 1
	
	for(laco=1;laco=1;) //inicio da repeti��o 1
	{
	    system("cls");//limpar a tela
	    
	    setlocale(LC_ALL, "portuguese"); //Definindo linguagem
    
	
	    printf("  ##### Cart�rio da Ebac #####\n\n"); //Inicio do menu
        printf("Escolha a op��o desejada do menu:\n\n");
        printf("1 - Registrar nomes\n");
        printf("2 - Consultar nomes\n");
        printf("3 - Excluir nomes\n");
		printf("4 - Sair\n");
		printf("\nOp��o: "); //final do menu
    
        scanf("%d" , &opcao); //Armazenando a escolha do usuario
    
        system("cls"); //responsavel por limpar a tela
    
        
		switch(opcao) //Sistema de escolha 1
		{
		    case 1:
			registro(); //chamada de fun��es
	        break;
	        
	        case 2:
		    consultar(); //chamada de fun��es
	        break;
	        
	        case 3:
			excluir(); //chamada de fun��es
	        break;
	       
		    case 4:
			printf("Obrigado por utilizar o sistema\n");
			return 0;
			break;
			 
	        default://op��o invalida
			printf("Essa op��o n�o esta disponivel\n"); 
	        system("pause");
		    break;
		}
			
	
   } //final da repeti��o 1
	
	
}

