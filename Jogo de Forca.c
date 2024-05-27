#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void escolha_da_palavra(), abertura(), forca(), nova_letra(), caveira(), trofeu(), adicionar_palavra();
int repeticao_da_letra(int* i_v), enforcou(), ganhou();

char letras[26], palavra_secreta[100];
int chutes_dados;

void escolha_da_palavra() {
    int i, quantidade_pal, randomico;
    FILE* f;
    f = fopen("palavras.txt", "r");
    if(f==0) {
        printf("Desculpa! Banco de dados não disponível :(\n\n");
        exit(1);
    }
    fscanf(f, "%d", &quantidade_pal);
    srand(time(0));
    randomico = rand()%quantidade_pal;
    for(i=0; i<randomico; i++) {
        fscanf(f, "%s", palavra_secreta);
    }
    fclose(f);
}

void abertura() {
    printf("*************************\n");
    printf("*     Jogo da Forca     *\n");
    printf("*************************\n\n");
}

int repeticao_da_letra(int* i_v) {
    int ach, j;
    for(j=0; j<chutes_dados; j++) {
        ach = 0;
        if(letras[j]==palavra_secreta[(*i_v)]) {
            ach = 1;
            break;
        }
    }
    return ach;
}

void forca() {
    int i, achou, erros;
    erros = enforcou();
    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros>=1?'(':' '), (erros>=1?'_':' '), (erros>=1?')':' '));
    printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), (erros>=2?'|':' '), (erros>=4?'/':' '));
    printf(" |       %c     \n", (erros>=2?'|':' '));
    printf(" |      %c %c   \n", (erros>=5?'/':' '), (erros>=6?'\\':' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");
    for(i=0; i<strlen(palavra_secreta); i++) {
        achou = repeticao_da_letra(&i);
        if(achou) {
            printf("%c ", palavra_secreta[i]);
        }
        else {
            printf("_ ");
        }
    }
    printf("\n");
}

void nova_letra() {
    char chute;
    scanf(" %c", &chute);
    letras[(chutes_dados)] = chute;
    (chutes_dados)++;
}

int enforcou() {
    int achou, erros, i, j;
    for(j=0; j<chutes_dados; j++) {
        achou = 0;
        for(i=0; i<strlen(palavra_secreta); i++) {
            if(letras[j]==palavra_secreta[i]) {
                achou = 1;
                break;
            }
        }
        if(!achou) {
            erros++;
        }
    }
    return erros;
}

void caveira() {
    printf("Você perdeu! :(\n");
    printf("A palavra secreta era %s\n\n", palavra_secreta);
    printf("        _______________         \n");
    printf("       /               \\       \n");
    printf("      /                 \\      \n");
    printf("    //                   \\\\   \n");
    printf("    \\|   XXXX     XXXX   |/    \n");
    printf("     |   XXXX     XXXX   |      \n");
    printf("     |   XXX       XXX   |      \n");
    printf("     |                   |      \n");
    printf("     \\__      XXX      __/     \n");
    printf("       |\\     XXX     /|       \n");
    printf("       | |           | |        \n");
    printf("       | I I I I I I I |        \n");
    printf("       |  I I I I I I  |        \n");
    printf("       \\_             _/       \n");
    printf("         \\_         _/         \n");  
    printf("           \\_______/           \n\n");
}

int ganhou() {
    int i;
    for(i=0; i<strlen(palavra_secreta); i++) {
        if(!repeticao_da_letra(&i)) {
            return 0;
        }
    }
    return 1;
}

void trofeu() {
    printf("Parabéns, você ganhou!\n\n");
    printf("       ___________      \n");
    printf("      '._==_==_=_.'     \n");
    printf("      .-\\:      /-.    \n");
    printf("     | (|:.     |) |    \n");
    printf("      '-|:.     |-'     \n");
    printf("        \\::.    /      \n");
    printf("         '::. .'        \n");
    printf("           ) (          \n");
    printf("         _.' '._        \n");
    printf("        '-------'       \n\n");
}

void adicionar_palavra() {
    int i, quantidade;
    char add, nova_palavra[100];
    printf("Você deseja adicionar uma palavra ao jogo?\n");
    printf("(S\\N)\n");
    scanf(" %c", &add);
    if(add=='S') {
        printf("Qual a nova palavra: ");
        scanf("%s", nova_palavra);
    }
    FILE* f;
    f = fopen("palavras.txt", "r+");
    if(f==0) {
        printf("Desculpa! Banco de dados não disponível :(\n\n");
        exit(1);
    }
    fscanf(f, "%d", &quantidade);
    quantidade++;
    fseek(f, 0, SEEK_SET);
    fprintf(f, "%d", quantidade);
    fseek(f, 0, SEEK_END);
    fprintf(f, "\n%s", nova_palavra);
    fclose(f);
}

int main () {
    chutes_dados = 0;
    escolha_da_palavra();
    abertura();
    while(1) {
        forca();
        nova_letra();
        if(enforcou()>=7) {
            caveira();
            break;
        }
        if(ganhou()) {
            trofeu();
            break;
        }
    }
    adicionar_palavra();
    return 0;
}
