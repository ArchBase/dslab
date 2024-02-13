#include <stdio.h>

void main(){

    int mat[100][100], i, j, k, rows, cols, ans[100][100];
    printf("Enter rows: ");
    scanf("%d", &rows);
    printf("Enter cols: ");
    scanf("%d", &cols);
    printf("Enter mat\n");
    for(i=0; i<rows; i++){
        for(j=0; j<cols; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    ans[0][0] = rows;
    ans[0][1] = cols;
    ans[0][2] = 0;
    k=1;
    for(i=0; i<rows; i++){
        for(j=0; j<cols; j++){
            if(mat[i][j] != 0){
                ans[k][0] = i;
                ans[k][1] = j;
                ans[k][2] = mat[i][j];
                ans[0][2] += 1;
                k++;
            }
        }
    }

    printf("Sparse matrix: \n");
    for(i=0; i<ans[0][2]+1; i++){
        for(j=0; j<3; j++){
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }


}