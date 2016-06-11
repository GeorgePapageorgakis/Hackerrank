#Το όνομα και το επίθετο συνθέτη που τα τραγούδια του έχουν γραφεί σε cd μόνο από ένα τραγουδιστή.
select titlos as titlos_tragoudiou, onoma, epitheto
from tragoudi,kalitexnis
where sinthetis = ar_taut and titlos in(
	select title as titlos_tragoudiou
	from singer_prod
	group by title
	having count(title) = 1)