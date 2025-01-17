//Product array puzzle
function productExceptSelf(arr) {
    const n = arr.length;
    const res = new Array(n).fill(1);

    // Compute prefix product
    let prefix = 1;
    for (let i = 0; i < n; i++) {
        res[i] = prefix;
        prefix *= arr[i];
    }

    // Compute suffix product and multiply with prefix product
    let suffix = 1;
    for (let i = n - 1; i >= 0; i--) {
        res[i] *= suffix;
        suffix *= arr[i];
    }

    return res;
}
