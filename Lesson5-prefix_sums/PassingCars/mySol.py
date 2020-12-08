# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def prefix_sums(A):
    P = [0]
    for i in range(len(A)):
        P += [P[i] + A[i]]
    return P

def solution(A):
    # write your code in Python 3.6
    ret = 0
    PreSum = prefix_sums(A)
    TotalSum = PreSum[len(A)]
    for i in range(len(A)):
        if 0 == A[i]:
            ret += TotalSum - PreSum[i]
            if ret > 1000000000:
                return -1
    return ret