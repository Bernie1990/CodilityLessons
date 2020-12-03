// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int i, tmp=0, cnt = 0, cnt_flag=0;
    if (N==1)
        return A[0]==1? 1: 0;

    int map[100] = {0};
    for (i=0; i<N; i++){
        if (map[A[i]]==0) 
            map[A[i]] |= 1;
    }
    for(i=0;i<10;i++)
        //printf("%d ",map[i]);

    for (i=0; i<1000000000; i++){
        if ((tmp^map[i])%2 && !cnt_flag){
            //printf("\ns[%d] ",i);
            cnt_flag = 1;
        }
        else if ((tmp^map[i])%2 && cnt_flag){
            //printf("e[%d] ",i);
            if (cnt!=N){
                //printf("cnt[%d] ",cnt);
                return 0;
            }
            else
                return 1;
        }
        if (cnt_flag)
            cnt++;
        tmp = map[i];   
    }
    return 0; 
}