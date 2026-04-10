-- 코드를 입력하세요

select ugu.USER_ID, ugu.NICKNAME, w.TOTAL_SALES
from USED_GOODS_USER as ugu inner join 
( select WRITER_ID, sum(PRICE) as TOTAL_SALES
from USED_GOODS_BOARD
where STATUS = 'DONE'
group by WRITER_ID
having sum(PRICE) >= 700000 ) as w
on ugu.USER_ID = w.WRITER_ID
order by w.TOTAL_SALES
