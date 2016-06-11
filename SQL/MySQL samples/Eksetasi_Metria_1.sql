#Ανα συνθετη (ονομα επιθετο) ποσα τραγουδια εχει η βαση
select  onoma,epitheto, count(titlos) as tragoudia
from tragoudi, kalitexnis
where sinthetis = ar_taut
group by sinthetis
order by tragoudia desc