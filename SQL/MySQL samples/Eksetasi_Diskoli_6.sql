#Το πληθος των τραγουδιων που δεν εχουν γραφει σε cd ουτε απο τραγουδιστη ουτε απο συγκροτημα
select count(titlos) as Agrafa_tragoudia
from tragoudi
where titlos not in(select title	#ή <> all
	from singer_prod
	union
	select title
	from group_prod)