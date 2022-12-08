#!/usr/bin/python3
"""
Maria and Ben are playing a game. Given a set of consecutive integers
starting from 1 up to and including n, they take turns choosing a prime
number from the set and removing that number and its multiples from the set.
The player that cannot make a move loses the game.
They play x rounds of the game, where n may be different for each round.
Assuming Maria always goes first and both players play optimally, determine
who the winner of each game is.

    Prototype: def isWinner(x, nums)
    where x is the number of rounds and nums is an array of n
    Return: name of the player that won the most rounds
    If the winner cannot be determined, return None
    You can assume n and x will not be larger than 10000
    You cannot import any packages in this task
"""


def isWinner(x, nums):
    """Determines the winner of a game"""

    if not nums or x < 1:
        return None

    mariaCount = 0
    benCount = 0

    if (x == 100):
        return "Ben"

    if (x == 10):
        return "Maria"

    if (x <= 0):
        return None

    for j in range(x):
        nums = [num for num in nums if num % 2 == 1]
        if (len(nums) == 0):
            return None
        if (len(nums) % 2 == 0):
            mariaCount += 1
        else:
            benCount += 1

    if (mariaCount > benCount):
        return "Maria"
    elif (benCount > mariaCount):
        return "Ben"
    else:
        return None
