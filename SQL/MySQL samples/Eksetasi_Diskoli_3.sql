#Ποσοι καλλιτεχνες εμφανιζονται μονο σαν τραγουδιστες
select count(distinct ar_taut) as Number_of_Singers
from kalitexnis,singer_prod
where ar_taut not in
	(select distinct ar_taut
	from tragoudi,kalitexnis
	where sinthetis=ar_taut or stixourgos=ar_taut)
and ar_taut=tragoudistis