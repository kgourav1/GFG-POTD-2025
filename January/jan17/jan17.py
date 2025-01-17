//Product array puzzle

def productExceptSelf(arr):
    n = len(arr)
    res = [1] * n

    # Compute prefix product
    prefix = 1
    for i in range(n):
        res[i] = prefix
        prefix *= arr[i]

    # Compute suffix product and multiply with prefix product
    suffix = 1
    for i in range(n - 1, -1, -1):
        res[i] *= suffix
        suffix *= arr[i]

    return res
