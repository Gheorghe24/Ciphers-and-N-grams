#include "utils.h"
#define MAX 1000
#define Max_Cif 10

void decriptare_c(char s[MAX], int nr) {
    int i;

    for (i = 0; i < strlen(s); i++) {

            if (s[i] <= 'z' && s[i] >= 'a') {
                if (s[i] - nr % 26 < 'a') {
                    s[i] = 'z' + 1 + s[i] - (nr % 26) - 'a';
                } else {
                    s[i] = s[i] - (nr % 26);
                }
            }

        }
    
    for (i = 0; i < strlen(s); i++) {

        if (s[i] <= 'Z' && s[i] >= 'A') {
            if (s[i] - nr % 26 < 'A') {
                s[i] = 'Z' + 1 + s[i] - nr % 26 - 'A';
            } else {
                s[i] = s[i] - nr % 26;
            }
        }

    }
    
    for (i = 0; i < strlen(s); i++) {
        if (s[i] <= '9' && s[i] >= '0') {

            if ((s[i] - nr % 10) < '0') {
                s[i] = 10 - nr % 10 + s[i];
            } else {
                s[i] = s[i] - nr % 10;
            }

        }
    }
    
}
void decriptare_v(char s[MAX], char newKey[MAX]) {
    int i = 0, nr = 0, s_lungime = strlen(s);
    int nrMaj[MAX];

    for (i = 0; i < s_lungime; i++) {
            nrMaj[i] = newKey[i] - 'A';
    }

    for (i = 0; i < strlen(s); i++) {
           nr = nrMaj[i];
        if (s[i] <= 'Z' && s[i] >= 'A') {
            if (s[i] - nr % 26 < 'A') {
                s[i] = 'Z' + 1 + s[i] - nr % 26 - 'A';
            } else {
                s[i] = s[i] - nr % 26;
            }
        }
    }

    for (i = 0; i < strlen(s); i++) {
           nr = nrMaj[i];
        if (s[i] <= 'z' && s[i] >= 'a') {
            if (s[i] - nr % 26 < 'a') {
                s[i] = 'z' + 1 + s[i] - (nr % 26) - 'a';
            } else {
                s[i] = s[i] - (nr % 26);
            }
        }
    }

    for (i = 0; i < strlen(s); i++) {
          nr = nrMaj[i];

        if (s[i] <= '9' && s[i] >= '0') {
            if (s[i] - nr % 10 < '0') {
                s[i] = 10 - nr % 10 + s[i];
            } else {
                s[i] = s[i] - nr % 10;
            }
        }
    }

}

void swap2(char *str1, char *str2) {
  char *temp = (char *)malloc((strlen(str1) + 1) * sizeof(char));
  snprintf(temp, "%s", str1);
  snprintf(str1, "%s", str2);
  snprintf(str2, "%s", temp);
  free(temp);
}

char *strrev(char *str) {
    if (!str || !*str)
        return str;
    int i = strlen(str) - 1, j = 0;
    char ch;

    while (i > j) {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i--;
        j++;
    }
    return str;
}

void SolveTask2() {
    char s[MAX], mesaj[Max_Cif], cifru[Max_Cif], s1[MAX], rez[MAX] = {0};
    int nr = 0, i = 0;

    scanf("%s", cifru);
    scanf("%s", mesaj);
    scanf("%s", s);

    if (strcmp(cifru, "caesar") == 0) {
        nr = atoi(mesaj);
        decriptare_c(s, nr);
        printf("%s\n", s);
    }

    if (strcmp(cifru, "vigenere") == 0) {
        int  i , j, s_lungime = strlen(s);
        char newKey[MAX];
        for (i = 0, j = 0; i < s_lungime; i++, j++) {
        if (j == strlen(mesaj))
            j = 0;
        newKey[i] = mesaj[j];
        }
    newKey[i] = '\0';
    // declar un vector in care scriu literele majuscule ca
    // numarul lor in alfabet
    decriptare_v(s, newKey);
    printf("%s\n", s);
    }

    if (strcmp(cifru, "addition") == 0) {
        int len_max = 0, len1 = 0, len2 = 0, len_min = 0, c = 0;
        scanf("%s", s1);

        nr = atoi(mesaj);

        decriptare_c(s, nr);
        decriptare_c(s1, nr);

        len1 = strlen(s), len2 = strlen(s1);

        if (len1 >= len2) {
            len_max = len1;
            len_min = len2;
        } else {
            swap2(s, s1);
            len_min = len1;
            len_max = len2;
        }

        strrev(s);
        strrev(s1);

        for (i = 0; i < len_min; i++) {
            if (s[i] -'0' + s1[i] +c > '9') {
                    rez[i] = s[i] + s1[i] - '0'-10+c;;
                    c = 1;
                } else {
                    rez[i] = s[i]+s1[i]-'0'+c;
                c = 0;
                }
        }

        for (i = len_min; i < len_max; i++) {
            if (s[i] + c > '9') {
                rez[i] = s[i] + c - 10;
                c = 1;
                } else {
                    rez[i] = s[i]+c;
                    c = 0;
                }
        }

        if (c) {
            rez[i] = '1';
            len_max++;
        }

        strrev(rez);
        i = 0;
            while (rez[0] == '0') {
                snprintf(rez, "%s", rez + 1);
            }
            printf("%s\n", rez);
    }

}
