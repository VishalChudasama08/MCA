// let d = new Date();
// let day = d.getDay();
let day = new Date().getDay();

switch (day) {
    case 5:
        console.log("It's fentastic friday");
        break;
    case 6:
        console.log("It's super saturday");
        break;
    case 0:
        console.log("It's sanday");
        break;
    default:
        break;
}

// 9 excellent
// 8 very good
// 7 good 

// let cgpa = prompt("Enter your cgpa");
// switch (cgpa) {
//     case 10:
//     case 9: {
//         console.log("Excellent");
//         break;
//     }
//     case 8:
//         console.log("Very Good");
//         break;
//     case 7:
//         console.log("Good");
//         break;
//     case 6:
//     case 5:
//         console.log("Avg");
//         break;
//     case 4:
//     case 3:
//     case 2:
//     case 1:
//         console.log("FAIL");
//         break;

//     default:
//         console.log("Enter between 1 to 10");
//         break;
// }

// if (cgpa< 10 && cgpa>9) {
//     console.log("Excellent");
// } else if(cgpa<=8 && cgpa>=7){
//     console.log("Very Good");
// } else if(cgpa<=6 && cgpa>=5){
//     console.log("Good");
// } else {
//     console.log("FAIL");
// }

let cgpa = prompt("Enter your cgpa");

switch (true) {
    case(cgpa<=10 && cgpa>=9):
        console.log("Excellent");
        break;
    case(cgpa<=8 && cgpa>=7):
        console.log("Very Good");
        break;
    case(cgpa<=7 && cgpa>=6):
        console.log("Good");
        break;
    case(cgpa<=6 && cgpa>=5):
        console.log("AVG.");
        break;
    case(cgpa<5):
        console.log("FAIL");
        break;
    default:
        console.log("Enter between 1 to 10");
        break;
}