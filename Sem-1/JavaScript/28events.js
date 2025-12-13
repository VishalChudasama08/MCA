let btn2 = document.getElementById("btn2");

function show(){
    console.log("show() 1");
}
function show(){
    console.log("show() 2");
}
function show(){
    console.log("show() 3");
}


// in addEventListener time and space coplextity is more than simple event (like onclick)
btn2.addEventListener("click", ()=>{
    console.log("addEventListener click 1");
})
btn2.addEventListener("click", ()=>{
    console.log("addEventListener click 2");
})
btn2.addEventListener("click", ()=>{
    console.log("addEventListener click 3");
})

/// diffrent in addeventListener and simple event
// addeventListener: run all addeventListener
// simple event: only lasy call







let div = document.querySelector("#div_id");

div.onmouseover = () => {
    console.log("Your mouse inside div box");
}
div.onmouseleave = () => {
    console.log("Your leave div box");
}


let input_n = document.querySelector("#input_id");

input_n.onkeydown = () => {
    console.log("onkeydown");
}
input_n.onkeyup = () => {
    console.log("onkeyup");
}

let btn = document.querySelector("#btn1");
btn.addEventListener("click", ()=>{
    console.log("1st addEventListener click call");
})
btn.addEventListener("click", ()=>{
    console.log("2nd addEventListener click call");
})