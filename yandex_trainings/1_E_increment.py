import sys
from decimal import Decimal, getcontext

def main():
    """
    Пример ввода и вывода числа n, где -10^9 < n < 10^9:
    n = int(input())
    print(n)
    """
    n, k = [int(i) for i in input().split()]

    first_occurance = {}
    INX = 0
    VAL = 1

    while k > 0:
        k -= 1
        n += n % 10

        if n % 10 in first_occurance:
            interval = first_occurance[n % 10][INX] - k
            interval_val = n - first_occurance[n % 10][VAL]
            n += (k // interval) * interval_val
            k -= (k // interval) * interval
        else:
            first_occurance[n % 10] = [0,0]
            first_occurance[n % 10][INX] = k
            first_occurance[n % 10][VAL] = n

    print(n)
            

if __name__ == '__main__':
    main()
