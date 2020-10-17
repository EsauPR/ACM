/*
    https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=233
*/

#include <stdio.h>
#include <stdlib.h>

#define NCHILDS 4
#define MAX_LENGTH 1400

#define FULL 'f'
#define EMPTY 'e'
#define PARENT 'p'


typedef struct quadtree {
    char status;
    struct quadtree *childs[NCHILDS];
} Quadtree;


void clear(Quadtree ** node) {
    if (*node == NULL) {
        return;
    }

    for (int i = 0; i < NCHILDS; i++) {
        clear(&((*node)->childs[i]));
    }

    free(*node);
    *node = NULL;
}


char *insert(Quadtree ** node, char * sequence) {
    if (*sequence == '\0') {
        return sequence;
    }

    if (*node == NULL) {
        *node = (Quadtree *)malloc(sizeof(Quadtree));
        for (int i = 0; i < NCHILDS; ++i) {
            (*node)->childs[i] = NULL;
        }

        (*node)->status = *sequence;
    }

    // Si la el nodo a insert es EMPTY no pasa nada
    if (*sequence == EMPTY) {
        return sequence;
    }

    // Si la secuencuas a insertar is FULL
    // Actualizar el status a FULL sin importar si antes era parent o empty
    if (*sequence == FULL) {
        (*node)->status = FULL;
        return sequence;
    }

    // Si la anteriormente era EMPTY ahora será PARENT
    if ((*node)->status == EMPTY) {
        (*node)->status = PARENT;
    }

    // Insertamos los nodos hijos sin importar si antes era FULL
    // para no perder el order de inserción del árbol

    for (int i = 0; i < NCHILDS; i++)  {
        sequence = insert(&((*node)->childs[i]), sequence + 1);
    }

    // No necesario pero ñom
    return sequence;
}


void print_quadtree(Quadtree *node) {
    if (node == NULL) {
        return;
    }

    printf("%c", node->status);

    if (node->status == FULL || node->status == EMPTY) {
        return;
    }

    for (int i = 0; i < NCHILDS; ++i) {
        print_quadtree(node->childs[i]);
    }

}


int count(Quadtree *node, int node_value) {
    if (node == NULL || node->status == EMPTY) {
        return 0;
    }

    if (node->status == FULL) {
        return node_value;
    }

    int total = 0;

    for (int i = 0; i < NCHILDS; ++i) {
        total += count(node->childs[i], node_value/4);
    }

    return total;
}


int main(int argc, char const *argv[]) {
    char sequence[MAX_LENGTH];
    int ncases;

    scanf("%d", &ncases);

    while(ncases--) {
        Quadtree *root = NULL;
        scanf("%s", sequence);
        // puts(sequence);
        insert(&root, sequence);

        scanf("%s", sequence);
        // puts(sequence);
        insert(&root, sequence);

        // print_quadtree(root);
        // puts("");

        printf("There are %d black pixels.\n", count(root, 32*32));

        clear(&root);
    }

    return 0;
}
