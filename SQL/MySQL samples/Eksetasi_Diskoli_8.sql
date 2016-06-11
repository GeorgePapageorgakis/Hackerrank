#Τους καλλιτεχντες που εχουν γραψει μονο στιχους (δεν εχουν συνθεσει ή τραγουδισει)
select distinct ar_taut,onoma,epitheto
from kalitexnis,singer_prod
where ar_taut in(
	select distinct ar_taut
	from tragoudi,kalitexnis
	where ar_taut =stixourgos and ar_taut <> sinthetis)
and ar_taut <> tragoudistis