document.getElementById("fechar").onclick = function(){
    document.getElementById("ajuda").style.display = "none";
};

document.getElementById("exibe-menu").onclick = function(){
    var menu = document.getElementsByClassName("menu-opcoes")[0];
    if(menu.style.display == "initial")
        menu.style.display = "none";//oculta    
    else
        menu.style.display = "initial"; // exibe poxa

};

document.body.onresize = function(){
    var x = window.outerWidth;  //largura janela
    var menu = document.getElementsByClassName("menu-opcoes")[0];
    if(x >= 1000)
        menu.style.display = "initial";//exibe  
    else
        menu.style.display = "none"; // oculta
};