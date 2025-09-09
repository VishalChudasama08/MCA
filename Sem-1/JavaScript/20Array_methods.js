let arr = [1,2,5,8,9];

let calculate_square = (arr) => {
    arr.forEach((vel)=>{
        console.log(vel*vel);
    });
}

calculate_square(arr);

// map method
let newArray = arr.map((val)=>{
    console.log(val*val);
});

console.log(newArray);