#Τους καλλιτεχνες (ονονα επιθετο) που δεν εχουν γραψει τη μουσικη και τους στιχους τραγουδιου
select ar_taut,onoma,epitheto
from kalitexnis
where ar_taut not in (select ar_taut
from tragoudi,kalitexnis
where sinthetis=ar_taut or stixourgos=ar_taut)
