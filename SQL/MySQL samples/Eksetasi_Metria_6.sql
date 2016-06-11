#Ανα ετος ποσα τραγουδια εχουν γραφτει
select etos_par, count(distinct titlos) tragoudia #προαιρετικο το distinct
from tragoudi
group by etos_par
order by etos_par desc