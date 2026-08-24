/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let start=init;

     let d={
        increment:function(){
            start++;
            return start},
        decrement:function(){
            start--;
            return start},
        reset:function(){
            start=init;return start
        }
    }
    return d;
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */