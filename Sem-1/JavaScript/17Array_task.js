// static array 10 numbers element, 

// task-1 sorting assecding order
// task-2 find minimum number and print it squere
// task-3 
// task-2
// task-2


let arr = [45, 20, 2, 18, 555, 84, 22, 8, 36, 95];

// task-1
console.log("Array : ", arr);
for (let i = 0; i < arr.length - 1; i++) {
    for (let j = 0; j < arr.length - i - 1; j++) {
        if (arr[j] > arr[j + 1]) {
            let temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
    }
}

console.log("Sorted array : ", arr);

// task-2
console.log("Squere of minimum : ", arr[0] * arr[0]);

// task-3 convert in number
let sub = ["C", "C++", "Java", "PHP", "JavaScript", "Math", "English"];
console.log(typeof (sub));
console.log("Array is it's self object, than not posible to convert full array in number");

// task-4 add subject at last
sub.push(".Net");
console.log("object added : ", sub);

// task-5 find length than is length is old than delete last element else delete first element
console.log("subject array length is : " + sub.length);
console.log("Original array is : ", sub);
if (sub.length % 2 == 0) {
    sub.shift();
    console.log("delete from start : ", sub);
} else {
    sub.pop();
    console.log("delete from last : ", sub);
}

// task-6 marge array
let credit = [4, 3, 2, 5, 4, 3, 5];

let result = sub.concat(credit);
console.log("Merge array : ", result);

// task-7 print as sub array element : credit array element
console.log("Formated data :- "); 
if (sub.length <= credit.length) {
    for (let i = 0; i < sub.length; i++) {
        console.log(sub[i] + " : " + credit[i]);
    }
}