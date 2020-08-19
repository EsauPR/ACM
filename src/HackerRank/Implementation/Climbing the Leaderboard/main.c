#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 200009

int main(int argc, char const *argv[]) {
    int asize, ssize;
    int alice[MAX_SIZE], scores[MAX_SIZE];
    int num, prev = -1;

    scanf("%d", &ssize);

    int pos = 0;
    for (int i = 0; i < ssize; i++) {
        scanf("%d", &num);
        if (num != prev) {
            scores[pos++] = num;
            prev = num;
        }
    }
    ssize = pos;
    scanf("%d", &asize);


    for(int i = 0; i < asize; i++) {
        scanf("%d", &alice[i]);
    }


    int place = ssize + 1;

    for (int i = 0, j=ssize - 1; i < asize; i++) {
        if (j < 0) {
            printf("%d\n", place);
            continue;
        }

        while(j >=0 && alice[i] >= scores[j]) {
            place --;
            j--;
        }

        printf("%d\n", place);

    }

    return 0;
}
