-- 코드를 작성해주세요




select e2.ID, e2.GENOTYPE as GENOTYPE, e1.GENOTYPE as PARENT_GENOTYPE
from ECOLI_DATA e1 inner join ECOLI_DATA e2 on e1.ID = e2.PARENT_ID
where (e1.GENOTYPE & e2.GENOTYPE) = e1.GENOTYPE
order by e2.ID
