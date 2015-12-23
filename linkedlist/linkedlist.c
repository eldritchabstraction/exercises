#include <stdio.h>
#include <stdlib.h>

struct sll {
    int data;
    struct sll* next;
};

struct sll* initialize_sll(int quantity) {
    int i;
    struct sll *cursor, *prev;

    struct sll *root = (struct sll*)malloc(sizeof(struct sll));
    prev = root;
    for(i = 1; i < quantity; i++) {
        cursor = (struct sll*)malloc(sizeof(struct sll));
        cursor->data = i;
        prev->next = cursor;
        prev = cursor;
    }
    prev->next = NULL;

    return root;
}

void print_sll(struct sll *root) {
    struct sll *cursor = root;
    while(cursor) {
        printf("Index: %d\n", cursor->data);
        cursor = cursor->next;
    }
}

struct sll* delete_element(struct sll *root, int target) {
    struct sll *prev = root;
    struct sll *cursor = root->next;

    if (prev->data == target) {
        return root->next;
    }

    while (cursor) {
        if (cursor-> data == target) {
            prev->next = cursor->next;
            return root;
        }
        prev = cursor;
        cursor = cursor->next;
    }

    printf("We weren't able to find the target entry\n");
    return root;
}
int main(void) {
    struct sll *root = initialize_sll(9);

    print_sll(root);

    root = delete_element(root, 2);

    print_sll(root);
}
