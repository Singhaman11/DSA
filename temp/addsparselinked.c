#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int row;
    int col;
    int value;
    struct Node* next;
} Node;
void insert(Node** head, int row, int col, int value) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->row = row;
    new->col = col;
    new->value = value;
    new->next = NULL;
    if (*head == NULL) {
        *head = new;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new;
    }
}
void Addition(Node* matrix1, Node* matrix2, Node** result) {
    while (matrix1 != NULL && matrix2 != NULL) {
        if (matrix1->row < matrix2->row || (matrix1->row == matrix2->row && matrix1->col < matrix2->col)) {
            insert(result, matrix1->row, matrix1->col, matrix1->value);
            matrix1 = matrix1->next;
        } else if (matrix1->row > matrix2->row || (matrix1->row == matrix2->row && matrix1->col > matrix2->col)) {
            insert(result, matrix2->row, matrix2->col, matrix2->value);
            matrix2 = matrix2->next;
        } else {
            int sum = matrix1->value + matrix2->value;
            if (sum != 0) {
                insert(result, matrix1->row, matrix1->col, sum);
            }
            matrix1 = matrix1->next;
            matrix2 = matrix2->next;
        }
    }
    while (matrix1 != NULL) {
        insert(result, matrix1->row, matrix1->col, matrix1->value);
        matrix1 = matrix1->next;
    }
    while (matrix2 != NULL) {
        insert(result, matrix2->row, matrix2->col, matrix2->value);
        matrix2 = matrix2->next;
    }
}
void Multiply(Node* matrix1, Node* matrix2, Node** result) {
    while (matrix1 != NULL && matrix2 != NULL) {
        if (matrix1->row < matrix2->row || (matrix1->row == matrix2->row && matrix1->col < matrix2->col)) {
            insert(result, matrix1->row, matrix1->col, matrix1->value);
            matrix1 = matrix1->next;
        } else if (matrix1->row > matrix2->row || (matrix1->row == matrix2->row && matrix1->col > matrix2->col)) {
            insert(result, matrix2->row, matrix2->col, matrix2->value);
            matrix2 = matrix2->next;
        } else {
            int product = matrix1->value * matrix2->value;
            if (product != 0) {
                insert(result, matrix1->row, matrix1->col, product);
            }
            matrix1 = matrix1->next;
            matrix2 = matrix2->next;
        }
    }
    while (matrix1 != NULL) {
        insert(result, matrix1->row, matrix1->col, matrix1->value);
        matrix1 = matrix1->next;
    }
    while (matrix2 != NULL) {
        insert(result, matrix2->row, matrix2->col, matrix2->value);
        matrix2 = matrix2->next;
    }
}
void Display(Node* matrix) {
    printf("Row\tColumn\tValue\n");
    while (matrix != NULL) {
        printf("%d\t%d\t%d\n", matrix->row, matrix->col, matrix->value);
        matrix = matrix->next;
    }
}
int main() {
    Node* matrix1 = NULL;
    Node* matrix2 = NULL;
    Node* result = NULL;
    // Initialize and insert elements into matrix1 and matrix2
    // Example matrices
    insert(&matrix1, 0, 0, 1);
    insert(&matrix1, 1, 1, 2);
    insert(&matrix1, 2, 2, 3);
    insert(&matrix2, 0, 0, 4);
    insert(&matrix2, 1, 1, 5);
    insert(&matrix2, 2, 2, 6);
    Addition(matrix1, matrix2, &result);
    printf("Matrix 1:\n");
    Display(matrix1);
    printf("Matrix 2:\n");
    Display(matrix2);
    printf("Resultant Matrix:\n");
    Display(result);
    Multiply(matrix1, matrix2, &result);
    printf("Resultant Matrix:\n");
    Display(result);
    return 0;
}