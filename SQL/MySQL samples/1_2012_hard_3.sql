#Οι τιτλοι των τραγουδιών που έχουν γραφεί σε cd μόνο από συγκροτήματα 
select gp.title
from group_prod as gp 
where gp.title <> all(select sp.title	#ή με where gp.title not in (...)
from singer_prod as sp )