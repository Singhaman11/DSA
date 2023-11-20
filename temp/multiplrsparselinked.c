#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int row;
    int col;
    int value;
    struct Node* next;
} Node;

void insertNode(Node** head, int row, int col, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->row = row; 
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void MultiplySparseMatrices(Node* matrix1, Node* matrix2, Node** resultMatrix) {
    while (matrix1 != NULL && matrix2 != NULL) {

        

        if (matrix1->row < matrix2->row || (matrix1->row == matrix2->row && matrix1->col < matrix2->col)) {
            insertNode(resultMatrix, matrix1->row, matrix1->col, matrix1->value);
            matrix1 = matrix1->next;
        } else if (matrix1->row > matrix2->row || (matrix1->row == matrix2->row && matrix1->col > matrix2->col)) {
            insertNode(resultMatrix, matrix2->row, matrix2->col, matrix2->value);
            matrix2 = matrix2->next;
        } else {
            int product = matrix1->value * matrix2->value;
            if (product != 0) {
                insertNode(resultMatrix, matrix1->row, matrix1->col, product);
            }
            matrix1 = matrix1->next;
            matrix2 = matrix2->next;
        }
    }

    while (matrix1 != NULL) {
        insertNode(resultMatrix, matrix1->row, matrix1->col, matrix1->value);
        matrix1 = matrix1->next;
    }

    while (matrix2 != NULL) {
        insertNode(resultMatrix, matrix2->row, matrix2->col, matrix2->value);
        matrix2 = matrix2->next;
    }
}

void displaySparseMatrix(Node* matrix) {
    printf("Row\tColumn\tValue\n");
    while (matrix != NULL) {
        printf("%d\t%d\t%d\n", matrix->row, matrix->col, matrix->value);
        matrix = matrix->next;
    }
}

void freeSparseMatrix(Node* matrix) {
    Node* temp;
    while (matrix != NULL) {
        temp = matrix;
        matrix = matrix->next;
        free(temp);
    }
}

int main() {
    Node* matrix1 = NULL;
    Node* matrix2 = NULL;
    Node* resultMatrix = NULL;

    // Initialize and insert elements into matrix1 and matrix2

    // Example matrices
    insertNode(&matrix1, 0, 0, 1);
    insertNode(&matrix1, 1, 1, 2);
    insertNode(&matrix1, 2, 2, 3);

    insertNode(&matrix2, 0, 0, 4);
    insertNode(&matrix2, 1, 1, 5);
    insertNode(&matrix2, 2, 2, 6);

    addSparseMatrices(matrix1, matrix2, &resultMatrix);

    printf("Matrix 1:\n");
    displaySparseMatrix(matrix1);

    printf("Matrix 2:\n");
    displaySparseMatrix(matrix2);

    printf("Resultant Matrix:\n");
    displaySparseMatrix(resultMatrix);

    freeSparseMatrix(matrix1);
    freeSparseMatrix(matrix2);
    freeSparseMatrix(resultMatrix);

    return 0;
}