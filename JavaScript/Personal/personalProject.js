let quoteArray = [
"I am a little burrito",
"I like it",
"Ikke flere colaer Johan!!!",
"Hvem er hun? (random pige på Johans Facebook)",
"I want to go snoogie",
"Look at hims! (any cute animal on Twitter)",
"Lad være med at løfte mig"
]

function getRandomIndex(quoteArray){
    let tempRandomNumber = Math.random()*quoteArray.length;
    return Math.floor(tempRandomNumber);
}

let dailyQuote = quoteArray[getRandomIndex(quoteArray)];

document.getElementById("dailyQuote").innerHTML = `<h2> ${dailyQuote} - Sarah </h2>`

let sarahImage = document.getElementById("sarahpicture");

// A function that changes picture on click
function changeImage(){
    if (sarahImage.src.includes("sarah.jpg"))
    { 
        sarahImage.src = "sarah2.jpg";
    } else {
        sarahImage.src = "sarah.jpg";
    }
}

let imageTimer = null;

function setTimer(){
    imageTimer = setTimeout(function (){
        alert("HEY YOU")},
        4000);
}

function clearTimer(){
    if (imageTimer != null){
        clearTimeout(imageTimer);
        imageTimer = null;
    }
}