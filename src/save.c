#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

int salvarJogo(const char  *filename, Personagem, int maxX, int maxY, Inimigo, int numinimigo, Item, int numitem) {
    FILE *f = fopen(filename, "w");
    if (!f) return 0;
    fprintf(f, "%s\n", p->nome);
    fprintf(f, "%d %d %d %d\n", p->forca, p->velocidade, p->x, p->y);
    fprintf(f, "%d %d\n", maxX, maxY);
    fprintf(f, "%d\n", numinimigo);
    for (int i=0;i<numinimigo;i++) fprintf(f, "%d %d %d %d\n", inimigo[i].x, inimigo[i].y, inimigo[i].forca, inimigo[i].vivo);
    fprintf(f, "%d\n", numitem);
    for (int i=0;i<numitem;i++) fprintf(f, "%d %d %d %d %d\n", item[i].x, item[i].y, item[i].tipo, item[i].valor, item[i].ativo);
    fclose(f);
    return 1;
}

int carregarJogo (const char  *filename, Personagem, int maxX, int maxY, Inimigo, int numinimigo, Item, int numitem) {
    FILE *f = fopen(filename, "r");
    if (!f) return 0;
    char line[256];
    if (!fgets(line sizeof(line), f)) { fclose(f); return 0; }
    size_t L = strlen(line); if (L && line[L-1]=='\n') line[L-1] = '\0';
    strncpy(p->nome, line, 50);
    if (fscanf(f, "%d %d %d %d\n", &p->forca, &p->velocidade, &p->x, &p->y) != 4) { fclose(f); return 0; }
    if (fscanf(f, "%d %d\n", maxX, maxY) != 2) { fclose(f); return 0; }
    if (fscanf(f, "%d\n", numinimigo) != 1) { fclose(f); return 0; }
    if (*numinimigo > 0) {
        *inimigo = (Inimigo*)malloc(sizeof(Inimigo)*(*numinimigo));
        for (int i=0;i<numinimigo;i++) fscanf(f, "%d %d %d %d\n", &(*inimigo)[i].x, &(*inimigo)[i].y, &(*inimigo)[i].forca, &(*inimigo)[i].vivo);
    } else *inimigo = NULL;
    if (fscanf(f, "%d\n", numitem) != 1) { fclose(f); return 0 }
    if (*numitem > 0) {
        *item = (Item*)malloc(sizeof(Item)*(*numitem));
        for (int i=0;i<*numitem;i++) fscanf(f, "%d %d %d %d %d\n", &(*item)[i].x, &(*item)[i].y, &(*item)[i].tipo, &(*item)[i].ativo);
    } else *item = NULL;
    fclose(f);
    return 1;
}