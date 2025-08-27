// string methods

let str1 = "Hey";
let str2 = "There!";

let str3;

console.log(str1.length);
console.log(str2.length);

console.log(str1.toUpperCase());
console.log(str2.toLowerCase());

console.log(str1.concat(" ") + str2);

console.log(str1.charAt(2));

console.log(str1.indexOf('e')); // find this character index
console.log(str2.lastIndexOf('e')); // find last this character index 

//console.log("replace =>" + str1.replace());

let str4 = "hello";
let str5 = "good afternoon";
let str7 = "    here white space removed !    ";

let trim = str7.trim();
console.log(trim);

let slice = str4.slice(2, 4);
console.log(slice);

console.log(str4.charAt(2) + str5.charAt(3));



// string reverse
let str6="";
let str8="";
for (let i = str4.length-1; i >= 0; i--){
    str6 += str4.charAt(i);
    str8 += str4[i];
}

console.log("orignal => " + str4 + "\nreverse => " + str6);
console.log(str6);
console.log(str8);

// find how many space in str
let str9 = "How many white space ? ";
let space = 0;
for (let i = 0; i < str9.length; i++){
    if(str9[i] === ' '){
        space++;
    }
}
console.log("Space = "+space);

let splitarray = str9.split(' ');
let conunt = splitarray.length;
console.log("Space = "+ --conunt);

// str even char toUpperCase
for (let i = 0; i < str4.length; i++){
    if(i%2 == 0){
        console.log(str4[i].toUpperCase());
    } else {
        console.log(str4[i]);
    }
}