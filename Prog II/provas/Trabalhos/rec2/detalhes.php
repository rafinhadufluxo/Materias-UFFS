<?php
session_start();
?>

<!doctype html>
<html lang="en">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <link rel="stylesheet" href="index.css">
    <title>Hello, world!</title>
  </head>
  <body>

  <table>
    <tr>
        <td>Nome</td>
        <td>E-mail</td>
        <td>Endereço</td>
        <td>Cidade</td>
        <td>Telefone</td>
        <td>Situação</td>

    </tr>
    <tr>
        <td><?=$_SESSION['nome']?></td>
        <td><?=$_SESSION['email']?></td>
        <td><?=$_SESSION['endereco']?></td>
        <td><?=$_SESSION['cidade']?></td>
        <td><?=$_SESSION['telefone']?></td>
        <td><?=$_SESSION['situacao']?></td>
    </tr>
</table>

  </body>
</html>
