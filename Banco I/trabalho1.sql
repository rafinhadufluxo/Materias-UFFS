

--  Aluno: Eduardo Stefanello       --
--  Data:  01 de Junho de 2017      --
--  Trabalho SQL - Banco de Dados I --


--1
  select sigc, nomec, uf
  from cidade;
  --     sigc |   nomec   | uf
  --    ------+-----------+----
  --     ITA  | Itajaí    | SC
  --     JOI  | Joiville  | SC
  --     XAP  | Chapecó   | SC
  --     ERE  | Erechim   | RS
  --     CWB  | Curitiba  | PR
  --     ITU  | Itu       | SP
  --     SPO  | São Paulo | SP
  --     CAI  | Caibi     | SC
  --     BLU  | Blumeau   | SC


--2
  select count(sigc)
  from cidade
  where uf = 'SC';
  --   count
  --  -------
  --       5


--3
  select nomec
  from cidade
  where uf = 'SC'
  order by nomec;
  --      nomec
  --    ----------
  --     Blumeau
  --     Caibi
  --     Chapecó
  --     Itajaí
  --     Joiville


--4
  select nomel
  from local
  where capac < 500;
  --         nomel
  --    ------------------
  --     Teatro Municipal
  --     Centro Eventos
  --     Teatro Municipal
  --     Teatro Municipal


--5
  select max(capac)
  from local;
  --     max
  --    ------
  --     1000


--6
  select nomel, capac
  from local
  order by capac
  desc limit 1;
  --         nomel      | capac
  --    ----------------+-------
  --     Pavilhão Shows |  1000


--7
  select nomec, nomel, capac
  from cidade
  inner join local
    on cidade.sigc = local.sigc
  order by capac desc
  limit 1;
  --      nomec  |     nomel      | capac
  --    ---------+----------------+-------
  --     Erechim | Pavilhão Shows |  1000


--8
  select avg(capac)
  from local
  where sigc = 'JOI';
  --              avg
  --    ----------------------
  --     375.0000000000000000


--9
  select nomec
  from cidade
  left join evento
    on cidade.sigc = evento.sigc
  where evento.sigc is null;
  --       nomec
  --    -----------
  --     Erechim
  --     Curitiba
  --     Itu
  --     São Paulo
  --     Caibi
  --     Blumeau


--10
  select distinct nomel
  from local
  inner join evento
    on local.sigl = evento.sigl;
  --        nomel
  --    ------------------
  --     Centro Eventos
  --     Teatro Municipal


--11
  select cidade.nomec, count(*)
  from evento
  inner join cidade
    on cidade.sigc = evento.sigc
  group by cidade.nomec;
  --      nomec   | count
  --    ----------+-------
  --     Itajaí   |     1
  --     Chapecó  |     1
  --     Joiville |     1


--12
  select evento.nomee
  from evento
  full outer join cidade
    on evento.sigc = cidade.sigc
  where cidade.sigc = 'XAP';
  --             nomee
  --    ----------------------
  --     Barbeiro de Sevilha


--13
  select distinct evento.nomee, cidade.nomec,
      local.nomel, bairro.nomeb
  from evento
  inner join cidade
    on evento.sigc = cidade.sigc
  inner join bairro
    on evento.sigb = bairro.sigb
  inner join local
    on evento.sigl = local.sigl;
  --            nomee         |  nomec   |      nomel       | nomeb
  --    ----------------------+----------+------------------+--------
  --     Barbeiro de Sevilha  | Chapecó  | Centro Eventos   | Centro
  --     Noivas de Copacabana | Itajaí   | Teatro Municipal | Centro
  --     Bolshoi              | Joiville | Teatro Municipal | Irirui


--14
  select distinct evento.nomee, cidade.nomec,
      local.nomel, bairro.nomeb
  from evento
  inner join cidade
    on evento.sigc = cidade.sigc
  inner join bairro
    on evento.sigb = bairro.sigb
  inner join local
    on evento.sigl = local.sigl
  where cidade.sigc = 'XAP'
    and evento.tpev = 1;
  --            nomee        |  nomec  |     nomel      | nomeb
  --    ---------------------+---------+----------------+--------
  --     Barbeiro de Sevilha | Chapecó | Centro Eventos | Centro


--15
  select distinct evento.nomee, tipoev.descr, local.capac
  from evento
  inner join tipoev
    on evento.tpev = tipoev.code
  inner join local
    on evento.sigl = local.sigl
  order by local.capac
  limit 1;
  --            nomee         |    descr     | capac
  --    ----------------------+--------------+-------
  --     Noivas de Copacabana | Show Musical |   200
