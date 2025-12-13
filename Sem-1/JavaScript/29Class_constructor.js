class A{
    constructor(){ // constructor call itsef wan class object created.
        console.log("constructor is called");
    }
    // constructor(a, b){
    //     console.log(a, b);
    // }
    start(){
        console.log("start method is called");
    }
    start(a,b){ // in js class method override or constructor override consept not preset
        console.log(a + b + " start method is called");
    }
    stop(){
        console.log("stop method is called");
    }
}
let a1 = new A();
a1.start();
a1.start(10, 20);
a1.stop();