// task-1 
// take a number from user, print its table until answer comes in 3 digit

// let a = prompt("Enter number: ");

// function digitcount(ans){
//     let d=0;
//     let n = ans;
//     while(n > 0){
//         d++;
//         n = Math.floor(n/10);
//     }
//     return d;
// }

// let v=1;
// let digit = digitcount(a*v);
// // console.log(digit);
// while(digit != 3 && digit < 4){
//     console.log(a + " * " + v + " = " + (a * v));
//     v++;
//     digit = digitcount(a * v);
// }


// task-2
// take an alphabate from user and print its ascii value 
// let alph = prompt("Enter one charecter: ");
// console.log(alph.charCodeAt(0));

// task-3
// take a 3 digit number from user. if sum of all digit is grater than multiplication of all digit, then print "its special number"
// let num = prompt("Enter 3 digit number only: ");
// let rem=0;
// let n = num;
// let sum = 0;
// let mul = 1;
// while(n > 0){
//     rem = n%10;
//     sum = sum+rem;
//     mul = mul*rem;
//     n = Math.floor(n/10);
// }
// console.log("Number is: " + num);
// console.log("addition of digit:  "+sum);
// console.log("multiplication of digit: "+mul);
// if(sum > mul){
//     console.log(num + " its special number.");
// } else if(sum == mul){ // extra
//     console.log(num + " its super special number.");
// } else {
//     console.log(num + " its normal number.");
// }

// task-4
// take a number from user, if number ends with even number then perform squere of that number else cube
let number = prompt("Enter number: ");
let n = number;
let lastDigit = 0;
while(n > 0){
    lastDigit = n%10;
    n = Math.floor(n/10);
}
console.log(lastDigit%10);
if (lastDigit%2 == 0){
    console.log("Sauere of number is: " + number*number);
} else {
    console.log("Cube of number is: " + number*number*number);
}

// task-5
// take an odd number