#include <stdio.h> 
#define MAX 10
int K[MAX][MAX];
int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int val[], int n) {
    int i, w;

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]],
                    K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

int main() {
    int i, W, n, profit[MAX], weight[MAX];

    printf("Enter the total number of items\n");
    scanf("%d", & n);
    printf("Enter the total weight\n");
    scanf("%d", & W);
    printf("Enter the profits and weights\n");

    for (i = 0; i < n; i++) {
        scanf("%d%d", & profit[i], & weight[i]);
    }

    printf("Total profit is %d", knapSack(W, weight, profit, n));

    return 0;
}