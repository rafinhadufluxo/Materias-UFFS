<?php ?>
<!DOCTYPE html>
<html lang="pt-br" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title></title>
  </head>
  <body>
    <?php
    include "conexao.php";
    if (isset($_POST["cadastrar"])) {
      $_erros;
      if (!isset($_POST["nomeSerie"])) {
        $_erros .= "Digite o nome da série!<br>";
      }else{
        $nomeSerie = trim(addslashes($_POST["nomeSerie"]));
      }
      if (!isset($_POST["genero"])) {
        $_erros .= "Selecione o gênero da série!<br>";
      }else{
        $genero = $_POST["genero"];
      }
      if (!isset($_POST["texto"])) {
        $_erros .= "Digite o texto sobre à série!<br>";
      }else{
        $texto = trim(addslashes($_POST["texto"]));
      }
      if(empty($_erros)){
        $avaliacao = $_POST["nota"];
        if(!isset($_POST["encerrada"]))
          $encerrada = 0;
        else
          $encerrada = 1;
        $data = date('y/m/d');
        $sql = "INSERT INTO reviews (nomeSerie, codGenero, avaliacao, texto, encerrada, data, curtidas) VALUES ('$nomeSerie', $genero,
         $avaliacao,'$texto', $encerrada, '$data', 0)";
        mysqli_query($conexao,$sql);
        $sql = "";
        echo "Série cadastrada com sucesso!<br>";
      }else{
        ?>
        <p><?=$_erros?></p>
        <?php
      }
    }
     ?>
    <form class="teste" action="index.php" method="post">
      <label>Nome da série:<input type="text" name="nomeSerie" maxlength="50"></label> <br>
      <label>Genero:<select name="genero" id="genero">
        <option>Selecione o genero:</option>
        <?php

        $sql1 = "select * from genero";
        $resultado = mysqli_query($conexao,$sql1);
        if(mysqli_num_rows($resultado) == 0){
					echo "<p>Nenhuma categoria encontrada</p>";
				}
				else{
          while ($teste = mysqli_fetch_array($resultado)){
         ?>
          <option value="<?=$teste['codigo'];?>"><?=$teste['nomeGenero'];?></option>
         <?php
          }
        }
         ?>
      </select></label> <br>
      <label>Nota:<label><input type="radio" name="nota" value="0" checked>0</label>
      <label><input type="radio" name="nota" value="1">1</label>
      <label><input type="radio" name="nota" value="2">2</label>
      <label><input type="radio" name="nota" value="3">3</label>
      <label><input type="radio" name="nota" value="4">4</label>
      <label><input type="radio" name="nota" value="5">5</label></label> <br>
      <label>Texto:<textarea name="texto" rows="8" cols="80"></textarea></label> <br>
      <label><input type="checkbox" name="encerrada">Encerrada</label> <br>
      <input type="submit" name="cadastrar" value="Cadastrar Série">
      <input type="reset" value="Limpar campos">
    </form>
  </body>
</html>
