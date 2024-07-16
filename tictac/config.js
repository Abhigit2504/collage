function editclicked(event){
    editedplayer= +event.target.dataset.playerid;
  
    configureoverlay.style.display ='block';
    configureoverlay.style.background='white';
    configureoverlay.style.height='170px';
    backdrop.style.display ='block';
}
function displaynone(){
    configureoverlay.style.display ='none';
    backdrop.style.display ='none';
    confirmbtn.firstElementChild.classList.remove('error');
    errortext.textContent='';
    confirmbtn.firstElementChild.lastElementChild.value='';
}

function conformfun(event){
    event.preventDefault();
    const formdata=new FormData(event.target);
    const enteredname= formdata.get('nop').trim();
    
if(!enteredname){
    event.target.firstElemnetChild.classList.add('error');
    errortext.textContent="invalid user name";
    return;
}

const updatedplayerdata=document.getElementById('player-'+editedplayer+'-data');
updatedplayerdata.children[1].textContent=enteredname;
 players[editedplayer-1].name=enteredname;

displaynone();
}


