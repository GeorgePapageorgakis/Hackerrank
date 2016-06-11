#Οι συνθετες (ονομα επιθετο) που εχουν γραψει μονο στιχους (δεν εχουν γραψει μουσικη σε κανενα τραγουδι)
select distinct ar_taut,onoma,epitheto
from tragoudi,kalitexnis
where ar_taut not in(select distinct ar_taut
	from tragoudi,kalitexnis
	where sinthetis=ar_taut)
and ar_taut = stixourgos