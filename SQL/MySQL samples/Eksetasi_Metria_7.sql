#Για καθε τιτλο τραγουδιου ποσες εκτελεσεις υπαρχουν σε cd απο τραγουδιστες
select distinct title, count(title) as ekteleseis
from singer_prod
group by title
order by ekteleseis desc