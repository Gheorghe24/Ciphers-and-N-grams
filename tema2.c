#include "utils.h"

int main()
{
    int task_number = 0;
    scanf("%d", &task_number);

    switch (task_number) {
        case 1:
            SolveTask1();
            break;
        case 2:
            SolveTask2();
            break;
        case 3:
            SolveTask3();
            break;
        default:
            printf("Undefined task number.\n");
    }

    return 0;
}
