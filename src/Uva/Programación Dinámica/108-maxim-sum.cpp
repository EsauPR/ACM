//108 - Maximum Sum
#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAX 101

int matrix[MAX][MAX];

int main(int argc, char const *argv[]) {
    int size;
    scanf("%d", &size);

    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            scanf("%d", &matrix[i][j]);
            matrix[i][j] += matrix[i-1][j];
        }
    }

    int sum = 0;
    int maxim = matrix[1][1];

    for (int index_sup = 1; index_sup <= size; index_sup++) {
        for (int index_inf = index_sup; index_inf <= size; index_inf++) {
            sum = 0;
            for(int i = 1; i <= size; i++)
            {
                sum += matrix[index_inf][i] - matrix[index_sup-1][i];
                maxim = max(maxim, sum);
                sum = max(sum, 0);
            }
        }
    }

    printf("%d\n", maxim);

    return 0;
}
