#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 10

struct carro{
        char marca[50];
        char modelo[50];
        int ano;
        char placa[9];
};

typedef struct carro carro;

void limpar_entrada() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main()
{

    setlocale(LC_ALL, "Portuguese");
    int opcao = 0, i = 0, a = 0;
    char m[50];

    carro lista[TAM];

    do {
        printf("================== CADASTRO DE VEICULOS =====================\n");
        printf("[ 1 ] - Listar os veiculos cadastrados \n");
        printf("[ 2 ] - Inserir um novo veiculo\n");
        printf("[ 3 ] - Listar os veiculos filtrando-se por ano de fabrica��o\n");
        printf("[ 4 ] - Listar veiculos acima do ano especificado\n");
        printf("[ 5 ] - Listar os veiculos filtrando-se pelo modelo\n");
        printf("[ 6 ] - Sair\n");
        printf("Informe a op��o: ");
        scanf("%d", &opcao);
        printf("=============================================================\n");
        switch(opcao){
            case 1:
                //imprimir_lista(lista);
                printf("**** LISTA DE CARROS - UAM ****\n");
                int j = 0, temp = 0;
                if(lista == NULL){
                    printf("N�o h� nenhum ve�culo cadastrado!!\n");
                }else{
                    for(i = 0; i < TAM; i++){
                        printf("Dados do %d� Carro: \n", i + 1);
                        printf("\tMarca: %s\n", lista[i].marca);
                        printf("\tModelo: %s\n", lista[i].modelo);
                        printf("\tAno Fabrica��o: %d\n", lista[i].ano);
                        printf("\tPlaca: %s\n", lista[i].placa);
                    }
                }
                //system("cls");
                break;
            case 2:
                printf("*** CADASTRO DE CARROS UAM ***\n");
                limpar_entrada();
                for(i = 0; i < TAM;i++){
                    printf("\nDados do %d� Carro:\n", i + 1);
                    puts("Marca: ");
                    scanf("%s", &lista[i].marca);
                    fflush(stdin);
                    //limpar_entrada();
                    puts("Modelo: ");
                    scanf("%s", &lista[i].modelo);
                    fflush(stdin);
                    puts("Ano de Fabrica��o: ");
                    scanf("%d", &lista[i].ano);
                    fflush(stdin);
                    puts("Placa do Carro: ");
                    scanf("%s", &lista[i].placa);
                }
                system("cls");
                limpar_entrada();
                break;
            case 3:
                printf("**** LISTA DE CARROS - UAM ****\n");
                printf("Filtro por ano de fabrica��o: \n");
                puts("Informe o ano: ");
                scanf("%d", &a);
                if(lista == NULL){
                    printf("N�o h� nenhum ve�culo cadastrado!!\n");
                }else{
                    for(i = 0; i < TAM; i++){
                        if(lista[i].ano == a){
                            printf("Dados do %d� Carro: \n", i + 1);
                            printf("\tMarca: %s\n", lista[i].marca);
                            printf("\tModelo: %s\n", lista[i].modelo);
                            printf("\tAno Fabrica��o: %d\n", lista[i].ano);
                            printf("\tPlaca: %s\n", lista[i].placa);
                        }
                    }
                }
                break;
            case 4:
                printf("Filtro acima do ano de fabrica��o: \n");
                puts("Informe o ano: ");
                scanf("%d", &a);
                if(lista == NULL){
                    printf("N�o h� nenhum ve�culo cadastrado!!\n");
                }else{
                    for(i = 0; i < TAM; i++){
                        if(lista[i].ano > a){
                            printf("Dados do %d� Carro: \n", i + 1);
                            printf("\tMarca: %s\n", lista[i].marca);
                            printf("\tModelo: %s\n", lista[i].modelo);
                            printf("\tAno Fabrica��o: %d\n", lista[i].ano);
                            printf("\tPlaca: %s\n", lista[i].placa);
                        }
                    }
                }
                break;
            case 5:
                printf("Informe o modelo do Autom�vel: \n");
                scanf("%s", &m);
                if(lista == NULL){
                    printf("N�o h� nenhum ve�culo cadastrado!!\n");
                }else{
                    for(i = 0; i < TAM; i++){
                        if(!strcmp(lista[i].modelo, m)){
                            //strcmp(info[i].nome, busca.nome) == 0
                            printf("Dados do %d� Carro: \n", i + 1);
                            printf("\tMarca: %s\n", lista[i].marca);
                            printf("\tModelo: %s\n", lista[i].modelo);
                            printf("\tAno Fabrica��o: %d\n", lista[i].ano);
                            printf("\tPlaca: %s\n", lista[i].placa);
                        }
                    }
                }
                break;
        }
        printf("=============================================================\n");
    }while(opcao != 6);
        printf("PROGRAMA ENCERRADO!!!");
    return 0;
}
