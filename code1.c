#include <stdio.h>
#include <stdlib.h>

int min(float sales[]);
int max(float sales[]);
float average(float sales[]);
float six_month_average(float sales[], int start);

int main() {
    // read in the file
    FILE *file = fopen("sales_report.txt", "r");
    if (file == NULL) { // handles if the file doesn't exist at path specified
        printf("file DNE");
        return 0;
    }

    const char *months[12] = {
        "January", "February", "March", "April", "May", "June", "July", "August",
        "September", "October", "November", "December",
    };

    float sales[12];
    for (int i = 0; i < 12; i++) {
        // fscanf returns a 1 when the scan is successful
        if (fscanf(file, "%f\n", &sales[i]) != 1) {
            printf("something went wrong!");
            return 0;
        }
    }

    printf("Monthly Sales Report for 2024\n\n");

    printf("Month      Sales\n");
    for (int i = 0; i < 12; i++) {
        printf("%-10s %-.2f\n", months[i], sales[i]);
    }
    
    printf("\nSales summary report:\n\n");

    int i = min(sales);
    printf("Minimum sales: %.2f (%s)\n", sales[i], months[i]);

    i = max(sales);
    printf("Maximum sales: %.2f (%s)\n", sales[i], months[i]);
    
    float sales_avg = average(sales);
    printf("Average sales: %.2f\n", sales_avg);

    printf("\nSix-Month moving average report:\n\n");
    for (int i = 0; i < 6; i++) {
        float sales_avg = six_month_average(sales, i);
        char range[18];
        snprintf(range, 18, "%s-%s", months[i], months[i + 5]);
        printf("%-16s %-.2f\n", range, sales_avg);
    }

    printf("\nSales report (highest to lowest):\n\n");

    /* return an array of indices sorted in descending order based on sales[] values. */
    float temp[12];
    for (int i = 0; i < 12; i++) {
        temp[i] = sales[i];
    }

    printf("Month      Sales\n");
    for (int i = 0; i < 12; i++) {
        int ith_high = max(temp); // ith_high holds the ith highest value in arr
        printf("%-10s %-.2f\n", months[ith_high], sales[ith_high]);
        temp[ith_high] = -1;
    }

    return 0;
}

int min(float sales[]) {
    /* return the index where the minimum value in sales[] is. */
    int low = 0;
    for (int i = 0; i < 12; i++) {
        if (sales[i] < sales[low]) {
            low = i;
        }
    }
    return low;
}

int max(float sales[]) {
    /* return the index where the maximum value in sales[] is. */
    int high = 0;
    for (int i = 0; i < 12; i++) {
        if (sales[i] > sales[high]) {
            high = i;
        }
    }
    return high;
}

float average(float sales[]) {
    /* return the average of sales[]. */
    float res = 0;
    
    for (int i = 0; i < 12; i++) {
        res += sales[i];
    }
    return res / 12;
}

float six_month_average(float sales[], int start) {
    /* return the six-month average (start, start + 5) of sales[]. */
    float res = 0;
    for (int i = start; i < (start + 5); i++) {
        res += sales[i];
    }
    return res / 6;
}
