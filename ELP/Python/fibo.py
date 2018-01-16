def fib1(n):
    res = []
    a,b = 0, 1
    while b < n:
        res.append(b)
        a, b = b, a+b
    return res

def fib2(n):
    if n < 2:
        return n
    else:
        return fib2(n-1) + fib2(n-2)


if __name__=="__main__":
    import sys
    print(fib1(int(sys.argv[1])))

