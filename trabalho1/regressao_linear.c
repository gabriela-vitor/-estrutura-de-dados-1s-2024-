#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x;
    float y;
}Ponto;

void calcularMediaX(Ponto *pontos, int qtd, float *xmedia){
    *xmedia = 0;
    for(int i = 0; i < qtd; i++){
        *xmedia += pontos[i].x;
    }
    *xmedia /= qtd;
}

void calcularMediaY(Ponto *pontos, int qtd, float *ymedia){
    *ymedia = 0;
    for(int i = 0; i < qtd; i++){
        *ymedia += pontos[i].y;
    }
    *ymedia /= qtd;
}

float calcularInclinacao(Ponto *pontos, int qtd, float xmedia, float ymedia){
    float numerador = 0;
    float denominador = 0;
    for (int i = 0; i < qtd; i++) {
        numerador += (pontos[i].x - xmedia) * (pontos[i].y - ymedia);
        denominador += (pontos[i].x - xmedia) * (pontos[i].x - xmedia);
    }
    return numerador / denominador;
}

float calcularIntercepcao(Ponto *pontos, int qtd, float xmedia, float ymedia){
    float inclinacao = calcularInclinacao(pontos, qtd, xmedia, ymedia);
    return ymedia - inclinacao * xmedia;
}

int main(int argc, char *argv[]){

    FILE *dados_csv = fopen(argv[1], "r");
    if(dados_csv == NULL){
        printf("ERRO AO ABRIR O ARQUIVO.\n");
        return 1;
    }

    int qtd = 0;

    while(fgetc(dados_csv) != EOF){
        if(fgetc(dados_csv) == '\n'){
            qtd++;
        }
    }
    rewind(dados_csv);

    Ponto *pontos = malloc(qtd * sizeof(Ponto));


    for (int i = 0; i < qtd; i++) {
    if(fscanf(dados_csv, "%d,%f", &pontos[i].x, &pontos[i].y) != 2) {
        printf("Erro ao ler o arquivo dados.csv.\n");
        return 1;
       }
    }
    fclose(dados_csv);

    
    float xmedia;
    float ymedia;
    calcularMediaX(pontos, qtd, &xmedia);
    calcularMediaY(pontos, qtd, &ymedia);
    float inclinacao = calcularInclinacao(pontos, qtd, xmedia, ymedia);
    float intercepcao = calcularIntercepcao(pontos, qtd, xmedia, ymedia);

    printf("y = %.1fx + %.f\n", inclinacao, intercepcao);

}