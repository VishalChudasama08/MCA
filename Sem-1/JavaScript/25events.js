let btn = document.querySelector("button")[0];
console.log(btn);
if(btn){
    btn.addEventListener('click', function(){
        alert("Okay!");
        console.log("Button clicked.");
    })
} else {
    console.log("no such element");
}

let div = document.getElementById("div1");
if(div){
    div.addEventListener('mouseover', function(){
        console.log("mouseover");
    })
    // div.addEventListener('mouseenter', function(){
    //     console.log("mouseenter");
    // })
    // div.addEventListener('mouseleave', function(){
    //     console.log("mouseleave");
    // })
} else {
    console.log("no such element");
}


let btn2 = document.getElementById("count");
if(btn2){
    let count = 0;
    btn2.addEventListener('click', function(){
        count++;
        document.getElementById("count_s").innerHTML = count;
        // console.log(count);
    })
} else {
    console.log("no such element");
}

