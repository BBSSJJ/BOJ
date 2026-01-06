select e.ID, IFNULL(es.CHILD_COUNT, 0) as CHILD_COUNT
from ECOLI_DATA as e left join (SELECT e1.ID, COUNT(*) as CHILD_COUNT
from ECOLI_DATA as e1 inner join ECOLI_DATA as e2 on e1.ID = e2.PARENT_ID
group by e1.ID) as es on e.ID = es.ID