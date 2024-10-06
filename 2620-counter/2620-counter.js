/**
 * @param {number} n
 * @return {Function} counter
 */

var count = 0;
var createCounter = function(n) {
    
    return function() {    
        // if(count===0) {
        //     count=1;
        //     return n;
        // }
        // else {
        //     n++;
        //     return n;    
        // }
        return n++;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */