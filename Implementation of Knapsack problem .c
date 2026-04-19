#include <stdio.h>

struct item {
    int wt;
    int pft;
    float ratio;
};

void sort(struct item itm[], int n) {
    struct item temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i; j++) {
            if (itm[j].ratio < itm[j + 1].ratio) {
                temp = itm[j];
                itm[j] = itm[j + 1];
                itm[j + 1] = temp;
            }
        }
    }

    printf("Items sorted by pft/wt ratio:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: wt=%d, pft=%d, ratio=%.2f\n",
               i + 1, itm[i].wt, itm[i].pft, itm[i].ratio);
    }
}

int main() {
    int n;
    float capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct item itm[n];

    for (int i = 0; i < n; i++) {
        printf("Enter item %d weight and profit: ", i + 1);
        scanf("%d %d", &itm[i].wt, &itm[i].pft);
        itm[i].ratio = (float)itm[i].pft / itm[i].wt;
    }

    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    sort(itm, n);

    float totalProfit = 0.0;

    for (int i = 0; i < n; i++) {
        if (capacity >= itm[i].wt) {
            totalProfit += itm[i].pft;
            capacity -= itm[i].wt;
        } 
        else {
            totalProfit += itm[i].ratio * capacity;
            break;
        }
    }

    printf("Maximum profit = %.2f\n", totalProfit);

    return 0;
}

// Code By @saiganesh-A261
