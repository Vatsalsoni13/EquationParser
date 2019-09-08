#include<stdio.h>
int main()
{
    int i,j,k,n;
    float A[20][20],c,X[10],sum=0.0;
    printf("Enter th order of rows: ");
    scanf("%d",&n);
    printf("Enter the value of matrix: ");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=(n+1);j++)
        {
            printf("A[%d][%d]: ",i,j);
            scanf("%f",&A[i][j]);
        }
    }
    for(j=1;j<=n;j++)
    {
        for(i=1;i<=n;i++)
        {
            if(i>j)
            {
                c=A[i][j]/A[j][j];
                for(k=1;k<=n+1;k++)
                {
                    A[i][k]=A[i][k]-(c*A[j][k]);
                }
            }
        }
    }
   /* printf("\nThe Upper Triangular Matrix : \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%f",A[i][j]);
        }
        printf("\n");
    }*/
    X[n]=A[n][n+1]/A[n][n];
    for(i=n-1;i>=1;i--)
    {
        sum=0.0;
        for(j=i+1;j<=n;j++)
        {
            sum+=A[i][j]*X[j];
        }
        X[i]=(A[i][n+1]-sum)/A[i][i];
    }
    printf("\nSolution : \n");
    for(i=1;i<=n;i++)
    {
        printf("\n%f\n",X[i]);
    }
    return 0;
}
