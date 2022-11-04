import Ball from "./ball.js"
import Paddle from "./paddle.js"

const ball = new Ball(document.getElementById("ball"))
const playerPaddle = new Paddle(document.getElementById("player-paddle"))
const computerPaddle = new Paddle(document.getElementById("computer-paddle"))
const playerScoreElem = document.getElementById("player-score")
const computerScoreElem = document.getElementById("computer-score")
const pause = document.getElementById("pause")
const reset = document.getElementById("reset")
var isPaused = 0;

let lastTime
function update(time) {
  if (lastTime != null) {
    const delta = time - lastTime
    if(isPaused ==0){
      ball.update(delta, [playerPaddle.rect(), computerPaddle.rect()])
    }
    computerPaddle.update(delta, ball.y)

    if (isLose()) handleLose()
  }

  lastTime = time
  window.requestAnimationFrame(update)
}

function isLose() {
  const rect = ball.rect()
  return rect.right >= window.innerWidth || rect.left <= 0
}

function handleLose() {
  const rect = ball.rect()
  if (rect.right >= window.innerWidth) {
    playerScoreElem.textContent = parseInt(playerScoreElem.textContent) + 1
  } else {
    computerScoreElem.textContent = parseInt(computerScoreElem.textContent) + 1
  }
  ball.reset()
  computerPaddle.reset()
}

pause.addEventListener('click', () =>{
  if (isPaused==0){
    pause.innerHTML = "Resume";
    isPaused = 1;
  }
  else{
    pause.innerHTML = "Pause";
    isPaused = 0;
  }
})

reset.addEventListener('click', () =>{
  playerScoreElem.textContent = 0;
  computerScoreElem.textContent = 0;
  ball.reset()
  computerPaddle.reset()
})

document.addEventListener("mousemove", e => {
  playerPaddle.position = (e.y / window.innerHeight) * 100
})

window.requestAnimationFrame(update)


// Credit: a lot of this game was created following tutorials and I implemented my own version with my own details.
// Sources:
// https://www.youtube.com/watch?v=PeY6lXPrPaA
// https://www.geeksforgeeks.org/pong-game-in-javascript/
// https://codepen.io/gdube/pen/JybxxZ

