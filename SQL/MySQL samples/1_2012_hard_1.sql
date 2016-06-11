#Ποια τραγούδια έχουν παραχθεί σε cd τόσο από τραγουδιστές όσο και από συγκροτήματα
select title
from singer_prod
where title in
(select title
from group_prod); 

/* γινεται και:

select title
from group_prod,tragoudi
where title=titlos
union
select title
from group_prod, tragoudi
where title=titlos
*/