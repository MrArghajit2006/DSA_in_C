#include <stdio.h>
#include<limits.h>
int m[100][100], s[100][100];
void matrix_chain_oder(int dim_array[], int no_of_matrix){
    for (int i = 1; i <= no_of_matrix; i++)
    {
        m[i][i] = 0;
    }
    for (int l = 2; l <= no_of_matrix; l++)
    {
        for (int i = 1; i <= no_of_matrix-l+1; i++)
        {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k+1][j] + dim_array[i-1]*dim_array[k]*dim_array[j];
                if (q< m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
                
            }
            
        }
        
    }
    
}
int print_optimal_parens(int i, int j){
    if (i == j)
    {
        printf("A%d", i);
    }else{
        printf("(");
        print_optimal_parens( i, s[i][j]);
        print_optimal_parens(s[i][j]+1, j);
        printf(")");
    }
    
}
int main(){
    int n = 6;
    int dim_array[] = {30,35,15,5,10,20,25};
    matrix_chain_oder(dim_array, n);
    printf("Minimum Cost %d\n", m[1][n]);
    print_optimal_parens(1,n);

    return 0;
}