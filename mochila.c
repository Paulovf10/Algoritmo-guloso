#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct objeto{ //Struct que contem o nome valor e peso de cada item
    char nome[100];
    int peso;
    int valor;
  
};
typedef struct objeto Objeto;

void guloso(Objeto obj[], int peso, int tam){ //Algoritmo guloso
    //Variaveis
    int j=0;
    int total = 0;
    int vtotal = 0;
    for( int i = 0; i<tam; i++){ //Percorre o vetor ja ordenado
        if(total==peso){ //Caso a soma do peso dos itens ja dicioando a mochila seja igual a capicade, finaliza o programa
            break;
        }
         if((obj[i].peso + total) > peso){ // Caso o peso dos itens adiconandos mais o proximo item da caixa exeda o peso 
            i++;                           //limite ele pula para o proximo vetor
        }
        if((obj[i].peso + total) <= peso){ // Caso seja possivel ele adiciona o item a mochila
            printf("------------------Adicionando a mochila---------------------------------\n");
            printf("Nome = %s \n", obj[i].nome); //Printa o nome
            printf("Peso do objeto = %i \n", obj[i].peso); //Printa o peso
            printf("Valor do objeto = %i \n" , obj[i].valor); //Printa o valor
            total = total + obj[i].peso; //Adiciona o peso do objeto ao total da machila
            vtotal = vtotal + obj[i].valor; //Adiciona o valor no valor total ate agora
        }
        j++;
    }
    printf("-----------------Total adicionados a mochila----------------------------------------\n");
    printf("Peso total na mochila: %i\n", total); //Printa o peso total
    printf("Valor total na mochila: %i\n", vtotal); //Printa o valor

}

void InsertionSortPeso(struct objeto *ob,int tamanho){ // Algoritmo de ordenacao para os valores
    int i, j; //Variaveis
    struct objeto aux; // Variavel auxiliar
    for(i = 0;i < tamanho; i++){ //Percorre o vetor
        aux = ob[i]; //adiciona o valor da posiçaõ i na variavel auxiliar
        for(j = i; (j > 0) && (aux.valor > ob[j - 1].valor); j--){ //Percorre o vetor para achar a posicao do item
            ob[j] = ob[j-1]; // Coloca na posicao certa
        }
        ob[j] = aux; //Coloca na posicao correta
    }

}
void main(){
    

    int peso, op = 0, tam; // Variaveis
    printf("Digite o numero de itens: \n");
    scanf("%d", &tam); // Recebe a quantidade de itens
    Objeto obj[tam]; // Cria uma struct com o tamanho desejado
    printf("Digite a capacidade da mochila: \n");
    scanf("%d", &peso); // Rcebe o peso da mochila
    for(int i = 0; i<tam; i++){ // Recebe os itens
        printf("Digite o nome do objeto: ");
        setbuf(stdin, NULL);
        gets(obj[i].nome); //Recebe o nome
        printf("Digite o peso do objeto: ");
        scanf("%d", &obj[i].peso);// Recebe o peso
        printf("Digite o valor do objeto: ");
        scanf("%d", &obj[i].valor);// Recebe o valor
        op++;
        printf("\e[H\e[2J");
    }
    InsertionSortPeso(obj,op);//Ordena os itens
    guloso(obj, peso, tam); // Aplica o algoritmo guloso


}