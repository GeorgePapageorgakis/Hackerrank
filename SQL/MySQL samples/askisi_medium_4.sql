#Ποιοι συνθετες ειναι και στιχουργοι?
select distinct ar_taut, onoma, epitheto
from kalitexnis, tragoudi
where sinthetis = stixourgos and sinthetis = ar_taut and stixourgos = ar_taut