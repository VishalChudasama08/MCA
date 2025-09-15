
const student = {
    name: "yesha",
    id: 29,
    marks: 98,
    printmarks: function(){
        console.log(this.marks);
    }
}
console.log(student);
student.printmarks();
console.log(typeof(student));

const employee = {
    calculate_increment(){
        console.log("10% increment");
    },
    calculate_apprisal: function () {
        console.log("Apprisal is 13%");
    }
}
console.log(employee);
employee.calculate_increment()
employee.calculate_apprisal()
console.log(typeof employee);