<?php
	class Comentario{
		private $autor;
		private $texto;
		private $avaliacao;
		private $data;

		public function __construct($autor, $text, $avaliacao){
			$this->autor = $this->checkTxt($autor);
			$this->texto = $this->checkTxt($text);
			$this->avaliacao = $avaliacao;
			$this->data = date('Y-m-d'); #HAVIA FALTADO o 'Y-m-d' no moodle
		}

		public function getAutor(){
			return $this->autor;
		}

		public function setAutor($autor){
			$this->autor = $this->checkTxt($autor);
		}

		public function getTexto(){
			return $this->texto;
		}

		public function setTexto($texto){
			$this->texto = $texto;
		}

		public function getAvaliacao(){
			return $this->avaliacao;
		}

		public function setAvaliacao($avaliacao){
			$this->avaliacao = $avaliacao;
		}

		public function getData(){
			return $this->data;
		}

		private function checkTxt($autor){
			return addslashes($autor);
		}
	}

	class Banco{
		private $idconexao;
		const host = "localhost";
		const usuario = "root";
		const senha = "";
		const database = "museu";

		function __construct(){
			$this->idconexao = mysqli_connect(Banco::host, Banco::usuario, Banco::senha, Banco::database);
			//$this->idconexao = new PDO("mysql:host=".$this->host.";dbname=" . $this->database, $this->user, $this->password);
		}

		public function inserir(Comentario $comentario = NULL){

			if(!isset($comentario)) return false;

			$aut = $comentario->getAutor();
			$txt = $comentario->getTexto();
			$data = $comentario->getData();
			$ava = $comentario->getAvaliacao();

			if($ava > 5 || $ava < 1) return false;

			$string = "INSERT INTO comentario (autor, texto, data, avaliacao) VALUES ('$aut', '$txt', '$data', '$ava');";
			$resultado = mysqli_query($this->idconexao, $string);
			# NÃO CONSEGUI FAZER FUNCIONAR O PREPARE
			return $resultado;
		}

		function __destruct(){
			mysqli_close($this->idconexao);
		}
	}

	$comment = new Comentario("rafa", "trouxa!!!", 5);
	$db = new Banco();
	$res = $db->inserir($comment);
	if($res)
		echo "Inserção bem sucedida";
	else
		echo "Inserção retornou erro";
	unset($db);
?>


