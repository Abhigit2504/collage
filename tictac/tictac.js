const gamedata=[
    [0,0,0],
    [0,0,0],
    [0,0,0],
];


let editedplayer =0;
let activeplayer=0;
let cuurentround=1;

const players =[
    {
        name:'',
        symbol:'X'
    },
    {
        name:'',
        symbol:'O'
    }
]

const configureoverlay=document.getElementById('configure-overlay');

const backdrop = document.getElementById('backdrop');

const editbutton1=document.getElementById('player1-edit-button');
const editbutton2=document.getElementById('player2-edit-button');

const cancelbtn=document.getElementById('calclebtn1');

const confirmbtn=document.querySelector('form');
const errortext=document.getElementById('error-text1');
const playername1=document.getElementById('player1-name');
const playername2=document.getElementById('player2-name');
const activeplayername=document.getElementById('turn-player-name');

editbutton1.addEventListener('click', editclicked);
editbutton2.addEventListener('click', editclicked);
cancelbtn.addEventListener('click',displaynone);
confirmbtn.addEventListener('submit',conformfun);


const startbutton=document.getElementById('startbtn');
const gamearea=document.getElementById('active-game');
// const gamesymbols=document.querySelectorAll('#game-grids li');
const gameboard=document.getElementById('game-grids')


startbutton.addEventListener('click',startnewgame);

// for(const gamesymbol of gamesymbols){
//   gamesymbol.addEventListener('click',selectgamefield);

// }
gameboard.addEventListener('click',selectgamefield);


const endgame=document.getElementById('game-article');

const gameovername=document.getElementById('winner-name');

