//Problem 2
let techStars = {
    "companyName": "Tech Stars",
    "website": "www.techstars.site,",
    //Problem 1
    "employees": [
      {
        "firstName": "Sam",
        "department": "Tech",
        "designation": "Manager",
        "salary": 40000,
        "raiseEligible": true
      },
      {
        "firstName": "Mary",
        "department": "Finance",
        "designation": "Trainee",
        "salary": 18500,
        "raiseEligible": true
      },
      {
        "firstName": "Bill",
        "department": "HR",
        "designation": "Executive",
        "salary": 21200,
        "raiseEligible": false
      }
    ]
}

function problem1(){
    console.log("Problem 1", techStars.employees) //Problem 1
    problem2();
}

function problem2(){
    console.log("Problem 2", techStars) // Problem 2
    problem3();
}


//Problem 3
function addEmployee(obj, firstName, department, designation, salary, raiseEligible){
    let employee = {
        "firstName": firstName,
        "department": department,
        "designation": designation,
        "salary": salary,
        "raiseEligible": raiseEligible
    };
    obj['employees'].push(employee);
    console.log("Problem 3", techStars); //Problem 3
}
function problem3(){
    addEmployee(techStars, "Anna", "Tech", "Executive", 25600, false);
    problem4();
}

//Problem 4
function calculateSalary(obj){
    var emp = obj['employees'];
    var totalSalary = 0;
    for (let x in emp){
        totalSalary += emp[x].salary
    }
    console.log("Problem 4 - Total salary: ", totalSalary);
}
function problem4(){
    calculateSalary(techStars);
    problem5();
}

//Problem 5
function raise(obj){
    var emp = obj['employees'];
    for (let x in emp){
        if (emp[x].raiseEligible){
            emp[x].salary = emp[x].salary*1.1;
            emp[x].raiseEligible = false;
        }
    }
    console.log("Problem 5: ", techStars);
}
function problem5(){
    raise(techStars);
    problem6();
}


//Problem 6
wfh = ['Anna', 'Sam'];

function workFromHome(obj, wfh){
    var emp = obj['employees'];
    for (let x in emp){
        if(wfh.includes(emp[x].firstName)){
            emp[x]['wfh'] = true;
        }
        else{
            emp[x]['wfh'] = false;
        }
    }
    console.log("Problem 6: ", techStars);
}

function problem6(){
    workFromHome(techStars, wfh);
}

// function exec(){
//     var functions = new Array();
//     functions[0] = problem1;
//     functions[1] = problem2;
//     functions[2] = problem3;
//     functions[3] = problem4;
//     functions[4] = problem5;
//     functions[5] = problem6;
//     for (var i = 0; i < 3; i++) {         
//         asynfunctions[i].call();
//     }
// }

document.getElementById('jsonBtn').addEventListener('click', problem1);


