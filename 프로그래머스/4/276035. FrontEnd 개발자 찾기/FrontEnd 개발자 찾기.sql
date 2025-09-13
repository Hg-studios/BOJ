-- 개발자의 스킬들을 뽑기
# select d.ID, d.EMAIL, d.FIRST_NAME, d.LAST_NAME
# from SKILLCODES s
# join DEVELOPERS d
# where (s.code & d.skill_code) = s.code
# and s.CATEGORY = 'Front End'
# group by d.ID, d.EMAIL, d.FIRST_NAME, d.LAST_NAME
# order by d.ID


select d.ID, d.EMAIL, d.FIRST_NAME, d.LAST_NAME
from DEVELOPERS d
where d.SKILL_CODE & (
    select sum(CODE)
    from SKILLCODES
    where CATEGORY='Front End'
) > 0
order by d.ID