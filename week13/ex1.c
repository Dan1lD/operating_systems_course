#include <stdio.h>

int main() {
    const int RES_NUM = 3;
    const int PROC_NUM = 5;

    int E[RES_NUM], A[RES_NUM], C[PROC_NUM][RES_NUM], R[PROC_NUM][RES_NUM];
    int released[PROC_NUM];
    for (int i = 0; i < PROC_NUM; i++) {
        released[i] = 0;
    }

    FILE *file;
    file = fopen("input.txt", "r");
    for (int i = 0; i < RES_NUM; i++) {
        fscanf(file, "%d", &E[i]);
    }

    for (int i = 0; i < RES_NUM; i++) {
        fscanf(file, "%d", &A[i]);
    }

    for (int i = 0; i < PROC_NUM; i++) {
        for (int k = 0; k < RES_NUM; k++) {
            fscanf(file, "%d", &C[i][k]);
        }
    }

    for (int i = 0; i < PROC_NUM; i++) {
        for (int k = 0; k < RES_NUM; k++) {
            fscanf(file, "%d", &R[i][k]);
        }
    }

    for (int left = PROC_NUM; left > 0; left--) {
        for (int proc_id = 0; proc_id < PROC_NUM; proc_id++) {
            int cont = 0;
            for (int res_id = 0; res_id < RES_NUM; res_id++) {
                if (R[proc_id][res_id] > A[res_id] || released[proc_id] == 1) {
                    if (proc_id == PROC_NUM - 1) {
                        for (int cur_proc_id = 0; cur_proc_id < PROC_NUM; cur_proc_id++) {
                            if(released[cur_proc_id] == 0) {
                                printf("%d\n", cur_proc_id);
                            }
                        }
                        return 0;
                    }
                    cont = 1;
                    break;
                }
            }

            if (cont) {
                continue;
            }

            for (int res_id = 0; res_id < RES_NUM; res_id++) {
                A[res_id] += C[proc_id][res_id];
            }

            released[proc_id] = 1;
            break;
        }
    }

    printf("No deadlock detected\n");

    return 0;
}