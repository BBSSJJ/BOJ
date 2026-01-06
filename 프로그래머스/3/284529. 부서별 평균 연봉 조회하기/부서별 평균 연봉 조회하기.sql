select d.DEPT_ID as DEPT_ID, d.DEPT_NAME_EN as DEPT_NAME_EN, round(avg(e.SAL), 0) as AVG_SAL
from HR_EMPLOYEES as e inner join HR_DEPARTMENT as d on e.DEPT_ID = d.DEPT_ID
group by e.DEPT_ID
order by AVG_SAL desc