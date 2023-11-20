#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int row;
    int col;
    int value;
} Element;

void multiplySparseMatrices(Element matrix1[], int size1, Element matrix2[], int size2, Element resultMatrix[], int* sizeResult) {
    if (matrix1[size1 - 1].col != matrix2[size2 - 1].row) {
        printf("Invalid matrix dimensions for multiplication.\n");
        *sizeResult = 0;
        return;
    }

    int maxElements = size1 * size2;
    Element tempMatrix[maxElements];

    int k = 0;
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (matrix1[i].col == matrix2[j].row) {
                tempMatrix[k].row = matrix1[i].row;
                tempMatrix[k].col = matrix2[j].col;
                tempMatrix[k].value = matrix1[i].value * matrix2[j].value;
                k++;
            }
        }
    }

    *sizeResult = k;

    for (int i = 0; i < *sizeResult; i++) {
        int row = tempMatrix[i].row;
        int col = tempMatrix[i].col;
        int value = tempMatrix[i].value;

        for (int j = i + 1; j < *sizeResult; j++) {
            if (tempMatrix[j].row == row && tempMatrix[j].col == col) {
                value += tempMatrix[j].value;
                for (int l = j; l < *sizeResult - 1; l++) {
                    tempMatrix[l] = tempMatrix[l + 1];
                }
                (*sizeResult)--;
                j--;
            }
        }

        resultMatrix[i].row = row;
        resultMatrix[i].col = col;
        resultMatrix[i].value = value;
    }
}

void displaySparseMatrix(Element matrix[], int size) {
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%d\t%d\n", matrix[i].row, matrix[i].col, matrix[i].value);
    }
}

int main() {
    int size1, size2;
    printf("Enter the size of the first sparse matrix: ");
    scanf("%d", &size1);

    Element matrix1[size1];
    printf("Enter the elements of the first sparse matrix (row, column, value):\n");
    for (int i = 0; i < size1; i++) {
        scanf("%d %d %d", &matrix1[i].row, &matrix1[i].col, &matrix1[i].value);
    }

    printf("Enter the size of the second sparse matrix: ");
    scanf("%d", &size2);

    Element matrix2[size2];
    printf("Enter the elements of the second sparse matrix (row, column, value):\n");
    for (int i = 0; i < size2; i++) {
        scanf("%d %d %d", &matrix2[i].row, &matrix2[i].col, &matrix2[i].value);
    }

    Element resultMatrix[size1 * size2];
    int sizeResult;

    multiplySparseMatrices(matrix1, size1, matrix2, size2, resultMatrix, &sizeResult);

    printf("Resultant Sparse Matrix:\n");
    displaySparseMatrix(resultMatrix, sizeResult);

    return 0;
}