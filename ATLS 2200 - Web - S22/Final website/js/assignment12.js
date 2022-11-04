var quote = document.getElementById("quote");
var author = document.getElementById("author");
var quoteButton = document.getElementById("quoteBtn");


const endpoint = "https://api.quotable.io/random";

quoteButton.addEventListener('click', () => {
    try{
        fetch(endpoint)
            .then((data) => data.json())
            .then((item) => {
                quote.innerText = item.content;
                author.innerText = item.author;
            });

    }catch{
        console.log(err);
        alert("failed");
    }
})
