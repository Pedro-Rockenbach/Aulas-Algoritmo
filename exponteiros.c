#include <stdio.h>
#include <stdlib.h> // É necessário para usar malloc e free

int main()
{
    int n;

    while (scanf("%d", &n) == 1 && (n != 0))
    {
        int **M = (int **)malloc(n * sizeof(int *));
        
        for (int i = 0; i < n; i++)
        {
            M[i] = (int *)malloc(n * sizeof(int));
        }
        
        int li = 0, ci = 0, lf = n - 1, cf = n - 1, x = 1;

        while (li <= lf && ci <= cf)
        {
            for (int j = ci; j <= cf; j++)
            {
                M[li][j] = x;
            }
            for (int i = li + 1; i <= lf; i++)
            {
                M[i][cf] = x;
            }
            if (li < lf)
            {
                for (int j = cf - 1; j >= ci; j--)
                {
                    M[lf][j] = x;
                }
            }
            if (ci < cf)
            {
                for (int i = lf - 1; i > li; i--)
                {
                    M[i][ci] = x;
                }
            }
            x++;
            li++;
            lf--;
            ci++;
            cf--;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%3d", M[i][j]);
                if (j < n - 1)
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
        printf("\n");
        
        for (int i = 0; i < n; i++)
        {
            free(M[i]);
        }
        free(M);
    }
    return 0;
}