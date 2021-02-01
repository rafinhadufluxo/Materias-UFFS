<?php
include_once "conexao.php";
if (isset($_POST['cadastrar'])){ 
	$nome = addslashes($_POST['nome']);
	$fabricante = addslashes($_POST['fabricante']);
	$avaliacao = $_POST['avaliacao'];
	$texto = addslashes($_POST['txt']);
	//$likes = $_POST['likes'];
	$dat = date("'d-m-Y'");
	$curtidas = 0;

	

	$sql = "INSERT INTO posts (nomeProduto, nomeFabricante, avaliacao, texto, data, curtidas) 
				values ('$nome', '$fabricante', '$avaliacao', '$texto', STR_TO_DATE($dat, '%d-%m-%Y'), $curtidas)";
	//echo $sql;

include_once "conexao.php";

	if (mysqli_query($conexao, $sql)) {
		echo "Cadastro realizado com sucesso";
	} else {
		echo "Ocorreu um erro no cadastro";
		echo mysqli_error($conexao);
	}
}
?>

<h1>Reviews</h1>


<?php
if (isset($erros)) {
	echo "<p>Foram encontrados os seguintes erros:</p>";
	echo "<ul>";
	for ($i = 0; $i < count($erros); $i++)
		echo "<li style='color: red'>$erros[$i]</li>";
	echo "</ul>";
}

$nome = isset($_POST['nome']) ? $_POST['nome'] : "";
$fabricante = isset($_POST['fabricante']) ? $_POST['fabricante'] : "";
$avaliacao = isset($_POST['avaliacao']) ? $_POST['avaliacao'] : "";
//$data = isset($_POST['data']) ? $_POST['data'] :"";
$texto = isset($_POST['txt']) ? $_POST['txt'] : "";

?>
<form action="cadastro.php" method="post">
	<div>
		<label>Nome: <input type="text" name="nome" maxlength="50" size="50" value="<?= $nome ?>" required autofocus></label>
	</div>

	<div><br>
		<label>Fabricante:
			<select name="fabricante">
				<option value="0" <?= ($fabricante == 0) ? "selected" : "" ?>>XYZ Games</option>
				<option value="1" <?= ($fabricante == 1) ? "selected" : "" ?>>KWY Games</option>
				<option value="2" <?= ($fabricante == 2) ? "selected" : "" ?>>WWW Games</option>
				<option value="3" <?= ($fabricante == 3) ? "selected" : "" ?>>FFF Games</option>
				<option value="4" <?= ($fabricante == 4) ? "selected" : "" ?>>ASF Games</option>
			</select>
		</label>
	</div><br>
	
	<div>
		<fieldset>
			<legend>Avaliação:</legend>
			<label><input type="radio" name="avaliacao" checked value="0" <?= ($avaliacao == 0) ? "selected" : "" ?>>0</label><br>
			<label><input type="radio" name="avaliacao" value="1" <?= ($avaliacao == 1) ? "selected" : "" ?>>1</label><br>
			<label><input type="radio" name="avaliacao" value="2" <?= ($avaliacao == 2) ? "selected" : "" ?>>2</label><br>
			<label><input type="radio" name="avaliacao" value="3" <?= ($avaliacao == 3) ? "selected" : "" ?>>3</label><br>
			<label><input type="radio" name="avaliacao" value="4" <?= ($avaliacao == 4) ? "selected" : "" ?>>4</label><br>
			<label><input type="radio" name="avaliacao" value="5" <?= ($avaliacao == 5) ? "selected" : "" ?>>5</label><br>

		</fieldset>
	</div>
	<div>
		<label for="txt">Texto:</label><br>
		<textarea name="txt" id="txt" rows="10" cols="40" placeholder="Escreva seu comentário" required autofocus></textarea>
	</div>

	<div>
		<input type="submit" name="cadastrar" value="Confirmar">
		<input type="reset" name="reset" value="Limpar campos">
	</div>


</form>