let quoteArray = [
"I am a little burrito",
"I like it",
"Ikke flere colaer Johan!!!",
"Hvem er hun? (random pige på Johans Facebook)",
"I want to go snoogie",
"Look at hims! (any cute animal on Twitter)"
]

function getRandomIndex(quoteArray)
{
    let tempRandomNumber = Math.random()*quoteArray.length;
    return Math.floor(tempRandomNumber);
}

let dailyQuote = quoteArray[getRandomIndex(quoteArray)];

document.getElementById("dailyQuote").innerHTML = `<h2> ${dailyQuote} - Sarah </h2>`

function changeImage()
{
    if (document.getElementById("sarahpicture").src == "http://127.0.0.1:5500/Personal/sarah.jpg")
    { 
        document.getElementById("sarahpicture").src = "http://127.0.0.1:5500/Personal/sarah2.jpg";
    } else {
        document.getElementById("sarahpicture").src = "http://127.0.0.1:5500/Personal/sarah.jpg";
    }
}