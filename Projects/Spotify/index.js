

//Initialising the variables
let songIndex = 1;
let audioElement = new Audio('Audio/1.mp3');
let playButton = document.getElementById("playButton");
let progressbar = document.getElementById("progressbar");
let gif = document.getElementById("gif");
let mastersong = document.getElementById("mastersongname");



//Array of songs
let songs = [
    {SongName:"Besharam Rang",filepath:"Audio/1.mp3",cover:"images/pathaan-shah-rukh-khan-deepika-padukones-sizzling-chemistry-in-new-song-besharam-rang-left-fans-gasping-for-air-netizens-thirsty-comments-are-to-watch-out-for-001.jpg"},
    {SongName:"Janam Janam",filepath:"Audio/2.mp3",cover:"images/janam-janam-lyrics.jpg"},
    {SongName:"Zaalima",filepath:"Audio/3.mp3",cover:"images/Zaalima.jpg"},
    {SongName:"Mere Naam Tu",filepath:"Audio/4.mp3",cover:"images/MERE-NAAM-TU.jpg"},
    {SongName:"Manwa Laage",filepath:"Audio/5.mp3",cover:"images/Manwalaage.jpg"},
    {SongName:"Jabra Fan",filepath:"Audio/6.mp3",cover:"images/jabrafan.jpg"},
    {SongName:"Issaqbaazi",filepath:"Audio/7.mp3",cover:"images/ishqbazi.jpg"},
    {SongName:"Yun hi chala chal",filepath:"Audio/8.mp3",cover:"images/yuhhi.jpg"},
    {SongName:"Mitwa",filepath:"Audio/9.mp3",cover:"images/mitwa.jpg"},
    {SongName:"Haule Haule",filepath:"Audio/10.mp3",cover:"images/haule haule.jpg"},
    {SongName:"Chammak Challo",filepath:"Audio/11.mp3",cover:"images/chammak.jpeg"},
    {SongName:"I am the Best",filepath:"Audio/12.mp3",cover:"images/i am the best.jpg"},

]


//Play pause of masterplaybutton
playButton.addEventListener('click',()=>{
    if(audioElement.paused || audioElement.currentTime<=0){
        audioElement.play();
        playButton.classList.remove("fa-circle-play");
        playButton.classList.add("fa-circle-pause");
        gif.style.opacity = 1;
     }
     else{
        audioElement.pause();
        playButton.classList.add("fa-circle-play");
        playButton.classList.remove("fa-circle-pause");
        gif.style.opacity = 0;

     }
})




//progress bar
audioElement.addEventListener('timeupdate',()=>{
    progress = parseInt((audioElement.currentTime/audioElement.duration)*100);
    progressbar.value = progress;
})

progressbar.addEventListener('change',()=>{
    audioElement.currentTime = (progressbar.value * audioElement.duration) /100;
})


//The small play pause buttons
const makeallplays = ()=>{
    Array.from(document.getElementsByClassName("songitemplay")).forEach((element)=>{
        element.classList.remove("fa-circle-pause");
        element.classList.add("fa-circle-play");
    
    })
}



Array.from(document.getElementsByClassName("songitemplay")).forEach((element)=>{
    element.addEventListener('click',(e)=>{
        makeallplays();
        songIndex = parseInt(e.target.id);
        // console.log("Audio/${index}.mp3");
        mastersong.innerText = songs[songIndex-1].SongName;
        e.target.classList.remove("fa-circle-play");
        e.target.classList.add("fa-circle-pause");
        let text1 = "Audio/";
        let text2 = songIndex;
        let text3 = '.mp3';
        let result1 = text1.concat(text2);
        let result2 = result1.concat(text3);
        gif.style.opacity = 1;
        // console.log(result2);
        audioElement.src = result2;
        audioElement.currentTime = 0;
        audioElement.play();
        playButton.classList.add("fa-circle-pause");
        playButton.classList.remove("fa-circle-play");
    })
})




//Back and forward buttons

document.getElementById('forward').addEventListener('click',()=>{
    if(songIndex>=11)
    {
        songIndex = 0;
    }
    else{
        songIndex += 1;
    }
    let text1 = "Audio/";
    let text2 = songIndex+1;
    let text3 = '.mp3';
    let result1 = text1.concat(text2);
    let result2 = result1.concat(text3);
    gif.style.opacity = 1;
    mastersong.innerText = songs[songIndex].SongName;

    // console.log(result2);
    audioElement.src = result2;
    audioElement.currentTime = 0;
    audioElement.play();
    makeallplays();
    playButton.classList.add("fa-circle-pause");
    playButton.classList.remove("fa-circle-play");

})

document.getElementById('backward').addEventListener('click',()=>{
    if(songIndex<=0)
    {
        songIndex = 11;
    }
    else{
        songIndex -= 1;
    }
    console.log(songIndex);
    let text1 = "Audio/";
    let text2 = songIndex+1;
    let text3 = '.mp3';
    let result1 = text1.concat(text2);
    let result2 = result1.concat(text3);
    mastersong.innerText = songs[songIndex].SongName;

    gif.style.opacity = 1;
    // console.log(result2);
    audioElement.src = result2;
    audioElement.currentTime = 0;
    audioElement.play();
    makeallplays();
    playButton.classList.add("fa-circle-pause");
    playButton.classList.remove("fa-circle-play");

})
