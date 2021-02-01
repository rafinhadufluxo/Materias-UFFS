DROP DATABASE IF EXISTS ti;
CREATE DATABASE ti DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;
USE ti;
DROP USER IF EXISTS 'suporte'@'localhost';
CREATE USER 'suporte'@'localhost' IDENTIFIED BY '12345';
GRANT SELECT, INSERT, UPDATE, DELETE ON ti.* TO 'suporte'@'localhost';
CREATE TABLE chamados (
  id INTEGER AUTO_INCREMENT PRIMARY KEY,  
  funcionario VARCHAR(50) NOT NULL,
  equipamento VARCHAR(50) NOT NULL,
  defeito TEXT,
  turno TINYINT(1)
);