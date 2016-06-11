#Το πληθος των τραγουδιων που δεν εχουν γραφει σε cd απο τραγουδιστη
select titlos
from tragoudi
where titlos not in (select title 
	from singer_prod)