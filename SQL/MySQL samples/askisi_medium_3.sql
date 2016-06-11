#Ποιοι συνθετες ειναι και τραγουδιστες
select onoma as k_name, epitheto as k_surname
from tragoudi,kalitexnis
where sinthetis=ar_taut
union
select onoma as k_name, epitheto as k_surname 
from singer_prod,kalitexnis
where tragoudistis = ar_taut