#Οι συνθετες (ονομα επιθετο) που εχουν γραψει μονο μουσικη (και δεν εχουν γραψει  στιχους σε κανενα τραγουδι)
select distinct ar_taut,onoma,epitheto
from tragoudi,kalitexnis
where ar_taut not in(select distinct ar_taut
	from tragoudi,kalitexnis
	where stixourgos=ar_taut)
and ar_taut = sinthetis