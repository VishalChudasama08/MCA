// 06-10-2025 scope of the function

function display(){
    console.log("display function");
    function show(){
        console.log("show function");
    }
    show();
}
display();

function display1(){
    console.log("display1 function");
}
display1(function show1(){
    console.log("show1 function");
});

function display4(a,b){
    console.log("1st display4 function");
}
function display4(){
    console.log("2st display4 function");
}
function display4(a,b,c,d){
    console.log("3st display4 function");
}
display4(); // argument not matter, only call last difened function



function display5(a,b){
    console.log("1st display5 function");
}
display5();
function display5(){
    console.log("2st display5 function");
}
display5();
function display5(a,b,c,d){
    console.log("3st display5 function");
}
display5();
// for all display5() run last display5() function "3st display5 function"
// because in js 
// Just-In-Time (JIT) Compilation
// Combines interpretation & compilation during execution


function display6(){
    console.log("Display 6 function");
}
function display7(){
    console.log("Display 7 function");
}
display6(display7()) 
display7(display6())

function display8(){
    console.log("Display 8 function");
}
function display9(display8){
    console.log("Display 9 function");
}


// my self =>
// callback function
function display2(callback){
    console.log("display2 function");
    callback(); // this calls show1()
}
function show2(){
    console.log("show2 function");
}
display2(show2);

