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
            printf("Encontro com um inimigo! For�a inimigo=%d, sua for�a=%d\n", inimigo[i].for�a, p->for�a);
            if (p->for�a > inimigo[i].for�a) {
                printf("Voce venceu! Voce ganhou %d de for�a.\n", inimigo[i].for�a);
                p->for�a += inimigo[i].forca;
                inimigo[i].vivo = 0;
                return 2
            } else if (p-> forca < inimigo[i].for�a) {
                printf ("Inimigo � mais forte que voce! Voce foi derrotado. \n");
                return -1;
            }
        }
    }
    if (item) for (int i=0;i<*numitem;i++) {
        if (item[i].ativo && item[i].x==p->x && item[i].y==p->y) {
            if (item[i].tipo==0) {
                p->for�a += item[i].valor;
                printf("Voce encontrou um item de for�a +%d!\n", item[i].valor);
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