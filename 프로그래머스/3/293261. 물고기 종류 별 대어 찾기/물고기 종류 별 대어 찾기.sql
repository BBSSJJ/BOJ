select i.ID, n.FISH_NAME, m.LENGTH
from (select FISH_TYPE, MAX(LENGTH) as LENGTH
        from FISH_INFO
        group by FISH_TYPE) as m
    inner join FISH_INFO as i on m.FISH_TYPE = i.FISH_TYPE and m.LENGTH = i.LENGTH
    inner join FISH_NAME_INFO as n on m.FISH_TYPE = n.FISH_TYPE
order by i.ID