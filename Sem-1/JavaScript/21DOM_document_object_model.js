let div = document.querySelector("div");
console.log(div);

console.log(div.getAttribute("id"));
console.log(div.getAttribute("name"));

div.setAttribute("id", "newid");

div.style.backgroundColor = "cyan";

let heading = document.querySelector("h2");
console.log(heading.getAttribute("id"));
console.log(heading.getAttribute("class"));
heading.setAttribute("name", "head_name");


// ========== task ==========

// let div = document.querySelector("div");
// let h1 = document.querySelector("h1");
// let button = document.querySelector("button");
// let p = document.querySelector("p");

// // old id
// console.log(div.getAttribute("id"));
// console.log(h1.getAttribute("id"));
// console.log(button.getAttribute("id"));
// console.log(p.getAttribute("id"));

// // update id
// div.setAttribute("id", "div_new_id");
// h1.setAttribute("id", "h1_new_id");
// button.setAttribute("id", "button_new_id");
// p.setAttribute("id", "p_new_id");

// ========== ========== 


// my own code
let i = 255;
let j = 0;
let k = 100;
function chage() {
    if (i <= 0){
        i = 255;
    }
    if(j >= 255){
        j = 0;
    }
    if(k >= 255){
        k = 125;
    }
    div.style.backgroundColor = 'rgb(' + i + ',' + j + ',' + k + ')';
    i = i - 5;
    j = j + 5;
    k = k + 5;
    console.log(i, j, k);
}