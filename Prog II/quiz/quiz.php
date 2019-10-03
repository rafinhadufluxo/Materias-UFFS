<!doctype html>
<html lang="pt-br">
<head>
    <title>Quiz Web</title>
    <meta charset="utf-8">
    <style>
    body {
    	font-family: Verdana;
    	color:#0d244c;
    	font-size:1.2em;
    }
    legend {
    	color:#786007;
    	font-weight:bold;
    }
    h1 {
    	font-size:2em;
    	color:#1b1050;
    	font-weight:bolder;
        text-align: center;
        text-shadow: 2px 0px 2px #6D6498;
        text-shadow: 0px 3px 3px  #Dccc86; 
    }
    div.opcao {
    	width:150px;
    	float:left;
    }
    input, select, textarea{
        color: #735F0A;
        background-color: #fff7D5;
        border: 1px solid #1b1050;
    }
    input[type=submit]{
        padding: 5px 20px;
        background-color: #0c254f;
        color: #DCBD86;
        font-weight: bolder;
    }
    </style>
</head>
<body>
<h1>Teste seus conhecimentos sobre linguagens para a Web!</h1>
<br><br>
<form name="teste" action="respostas.php" method="post">
    <label>Seu nome: <input type="text" name="nome"></label>
    <br><br> 
    <label>Seu e-mail: <input type="email" name="email" size="50"></label>
    <br><br>
    <fieldset>
        <legend>Questão 1</legend>
        <label>Sigla da linguagem de marcação de hipertexto padrão da Web: 
        <input type="text" name="q1"></label>
    </fieldset>

    <fieldset>
        <legend>Questão 2</legend>
        <label>Sigla da linguagem estilização de páginas padrão da Web: 
        <input type="text" name="q2"></label>
    </fieldset>
    <fieldset>
    <legend>Questão 3</legend>
        Quais das linguagens abaixo são <i>client side</i>?<br>
        <div class="opcao"><input type="checkbox" value="a" name="q3[]">(a) Apache</div>
        <div class="opcao"><input type="checkbox" value="b" name="q3[]">(b) HTML</div>
        <div class="opcao"><input type="checkbox" value="c" name="q3[]">(c) PHP</div>
        <div class="opcao"><input type="checkbox" value="d" name="q3[]">(d) CSS</div>
        <div class="opcao"><input type="checkbox" value="e" name="q3[]">(e) JavaScript</div>    
        <div class="opcao"><input type="checkbox" value="f" name="q3[]">(f) ASP</div>    
    </fieldset>   
    <fieldset>
       <legend>Questão 4</legend>
       É um software responsável por servir páginas web:<br>
        <div class="opcao"><input type="radio" value="a" name="q4">(a) Apache</div>
        <div class="opcao"><input type="radio" value="b" name="q4">(b) HTML</div>
        <div class="opcao"><input type="radio" value="c" name="q4">(c) PHP</div>
        <div class="opcao"><input type="radio" value="d" name="q4">(d) n.d.a.</div>
    </fieldset>
    <fieldset>
        <legend>Questão 5</legend>
        Quais nomes abaixo correspondem a servidores HTTP?<br>
        <div class="opcao"><input type="checkbox" value="a" name="q5[]">(a) Apache</div>
        <div class="opcao"><input type="checkbox" value="b" name="q5[]">(b) PHP</div>
        <div class="opcao"><input type="checkbox" value="c" name="q5[]">(c) Safari</div>
        <div class="opcao"><input type="checkbox" value="d" name="q5[]">(d) Tomcat</div>
        <div class="opcao"><input type="checkbox" value="e" name="q5[]">(e) Lighttpd</div>    
        <div class="opcao"><input type="checkbox" value="f" name="q5[]">(f) IIS</div>      
    </fieldset>
    <fieldset>
        <legend>Questão 5</legend>
        É um sistema gerenciador de banco de dados relacional. Estamos falando de:<br>
        <div class="opcao"><input type="radio" value="a" name="q6">(a) MYSQL</div>
        <div class="opcao"><input type="radio" value="b" name="q6">(b) PHP</div>
        <div class="opcao"><input type="radio" value="c" name="q6">(c) Java</div>
        <div class="opcao"><input type="radio" value="d" name="q6">(d) Apache</div>
    </fieldset>
    <fieldset>
        <legend>Questão 7</legend> O
        <select name="q7">
            <option>Escolha</option>
            <option>Apache</option>
            <option>Navegador Web</option>
            <option>Servidor Web</option>
            <option>PHP</option>
            <option>MySQL</option>
        </select> é o software responsável por criar e exibir a interface com o usuário. O primeiro navegador gráfico foi criado em 1993 e chamava-se 
        <select name="q8">
            <option>Escolha</option>
            <option>Internet Explorer</option>
            <option>Mozilla</option>
            <option>Mosaic</option>
            <option>Netscape Navigator</option>
            <option>Safari</option>
        </select>.
    </fieldset>
    <fieldset>
        <legend>Comentários:</legend>
        <textarea name="comentario" rows="5" cols="80"></textarea>
    </fieldset>

    <br>
    <br>
  
    <input type="checkbox" name="concordo" checked>Concordo em ceder meu e-mail para receber propagandas desta empresa e seus parceiros.<br><br>

  <input type="submit" value="Ver resultado!">
</form>
<br>
</body>
</html>
