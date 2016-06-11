# Query the names of all American cities in CITY with populations larger than 120,000. The CountryCode for America is USA.
select NAME
from city 
where countrycode = 'USA' and population > 120000