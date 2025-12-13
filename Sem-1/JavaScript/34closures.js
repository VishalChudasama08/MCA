// closures

function createCounter(){
    let count = 0; // 'count' is a private variable within the closure

    // function return function that is closure and it's scope is leczical scope
    return function(){ 
        count++;
        return count;
    };
}

const counter1 = createCounter();

console.log(counter1);

// variable read as function
console.log(counter1()); // output: 1
console.log(counter1()); // output: 2

const counter2 = createCounter();
console.log(counter2()); // output: 1
console.log(counter2()); // output: 2

const counter3 = createCounter();
const counter4 = createCounter();
console.log(counter4(counter3())); // output: 1

const counter5 = createCounter();
const counter6 = createCounter();
console.log(counter6(counter5(counter6))); // output: 2 

