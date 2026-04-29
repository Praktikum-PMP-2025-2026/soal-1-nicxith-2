/* EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 
 * Modul      : Structures and Dynamic Arrays
 * Pembuat    : Saragih, Jan Roman Arthuro
 * NIM        : 13224012 
 * Deskripsi  : Program yang mengsort sebuah input yang ada nama kategori tahun dan nilai
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nama[100];
    char kategori[100];
    int tahun;
    int nilai;
} Artefak;

void tukar(Artefak *a, Artefak *b) {
    Artefak temp = *a;
    *a = *b;
    *b = temp;
}

int lebihDahulu(Artefak a, Artefak b) {
    int cmp = strcmp(a.kategori, b.kategori);
    if (cmp != 0) return cmp < 0;

    if (a.tahun != b.tahun) return a.tahun < b.tahun;

    if (a.nilai != b.nilai) return a.nilai > b.nilai;

    return strcmp(a.nama, b.nama) < 0;
}

int main() {
    int n;
    scanf("%d", &n);

    Artefak *artefak = (Artefak *)malloc(n * sizeof(Artefak));

    int i, j;
    for (i = 0; i < n; i++) {
        scanf("%s %s %d %d", artefak[i].nama, artefak[i].kategori, &artefak[i].tahun, &artefak[i].nilai);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (!lebihDahulu(artefak[j], artefak[j + 1])) {
                tukar(&artefak[j], &artefak[j + 1]);
            }
        }
    }

    for (i = 0; i < n; i++) {
        printf("%s %s %d %d\n", artefak[i].nama, artefak[i].kategori, artefak[i].tahun, artefak[i].nilai);
    }

    free(artefak);
    return 0;
}
