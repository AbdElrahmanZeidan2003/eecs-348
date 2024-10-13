#include <stdio.h>
#include <stdlib.h>

#define MONTHS 12

void printSales(double sales[]);
void computeStats(double sales[]);
void movingAvg(double sales[]);
void sortSales(double sales[]);

int main() {
    double sales[MONTHS];
    FILE *fp = fopen("sales.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    for (int i = 0; i < MONTHS; i++) {
        fscanf(fp, "%lf", &sales[i]);
    }
    fclose(fp);

    printSales(sales);
    computeStats(sales);
    movingAvg(sales);
    sortSales(sales);

    return 0;
}

void printSales(double sales[]) {
    const char *months[MONTHS] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };

    printf("\nMonthly Sales Report for 2024\nMonth\tSales\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%s\t$%.2f\n", months[i], sales[i]);
    }
}

void computeStats(double sales[]) {
    double min = sales[0], max = sales[0], sum = 0, avg;
    for (int i = 1; i < MONTHS; i++) {
        if (sales[i] < min) min = sales[i];
        if (sales[i] > max) max = sales[i];
        sum += sales[i];
    }
    avg = sum / MONTHS;
    printf("\nSales summary report:\nMin sales: $%.2f\nMax sales: $%.2f\nAvg sales: $%.2f\n", min, max, avg);
}

void movingAvg(double sales[]) {
    printf("\nSix-Month Moving Average Report:\n");
    for (int i = 0; i <= MONTHS - 6; i++) {
        double sum = 0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        printf("%s-%s\t$%.2f\n", months[i], months[i+5], sum / 6);
    }
}

void sortSales(double sales[]) {
    double temp;
    const char *months[MONTHS] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };
    int idx[MONTHS];
    for (int i = 0; i < MONTHS; i++) {
        idx[i] = i;
    }


    for (int i = 0; i < MONTHS - 1; i++) {
        for (int j = 0; j < MONTHS - 1 - i; j++) {
            if (sales[j] < sales[j + 1]) {
                temp = sales[j];
                sales[j] = sales[j + 1];
                sales[j + 1] = temp;

                int tempIdx = idx[j];
                idx[j] = idx[j + 1];
                idx[j + 1] = tempIdx;
            }
        }
    }

    printf("\nSales Report (Highest to Lowest):\nMonth\tSales\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%s\t$%.2f\n", months[idx[i]], sales[i]);
    }
}
