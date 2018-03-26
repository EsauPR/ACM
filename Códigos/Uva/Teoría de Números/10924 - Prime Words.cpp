/*
    Problem: Prime words
    Url: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1865
*/
#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

#define MAX 1050

bitset<MAX> sieve;

void c_sieve() {
    sieve.set();
    for (int i = 2; i < MAX; i++) {
        if (sieve.test(i)) {
            for (int j = i*2; j < MAX; j+=i) sieve.reset(j);
        }
    }
}

int char_to_num(char character) {
    if ( 'a' <= character && character <= 'z')
        return character - 'a' + 1;
    if ( 'A' <= character && character <= 'Z')
        return character - 'A' + 27;
    return 0;
}

int word_to_num(char* word) {
    int sum = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        sum += char_to_num(word[i]);
    }
    return sum;
}

int main(int argc, char const *argv[]) {
    char word[30];
    c_sieve();

    while(scanf("%s", word) != EOF) {
        if (sieve.test(word_to_num(word))) {
            printf("It is a prime word.\n");
        } else {
            printf("It is not a prime word.\n");
        }
    }


    return 0;
}
