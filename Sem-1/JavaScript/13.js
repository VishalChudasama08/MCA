// 1) take username from user print indexof @ and count length of it, print count of capital letters
console.log("Task-1");
let username = prompt("Enter username: ");
let indexof = username.indexOf('@');
let length = username.length;
let capitalCount = 0;
for (const i of username) {
    if (i >= 'A' && i <= 'Z') {
        // console.log(i);
        capitalCount++;
    }
}
console.log("indexof @: " + indexof + ",  length: " + length + ",  capital letter count: " + capitalCount);



// 2) take n from user. make a function to print fibonaci series from 1 to n
console.log("Task-2");
let n = +prompt("Print how many number fibonaci series: ");
let x = 1;
let y = 1;
let z = 0;
if (n == 1) {
    console.log(x);
} else if (n == 2) {
    console.log(x);
    console.log(y);
} else {
    console.log(x);
    console.log(y);
    for (let i = 0; i < n - 2; i++) {
        z = x + y;
        console.log(z);
        x = y;
        y = z;
    }
}



// 3) take a static string and perform each string methods.
console.log("Task-3");
let str1 = "Hey There";
console.log(str1.length);
console.log(str1.charAt(2));
console.log(str1.indexOf('y'));
console.log(str1.toUpperCase());
console.log(str1.toLowerCase());
console.log(str1.concat(" this is new part"));
console.log(str1.replace("replace"));
console.log(str1.split(" ")); // split return array
console.log(str1.slice(2, 6));
let str2 = "    remove space     ";
console.log(str2.trim());



// 4) create an object for doctor and print only its value
console.log("Task-4");
let doctor = {
    "name": "Shubhash",
    no: 9876543210,
    pincode: 361306,
    "profeson": "General"
}
for (const key in doctor) {
    console.log(doctor[key]);
}



// 5) WAP to demonstrate for in, for of, do while loop
console.log("Task-5");
let arr = [1, 2, 3, 4];
let str3 = "This is string."
for (const i in arr) {
    console.log(arr[i]);
}
for (const i of str3) {
    console.log(i);
}
let k = 0;
do {
    k++;
    console.log(k);
} while (k < 6);



// 6) WAP to change designing of any element using js file. without using css
console.log("Task-6");
let p = document.createElement("p");
p.innerText = "This is paragraph. tag created by js.";
p.style.backgroundColor = "yellow";
p.style.color = "red";

document.querySelector("body").append(p);


