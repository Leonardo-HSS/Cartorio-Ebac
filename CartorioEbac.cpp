#include <stdio.h> // bliblioteca de comunicação com o usuario
#include <stdlib.h> //bliblioteca de alocação de espaço em momoria
#include <locale.h> //bliblioteca de alocação de texto por região
#include <string.h> //bliblioteca responsavel nas strings


int registro()//função responsavel por cadastrar o usuario no sistema
{
    //inicio da criação de variaveis/string
    char arquivo[30];
    char cpf[40];
    char nome[40];
    char sobrenome[80];
    char cargo[40];
    //final da criação de variaveis/string
    
    printf("Digite o CPF a ser cadastrado: ");//coletanto informação do usuario
    scanf("%s", cpf); //%s se refere a string
    
    strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); // "W" significa escrever
    fprintf(file,"CPF: ");//identação do arquivo
    fprintf(file,cpf); //salva o arquivo
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a"); // "a" para atualizar o arquivo
    fprintf(file,", Nome: ");//identação do arquivo
    fclose(file);//fecha o arquivo
    
    printf("Digite o NOME a ser cadastrado: ");//coletanto informação do usuario
    scanf("%s", nome);//armazena informação do usuario
    
    file = fopen(arquivo, "a");//abre o arquivo
    fprintf(file, nome);//salva a informação do usuario
    fclose(file);//fecha o arquivo
    
    file = fopen(arquivo, "a");//abre o arquivo
    fprintf(file,", Sobrenome: ");//identação do arquivo
    fclose(file);//fecha o arquivo
    
    printf("Digite o SOBRENOME a ser cadastrado: ");//coletanto informação do usuario
    scanf("%s", sobrenome);//armazena informação do usuario
    
    file = fopen(arquivo, "a");//abre o arquivo
    fprintf(file, sobrenome);
    fclose(file);//fecha o arquivo
    
    file = fopen(arquivo, "a");//abre o arquivo
    fprintf(file,", Cargo: ");//identação do arquivo
    fclose(file);//fecha o arquivo
    
    printf("Digite o CARGO a ser cadastrado: ");//coletanto informação do usuario
    scanf("%s", cargo);//armazena informação do usuario
    
    file = fopen(arquivo, "a");//abre o arquivo
    fprintf(file, cargo);
    fclose(file);//fecha o arquivo
}

int consultar()//função responsavel por consultar o usuario no sistema
{
    setlocale(LC_ALL, "portuguese"); // para fazer uso da localização em uma função diferente e mesma deve ser posta dentro da nova função
	
    //inicio da criação de string
    char cpf[40];
    char conteudo[200];
    //final da criação de string
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);//coletando informação do usuario
    
    FILE *file;//abrindo arquivo
    file = fopen(cpf,"r"); // "r" para ler o arquivo
    
    if(file == NULL)//arquivo não localizado
	{
	    printf("\nRegistro não encontrado\n\n");
	}
    
    while(fgets(conteudo, 200, file) != NULL)//arquivo localizado
	{
	    printf("\nInformações do usuario - ");
	    printf("%s", conteudo);
	    printf("\n\n");
	    
	}
	fclose(file);
	system("pause");
}

int excluir()//função para excluir o usuario do sistema
{
    setlocale(LC_ALL, "portuguese");//localização
   
    char cpf[40];//string
    
    printf("Digite o CPF do usuario que deseja excluir: ");
    scanf("%s",cpf);//coletando informação do usuario
    
	if(remove(cpf) != 0)//usuario não encontrado
	{
	    printf("Usuario não cadastrado\n");
	    system("pause");
	}else//usuario encontrado
	{
	    printf("Usuario: %s deletado com sucesso\n", cpf);
	    system("pause");
	}
}

int main()//função principal
{
        int opcao=0; //variavel de escolha 1
	
	int laco=1; //variavel de repetição 1
	
	for(laco=1;laco=1;) //inicio da repetição 1
	{
	    system("cls");//limpar a tela
	    setlocale(LC_ALL, "portuguese"); //Definindo linguagem
	
	    printf("  ##### Cartório da Ebac #####\n\n"); //Inicio do menu
            printf("Escolha a opção desejada do menu:\n\n");
            printf("1 - Registrar nomes\n");
            printf("2 - Consultar nomes\n");
            printf("3 - Excluir nomes\n");
	    printf("4 - Sair\n");
	    printf("\nOpção: "); //final do menu
    
            scanf("%d" , &opcao); //Armazenando a escolha do usuario
            system("cls"); //responsavel por limpar a tela
    
		switch(opcao) //Sistema de escolha 1
		{
		     case 1:
		     registro(); //chamada de funções
	             break;
	        
	             case 2:
		     consultar(); //chamada de funções
	             break;
	        
	             case 3:
		     excluir(); //chamada de funções
	             break;
	       
		     case 4:
		     printf("Obrigado por utilizar o sistema\n");
		     return 0;
		     break;
			 
	             default://opção invalida
		     printf("Essa opção não esta disponivel\n"); 
	             system("pause");
		     break;
	        }	
   } //final da repetição 1		
}

