const toggleButton = document.getElementsByClassName('toggle-button')[0];
const navbarLinks = document.getElementsByClassName('navbar-links')[0];

toggleButton.addEventListener('click', () => {
    navbarLinks.classList.toggle('active');
})

function nav (){
    $("#nav-placeholder").load("../nav.html");
}

function footer(){
    $("#footer-placeholder").load("../footer.html");
}


var blackToggle = document.getElementById("darkModeBlack");
var whiteToggle =  document.getElementById("darkModeWhite");
whiteToggle.addEventListener('click', () => {
    whiteToggle.style.display = "none";
    blackToggle.style.display = "inline";
    document.getElementsByClassName('navbar')[0].classList.toggle("light-mode");
    document.getElementsByClassName('fl-name')[0].classList.toggle("light-mode");
    document.getElementsByClassName('text-home-container')[0].classList.toggle("light-mode");
    document.getElementsByClassName('navbar-links')[0].classList.toggle("light-mode");
    document.body.classList.toggle("light-mode");
})

blackToggle.addEventListener('click', () => {
    whiteToggle.style.display = "inline";
    blackToggle.style.display = "none";
    document.getElementsByClassName('navbar')[0].classList.toggle("light-mode");
    document.getElementsByClassName('fl-name')[0].classList.toggle("light-mode");
    document.getElementsByClassName('text-home-container')[0].classList.toggle("light-mode");
    document.getElementsByClassName('navbar-links')[0].classList.toggle("light-mode");
    document.body.classList.toggle("light-mode");
})


const imgarr = ["../img/me.jpg", "../img/sky.jpeg", "../img/canyon.jpeg"];
i = 0;
var currImg = document.getElementsByClassName("snowpic")[0];
currImg.addEventListener('click', () => {
    i++;
    if(i == 3){
        i = 0;
    }
    currImg.src = imgarr[i];
})


