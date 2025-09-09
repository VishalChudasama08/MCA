function perform() {
    let n = +document.getElementById("n").value;
    let v = document.getElementById("answer");
    console.log(n);

    let fact = 1;
    if(n%2 == 0){
        while (n > 0){
            fact = fact * n;
            n = n - 1;;
        }
        v.innerHTML = "Factorial: " + fact;
        console.log("Factorial: " + fact);

    } else {
        console.log("Fibonaci: ");
        let a = 1;
        let b = 1;
        v.innerHTML = "Fibonaci: ";
        if(n == 1){
            console.log(a);
            v.innerHTML += a;
        } else {
            v.innerHTML += a +", " + b;
            console.log(a);
            console.log(b);
        }
        for (let i = 2; i < n; i++) {
            c = a + b;
            v.innerHTML += ", "+ c;
            a = b;
            b = c;
            console.log(c);
        }
    }
}