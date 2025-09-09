let arr = [3, 5, 7, 8, 2];

arr.forEach((e) => {
    console.log(e - 3); // print each element subtract by 3
});


let arr1 = ["pune", "mumbai", "ahmd"];


arr1.forEach((value, index, array) => {
    // 1st-value as per each element, 2nd-index as per value(each element), 3rd-array (here original array)
    console.log(value.toUpperCase(), index, array);
})


// task-1 convert all element data type in number
let arr2 = [3, 5, 7, "8", "2", "9"];
arr2.forEach((e, key) => {
    console.log(typeof (e));

    arr2[key] = +e;
})
arr2.forEach((e) => {
    console.log(typeof (e));
})

// task-2 create an array
// ["i20", "i10", "exter", "venue", "creta"]
// [800000, 900000, 1000000, 1400000, 1700000]
// add an element at stating index named Nexon
// delete an element at end index.
// calculate length of araay.
// if length of first array is odd then merge both arrays
// if length of first array is even then add 1 lac in each element

let cars = ["i20", "i10", "exter", "venue", "creta"];
let price = [800000, 900000, 1000000, 1400000, 1700000];

cars.unshift("Nexon"); // add at start
cars.pop(); // delete from last

let n = cars.length; // find length

let f = (value, key) => {
    price[key] = value + 100000;
};
console.log(typeof(f));
if (n%2 == 0) { // even
    price.forEach(f)
    console.log(price);
} else {
    console.log(cars.concat(price));
}



// task - read string from user if string first vowel is even than prtint string in upper case else concat with " Hey there ".
let str1 = prompt("Enter string: ");
let str2 = " Hey there ";

for (let i = 0; i < str1.length; i++) {
    if(str1[i] == 'A' || str1[i] == 'E' || str1[i] == 'I' || str1[i] == 'O' || str1[i] == 'U' || str1[i] == 'a' || str1[i] == 'e' || str1[i] == 'i' || str1[i] == 'o' || str1[i] == 'u'){
        if(i%2 == 0){
            console.log(str1.toUpperCase());
        }
        break;
    } else {
        console.log(str1.concat(str2));
    }
}

// task - find last index of string
console.log(str2.length - 1);