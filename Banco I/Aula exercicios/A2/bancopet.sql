create database bancopet;

Create TABLE clientes ( 
    cpf INTEGER NOT NULL, 
    nome VARCHAR NOT NULL, 
    email VARCHAR NOT NULL, 
    ntel INTEGER NOT NULL, 
    constraint pk_cpf PRIMARY KEY (cpf) 
); 

create table raca (
  cod varchar not null,
  descr varchar not null,
  constraint pk_cod primary key(cod)
);


create table pet(
  codpet integer not null,
  nome varchar not null,
  draca varchar not null,
  dono integer not null,
  coment varchar,
  constraint pk_codpet primary key(codpet),
  constraint fk_petcliente foreign key(dono)references clientes(cpf),
  constraint fk_petraca foreign key(draca)references raca(cod)
);

create table historico(
  idhist varchar not null,
  codpet integer not null,
  data date not null,
  medida varchar not null,
  valor integer not null,
  unid varchar not null,
  constraint pk_idhist primary key(idhist),
  constraint fk_petcod foreign key(codpet)references pet(codpet)
);

insert into clientes(cpf,nome,email,ntel)values
  (11111,'Cruela de Vil','cruela@dalmata.com',1199932323),
  (44444,'Roger Dearly','roger@dalmata.com',1198761111),
  (55555,'Lee Duncan','lee@rinty',2134512222),
  (66666,'Anita Campbell','anita@dalmata.com',1187679988);
  
insert into raca (cod, descr)values
  (1,'Dalmata'),
  (2,'Pastor Alemão'),
  (3,'Yorkshire');

insert into pet(codpet,nome,draca,dono,coment)values
  (1,'Pongo','1', 44444,' '),
    (2,'Rin tin tin','2',55555,'Muito dócil'),
    (3,'Perdy','1', 66666,'Alérgica a sabão'),
    (4,'Benji','3', 11111,' ');
  
INSERT INTO historico(idhist,codpet,data,medida,valor,unid) values
  ('1',1,'10/05/2018','peso',10,'KG'),
  ('2',1,'10/05/2018','altura',98,'CM'),
  ('3',1,'10/05/2018','comprimento',1.23,'M'),
  ('4',2,'05/06/1975','peso',14.56,'KG'),
  ('5',2,'05/06/1975','altura',1.2,'M'),
  ('6',3,'12/08/2018','peso',9.8,'KG'),
  ('7',1,'14/08/2018','peso',11.2,'CM'),
  ('8',1,'11/11/2011','altura',89,'CM');
