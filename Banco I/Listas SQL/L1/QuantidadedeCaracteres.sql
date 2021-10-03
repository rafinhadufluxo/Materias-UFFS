select name, char_length(name) as length
from people
order by length desc;
