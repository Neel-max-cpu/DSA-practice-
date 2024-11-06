/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function(fn) {
    let calls = false;        
    return function(...args){            
        if(calls) return undefined;
        else{
            calls = true;
            return fn(...args);
            // return fn(args[0]);
        }
    }    
};

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */
