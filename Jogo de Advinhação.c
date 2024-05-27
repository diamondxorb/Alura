#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main () {
    int i, numero_secreto, chute, contagem, dificuldade;
    double pontos;
    srand(time(0));
    numero_secreto = rand()%100;
    pontos = 1000.00;
    printf("\n      P  /_\\  P                           \n");
    printf("     /_\\_|_|_/_\\                           \n");
    printf(" n_n | ||. .|| | n_n         Bem vindo ao    \n");
    printf(" |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação!\n");
    printf("|  | |_|     |_| |  |                        \n");
    printf("|____|  ' _ '  |____|                        \n");
    printf("      \\__|_|__/                             \n\n");
    printf("Escolha um nível de dificuldade:\n");
    printf(" (1)-Fácil\n (2)-Médio\n (3)-Difícil\n\n");
    scanf("%d", &dificuldade);
    switch(dificuldade) {
        case 1:
            contagem = 20;
            break;
        case 2:
            contagem = 10;
            break;
        default:
            contagem = 5;
            break;
    }
    for(i=1; i<=contagem; i++) {
        printf("\nTentativa %d\n", i);
        printf("Digite seu chute: ");
        scanf("%d", &chute);
        if(chute<0) {
            printf("Aqui números negativos não tem lugar!\n");
            continue;
        }
        if(chute==numero_secreto) {
            break;
        }
        if(chute>numero_secreto) {
            printf("O número secreto é menor que seu chute!\n");
        }
        else {
            printf("O número secreto é maior que seu chute!\n");
        }
        pontos-=(abs(chute-numero_secreto)/2.0);
    }
    if(chute==numero_secreto) {
        printf("Parabéns! Você acertou o número secreto com %d tentativas\n", i);
        printf("Sua pontuação final é: %.1lf\n\n", pontos);
        printf("Fim de jogo! Jogue de novo, você é um bom jogador!\n\n");
        printf("\\|/ ____ \\|/  \n");     
        printf(" @~/ ,. \\~@   \n");     
        printf("/_( \\__/ )_\\  \n");  
        printf("   \\__U_/     \n");
    }
    else {
        printf("Você perdeu :(\n");
        printf("Tente de novo!\n");
    }
    return 0;
}
