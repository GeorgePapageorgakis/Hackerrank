select etaireia, count(all *) as cds 
from cd_production
group by etaireia 
order by cds desc