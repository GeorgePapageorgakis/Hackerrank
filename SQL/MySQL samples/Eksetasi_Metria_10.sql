#Το πληθος των τραγουδιων που δεν εχουν γραφει σε cd απο συγκροτημα
select titlos
from tragoudi
where titlos <> all (select title 
	from group_prod)