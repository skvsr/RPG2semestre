#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MAPA 100
#define SAVE_FILE "save.dat"

//Funções salvar e carregar jogo

void salvar() {
    FILE *f = fopen(SAVE_FILE, "wb");
    if (!f) {
        printf("Erro ao salvar!\n");
        return;
    }
    fwrite(&largura, sizeof(int), 1, f);
    fwrite(&altura, sizeof(int), 1, f);
    fwrite(&x, sizeof(int), 1, f);
    fwrite(&jogador, sizeof(Personagem), 1, f);
    fwrite(inimigo, sizeof(Inimigo), x, f);
    fwrite(item, sizeof(Item), x, f);
    fclose(f);
    printf("Jogo salvo com sucesso!");
}

int carregar() {
    FILE *f = fopen(SAVE_FILE, "rb");
    if (!f) {
        return 0;
    }
    fread(&largura, sizeof(int), 1, f);
    fread(&altura, sizeof(int), 1, f);
    fread(&x, sizeof(int), 1, f);
    inimigo = malloc(sizeof(Inimigo) * X);
    item = malloc(sizeof(Item) * X);
    fread(&jogador, sizeof(Personagem), 1, f);
    fread(inimigo, sizeof(Inimigo), x, f);
    fread(item, sizeof(Item), x, f);
    fclose(f);
    return 1;
}

//Funcão para o combate

void combate(Inimigo *inimigo) {
    printf("Voce entrou em um combate!\n");
    printf("%s (Força: %d) contra Inimigo (Força: %d)\n", jogador.nome, jogador.forca, inimigo->forca);

    if (jogador.forca >= inimigo->forca) {
        jogador.forca += inimigo->forca;
        inimigo->vivo = 0;
        printf("Voce venceu! Sua força agora é %d\n", jogador.forca);
    } else {
        jogador.vivo = 0;
        printf("Voce foi derrotado!\n GAME OVER");
    }
}

// Funçao de movimento

void movimentacao(char mover) {
    int dx = 0, dy = 0;
    if (mover == "w") dy = jogador.velocidade;
    else if (mover == "s") dy = jogador.velocidade;
    else if (mover == "a") dx = jogador.velocidade;
    else if (mover == "d") dx = jogador.velocidade;

    int UX = jogador.x + dx;
    int UY = jogador.y + dy;
    
    if (int i = 0; i < x; i++) {
        if (inimigo[i].vivo && inimigo[i].x == jogador.x && inimigo[i].y == jogador[i].y) {
            combate(&inimigo[i]);
        }
        if (item[i].ativo && item[i].x == jogador.x && item[i].y == jogador.y) {
            jogador.forca += item[i].bonus;
            jogador.velocidade++;
            item[i].ativo = 0;
            printf("Voce encontrou um item! Força adicionada %d, Velocidade +1\n", item[i],bonus);
        }
    } else {
        printf("Movimento Invalido!\n");
    }
}


int main(){

printf("-------------------------------------------------\n");
printf("             BEM VINDO AO RPG GAME               \n");
printf("-------------------------------------------------\n");

printf("                    JOGO POR                     \n");
printf("        Samuel Pinheiro e Samuel Rodrigues       \n");



}
