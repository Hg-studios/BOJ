SELECT O.ANIMAL_ID, O.NAME
from animal_ins i 
right outer join animal_outs o on i.animal_id = o.animal_id
WHERE I.ANIMAL_ID IS NULL
ORDER BY O.ANIMAL_ID;