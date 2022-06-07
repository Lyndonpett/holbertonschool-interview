#!/usr/bin/python3
"""Module for determining if lockboxes can be opened."""


def canUnlockAll(boxes):
    """Returns true if all boxes can be opened"""
    # Create our starting list
    keyList = [0]

    # Copy keys from box 0 to test list
    testKey = boxes[0]

    # loop through each key
    for key in testKey:
        if key not in keyList:
            try:
                testKey.extend(boxes[key])
                keyList.append(key)
            except Exception:
                continue

    # If all keys are in the list, return true
    if len(keyList) == len(boxes):
        return True
    else:
        return False
