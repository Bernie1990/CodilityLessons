// you can also use imports, for example:
// import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");
import java.util.Arrays;

class Solution {

    public int solution(int[] A) {

        int N = A.length;
        Arrays.sort(A);

        /**
         * When we sort an array there are two possible options for the largest product
         * 1) The largest (the last) three elements
         * 2) Combination of two smallest and the largest elements
         * Logic of (1): Obvious
         * Logic of (2): A pair of negatives multiplied returns a positive, which in combination with 
         * the largest positive element of the array can give the max outcome.
         * Therefore we return the max of options (1) and (2)
         */
        return Math.max(A[0] * A[1] * A[N - 1], A[N - 1] * A[N - 2] * A[N - 3]);
    }
}