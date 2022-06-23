#!/usr/bin/python3
"""Method that calculates the fewest number of operations needed"""


def minOperations(n):
    """Method that calculates the fewest number of operations needed"""
    if n <= 1:
        return 0

    factor = 2
    factorList = []

    while (n % factor > 0):
        factor += 1

    while (n % factor == 0):
        factorList.append(factor)

        n = n / factor

        if (n == 1):
            for i in factorList:
                return (sum(factorList))

        while (n % factor > 0):
            factor += 1
