# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # write your code in Python 3.6
    D = {}
    ret = 0
    for i in range(len(A)):
        if A[i] not in D:
            D[A[i]] = 1
            ret += 1

    return ret 
