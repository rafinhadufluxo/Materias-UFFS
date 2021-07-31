<?php
session_start();
require_once "conexao.php";
//$_POST['lalaa'] = 'asdasda';
$idMatricula = $_POST['matricula'];
//$rafa = array();



$stmt = $dbh->prepare("SELECT * FROM alunos WHERE matricula=:id");

$stmt->execute(['id' => $idMatricula]); 


while ($row = $stmt->fetch()) {



    if($row != true){
        echo"nao achou";
        $_SESSION['matricula']=null;
        header('Location:ninguem.php');
      
    }else{

        $_SESSION['matricula'] = $row['matricula'];
        $_SESSION['nome'] = $row['nome'];
        $_SESSION['email']= $row['email'];
        $_SESSION['endereco'] = $row['endereco'];
        $_SESSION['cidade']= $row['cidade'];
        $_SESSION['telefone'] = $row['telefone'];
        $_SESSION['situacao'] = $row['situacao'];

 }

}
if($row == false){
    $_SESSION['matricula']=null;
    header('Location:ninguem.php');
}
    
//var_dump($row);
//exit();
//print_r($_SESSION);
//exit();
//$_POST['teste'] = 'testezada';
$dbh = null;
$idMatricula = null;

//print_r($_SESSION);
header('Location:detalhes.php');
