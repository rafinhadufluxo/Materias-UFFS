/*01*/
SELECT sailor.name, level.dscr FROM sailor JOIN level ON level.aclevel = sailor.level;
/*02*/
SELECT * FROM level WHERE level.aclevel  NOT IN(SELECT level FROM sailor);
/*03*/
SELECT id FROM boattype WHERE id NOT IN(SELECT btype FROM boat);
/*04*/ 
SELECT * FROM boat JOIN boattype ON boat.bid = boattype.id WHERE boattype.id = 2 AND boat.phorses > 30;
/*05*/
SELECT * FROM reserve JOIN sailor ON reserve.sid = sailor.sid WHERE sailor.level = 'YOU';
/*06*/
SELECT * FROM boat WHERE len < 10;
/*07*/
SELECT * FROM reserve WHERE reserve.dhour BETWEEN '2019-05-01 00:00:00' AND '2019-05-01 23:59:59';
/*08*/
SELECT AVG(boat.phorses), boattype.dscr FROM boat JOIN boattype ON boat.bid = boattype.id WHERE boattype.dscr = (SELECT boattype.dscr WHERE id = 2) GROUP BY boattype.dscr;
/*09*/
SELECT boattype.dscr, MAX(boat.phorses) FROM boattype JOIN boat ON boattype.id = boat.bid GROUP BY boattype.dscr;
/*10*/
SELECT COUNT(*), sailor.level FROM sailor GROUP BY sailor.level;
/*11*/
SELECT * FROM boat JOIN reserve ON boat.bid = reserve.bid;
/*12*/
SELECT sailor.name, boat.name FROM sailor JOIN reserve ON sailor.sid = reserve.sid JOIN boat ON boat.bid = reserve.bid WHERE reserve.dhourret IS NULL;
/*13*/
SELECT sailor.name, boat.name FROM (reserve JOIN sailor ON sailor.sid=reserve.sid) JOIN boat ON reserve.bid=boat.bid WHERE reserve.dhourret - reserve.dhour=(SELECT MAX(reserve.dhourret - reserve.dhour) FROM reserve) GROUP BY sailor.name, boat.name;
/*14*/
SELECT * FROM boat WHERE boat.bid NOT IN(SELECT bid FROM reserve);
/*15*/
/*16*/
SELECT sailor.name, level.dscr, boat.name, boat.btype from boat LEFT JOIN reserve ON boat.bid = reserve.bid JOIN sailor ON reserve.sid = sailor.sid JOIN level ON sailor.level = level.aclevel;
/*17*/
SELECT * FROM boat WHERE boat.len = (SELECT MAX(len) FROM boat);
/*18*/
SELECT sailor.* FROM reserve JOIN boat ON reserve.bid = boat.bid JOIN sailor ON reserve.sid = sailor.sid WHERE boat.len = (SELECT MAX(len) FROM boat);
/*19*/
SELECT sailor.sid, sailor.name, sailor. level, (SELECT MAX(sailor.dbirth)) FROM sailor WHERE sailor.level = 'MAS' GROUP BY sailor.sid;
/*20*/

