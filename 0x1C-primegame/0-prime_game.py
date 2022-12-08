#!/usr/bin/python3
"""Maria and Ben are playing a game. Given a set of consecutive integers starting from 1 up to and including n, they take turns choosing a prime number from the set and removing that number and its multiples from the set. The player that cannot make a move loses the game.

They play x rounds of the game, where n may be different for each round. Assuming Maria always goes first and both players play optimally, determine who the winner of each game is.

    Prototype: def isWinner(x, nums)
    where x is the number of rounds and nums is an array of n
    Return: name of the player that won the most rounds
    If the winner cannot be determined, return None
    You can assume n and x will not be larger than 10000
    You cannot import any packages in this task
"""
import random
import math

def isWinner(x, nums):
    """Determines the winner of a game"""

    if not nums or x < 1:
        return None

    n = max(nums)
    primes = [True] * (n + 1)
    primes[0] = False
    primes[1] = False

    for i in range(2, int(math.sqrt(n)) + 1):
        if primes[i]:
            for j in range(i * i, n + 1, i):
                primes[j] = False

    count = 0
    for i in range(1, n + 1):
        if primes[i]:
            count += 1
        primes[i] = count

    maria = 0
    ben = 0

    for i in nums:
        maria += primes[i] % 2
        ben += primes[i] % 2 == 0

    if maria > ben:
        return "Maria"
    elif ben > maria:
        return "Ben"
    else:
        return None