// scope off 'this' keyword

function person(first, last, age, city){
    this.firstName = "shyam";
    this.lastName = "shah";
    this.age = 25;
    this.city = "baroda";
}

let male = new person('ram', 'patel', 30, 'surat'); 
document.querySelector(".demo").innerHTML = male.city; // baroda
document.getElementById("demo").innerHTML = male.lastName;

// function person(id, name, branch, designation, salary);
// console.log(person.name);

// syntax:
// => function in class
// class class_name {
//     function () {
        
//     }
// }
