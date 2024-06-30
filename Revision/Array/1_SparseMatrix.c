#include <stdio.h>
#include <stdlib.h>
void display(int rows, int cols, int ar[rows][cols])
{
    printf("Rows Columns Values\n");
    for(int i = 0; i <= rows; i++)
    {
        printf("%d\t%d\t%d\n", ar[i][0], ar[i][1], ar[i][2]);
    }
}
int main()
{
    int rows = 0, cols = 0, count = 0;
    printf("Enter the no. of rows & columns of the matrix.\n");
    scanf("%d", &rows);
    scanf("%d", &cols);
    // Create a matrix
    int mat[rows][cols];
    printf("Enter the %d elements.\n", (rows*cols));
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            scanf("%d", &mat[i][j]);
            if(mat[i][j] > 0)
            {
                count++;
            }
        }
    }
    // Check whether the matrix is sparse or not.
    if((double)count > (double)(rows*cols)/2)
    {
        printf("Not a sparse matrix");
        return 0;
    }
    printf("Matrix is a sparse matrix.\n");
    // Create a sparse matrix
    int sp_mat[count+1][3];
    sp_mat[0][0] = rows;
    sp_mat[0][1] = cols;
    sp_mat[0][2] = count;
    int k = 1;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(mat[i][j] > 0)
            {
                sp_mat[k][0] = i;
                sp_mat[k][1] = j;
                sp_mat[k][2] = mat[i][j];
                k++;
            }
        }
    }
    // Display the sparse matrix
    printf("Sparse Matrix\n");
    display(sp_mat[0][2], 3, sp_mat);
    // Transpose of the sparse matrix
    int trans_sp_mat[count+1][3];
    for(int i = 0; i <= count; i++)
    {
        trans_sp_mat[i][0] = sp_mat[i][1];
        trans_sp_mat[i][1] = sp_mat[i][0];
        trans_sp_mat[i][2] = sp_mat[i][2];
    }
    // Display the transpose of the sparse matrix
    printf("Transpose of Sparse Matrix\n");
    display(trans_sp_mat[0][2], 3, trans_sp_mat);
    return 0;
}