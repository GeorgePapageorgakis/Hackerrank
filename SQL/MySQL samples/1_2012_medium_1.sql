#Οι τίτλοι των τραγουδιών με περισσότερες από μια εκτελέσεις από τραγουδιστές σε cd.
select title, COUNT(title) as Ekteleseis
from singer_prod
group by title
having ekteleseis > 1