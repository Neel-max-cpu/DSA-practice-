/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
    // method 1 
    // return await promise1+ await promise2;

    // method 2 
    return Promise.all([promise1, promise2])
    .then(results=>{
        return results[0]+results[1];
    })    
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */