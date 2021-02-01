<?php
    $dsn = 'mysql:dbname=uffs;host=127.0.0.1';
    $user = 'root';
    $password = '';


try {
    $dbh = new PDO($dsn, $user, $password);
} catch (PDOException $e) {
    echo 'Connection failed: ' . $e->getMessage();
}




//  var_dump($_POST);
//     exit();
// 	$conexao = mysqli_connect("localhost", "webmaster", "sys123", "games");
// 	mysqli_query($conexao, "SET NAMES 'utf8'");
// 	mysqli_query($conexao, "SET character_set_connection=utf8");
// 	mysqli_query($conexao, "SET character_set_client=utf8");
// 	mysqli_query($conexao, "SET character_set_results=utf8");
?>

