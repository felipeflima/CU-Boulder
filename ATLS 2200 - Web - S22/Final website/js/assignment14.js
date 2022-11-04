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

console.log("Problem 1", techStars.employees) //Problem 1


console.log("Problem 2", techStars) // Problem 2



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
addEmployee(techStars, "Anna", "Tech", "Executive", 25600, false);


//Problem 4
function calculateSalary(obj){
    var emp = obj['employees'];
    var totalSalary = 0;
    for (let x in emp){
        totalSalary += emp[x].salary
    }
    console.log("Problem 4 - Total salary: ", totalSalary);
}
calculateSalary(techStars);


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
raise(techStars);


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

workFromHome(techStars, wfh);




