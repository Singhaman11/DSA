#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int row;
    int col;
    int value;
}Element;

void addSparseMatrices(Element matrix1[], int size1, Element matrix2[], int size2, Element resultMatrix[], int* sizeResult) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (matrix1[i].row < matrix2[j].row || (matrix1[i].row == matrix2[j].row && matrix1[i].col < matrix2[j].col)) {
            resultMatrix[k++] = matrix1[i++];
        } else if (matrix1[i].row > matrix2[j].row || (matrix1[i].row == matrix2[j].row && matrix1[i].col > matrix2[j].col)) {
            resultMatrix[k++] = matrix2[j++];
        } else {
            resultMatrix[k] = matrix1[i];
            resultMatrix[k++].value += matrix2[j++].value;
            if (resultMatrix[k - 1].value == 0) {
                k--;
            }
            i++;
        }
    }

    while (i < size1) {
        resultMatrix[k++] = matrix1[i++];
    }

    while (j < size2) {
        resultMatrix[k++] = matrix2[j++];
    }

    *sizeResult = k;
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

    Element resultMatrix[size1 + size2];
    int sizeResult;

    addSparseMatrices(matrix1, size1, matrix2, size2, resultMatrix, &sizeResult);

    printf("Resultant Sparse Matrix:\n");
    displaySparseMatrix(resultMatrix, sizeResult);

    return 0;
}