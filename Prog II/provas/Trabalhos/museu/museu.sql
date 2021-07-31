create table comentario(
    id int NOT NULL AUTO_INCREMENT PRIMARY KEY,
    autor varchar(50),
    texto text,
    data date,
    avaliacao  int
);

HOSTS: localhost
Usuário : user
Senha: sistema
Database: museu

Utilize o codigo abaixar para testar as duas classes. O resultado
deve ser "Inserção bem sucedida".

$comment = new Comentario("Andressa", "Gostei demais!!", 5);
$db = new Banco();
$res = $db->inserir($comment);
	if($res)
		echo "Inserção bem sucedida";
	else
		echo "Inserção retornou erro";
	unset($db);