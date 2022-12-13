var numDrums = document.querySelectorAll(".drum").length;
for(var i = 0;i<numDrums;i++)
{
    document.querySelectorAll(".drum")[i].addEventListener("click",function (){
       
        var pressed = this.innerHTML;
        playtheChar(pressed);
        buttonAnimation(pressed);
        
    });
}

document.addEventListener("keydown",function(event){
     var press = event.key;
     playtheChar(press);
     buttonAnimation(press);
})


function playtheChar(pressing)
{
    switch (pressing) {
        case "w":
            var tom1 = new Audio('sounds/tom-1.mp3');
            tom1.play();    
            break;
        case "a":
                var tom2 = new Audio('sounds/tom-2.mp3');
                tom2.play();    
                break;

        case "s":
            var tom3 = new Audio('sounds/tom-3.mp3');
            tom3.play();
            break;
        
        case "d":
            var tom4 = new Audio('sounds/tom-4.mp3');
            tom4.play();
            break;

        case "j":
            var crash = new Audio('sounds/crash.mp3');
            crash.play();
            break;

        case "k":
            var kickbass = new Audio('sounds/kick-bass.mp3');
            kickbass.play();
            break;
        

        case "l":
            var snare = new Audio('sounds/snare.mp3');
            snare.play();
            break;
        default:
            break;
       }
}

function buttonAnimation(key)
{
    var btn = document.querySelector("."+key);
    btn.classList.add("pressed");

    setTimeout(function()
    {
        btn.classList.remove("pressed");
    },100);
}
// var audio = new Audio('sounds/tom-1.mp3');
//     //    audio.play();