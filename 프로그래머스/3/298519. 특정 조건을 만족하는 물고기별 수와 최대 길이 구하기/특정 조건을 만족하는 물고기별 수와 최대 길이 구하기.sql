
select count(*) as FISH_COUNT, max(t.LENGTH) as MAX_LENGTH, t.FISH_TYPE
from FISH_INFO as t inner join
    (select FISH_TYPE, avg(ifnull(LENGTH, 10)) as AVG_LENGTH
    from FISH_INFO
    group by FISH_TYPE) as a on t.FISH_TYPE = a.FISH_TYPE
where a.AVG_LENGTH >= 33
group by FISH_TYPE
order by t.FISH_TYPE
