#Οι συνθετες (ονομα επιθετο) με περισσοτερα απο 2 τραγουδια
select onoma, epitheto, count(titlos) as tragoudia
from kalitexnis,tragoudi
where ar_taut=sinthetis
group by sinthetis
having tragoudia>2