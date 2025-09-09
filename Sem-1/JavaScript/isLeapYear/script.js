function isLeapYear() {
    let n = +document.getElementById("year").value;
    let a = document.getElementById("isLeap");
    console.log(n);
    if ((n % 4 == 0 && n % 100 != 0) || (n % 400 == 0)) {
        a.innerHTML = n + " is leap year";
    } else {
        a.innerHTML = n + " is not leap year";
    }
}