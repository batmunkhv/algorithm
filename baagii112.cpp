#include <stdio.h>

int max(int a, int b) {
   return (a > b) ? a : b;
}

int main() {
    int val[] = {60, 100, 120,100,150};
    int wt[] = {10, 20, 30,40,50};
    int W = 70;
    int w = W / 10 + 1;
    int n = 5;

    int solution_wt[w][n];
    int solution_val[w][n];

    for (int i = 0; i < w; i++) {
        if (i * 10 >= wt[0]) {
            solution_wt[i][0] = wt[0];
            solution_val[i][0] = val[0];
        } else {
            solution_wt[i][0] = 0;
            solution_val[i][0] = 0;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < w; j++) {
            if (wt[i] <= j * 10) {
                int empty_space = j * 10 - wt[i];
                int empty_space_index = empty_space / 10;

                int prev_solution_wt = solution_wt[empty_space_index][i - 1];
                int prev_solution_val = solution_val[empty_space_index][i - 1];

                int new_solution_val = prev_solution_val + val[i];
                int new_solution_wt = prev_solution_wt + wt[i];

                if (new_solution_val > solution_val[j][i - 1]) {
                    solution_wt[j][i] = new_solution_wt;
                    solution_val[j][i] = new_solution_val;
                } else {
                    solution_wt[j][i] = solution_wt[j][i - 1];
                    solution_val[j][i] = solution_val[j][i - 1];
                }

            } else {
                solution_wt[j][i] = solution_wt[j][i - 1];
                solution_val[j][i] = solution_val[j][i - 1];
            }
        }
    }

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d %d\t", solution_wt[i][j], solution_val[i][j]);
        }
        printf("\n");
    }

    return 0;
}


