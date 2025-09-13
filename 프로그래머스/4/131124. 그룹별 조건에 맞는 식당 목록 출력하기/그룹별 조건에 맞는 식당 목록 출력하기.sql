-- 가장 리뷰를 많이 쓴 사람의 리뷰 개수
# select count(*)
# from REST_REVIEW
# group by MEMBER_ID
# order by count(*) desc
# limit 1;

# with top_writer as (
#     select m.MEMBER_ID
#     from MEMBER_PROFILE m
#     join REST_REVIEW r on m.MEMBER_ID = r.MEMBER_ID
#     group by m.MEMBER_ID
#     having count(m.MEMBER_ID) =  ( 
#         select count(*)
#         from REST_REVIEW
#         group by MEMBER_ID
#         order by count(*) desc
#         limit 1
#     )   
# )

select m.MEMBER_NAME MEMBER_NAME, r.REVIEW_TEXT REVIEW_TEXT, date_format(r.REVIEW_DATE, '%Y-%m-%d') REVIEW_DATE
from MEMBER_PROFILE m 
join REST_REVIEW r on m.MEMBER_ID = r.MEMBER_ID
# from top_writer t
# join REST_REVIEW r on t.member_id = r.member_id
where r.MEMBER_ID in (
    select m.MEMBER_ID
    from MEMBER_PROFILE m
    join REST_REVIEW r on m.MEMBER_ID = r.MEMBER_ID
    group by m.MEMBER_ID
    having count(m.MEMBER_ID) =  ( 
        select count(*)
        from REST_REVIEW
        group by MEMBER_ID
        order by count(*) desc
        limit 1
    )
)
order by REVIEW_DATE, REVIEW_TEXT


