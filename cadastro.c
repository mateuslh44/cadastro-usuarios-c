#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    char nome[80];
    char cpf[50];
    char endereco[90];
    int idade;
}usuario;

void ler_dados(usuario *p){
    printf("digite nome: ");
    fgets(p->nome, 80, stdin);
    p->nome[strcspn(p->nome, "\n")] = '\0';

    printf("digite CPF: ");
    fgets(p->cpf, 50, stdin);
    p->cpf[strcspn(p->cpf, "\n")] = '\0';

    printf("digite endereco: ");
    fgets(p->endereco, 90, stdin);
    p->endereco[strcspn(p->endereco, "\n")] = '\0';

    printf("digite idade: ");
    scanf("%d", &p->idade);

    while(getchar() != '\n');
    system("cls");
}

void cadastro(usuario *p){
    for(int i = 0; i < 5; i++){
        printf("======CADASTRO======\n");
        ler_dados(&p[i]);
    }
}

void pesquisa(usuario *p){
    int i, flag = 0;
    char pesq[80];

    printf("pesquise um nome cadastrado");
    fgets(pesq, 80, stdin);
    pesq[strcspn(pesq, "\n")] = '\0';
    system("cls");
    
    for(i = 0; i < 5; i++){
        if(strcmp(pesq, p[i].nome) == 0){
            printf("nome: %s \n cpf: %s \n endereco: %s \n idade: %d \n ", p[i].nome, p[i].cpf, p[i].endereco, p[i].idade);
            flag = 1;
        }
    }
    if(flag == 0){
        printf("usuario nao encontrado");
    }
    while(getchar() != '\n');
    system("cls");
}

void classificacao(usuario *p){
    int i, j;
    usuario tr;
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5 - i; j++){
            if(strcmp(p[j].nome, p[j+1].nome) < 0){
                tr = p[j];
                p[j] = p[j+1];
                p[j+1] =  tr;
            }
        }
        printf("%d- %s \n",i+1, p[j].nome);
    }
    printf("aperte enter para continuar");
    while(getchar() != '\n');
    system("cls");
}

void alteracao(usuario *p){
    int i;
    printf("digite numero do usuario: ");
    scanf("%d", &i);
    while(getchar() != '\n');
    
    if(i >= 1 && i <= 5){
        ler_dados(&p[i]);
    }else{
        printf("usuario nao encontrado");
    }
    printf("aperte enter para continuar");
    while(getchar() != '\n');
    system("cls");
}


int main(){
    usuario usuario[5];
    int op;
    do{
        printf("1- para cadastro\n");
        printf("2- para pesquisa\n");
        printf("3- para alteracao\n");
        printf("4- para classificacao\n");
        printf("5- para sair\n");
        scanf("%d", &op);

        while(getchar() != '\n');
        system("cls");
        switch(op){
            case 1:cadastro(usuario); break;
            case 2:pesquisa(usuario); break;
            case 3:alteracao(usuario); break;
            case 4:classificacao(usuario);break;
            case 5:printf("saindo do progama");break;
        }
    }while(op != 5);
}