// array methods

let e = ["rajkot", "surat", "baroda", "ahemdabad", "dwarka"];
console.log("main array : ", e);

e.push("jamnagar"); // add element at last
console.log("push : ", e); 

let f = e.pop(); // remove last element, return poped element
console.log("pop : ", e); 
console.log("poped element : ", f);

console.log("toString : ", e.toString()); // convert in string, return array to string

let s = ["gujarat", "rajeshthan", "MP"];
let v = e.shift(); // delete from start, return deleted element
console.log("shifted element : ", v);

e.unshift("bhavnagar"); // add at start
console.log("unshift element : ", e);

console.log("slice 1, 3 : ", e.slice(1,4)); // return new array that is part of array as per index, 
//slice method two argument is starting and eding index

let m = e.concat(s); // return join array
console.log("concat : ", m);

let arr = [1,2,3,4,5,6,7,8];
console.log(arr);
// splice(<starting_index>, <how_many_element_delete?>, <edded_elements>,...);
// it well chage original array
arr.splice(2,3,101,102);
console.log("splice(2,3,101,102) : ", arr);
arr.splice(3,0,201); // 2nd argument is 0 means here, not any element delete, but after index 3 (as per 1st argument) add elements (added 3rd, 4th,... arguments)
console.log("splice(3,0,201) : ", arr);
arr.splice(2,1); // here 3rd augument not present means only delete one emelemt at index 2, because 1st argument is 2 that is index value, 2nd argument is 1 that is how many element delete stating from 2 number index
console.log("splice(2,1) : ", arr);
arr.splice(3,1,101);
console.log("splice(3,1,101) : ", arr);
arr.splice(2); // after index 2 another all element delete
console.log("splice(2) : ", arr);


