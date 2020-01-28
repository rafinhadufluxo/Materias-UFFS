<!DOCTYPE html>
<html lang="pt-br">
    <head>
        <meta charset="UTF-8">
        <title>Contato</title>
    </head>
    <body>
		<h1>Formulário de Contato</h1>
		<form method="POST" action="processa.php">
			<label>Nome</label>
			<input type="text" name="nome" placeholder="Nome completo"><br><br>
			
			<label>Email</label>
			<input type="email" name="email" placeholder="Seu melhor e-mail"><br><br>
			
			<label>Mensagem</label>
			<textarea name="mensagem" rows="4" cols="50"></textarea><br><br>
			
			<input type="submit" value="Enviar"><br><br>
		</form>
	</body>
</html>