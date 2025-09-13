-- 2021년에 가입한 전체 회원들에 대한 판매 데이터
with 
join_2021 as (
    select u.USER_ID, o.SALES_DATE
    from USER_INFO u
    join ONLINE_SALE o on u.USER_ID = o.USER_ID
    where date_format(u.JOINED, '%Y') = '2021'
),

cnt_2021 as (
    select count(*) cnt
    from USER_INFO u
    where date_format(u.JOINED, '%Y') = '2021'
)

-- 2021
# select * from join_2021
# order by SALES_DATE

 # select * from cnt_2021;
 
select date_format(SALES_DATE, '%Y') YEAR, date_format(SALES_DATE, '%m') MONTH, count(distinct(USER_ID)) PURCHASED_USERS, round(count(distinct(USER_ID))/cnt, 1) PUCHASED_RATIO
from join_2021
join cnt_2021
group by date_format(SALES_DATE, '%Y'), date_format(SALES_DATE, '%m')
order by SALES_DATE

-- join_2021에서 결국 같은 년월에 판매한 회원은 group by 해야됨 
-- 아니면 그냥 년월로 그룹바이 하고 user_id에 distinct를 써야되나?
-- 그룹바이 하기 전에 전체 개수를 어떻게 기억하고 있지....? 걍 조인해야되나?