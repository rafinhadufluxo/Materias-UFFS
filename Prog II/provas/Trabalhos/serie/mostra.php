<?php
 include "conexao.php";
 $sql = "select * from reviews";
 $resultado = mysqli_query($conexao, $sql);
       if(mysqli_num_rows($resultado) == 0){
         echo "<p>Nenhum review encontrado</p>";
       }
       else{
         while ($review = mysqli_fetch_array($resultado)){
         ?>
         <h1><?=$review["nomeSerie"];?></h1>
         <?php
          if($review["codGenero"] == 1){
            $gen = "drama";
          }
          if($review["codGenero"] == 2){
            $gen = "ação";
          }
          if($review["codGenero"] == 3){
            $gen = "aventura";
          }
          if($review["codGenero"] == 4){
            $gen = "terror";
          }
          if($review["codGenero"] == 5){
            $gen = "comédia";
          }
          if($review["codGenero"] == 6){
            $gen = "ficção";
          }
          if($review["codGenero"] == 7){
            $gen = "fantasia";
          }
          ?>
         <h3><?=$gen;?></h3>
         <p><?=$review["texto"];?></p>
         <strong><p><?=$review["data"];?></p></strong>
         <p>
         <?php
          for($i = 0; $i < $review["avaliacao"]; $i++){
          ?>
            <img src="icone_estrela.png" width="40">
          <?php
          }
          ?>
        </p>
        <p><img src="icone_curtir.png" width="40"><?=$review["curtidas"];?></p>
        <?php
        }
      }
        ?>
