<?php

include_once "conexao.php";

$sql = "select nomeProduto, nomeFabricante, avaliacao, texto, curtidas,  data as data from posts";
$resultado = mysqli_query($conexao, $sql); 

?>

<h1> Reviews: </h1>


<?php
	if(mysqli_num_rows($resultado) == 0){
	echo "<p>No momento, não há nenhuma review disponível</p>";
}

else {
	while($review = mysqli_fetch_array($resultado)){

	?>
	 <div class="review">
		<h1><?=$review['nomeProduto']?></h1>
		<h3><?=$review['nomeFabricante']?></h3>
		<p>avaliacao: <?=$review['avaliacao']?></p> 	
		<p><?=nl2br($review['texto'])?></p> 
		<p><?=nl2br($review['data'])?></p> 

	</div> 

	
	<?php
	}
	?>
<?php
} // fecha else
?>
</div>


