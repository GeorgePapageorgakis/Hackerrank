#Pio to onoma kai epitheto tou KALITEXNI me tis perisoteres ekteleseis  apo tragoudistes se cd
select title, onoma , epitheto, count(ALL tragoudistis) as cds #ALL gia non Null metriseis
from singer_prod,kalitexnis
where tragoudistis = ar_taut
group by title

having max(cds) and count(tragoudistis)>max(cds) 