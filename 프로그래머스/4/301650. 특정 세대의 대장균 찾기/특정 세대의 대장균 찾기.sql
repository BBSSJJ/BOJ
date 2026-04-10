-- 코드를 작성해주세요

select ed4.ID as ID
from
(select ed2.ID as ID
from ECOLI_DATA as ed1 inner join ECOLI_DATA as ed2
where ed1.ID = ed2.PARENT_ID and ed1.PARENT_ID is NULL) as ed3
inner join ECOLI_DATA as ed4 on ed3.ID = ed4.PARENT_ID
order by ID