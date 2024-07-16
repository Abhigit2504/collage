function valid(){
    var email2 = document.getElementById("emailbox").value;
    var pass =document.getElementById("passbox").value;
    var checkbx =document.getElementById("checkbx").checked;

    var at=email2.indexOf('@');
    var dot = email2.indexOf('.');
    if(at<3||dot<at+3||dot+2>email2.length){
        alert("invalid e mail or passowrd");
        return false;
    }
    else if(pass.length<=5){
        alert("password must contain 6 charactors");
        return false;
    }
    else if(checkbx==false){
        alert("check box not activated");
        return false;
        
    }
}