#include <stdio.h>
#include <stdlib.h>


int char_to_num(char c) {
    if ( 'a' <= c && c <= 'z')
        return c - 'a' + 1;
    return c - 'A' + 27;
}


int is_prime_word(char * word) {
    int sum = 0;
    for (int i=0; word[i] != '\0'; i++) {
        sum += char_to_num(word[i]);
    }

    return sum;
}


int main() {
    char word[25];

    while(scanf("%s", word) != EOF) {
        printf("%d\n", is_prime_word(word));
        if (is_prime_word(word))
            printf("It is a prime word.\n");
        else
            printf("It is not a prime word.\n");
    }
    
    return 0;
}