#Ανα στιχουργο (ονομα επιθετο) ποσα τραγουδια εχει η βαση
select onoma, epitheto, count(titlos) as  tragoudia
from kalitexnis,tragoudi
where ar_taut=stixourgos
group by stixourgos
order by tragoudia desc