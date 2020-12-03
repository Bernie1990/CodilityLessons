// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int X, int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int i;
    int the_road[] = (int *)malloc(X*sizeof(int));
    memset(the_road, 0, X*sizeof(int));
    for(i=0; i<N; i++)
        the_road[A[i]] = 1;
    for(i=0; i<N; i++)
        the_road[A[i]] = 1;

    free(the_road);

}