let marks = [40, 60, 80, 95];
for (let i = 0; i < marks.length; i++) {
    console.log(marks[i]);

}

for (let e in marks) {
    console.log(marks[e]);
}
for (let e of marks) {
    console.log(marks[e]);
}

// task 1: in colors if color name length is 5 than print in upper case else as it is
let colors = ["red", "white", "yellow", "green", "blue", "pink", "black"];
for (let i = 0; i < colors.length; i++) {
    if (colors[i].length == 5)
        console.log(colors[i].toUpperCase());
    else
        console.log(colors[i]);
}


// task: 2 a= [5,87,63,21,45], output = [6,89,66,25,50]
let a = [5, 87, 63, 21, 45];
let b = [];
for (let i = 0; i < a.length; i++) {
    b[i] = a[i] + i + 1;
}
console.log(b);

// task: 3 a=[8,96,25,14,58], output = [7,97,24,15,57]
let c = [8, 96, 25, 14, 58];
let d = [];
for (let i = 0; i < c.length; i++) {
    if (i % 2 == 0)
        d[i] = c[i] - 1;
    else
        d[i] = c[i] + 1;
}
console.log(d);
