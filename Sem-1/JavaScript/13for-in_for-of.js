for (let i = 0; i < 5; i++) {
    console.log(i);
}
for (let i = 5; i >= 0; i--) {
    console.log(i);
}

// for of loop
let str = "hello";
for (let e of str) {
    console.log(e);
}

// for in loop
let obj = {
    "name": "vishal",
    no: 13,
}
for (let e in obj) {
    console.log(e);
}

let arr = [1, 2, 3, 4, 5, 6];
for (let i in arr) {
    console.log(arr[i]);
}

// task-1 
// print even number and sum of odd number in 1 to 100
let a = 0;
for (let i = 1; i <= 100; i++) {
    if (i % 2 == 0) console.log(i); else a += i;
}
console.log("Sum of odd numbers = " + a);

// task-2 
// create a game where you statrt with any random number and ask user to keep gusseing a number unitill it enters the correct number
let b = 18;
let c;
// do{
//     c = prompt("Guss a number");
// } while(c != b);
// if(b == c){
//     confirm("Congratulation!");
// }

// task-3 
// in 1 to 100 make squere and that squere digit sum is greater than 10 than print that number 
let n;
for (let i = 0; i <= 100; i++) {
    n = i * i;
    let sum = 0;
    while (n > 0) {
        rem = n % 10;
        sum += rem;
        n /= 10;
    }
    sum = Math.trunc(sum);
    if (sum > 10)
        console.log(i);
    else
        document.write(i + "<br>");
}