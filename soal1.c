#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nama[100];
    char kategori[100];
    int tahun;
    int nilai;
} Artefak;

int banding(const void *a, const void *b) {
    Artefak *x = (Artefak *)a;
    Artefak *y = (Artefak *)b;

    if (strcmp(x->kategori, y->kategori) != 0)
        return strcmp(x->kategori, y->kategori);

    if (x->tahun != y->tahun)
        return x->tahun - y->tahun;

    if (x->nilai != y->nilai)
        return y->nilai - x->nilai;

    return strcmp(x->nama, y->nama);
}

int main() {
    int n;
    scanf("%d", n);
    Artefak artefak[n];

    for (int i = 0; i<n ; i++) {
        scanf("%s %s %d %d", artefak[i].nama, artefak[i].kategori, &artefak[i].tahun, &artefak[i].nilai);
    }
    qsort(artefak,n, sizeof(Artefak), banding);

    for (int i = 0; i<n; i++) {
        printf("%s %s %d %d\n", artefak[i].nama, artefak[i].kategori, &artefak[i].tahun, &artefak[i].nilai);
    }

    return 0;
}
