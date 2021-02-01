<?php
	$conexao = mysqli_connect("localhost", "webmaster", "sys123", "games");
	mysqli_query($conexao, "SET NAMES 'utf8'");
	mysqli_query($conexao, "SET character_set_connection=utf8");
	mysqli_query($conexao, "SET character_set_client=utf8");
	mysqli_query($conexao, "SET character_set_results=utf8");
?>

