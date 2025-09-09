function nSum() {
    let n = +document.getElementById("nsum").value;
    let a = document.getElementById("answer");
    console.log(n);
    let rem = 0;
    let sum = 0;
    while (n > 0){
        rem = n % 10;
        sum = sum + rem;
        n = n/10.0;
    }

    a.innerHTML = "Answer is = " + sum;
}