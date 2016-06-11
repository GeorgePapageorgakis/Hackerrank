select title,count(ALL title) as cds #ALL gia non Null metriseis
from singer_prod
group by title

having max(cds) and count(title)>max(cds) 
#efarmozete ana grammi sti sxesi 
#pou paragete k einai grouped by