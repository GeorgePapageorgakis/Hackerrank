#Για καθε τιτλο τραγουδιου ποσες εκτελεσεις υπαρχουν σε cd απο συγκροτημα
select distinct title, count(title) as ekteleseis
from group_prod
group by title
order by ekteleseis desc