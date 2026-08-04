

select e.EMP_NO as EMP_NO, EMP_NAME, GRADE,
        case
        when GRADE = 'S' then SAL * 0.2
        when GRADE = 'A' then SAL * 0.15
        when GRADE = 'B' then SAL * 0.1
        else 0
        end as BONUS
        
from HR_EMPLOYEES as e inner join 
    (select EMP_NO,
            case
            when avg(SCORE) >= 96 then 'S'
            when avg(SCORE) >= 90 then 'A'
            when avg(SCORE) >= 80 then 'B'
            else 'C'
            end as GRADE
    from HR_GRADE
    group by EMP_NO) as g on e.EMP_NO = g.EMP_NO
order by e.EMP_NO