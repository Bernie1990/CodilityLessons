// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
#include <string.h>
#define set_max(c, n, max) for(int j =0; j<n; j++) c[j]=max

struct Results solution(int N, int A[], int M) {
    struct Results result;
    // write your code in C99 (gcc 6.2.0)
    int i = 0, max = 0;

    result.C = malloc(sizeof(int)*N);
    memset(result.C, 0, sizeof(int)*N);

    for (i=0; i<M; i++){
        if (A[i]>=N)
            set_max(result.C, N, max);
        else{
            result.C[A[i]-1]++;
            if (result.C[A[i]-1] > max)
                max = result.C[A[i]-1];
        }
        // printf("C:[");
        // for(int k=0; k<N; k++) 
        //     printf(" %d", result.C[k]);
        // printf("] \n");
    }
    result.L = N;
    return result;
}
