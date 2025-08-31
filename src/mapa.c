#include <stdio.h>
#include <stdlib.h>

int ocupado(int x, int y,) {
    if
    if
    if
    return 0
}

void exibamapa (int maxX, maxY,) {
    printf(mapa %dx%d:\n, maxX, maxY);
    for (int y=0; y<maxY; y++) {
        for (int x=0; x<maxX; x++) {
            char c= '.';
            if (p && p->x==x && p->y==y) c='J';
            else {
                if (inimigo) for (int i=0;i<numinimigo;i++) if (inimigo[i].vivo && inimigo[i].x==x && inimigo[i].y==y) {c='I'; break;}
                if (c=='.' && item) for (int i=0;i<numitem;i++) if (item[i].ativo && item[i].x==x && item[i]. y==y {c='P'; break;}
            }
            printf("%c ", c);
        }
        printf("\n");
    }
    printf("\n");
}

int encontro () {
    if (inimigo) for (int i=o; i<numinimigo;i++) {
        if (inimigo[i].vivo && inimigo[i].x==p->x && inimigo[i].y==p->y) {
            printf("Encontro com um inimigo! Força inimigo=%d, sua força=%d\n", inimigo[i].força, p->força);
            if (p->força > inimigo[i].força) {
                printf("Voce venceu! Voce ganhou %d de força.\n", inimigo[i].força);
                p->força += inimigo[i].forca;
                inimigo[i].vivo = 0;
                return 2
            } else if (p-> forca < inimigo[i].força) {
                printf ("Inimigo é mais forte que voce! Voce foi derrotado. \n");
                return -1;
            }
        }
    }
    if (item) for (int i=0;i<*numitem;i++) {
        if (item[i].ativo && item[i].x==p->x && item[i].y==p->y) {
            if (item[i].tipo==0) {
                p->força += item[i].valor;
                printf("Voce encontrou um item de força +%d!\n", item[i].valor);
            } else {
                p->velocidade += item[i].valor;
                printf("Voce encontrou um item de velocidade +%d!\n", item[i].valor);
            }
            item[i].ativo = 0;
            return 1;
        }
    }
    return 0;
}