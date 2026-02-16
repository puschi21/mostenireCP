#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char full_line[256];
    char date[11]; // Salvat ca yyyy.mm.dd pentru sortare usoara
    char name[26]; // Adaugat pentru sortarea primara
} Record;

int compare(const void *a, const void *b) {
    Record *r1 = *(Record**)a;
    Record *r2 = *(Record**)b;

    // 1. Sortare primara dupa NAME
    int name_cmp = strcmp(r1->name, r2->name);
    if (name_cmp != 0) {
        return name_cmp;
    }

    // 2. Daca numele sunt identice, sortare secundara dupa DATE (yyyy.mm.dd)
    return strcmp(r1->date, r2->date);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Error: argumente insuficiente\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: nu pot deschide fisierul\n");
        return 1;
    }

    // Foloseste atof pentru float
    float threshold = atof(argv[2]);

    Record **list = NULL;
    char buffer[256];
    int count = 0;

    while (fgets(buffer, sizeof(buffer), fp)) {
        int d, m, y;
        char name[26];
        float fn;
        
        // sscanf returneaza numarul de elemente citite cu succes (trebuie sa fie 5)
        if (sscanf(buffer, "%d.%d.%d %s %f", &d, &m, &y, name, &fn) == 5) {
            if (fn > threshold) {
                Record **temp = realloc(list, (count + 1) * sizeof(Record*));
                if (temp != NULL) {
                    list = temp;
                    list[count] = malloc(sizeof(Record*));
                    
                    // Salveaza numele pentru sortare
                    strcpy(list[count]->name, name);
                    
                    // Salveaza data in format ISO (AN.LUNA.ZI) pentru strcmp
                    sprintf(list[count]->date, "%04d.%02d.%02d", y, m, d);
                    
                    // Pastreaza linia originala pentru afisare
                    strcpy(list[count]->full_line, buffer);
                    count++;
                }
            }
        }
    }

    if (count > 0) {
        qsort(list, count, sizeof(Record*), compare);
        for (int i = 0; i < count; i++) {
            printf("%s", list[i]->full_line);
            free(list[i]);
        }
    }

    free(list);
    fclose(fp);
    return 0;
}