-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

-- -----------------------------------------------------
-- Schema owldatabase
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema owldatabase
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `owldatabase` DEFAULT CHARACTER SET utf8 ;
USE `owldatabase` ;

-- -----------------------------------------------------
-- Table `owldatabase`.`cliente`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `owldatabase`.`cliente` (
  `idcliente` INT NOT NULL AUTO_INCREMENT,
  `clientenome` VARCHAR(45) NOT NULL,
  `clienteemail` VARCHAR(45) NULL,
  `clientetelefone` VARCHAR(45) NULL,
  `clienteendereco` VARCHAR(45) NULL,
  PRIMARY KEY (`idcliente`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `owldatabase`.`pedido`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `owldatabase`.`pedido` (
  `idpedido` INT NOT NULL AUTO_INCREMENT,
  `cliente_idcliente` INT NOT NULL,
  `pedidodata` DATE NOT NULL,
  `pedidoentrega` DATE NOT NULL,
  `pedidostatus` INT NOT NULL DEFAULT 0,
  `pedidodescricao` VARCHAR(450) NULL,
  PRIMARY KEY (`idpedido`),
  INDEX `fk_pedido_cliente1_idx` (`cliente_idcliente` ASC),
  CONSTRAINT `fk_pedido_cliente1`
    FOREIGN KEY (`cliente_idcliente`)
    REFERENCES `owldatabase`.`cliente` (`idcliente`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `owldatabase`.`tarefa`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `owldatabase`.`tarefa` (
  `idtarefa` INT NOT NULL AUTO_INCREMENT,
  `tarefaentrega` DATE NULL,
  `tarefadescricao` VARCHAR(450) NULL,
  `tarefaprioridade` INT NULL,
  `tarefastatus` TINYINT NOT NULL DEFAULT 0,
  PRIMARY KEY (`idtarefa`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `owldatabase`.`usuario`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `owldatabase`.`usuario` (
  `usuario` VARCHAR(45) NOT NULL,
  `usuariosenha` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`usuario`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `owldatabase`.`notas`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `owldatabase`.`notas` (
  `idnotas` INT NOT NULL,
  `usuario_idusuario` INT NOT NULL,
  `notastexto` VARCHAR(1000) NULL,
  `usuario_usuario` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`idnotas`, `usuario_idusuario`, `usuario_usuario`),
  INDEX `fk_notas_usuario1_idx` (`usuario_usuario` ASC),
  CONSTRAINT `fk_notas_usuario1`
    FOREIGN KEY (`usuario_usuario`)
    REFERENCES `owldatabase`.`usuario` (`usuario`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `owldatabase`.`tarefa_has_usuario`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `owldatabase`.`tarefa_has_usuario` (
  `tarefa_idtarefa` INT NOT NULL,
  `usuario_usuario` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`tarefa_idtarefa`, `usuario_usuario`),
  INDEX `fk_tarefa_has_usuario_usuario1_idx` (`usuario_usuario` ASC),
  INDEX `fk_tarefa_has_usuario_tarefa1_idx` (`tarefa_idtarefa` ASC),
  CONSTRAINT `fk_tarefa_has_usuario_tarefa1`
    FOREIGN KEY (`tarefa_idtarefa`)
    REFERENCES `owldatabase`.`tarefa` (`idtarefa`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_tarefa_has_usuario_usuario1`
    FOREIGN KEY (`usuario_usuario`)
    REFERENCES `owldatabase`.`usuario` (`usuario`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
