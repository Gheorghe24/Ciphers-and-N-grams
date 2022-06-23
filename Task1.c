#include "utils.h"
#define MAX 200
#define ZECE 10

int maxim(int num1, int num2) {
    return (num1 > num2 ) ? num1 : num2;
}

void afisare(int matrix[MAX/2][MAX/2], int N, int M) {
    int i = 0, j = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int64_t oglindit(int64_t n) {
    int64_t ogl = 0, cp_n = n;
    while (cp_n) {
        ogl = ogl*ZECE + cp_n%ZECE;
        cp_n = cp_n/ZECE;
    }
    return ogl;
}

int palindrom(int n) {
    if (n == oglindit(n))
    return 1;
    return 0;
}

int prim(int n) {
    if (n < 2) {
        return 0;
    }
        if (n == 2) {
            return 1;
        }
    for (int i = 2; i < n; i++) {
        if (n%i == 0)
        return 0;
    }
    return 1;
}

void SolveTask1() {
    int N = 0, M = 0;

    char str[MAX]="";

    int matrix[MAX/2][MAX/2];

    int i = 0, dir[MAX] = {0}, j = 0, k = 0;

    scanf("%d %d", &N, &M);
    // citirea cuvintelor de pe linie
    fgets(str, MAX, stdin);
    fgets(str, MAX, stdin);

    char* token = strtok(str, " ");
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            matrix[i][j] = 0;
        }
    }

    j = 0;
    while (token != NULL) {
        int max = 0, poz = 4;
        int64_t val = 0;
        val = atol(token+1);

        if (token[0] == 'a') {
            for (i = 4; i >= 1; i--) {
                if (max < val%ZECE) {
                max = val%ZECE;
                poz = i;}
                val/=ZECE;
            }
        }

        if (token[0] == 'b') {
            if (palindrom(val) && prim(val%100))
            poz = 3;
            if (palindrom(val) && !prim(val%100))
            poz = 1;
            if (!palindrom(val) && !prim(val%100))
            poz = 4;
            if (!palindrom(val) && prim(val%100))
            poz = 2;
        }

        if (token[0] == 'c') {
            int64_t ogl_val = oglindit(val);

            int k = ogl_val % 100 / 10, ck = k, S = 0;

            int n = ogl_val % 10, v_nr[n];
            ogl_val = ogl_val / 100;
            for (i = 0; i < n; i++) {
                v_nr[i] = ogl_val % ZECE;
                ogl_val = ogl_val / ZECE;
            }
            i = 0;
            while (ck) {
                S = S + v_nr[i];
                i += k;

                if (i >= n)
                i = i%n;
                ck--;
            }

            if (S%4 == 0)
            poz = 3;
            if (S%4 == 1)
            poz = 2;
            if (S%4 == 2)
            poz = 1;
            if (S%4 == 3)
            poz = 4;

        }
        dir[j++] = poz;
        token = strtok(NULL, " ");
    }

    int nrcitite = j;
    matrix[0][0] = 1;
    i = j = 0;

    for (int i1 = 0; i1 < nrcitite; i1++) {
         if (dir[i1] == 1) {
                j++;
                matrix[i][j] = (i1+2);
            }
        if (dir[i1] == 2) {
                i--;
                matrix[i][j] = (i1+2);
            }
        if (dir[i1] == 3) {
                j--;
                matrix[i][j] = (i1+2);
            }
        if (dir[i1] == 4) {
                i++;
                matrix[i][j] = (i1+2);
            }
     }
    afisare(matrix, N, M);
}
