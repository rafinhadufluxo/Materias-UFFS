<?php
$varnome = $_POST['nome'];
$varemail = $_POST['email'];
$acertos = 0;
$porcentagemdeacertos = 0;
$varconcordo = $_POST['concordo'];
echo "Nome:".$varnome."<br>E-mail:".$varemail."<br><br><br>";

$varq1 = $_POST['q1'];
if (isset($_POST['q1'])){
    if ($varq1 == "HTML"){
        echo "Questão 1: correta <br>";
        $acertos++;
    } else { if ($varq1 == " " ){
      echo "Questão 1: incorreta<br>";
    }
      echo "Questão 1: incorreta<br>";
    }
}

$varq2 = $_POST['q2'];
if (isset($_POST['q2'])){
if ($varq2 == "CSS"){
  echo "Questão 2: correta<br>";
  $acertos++;
} else { if ($varq2 == " " ){
  echo "Questão 2: incorreta<br>";
}
  echo "Questão 2: incorreta<br>";
}}


// insert into table_name (choice) VALUES ('varq3')
// if(empty($varq3))
// {
//   echo("Questão 3: incorreta.<br>");
// }
$varq3 = $_POST['q3'];
if (isset($_POST['q3'])){
$N = count($varq3);
  // echo("Foram selecionadas $N opções:<br> ");
for($i=0; $i < $N; $i++)
  {
    // echo htmlspecialchars($varq3[$i] ). " ";
    if($varq3[$i] == 'b' or $varq3[$i] == 'd' or $varq3[$i] == 'e'){
      echo "Questão 3: correta<br>";
      $acertos++;
    } else {
      echo "Questão 3: incorreta<br>";
    }
  }}

$varq4 = $_POST['q4'];
if (isset($_POST['q4'])){
if($varq4 == 'a'){
      echo "Questão 4: correta<br>";
      $acertos++;
    } else {
      echo "Questão 4: incorreta<br>";
    }}

$varq5 = $_POST['q5'];
if (isset($_POST['q5'])){
$k= count($varq5);
      // echo("Foram selecionadas $N opções:<br> ");
for($q=0; $q < $k; $q++)
      {
        echo "Questão 5: correta:<br>";

      if($varq5[$q] == 'a' or $varq5[$q] == 'd' or $varq5[$q] == 'e' or $varq5[$q] == 'f'){
          echo htmlspecialchars($varq5[$q] ). "<br> ";
          $acertos=$acertos+0.25;}
       else {
          echo "Questão 5: incorreta<br>";
        }
      }}

$varq6 = $_POST['q6'];
if (isset($_POST['q1'])){
if($varq6 == 'a'){
      echo "Questão 6: correta<br>";
      $acertos++;
    } else {
      echo "Questão 6: incorreta<br>";
    }}

$varq7 = $_POST['q7'];
if (isset($_POST['q7'])){
if($varq7 == "Navegador Web"){
      echo "Questão 7: correta<br>";
      $acertos++;
    } else { if(empty($varq7)){
        echo "Questão 7: incorreta<br>";
    }
       echo "Questão 7: incorreta<br>";
     }}

$varq8 = $_POST['q8'];
if (isset($_POST['q8'])){
if($varq8 == "Mosaic"){
          echo "Questão 8: correta<br>";
          $acertos++;
        } else { if(empty($varq7)){
            echo "Questão 8: incorreta<br>";
        }
           echo "Questão 8: incorreta<br>";
         }}


$varcomentario = $_POST['comentario'];
if (isset($_POST['comentario'])){
  echo "<br><br><br>Comentário:";
  echo "<pre>".$varcomentario."</pre><br>";
} else{
  echo "<br>";
}

$porcentagemdeacertos = (($acertos*100)/7);
echo round($porcentagemdeacertos,2);
echo "<br><br>Total de acertos:".$acertos." (".$porcentagemdeacertos." %)<br><br><br>";

if(!empty($varemail) && (isset($varconcordo))){
  echo "Você  autorizou o recebimento de propagandas no endereço ".$varemail.".";
}
else {
  echo "Você não autorizou o recebimento de propagandas no endereço ".$varemail.".";
}
?>
