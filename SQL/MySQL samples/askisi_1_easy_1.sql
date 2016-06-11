select onoma,titlos,etos_par
from kalitexnis, tragoudi
where kalitexnis.ar_taut = tragoudi.sinthetis and etos_par > 1980
order by onoma,titlos