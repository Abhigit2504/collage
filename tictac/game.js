
function resetgame(){
    activeplayer=0;
    cuurentround=1;
    endgame.firstElementChild.innerHTML='<h3>you won <span id="winner-name">winner name</span></h3>';
    endgame.style.display='none';
let gameboardindex=0;
    for(let i=0;i<3;i++){
        for (let j=0;j<3;j++){
            gamedata[i][j]=0;
            const gameboarditem=gameboard.children[gameboardindex];
            gameboarditem.textContent='';
            gameboard.classList.remove('disabled');
            gameboardindex++;
         
        }
    }
}



function startnewgame(){
    if(players[0].name==''||players[1].name==''){
        alert('plese set the names');
        return;
    }

resetgame();
    gamearea.style.display='block'
}

function activeplayerfun(){
    if(activeplayer===0){
        activeplayer= 1;
    }
    else{
        activeplayer = 0;
    }
    activeplayername.textContent=players[activeplayer].name;
}

function selectgamefield(event){
    console.log(event.target.tagName);
    if(event.target.tagName!=='LI'){
        return;
    }
const selectedfield=event.target;
const selectedcolumn=selectedfield.dataset.col -1;
   const selectedrow=selectedfield.dataset.row -1; 
   if(gamedata[selectedrow][selectedcolumn] > 0){
    alert("that box already filled");
    return;

   }

  selectedfield.textContent =players[activeplayer].symbol;
   selectedfield.classList.add('disabled');

  
   gamedata[selectedrow][selectedcolumn]=activeplayer +1; 
//    console.log(gamedata);

 const winnerid=checkforcombination();
if(winnerid !== 0){
    gamewinner(winnerid);

}
 console.log(winnerid);

    cuurentround++;
    activeplayerfun();
  
}

function checkforcombination(){
for(let i=0; i < 3; i++){

    if(gamedata[i][0]>0 && 
        gamedata[i][0]==gamedata[i][1] &&
         gamedata[i][1]==gamedata[i][2]){
        return gamedata[i][0];
    }
   }
    for(let i=0; i < 3; i++){
        if(
             gamedata[0][i]>0 && 
            gamedata[0][i]==gamedata[1][i] &&
             gamedata[0][i]==gamedata[2][i])
         {
            return gamedata[0][i];
        }
       }

        if(gamedata[0][0]>0 &&
            gamedata[0][0]==gamedata[1][1]&&
            gamedata[1][1]==gamedata[2][2]
            ){
                return gamedata[0][0];
            }
        if(gamedata[2][0]>0 &&
             gamedata[2][0]==gamedata[1][1]&&
            gamedata[1][1]==gamedata[0][2])
            {
            return gamedata[2][0];
            }
           if(cuurentround==9){
                return -1;
            }
       return 0;
 }

function gamewinner(winnerid){
    endgame.style.display='block';
    if(winnerid > 0){
        const winnername=players[winnerid -1].name;
        endgame.firstElementChild.firstElementChild.textContent=winnername;

    }else{
        endgame.firstElementChild.textContent="it's a draw";
    }

}

