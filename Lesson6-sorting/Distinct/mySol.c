// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

#define OFFSET 1000000
int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int i, ret = 0;
    int ARR[2000000+1] = {0};
    for (i = 0; i < N; i++){
        ARR[A[i]+OFFSET] = 1;
    }
    for (i = 0; i <2000000+1; i++){
        if (ARR[i])
            ret+=1;
    }
    return ret;
}