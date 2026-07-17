#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
int m[50][50], s[50][50], p[50] ;
FILE *fp,*ft;
void p_o_p(int i, int j){
	if(i == j){
		fprintf(ft, "A%d", i);
	}
	else{
		fprintf(ft,"(");
		p_o_p(i, s[i][j]);
		p_o_p(s[i][j] + 1, j);
		fprintf(ft, ")");
	}
}
void matrix_chain_order(int n){
	int i,l, j, k;
	for(i = 1; i<=n; i++){
		m[i][i] = 0;
	}
	for(l = 2; l<= n; l++){
		for(i = 1; i<= n-l+1; i++){
			j = i+l - 1;
			m[i][j] = INT_MAX;
			for( k = i; k<= j - 1; k++){
				int q = m[i][k] + m[k+1][j] + (p[i-1]*p[k]*p[j]);
				if (q<m[i][j]){
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
}

int main(){
	int i, j,n;
	fp=fopen("input.txt","r");
	if(fp==NULL)
	{
		printf("\n FILE NOT FOUND\n ");
		exit(0);
		
	}
	fscanf(fp,"%d",&n);
	for(i=0;i<=6;i++)
	{
		fscanf(fp,"%d",&p[i]);
	}
	ft=fopen("output.txt","w");
	if(ft==NULL)
	{
		printf("\n FILE NOT FOUND\n ");
		exit(0);
		
	}
	matrix_chain_order(6);
	fprintf(ft, "\n m[][]::\n");
	for(i = 1; i<= 6; i++){
		for(j = i; j<= 6; j++){
			fprintf(ft, "%d\t", m[i][j]);
		}
		fprintf(ft, "\n");
	}
	fprintf(ft, "\n s[][]::\n");
	for(i = 1; i<= 5; i++){
		for(j = i+1; j<= 6; j++){
			fprintf(ft, "%d\t", s[i][j]);
		}
		fprintf(ft, "\n");
	}
	fprintf(ft, "\n");
	p_o_p(1,6);
	fprintf(ft, "%d", m[1][6]);
	return 0;
	
}

