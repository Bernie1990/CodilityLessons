# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # write your code in Python 3.6
    if len(A)==3:
        return A[0]*A[1]*A[2]
    A.sort(reverse=True)

    ret1 = A[0]*A[1]*A[2]
    ret2 = A[0]*A[-1]*A[-2]
    
    return ret1 if ret1>=ret2 else ret2