-- 5월 생산 날짜를 년월까지만으로 바꾸기
with 
may as (
    select ORDER_ID, PRODUCT_ID, AMOUNT, date_format(PRODUCE_DATE, '%Y-%m') pd
    from FOOD_ORDER f
),
-- 5월달 제품별로 총 개수 구하기
mayTotal as (
    select PRODUCT_ID, sum(AMOUNT) AMOUNT
    from may
    where pd= '2022-05'
    group by PRODUCT_ID
)

select
o.PRODUCT_ID PRODUCT_ID, p.PRODUCT_NAME PRODUCT_NAME, p.PRICE*o.AMOUNT TOTAL_SALES
from mayTotal o
join FOOD_PRODUCT p on o.PRODUCT_ID = p.PRODUCT_ID
order by TOTAL_SALES desc, PRODUCT_ID
# select * 
# from mayTotal o
# join FOOD_PRODUCT p on o.PRODUCT_ID = p.PRODUCT_ID;

# select * from FOOD_PRODUCT;
# select * from FOOD_ORDER
# select * from FOOD_ORDER;

# select 
# # * 
# o.PRODUCT_ID
# # p.PRODUCT_NAME
# , sum(p.PRICE * o.AMOUNT)
# from FOOD_PRODUCT p
# join FOOD_ORDER o on p.PRODUCT_ID = o.PRODUCT_ID
# where date_format(o.PRODUCE_DATE, '%Y-%m') = '2022-05'
# group by o.PRODUCT_ID, o.PRODUCE_DATE
# having date_format(o.PRODUCE_DATE, '%Y-%m') = '2022-05';