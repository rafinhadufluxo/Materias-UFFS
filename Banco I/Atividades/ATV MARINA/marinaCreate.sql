-- create tables accroding to the definition chapter 5.1 (livro da vaquinha)
create table sailor(
       sid       integer not null,
       sname     varchar(20),
       rating    integer,
       age       numeric(4,1),
       constraint pk_sailor primary key (sid)
);
create table boat(
       bid       integer not null,
       bname     varchar(20),
       color     varchar(20),
       constraint pk_boat primary key (bid)
);
create table reserve(
       sid       integer,
       bid       integer,
       day       date,
       constraint pk_reserve primary key (sid,bid,day),
       constraint fk_reserve_sailor foreign key (sid) references sailor(sid),
       constraint fk_reserve_boat foreign key (bid) references boat(bid)
);

insert into sailor (sid,sname,rating,age)
       values(22,'Dustin',7,45.0), (29,'Brutus',1,33.0), (31,'Lubber',8,55.5),
             (32,'Andy',8,25.5), (58,'Rusty',10,35.0),(64,'Horataio',7,35.0),
             (71,'Zorba',10,16.0), (74,'Horataio',9,35.0), (85,'Art',3,25.5), (95,'Bob',3,63.5);

insert into boat (bid,bname,color)
       values (101,'Interlake','blue'), (102,'Interlake','red'),
              (103,'Clipper','green'), (104,'Marine','red');

insert into reserve(sid,bid,day)
       values(22,101,'10/10/1998'), (22,102,'10/10/1998'), (22,103,'8/10/1998'),
             (22,104,'7/10/1998'),  (31,102,'10/11/1998'), (31,103,'6/11/1998'),
             (31,104,'12/11/1998'), (64,101,'5/09/1998'),  (64,102,'8/09/1998'),
             (74,103,'8/09/1998');
