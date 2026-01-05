select COUNT(*) as FISH_COUNT
from FISH_INFO i inner join FISH_NAME_INFO n on i.FISH_TYPE = n.FISH_TYPE
where FISH_NAME = 'BASS' or FISH_NAME = 'SNAPPER'
