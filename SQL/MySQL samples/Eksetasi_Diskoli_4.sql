#Οι καλλιτεχνες (ονομα επιθετο) που εμφανιζονται μονο σαν τραγουδιστες
select distinct  ar_taut,onoma, epitheto
from kalitexnis,singer_prod
where ar_taut not in
	(select distinct ar_taut
	from tragoudi,kalitexnis
	where sinthetis=ar_taut or stixourgos=ar_taut)
and ar_taut=tragoudistis