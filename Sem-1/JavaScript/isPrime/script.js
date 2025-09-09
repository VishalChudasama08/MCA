function isPrime(){
    let n = +document.getElementById("prime").value;
    let a = document.getElementById("isP");
    let v = 0;
    console.log(n);
    for (let i = 2; i < n/2; i++) {
        if(n%i == 0){
            v = 0;
            // console.log(i);
            break;
        } else {
            v = 1;
            // console.log(i);
        }
    }

    if(v == 1){
        a.innerHTML = n + " is prime";
    } else {
        a.innerHTML = n + " is not prime";
    }
}