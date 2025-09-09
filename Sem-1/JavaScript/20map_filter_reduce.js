let arr1 = [1,2,5,8,9];

let calculate_square = (arr) => {
    arr1.forEach((val, index)=>{
        arr1[index] = val*val;
    });
    console.log(arr1);
}

calculate_square(arr1);

let arr2 = [1,2,5,8,9];

// map method
let newArray = arr2.map((val)=>{ 
    return val*val; // map method return new array. map not change original array
});

console.log(arr2);
console.log(newArray);


let arr3 = [11,26,54,81,99];

let oddArray = arr3.filter((val)=>{
    return val%2 != 0;
});

console.log(arr3);
console.log(oddArray);


let arr4 = [1,2,3,4,5];
console.log(arr4);
const output = arr4.reduce((res,current)=>{
    // console.log(res, current);
    return res+current;
})
console.log(output);
console.log(typeof(arr4));
console.log(typeof(output));


// task-1 create an array of marks. which contains marks for 5 subjects.
// return array which only have marks above 90.

let marks = [72,93,67,96,88];

let above90 = marks.filter((val)=>{
    return val>90;
})
console.log(above90);

// task-2 create an array of salary year vise of employee.
// return avg. salary of employee.

let salary = [80000,70000,50000,60000,40000];
let total = salary.reduce((res, current)=>{
    return res+current;
})

console.log("avg = "+total/salary.length);

// task-3 carate an array of 20 elements. return an array after performing % 10 operation on each element.

let number20 = [10,20,30,40,50,60,70,80,90,11,22,33,44,55,66,44,55,66,77,88]

let numberMod10 = number20.map((val)=>{
    return val%10;
})
console.log(number20);
console.log(numberMod10);

// task-4 take a number from user as input. crate an array of 1 to n. user reduce method to calculate sum and product of number
// let n = prompt("Enter n number: ");
// let nNumber = [];
// for (let i = 0; i < n; i++) {
//     nNumber[i] = +prompt("Enter a number: ");
// }
// const sum = nNumber.reduce((res,current)=>{
//     console.log(res, current);
//     return res+current;
// })
// const product = nNumber.reduce((res,current)=>{
//     return res*current;
// })

// console.log(nNumber);
// console.log(sum);
// console.log(product);



// task-5 create an object of customer having details of id, name, city, phone no, pincode.
// print each key and value along with its datatype.

let details = {
    id: 18,
    "name": "vishal",
    "city": "khambhalia",
    phone: 8320343610,
    pincode: 361306
}

for (const key in details) {
    console.log(key + "\t: " + details[key] + "\ttype is " + typeof(details[key]));
}


// task-6 create a regular function to print reverse array.
// i.e. i/p: 3,4,5,6,7,8
//      o/p: 8,7,6,5,4,3

let arr5 = [3,4,5,6,7,8]
function reverse(arr5){
    let rev = [];
    let j = 0;
    for (let i = arr5.length-1; i >= 0; i--) {
        rev[j++] = arr5[i];
    }
    return rev;
}
console.log(arr5);
console.log("reverse: ",reverse(arr5));


// task-7 create an array of strings. convert even index string in capital and odd index string in lowercase.
// print count of capital string and lowercase string at last. 

let strarr = ["you","know","this", "is", "string", "array"];
let countU = 0;
let countL = 0;
console.log(strarr);
for (let i = 0; i < strarr.length; i++) {
    if(i%2 == 0){
        console.log(strarr[i].toUpperCase());
        countU++;
    } else {
        console.log(strarr[i].toLowerCase());
        countL++;
    }
}
console.log("capital count: " + countU);
console.log("lower case count: " + countL);

// task-8 create 2 arrays of numbers.
// [12,34,11,16,18,19]
// [9,8,7,6,11,23]
// calculate addition of 2 arrays and return resultant array which only contains element above 30

let s1 = [12,34,11,16,18,19];
let s2 = [9,8,7,6,11,23];

if(s1.length == s2.length){
    for (let i = 0; i < s1.length; i++) {
        let s = s1[i]+s2[i];
        // console.log(s);
        if(( s > 30)){
            console.log(s);
        }
    }
}