#Τους καλλιτεχνες (ονομα επιθετο) που εχουν γραψει τη μουσικη και τους στιχους ολων των τραγουδιων τους
select distinct onoma,epitheto,ar_taut
from tragoudi,kalitexnis
where ar_taut=sinthetis and sinthetis not in (
select sinthetis
from tragoudi
where sinthetis<>stixourgos)