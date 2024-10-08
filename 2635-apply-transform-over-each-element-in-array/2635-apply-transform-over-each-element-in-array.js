/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    // a = [];
    for(let i=0; i<arr.length; i++){
        // a[i] = fn(arr[i])
        arr[i] = fn(arr[i], i);
    }
    // return a;
    return arr;
};