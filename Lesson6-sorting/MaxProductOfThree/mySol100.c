// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
#define get_min_three(x,y,z) ((x<=y && x<=z)?0:((y<=x && y<=z)?1:2))
#define abs(x) (x<0? (-x):x) 

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    double res=0, res_tmp=0;
    int i = 0;
    int M[3], Mindex[3];
    int tmp_index, tmp_val;
    int neg_cnt = 0;
    if (N==3) return A[0]*A[1]*A[2];

    M[0] = A[0];
    M[1] = A[1];
    M[2] = A[2];

    Mindex[0] = 0;
    Mindex[1] = 1;
    Mindex[2] = 2;
    
    for (i = 3; i<N; i++){
        tmp_index = get_min_three(abs(M[0]),abs(M[1]),abs(M[2]));
        if (abs(A[i]) > abs(M[tmp_index])){
            M[tmp_index] = A[i];
            Mindex[tmp_index] = i;
        }
    }
    res = M[0]*M[1]*M[2];

    neg_cnt = (M[0]<0)+(M[1]<0)+(M[2]<0);
    //printf("nc%d: %d*%d*%d ", neg_cnt,M[0],M[1],M[2]);
    if (neg_cnt==3) { //included all A[] are negative values
        tmp_val = -1000;
        for (i = 0; i<N; i++){
            if (A[i] > tmp_val) //pos
                tmp_val = A[i];
        }
        if (tmp_val==0)
            return 0;
        else if (tmp_val>0){
            tmp_index = get_min_three(abs(M[0]),abs(M[1]),abs(M[2]));
            M[tmp_index] = tmp_val;
        }
        else{
            M[0] = A[0];
            M[1] = A[1];
            M[2] = A[2];

            Mindex[0] = 0;
            Mindex[1] = 1;
            Mindex[2] = 2;
            for (i = 3; i<N; i++){
            tmp_index = get_min_three(-M[0],-M[1],-M[2]);
            if (A[i] > M[tmp_index]){
                M[tmp_index] = A[i];
                Mindex[tmp_index] = i;
        }
    }
        }

        res = M[0]*M[1]*M[2];
    }
    else if (neg_cnt==1){ //considering pos and neg substitution cases
        tmp_val = 0;

        //pos
        for (i = 0; i<N; i++){
            if ( A[i] > tmp_val && i^Mindex[0] && i^Mindex[1] && i^Mindex[2] )
                tmp_val = A[i];
        }
        if (tmp_val>=0){
            tmp_index = M[0]<0?0:(M[1]<0?1:2);
            res_tmp = res*tmp_val/M[tmp_index];
    //printf("pos%d: %d*%d*%d ", tmp_val, M[0],M[1],M[2]);
        }
        
        //neg
        for (i = 0; i<N; i++){
            if ( A[i] < tmp_val && i^Mindex[0] && i^Mindex[1] && i^Mindex[2] )
                tmp_val = A[i];
        }
        if (tmp_val<=0){
            tmp_index = M[0]<0?(M[1]>=M[2]?2:1):(M[1]<0?(M[0]>=M[2]?2:0):(M[0]>=M[1]?1:0));
    //printf("neg%d: %d*%d*%d ", tmp_val, M[0],M[1],M[2]);
            M[tmp_index] = tmp_val;
            res = M[0]*M[1]*M[2];
        }

        if (res<res_tmp)
            res = res_tmp;
    }

    return res;
}