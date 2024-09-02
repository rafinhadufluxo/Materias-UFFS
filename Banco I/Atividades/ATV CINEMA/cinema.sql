create table if not exists pessoa(
  codp integer not null,
  nome varchar(30) not null,
  dtnasc date not null,
  paisn  varchar(20) not null,
  constraint pk_pessoa primary key (codp)
);
--  
create table if not exists filme (
  codf integer not null,
  titulo varchar(20) not null,
  anol integer not null,
  dur  integer not null,
  codd integer not null,
  constraint pk_filme primary key (codf),
  constraint fk_filme_pessoa foreign key (codd) references pessoa(codp)
);
--
create table if not exists papel (
  codpp serial,
  descr varchar(20) not null,
  constraint pk_papel primary key (codpp)
);
--
create table if not exists elenco(
  codf  integer not null,
  codp  integer not null,
  codpapel integer not null,
  oscar char(1) not null,
  constraint pk_elenco primary key (codf,codp),
  constraint fk_elenco_pessoa foreign key (codp) references pessoa(codp),
  constraint fk_elenco_filme foreign key (codf) references filme(codf),
  constraint fk_elenco_papel foreign key (codpapel) references papel(codpp)  
);
--
create table if not exists avaliacao (
  codf integer not null,
  email varchar(30) not null,
  nestrelas numeric(2,1) not null,
  coment varchar(40),
  constraint pk_avaliacao primary key (codf,email),
  constraint fk_avaliacao_filme foreign key (codf) references filme(codf)
);
--
insert into pessoa (codp, nome, dtnasc, paisn) values
   (101,'Alfred','13/08/1889','Inglaterra'),
   (102,'Stephen','18/12/1946','EUA'),
   (104,'Harrison','13/07/1942','EUA'),
   (106,'Angelina','04/06/1975','EUA'),
   (109,'Sandra','26/07/1964','EUA'),
   (134,'Meryl','22/06/1949','EUA'),
   (136,'Brigitte','18/09/1934','França'),
   (144,'François','06/02/1932','França');
--
insert into filme (codf, titulo, anol, dur, codd) values
  (10,'Psycho',1960,109,101),
  (20,'The Birds',1963,119,101),
  (30,'Jaws',1975,124,102),
  (40,'Hook',1991,144,102),
  (50,'Fahr. 451',1966,112,144),
  (60,'Baisers Volés',1968,90,144);
--
insert into avaliacao (codf, email, nestrelas, coment) values
  (10,'cinefilo@yahoo.com',4.5,NULL),
  (10,'it@gmail.com',5,'Master Piece'),
  (20,'cinefilo@yahoo.com',5,'Awsome, hitchcock is fucking good!'),
  (20,'they@gmail.com',4.5,NULL),
  (20,'we@gmail.com',4,NULL),
  (60,'cinefilo@yahoo.com',4,'Un joli film'),
  (60,'he@gmail.com',3.8,'French movies :('),
  (60,'she@hotmail.com',4.5,'Excellent!'),
  (40,'cinefilo@yahoo.com',3,'So so'),
  (20,'she@hotmail.com',4.5,'I love it'),
  (10,'she@hotmail.com',5,'Uau! Tooke my breath away!!!'),
  (10,'he@gmail.com',4.8,'You cannot miss it!!');
--
insert into papel (descr) values ('Atriz Principal'),('Atriz Coadjuvante'),('Ator Principal'),('Ator Coadjuvante'),('Figurante');
--
insert into elenco (codf, codp, codpapel, oscar) values 
(10,		106,		1,	'Y'),
(10,		102,		3,	'N'),
(20,		102,		4,	'N'),
(20,		134,		1,	'N'),
(30,		106,		2,	'Y'),
(40,		136,		1,	'N'),
(50,		136,		1,	'N'),
(60,		109,		2,	'Y'),
(40,		109,		2,	'N'),
(10,		101,		5,	'N');
  
