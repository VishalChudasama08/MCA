let c;

let get = document.getElementById("get");

function getSum(){
    let val1 = document.getElementById("val1");
    let val2 = document.getElementById("val2");
    let a = +val1.value;
    let b = +val2.value;
    console.log(a);
    console.log(b);

    c = a + b;
    get.innerHTML = "Answer = "  + c;
}
function getSub(){
    let val1 = document.getElementById("val1");
    let val2 = document.getElementById("val2");
    let a = +val1.value;
    let b = +val2.value;
    console.log(a);
    console.log(b);

    c = a - b;
    get.innerHTML = "Answer = "  + c;
}
function getMulti(){
    let val1 = document.getElementById("val1");
    let val2 = document.getElementById("val2");
    let a = +val1.value;
    let b = +val2.value;
    console.log(a);
    console.log(b);

    c = a * b;
    get.innerHTML = "Answer = "  + c;
}
function getDiv(){
    let val1 = document.getElementById("val1");
    let val2 = document.getElementById("val2");
    let a = +val1.value;
    let b = +val2.value;
    console.log(a);
    console.log(b);

    c = a / b;
    get.innerHTML = "Answer = "  + c;
}