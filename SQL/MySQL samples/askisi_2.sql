SELECT   etaireia, COUNT(*) AS cds
FROM  cd_production
GROUP BY etaireia
HAVING cds = (
   SELECT MAX(cds) 
   FROM (SELECT etaireia, COUNT(*) as cds
         FROM cd_production 
         GROUP BY etaireia) as subq
   )