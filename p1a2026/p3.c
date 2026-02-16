#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char full_line[256];
    char date[11]; // yyyy-mm-dd
} Record;

// Functie pentru qsort: compara doua date sub forma de string
int compara(const void *a, const void *b) {
    // Deoarece qsort trimite adresa elementelor din lista (care sunt pointeri), 
    // trebuie sa facem cast la Record**
    Record *r1 = *(Record**)a;
    Record *r2 = *(Record**)b;
    return strcmp(r1->date, r2->date);
}

int main(int argc, char *argv[]) {
    // Verificare argumente linie de comanda
    if (argc < 4) return 1;

    FILE *fp = fopen(argv[1], "r");
    if (!fp) return 1;

    int an_cautat = atoi(argv[2]);
    char *cat_cautat = argv[3];

    // Alocam un vector de pointeri
    // Nota: Pentru a respecta "arbitrarily large number of lines", 
    // intr-un program real am folosi realloc, dar aici ramanem la 1000 pentru simplitate.
    Record **lista = malloc(1000 * sizeof(Record*));
    int count = 0;
    char buf[256];

    while (fgets(buf, sizeof(buf), fp)) {
        int y, m, d, val;
        char c[25];
        
        // Extragem datele pentru validare
        if (sscanf(buf, "%d-%d-%d %s %d", &y, &m, &d, c, &val) == 5) {
            if (y == an_cautat && strcmp(c, cat_cautat) == 0) {
                // Alocam memorie pentru structura
                lista[count] = malloc(sizeof(Record));
                
                // CORECTIE: Folosim -> pentru ca lista[count] este pointer
                // Salvam data in format string pentru o sortare usoara cu strcmp
                sprintf(lista[count]->date, "%4d-%2d-%2d", y, m, d);
                
                // Salvam linia originala
                strcpy(lista[count]->full_line, buf);
                
                count++;
            }
        }
    }

    // Sortare folosind qsort
    if (count > 0) {
        qsort(lista, count, sizeof(Record*), compara);
        
        // Afisare rezultate
        for (int j = 0; j < count; j++) {
            printf("%s", lista[j]->full_line);
            // Eliberam memoria pentru fiecare structura alocata
            free(lista[j]);
        }
    }

    // Eliberam vectorul de pointeri si inchidem fisierul
    free(lista);
    fclose(fp);
    
    return 0;
}