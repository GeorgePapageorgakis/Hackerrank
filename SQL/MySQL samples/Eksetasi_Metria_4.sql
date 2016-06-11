#Οι στιχουργοι (ονομα επιθετο) με περισσοτερα απο δυο τραγουδια
select onoma,epitheto,count(titlos) as tragoudia
from kalitexnis,tragoudi
where ar_taut = stixourgos
group by stixourgos
having tragoudia >2