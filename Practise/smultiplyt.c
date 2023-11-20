#include <stdio.h>
int main()
{
    int A[100][3], B[100][3], C[100][3], temp = 0, index = 0;
    printf("Enter the sparse matrix-1 in 3-tuple form (row col value):\n");
    scanf("%d%d%d", &A[0][0], &A[0][1], &A[0][2]);
    for(int i = 1; i <= A[0][2]; i++)
        scanf("%d%d%d", &A[i][0], &A[i][1], &A[i][2]);
    if(A[0][2] > (A[0][0]*A[0][1])/2)
    {
        printf("\nNot a sparse\n");
        return 0;
    }
    printf("Enter the sparse matrix-2 in 3-tuple form (row col value):\n");
    scanf("%d%d%d", &B[0][0], &B[0][1], &B[0][2]);
    for(int i = 1; i <= B[0][2]; i++)
        scanf("%d%d%d", &B[i][0], &B[i][1], &B[i][2]);
    if(B[0][2] > (B[0][0]*B[0][1])/2)
    {
        printf("\nNot a sparse\n");
        return 0;
    }
    if(A[0][1] != B[0][0])
    {
        printf("The matrices are not multipliable!");
        return 0;
    }
    for(int i = 0; i <= A[0][2]; i++)
    {
        for (int j = 0; j <= B[0][2]; j++)
        {
            if (A[i][1] == B[j][0])
            {
                int found = 0;
                for(int k = 0; k < index; k++)
                {
                    if (C[k][0] == A[i][0] && C[k][1] == B[j][1])
                    {
                        C[k][2] += A[i][2] * B[j][2];
                        found = 1;
                        break;
                    }
                }
                if (!found)
                {

                    C[index][0] = A[i][0];
                    C[index][1] = B[j][1];
                    C[index][2] = A[i][2] * B[j][2];
                    index++;
                }
            }
        }
    }
    C[0][2] = index - 1;
    printf("Result:\n");
    for(int i = 0; i < index; i++)
        printf("%d %d %d\n", C[i][0], C[i][1], C[i][2]);
return 0;
}