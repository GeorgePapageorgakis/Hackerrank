#Για καθε τιτλο τραγουδιου ποσες εκτελεσεις υπαρχουν σε cd ειτε απο τραγουδιστες ειτε απο συγκροτηματα
select count(Plirthos_ektelesewn)
from tragoudi, (
select title,count(title) as Plithos_ektelesewn
from singer_prod
group by title
union
select title,count(title) as Plithos_ektelesewn
from group_prod
group by title) A
