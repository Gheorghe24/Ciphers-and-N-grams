#include "utils.h"

#define MAX 1000

void SolveTask3() {

    char s[MAX];
    char text[MAX][35], gasit[MAX][35];
    char * token, * rest = NULL;
    int i = 0;

    while (fgets(s, MAX, stdin)) {
    
      s[strcspn(s, "\n")] = '\0';
      token = strtok_r(s, " .,!;\n", & rest);
      while (token != NULL) {
        snprintf(text[i], "%s", token);
        i++;
        token = strtok_r(NULL, " .,!;\n", & rest);
      }

    }

    int n = i, j = 0, c = 0, k = 0, cn = 1, ok = 0, nr_n_grame = 0;

      for (i = 0; i <= n - 1; i++) {
          c = 1;
          for (j = i + 1; j <= n - 2; j++) {
            if (strcmp(text[i], text[j]) == 0 && strcmp(text[i + 1], text[j + 1]) == 0) {
              c++;
            }
          }

        cn++;
        ok = 1;

          for (k = 0; k <= cn; k++) {
            if (strcmp(text[i], gasit[k]) == 0 && strcmp(text[i + 1], gasit[k + 1]) == 0) {
              ok = 0;
              k = cn;
            }
          }

          if (ok == 1) {
            nr_n_grame++;
          }

          snprintf(gasit[i], "%s", text[i]);
          snprintf(gasit[i + 1], "%s", text[i + 1]);
      }

      printf("%d\n", nr_n_grame);
      cn = 1;
      // reinitializarea vectorului de stringuri "gasit"
      for (i = 0; i <= n; i++) {
        snprintf(gasit[i], "%s", "");
      }

    for (i = 0; i <= n - 1; i++) {
      c = 1;

      for (j = i + 1; j <= n - 2; j++) {
        if (strcmp(text[i], text[j]) == 0 && strcmp(text[i + 1], text[j + 1]) == 0) {
          c++;
        }
      }

      cn++;
      ok = 1;
      for (k = 0; k <= cn; k++) {
        if (strcmp(text[i], gasit[k]) == 0 && strcmp(text[i + 1], gasit[k + 1]) == 0) {
          ok = 0;
          k = cn;
        }
      }

      if (ok == 1) {
        printf("%s %s %d\n", text[i], text[i + 1], c);
      }

      snprintf(gasit[i], "%s", text[i]);
      snprintf(gasit[i + 1], "%s", text[i + 1]);
    }

}