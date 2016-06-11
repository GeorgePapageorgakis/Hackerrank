#Τους καλλιτεχντες που εχουν γραψει μονο μουσικη (δεν εχουν γραψει στιχους ή τραγουδισει)
select distinct ar_taut,onoma,epitheto
from kalitexnis,singer_prod
where ar_taut in (select distinct ar_taut 
	from kalitexnis,tragoudi
	where ar_taut=sinthetis and ar_taut <> stixourgos)
and ar_taut <> tragoudistis