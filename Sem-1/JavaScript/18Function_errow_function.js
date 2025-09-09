const display = (msg, n) => {
    console.log(msg + " " + n);
};

display("hey", "There");

// task-1 get number from user than, make it's square is square is even than showing alert message else showing confirm message
const square_even_odd = (n) =>{
    let v = n*n;
    if(v%2 == 0){
        alert("Number square is even: " + v);
    } else {
        confirm("Number square is odd: " + v);
    }
}
//let n = prompt("Enter a number");
//square_even_odd(n);

// task-2 make a function to take a string from user. print a count of vowels inside that string using alert.
const vowel_count = (s) =>{
    let count = 0;
    for (let c of s) {
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            count++;
        }
    }
    alert("Here " + count + " Vowels.");
}
//let s = prompt("Enter string");
//vowel_count(s);

//task-3 string-1 "Hello" string-2 "good morning", make a function to take a numbner from user and print it's factorial
//       if factorial is odd than print string-1 in uppercase and length off marge string, even than print marge string
const task3 = (s1, s2, n) => {
    let fact = 1;
    let s = "";
    while (n > 0) {
        fact = fact * n;
        n--;
    }
    console.log(fact);
    s = s1.concat(s2);
    if(fact%2 == 0){
        console.log(s);
    }else{
        console.log("string 1 usercase: "+s1.toUpperCase());
        console.log("string 2 length : "+ s.length);
    }
}
//let n = prompt("Enter number: ");
//task3("Hello", "Good morning", n);


// task-4 add 5 in each element and print arr
function add5InArr(arr){
    console.log(""+arr);
    for (let i = 0; i < arr.length; i++) {
        arr[i] = arr[i]+5;
    }
    console.log("after 5 add :- " + arr);
}
let arr = [3,5,7,8,2];
add5InArr(arr);
