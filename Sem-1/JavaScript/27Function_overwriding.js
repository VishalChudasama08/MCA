let btn = document.querySelector("#btn1");
// btn.onclick = () =>{ // this is overwrite html onclick attribute
//     console.log("Js is working. first onclick");
// }
// btn.onclick = () =>{ // this is overwrite first onclick
//     console.log("Js is working. second onclick");
// }
// btn.ondblclick = () => {
//     console.log("js dubble click function call");
// }

// addEventListener not overwrite any (onclick attribute not overwrite). call all
btn.addEventListener("click", ()=>{ 
    console.log("1st addEventListener click call");
})
btn.addEventListener("click", ()=>{
    console.log("2nd addEventListener click call");
})
btn.addEventListener("click", ()=>{
    console.log("3rd addEventListener click call");
})

btn.onclick = () => {
    console.log("js onclick function call");
}
// let i = 1;
// while(i < 5){
//     // let j = 5;
//     console.log(i);
//     i++;
//     while(i < 10){
//         console.log(i);
//         i++;
//     }
// }

// let i = 1;
// do{
//     // let j = 5;
//     console.log(i);
//     i++;
//     do{
//         console.log(i);
//         i++;
//     }while(i < 10);

// }while(i < 5);

let key = 1;
let j = 'v';
switch (key) {
    case 1:{
        console.log("1st 1 working");
        switch (j) {
            case 'a':
                console.log('2nd a working');
                break;
            case 'v':
                console.log('2nd v working');
                break;
        
            default:
                break;
        }
        break;
    }

    case 2:{
        console.log('1nd 2 working');
        break;
    }

    default:
        break;
}