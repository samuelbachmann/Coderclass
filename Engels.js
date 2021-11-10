var nauwkeurigheid = 100;  // % (LET OP: dit kan hoger/lager uitkomen)
var snelheid = 500;  // ms
var EnableNextButton = true;
var skipWriting = true; // set to false if you want to do writing yourself

if (!document.getElementsByTagName("iframe")[0].contentWindow.document.body.getElementsByTagName("frame")[5] && skipWriting) {
   document.getElementsByClassName("item-link")[1].click();
}
var x = document.getElementsByTagName("iframe")[0].contentWindow.document.body.getElementsByTagName("frame")[5].contentWindow.document.body;
var clickItems = [];
x.getElementsByClassName("comprobarComponent")[0].classList.add("active");
x.getElementsByClassName("activity")[0].click()

// input fields
var inputs = x.getElementsByTagName("input");
for (i = 0; i < inputs.length; i++) {
    inputs[i].value = inputs[i].outerHTML.split('"')[19].split('|||')[0];
}

// cards
var place = x.getElementsByClassName("destinoConFondo_KidsBox")
var placeOrder = [];

var cards = x.getElementsByClassName("arrastrableConFondo_KidsBox");

for (i = 0; i < place.length; i++) {
    placeOrder.push(place[i].outerHTML.split('"')[9].split('_')[1]);
}
if (cards.length && cards[0].outerHTML.split('"')[5]) {
    for (i = 0; i < cards.length; i++) {
        cardId = cards[i].outerHTML.split('"')[5].split(',')[0];
        clickItems.push(cards[i])
        clickItems.push(place[placeOrder.indexOf(cardId)])
    }
} else {
    for (i = 1; i < (cards.length); i++) {
        cardId = cards[i].outerHTML.split('"')[5].split(',')[0];
        clickItems.push(cards[i])
        clickItems.push(place[placeOrder.indexOf(cardId)])
    }
}

// connected dots
var beginDots = x.getElementsByClassName("divInitPointFlechas")
var beginOrder = [];
var eindDots = x.getElementsByClassName("destinoFlechaComponent")

for (i = 0; i < beginDots.length; i++) {
    beginOrder.push(beginDots[i].outerHTML.split('"')[5]);
}

for (i = 0; i < eindDots.length; i++) {
    console.log(1 + eindDots[i].outerHTML.split('"')[5])
    cardId = eindDots[i].outerHTML.split('"')[5];
    clickItems.push(beginDots[beginOrder.indexOf(cardId)]);
    clickItems.push(eindDots[i])
    
}

// true or false
var trueButton = x.getElementsByClassName("divButtonVerdadero");
var falseButton = x.getElementsByClassName("divButtonFalso");
var answere  = x.getElementsByClassName("verdaderoFalso_KidsBox");

for (i = 0; i < answere.length; i++) {
    answere[i].value = answere[i].outerHTML.split('"')[11];
    if (answere[i].value == "true"){
        clickItems.push(trueButton[i]);
}   if (answere[i].value == "false"){
        clickItems.push(falseButton[i])
}   
}

// multiple choise
var checkbox = x.getElementsByClassName("rdSeleccionUnica_rb_KidsBox");
for (i = 0; i < checkbox.length; i++) {
    if (checkbox[i].outerHTML.split('"')[5] == "true") {
        clickItems.push(checkbox[i])
    }
}

// dropdown menu
var options = x.getElementsByTagName("option");
var correctAnswer = x.getElementsByClassName("combo real");
var dropDownMenu = x.getElementsByClassName("combo_KidsBox");
zero = [];
one = [];
two = [];

for (i = 0; i < options.length; i++) {
    if(options[i].id.endsWith("_0")) {
        zero.push(options[i])
    }
}

for (i = 0; i < options.length; i++) {
    if(options[i].id.endsWith("_1")) {
        one.push(options[i])
    }
}

for (i = 0; i < options.length; i++) {
    if(options[i].id.endsWith("_2")) {
        two.push(options[i])
    }
}

for (i = 0; i < correctAnswer.length; i++) {
    correctAnswer[i].value = correctAnswer[i].outerHTML.split('"')[11];
    if (correctAnswer[i].value == "0"){
        zero[i].selected = true;
    }   else if (correctAnswer[i].value == "1"){
        one[i].selected = true;
    }   else if (correctAnswer[i].value == "2"){
        two[i].selected = true;
    }
}

// click on items with delay
function clickOnItem(item) {
    item.click();
}

clickItems.push(x.getElementsByClassName("comprobarComponent")[0]);

if (EnableNextButton) {
    clickItems.push(document.getElementsByClassName("item-link")[1]);
}

var i = 0;
while (clickItems[i]) {
    setTimeout(clickOnItem, snelheid*i , clickItems[i]);
    i++;
}