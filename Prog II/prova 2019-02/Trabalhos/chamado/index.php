<?php
include_once "conexao.php";
if (isset($_POST['cadastrar'])) {
  $nome = addslashes($_POST['nome']);
  $equipamento = addslashes($_POST['equipamento']);
  $texto = addslashes($_POST['txt']);
  $turno =   addslashes($_POST['turno']);



  $sql = "INSERT INTO `chamados`(`funcionario`, `equipamento`, `defeito`, `turno`) VALUES
				 ('$nome', '$equipamento', '$texto', '$turno')";
  //echo $sql;



  include_once "conexao.php";

  if (mysqli_query($conexao, $sql)) {
    echo "O chamado foi aberto";
  } else {
    echo "Chamado não foi aberto";
    echo mysqli_error($conexao);
  }
}
?>

<!DOCTYPE html>
<html lang="pt-br">

<head>
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <meta charset="utf-8">
  <title>Abrindo Chamado</title>

  <?php
  

  ?>

</head>

<style>
  * {
    box-sizing: border-box;
  }

  .vintage {
    padding: 20px 0px 0px 345px;
  }

  h1 {
    text-align: center;
    color: black;
  }
  h2 {
    text-align: center;
    color: brown;
  }
  footer {
    padding: 0px 25px 0px 36px;
    display: flex;
    flex-direction: column;
    background: black;
    margin-top: 20px;
  }
  footer p {
    color: black;

  }
  .container {
    background-color: white;
    overflow: hidden;

  }

  header,
  footer {
    background-color: white;
    ;
    color: #ffffff;
    padding: 10px;
    position: relative;
  }

  .menu {
    display: flex;
    font-size: 1em;
    text-transform: uppercase;
    padding: 20px 0 0 810px
  }
  .menu ul{
    display: flex; 
    align-content: flex-end;

  }
  .menu ul li {
    margin-right: 10px;
    list-style-type: none;
    display: flex;
  }

 

  .menu a:active {
    color: #867DC6;
  }

  .menu a:hover {
    text-shadow: 2px 2px 2px #000;
    border-bottom: 2px solid white;
  }

  a {
    text-decoration: none;
    color: black;
    float: left;
  }

  body {
    font-family: "Lucida Sans", "Liberation Sans", sans-serif;
    margin: 0;
  }

  .susu {
    padding: 0;
    text-align: end;
    margin-top: -50px;
  }
</style>
<header>

  <nav class="menu">
    <ul>
      <li><a href="index.php">Abrir chamado</a></li>
      <li><a href="#">Atendimento</a></li>
      <li><a href="#">Histórico</a></li>

    </ul>
  </nav>
</header>

<body>
  <?php
  if (isset($erros)) {
    echo "<p>Foram encontrados os seguintes erros:</p>";
    echo "<ul>";
    for ($i = 0; $i < count($erros); $i++)
      echo "<li style='color: red'>$erros[$i]</li>";
    echo "</ul>";
  }

  $nome = isset($_POST['nome']) ? $_POST['nome'] : "";
  $equipamento = isset($_POST['equipamento']) ? $_POST['equipamento'] : "";
  $turno = isset($_POST['turno']) ? $_POST['turno'] : "";
  //$data = isset($_POST['data']) ? $_POST['data'] :"";
  $texto = isset($_POST['txt']) ? $_POST['txt'] : "";

  ?>
  <div class="container">
    <h2> Chamado urgente </h2>
    <div class="vintage">
      <form action="index.php" method="post">
        <div>
          <br>
          <br>
          <label>Nome do Funcionario: <input type="text" placeholder="informe o nome do funcionario" name="nome" maxlength="50" size="50" value="<?= $nome ?>" required autofocus></label>
        </div>

        <div><br>
          <label>Equipamento:
            <select name="equipamento">
              <option value="0" <?= ($equipamento == 0) ? "selected" : "" ?>>Selecione</option>
              <option value="1" <?= ($equipamento == 1) ? "seleracted" : "" ?>>computador</option>
              <option value="2" <?= ($equipamento == 2) ? "selected" : "" ?>>notebook</option>
              <option value="3" <?= ($equipamento == 3) ? "selected" : "" ?>>telefone VoIP</option>
              <option value="4" <?= ($equipamento == 4) ? "selected" : "" ?>>projetor</option>
            </select>
          </label>
        </div><br>
        <div>
          <label for="txt">Descrição do defeito:</label><br><br>
          <textarea name="txt" id="txt" rows="10" cols="50" placeholder="Escreva o defeito" required autofocus></textarea>
        </div>

        <div>
          <br>
          <legend>Turno preferencial para atendimento:</legend>
          <br>
          <label><input type="radio" name="turno" checked value="0" <?= ($turno == 0) ?>>AM</label><br>
          <label><input type="radio" name="turno" value="1" <?= ($turno == 1)  ?>>PM</label><br>
          <br>

        </div>

        <div>
          <input type="submit" name="cadastrar" value="Confirmar">
          <input type="reset" name="reset" value="Limpar campos">
        </div>
        <br>
        <br>
        <br>
      </form>
    </div>
    <footer>
      <p>Naruto - Toquio</p>
      <div class="susu">
        <p> Suporte made <br> Tel: 0800 - 1234</p>
      </div>
    </footer>
  </div>
</body>