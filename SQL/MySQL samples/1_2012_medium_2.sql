#Σε πόσα διαφορετικά cd έχει τραγουδήσει ένας τραγουδιστής.
select onoma, epitheto, count(all cd) as cds
from singer_prod,kalitexnis
where tragoudistis=ar_taut
group by tragoudistis
order by cds desc