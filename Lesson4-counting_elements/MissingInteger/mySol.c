// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int ret = 1;
    int i;

    if (N==1) return A[0]==1? 2: 1;

    int rangemap[100000-1] = {0};
    for (i=0; i<N; i++){
        if (A[i] < ret)
            continue;
        rangemap[A[i]-1] |= 1;
        if (A[i] == ret)
            ret = A[i];
    }
    for (i=(ret-1); i<(100000-1); i++){
        //printf("ret=%d, ",i+1);
        if (!rangemap[i])
            break;
        ret = i+1+1;
    }
    return ret;
}
