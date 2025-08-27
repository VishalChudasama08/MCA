let age = 18;
let citizen = "Indian";

if(age == 18 && citizen == "Indian"){ // true
    alert("You are eligible");
}
if(age == 18 && citizen == "indian"){ // false
    alert("You are eligible");
} else {
    alert("You are not eligible");
}

let sub1 = 50;
let sub2 = 60;
let sub3 = 70;
let sub4 = 40;

if(sub1 <= 40 || sub2 <= 40 || sub3 <= 40 || sub4 <= 40){
    console.log("You are need to inprument");
} else {
    console.log("Great");
}

sub1 = "50";
sub2 = "60";
sub3 = "70";
sub4 = "40"; 
if(sub1 <= 40 || sub2 <= 40 || sub3 <= 40 || sub4 <= 40){
    console.log("You are need to inprument");
} else {
    console.log("Great");
}

