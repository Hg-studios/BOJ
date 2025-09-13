-- 5월 생산 날짜를 년월까지만 보고 각 제품별로 총 주문 개수 구하기
with 
MAY as (
    select PRODUCT_ID, sum(AMOUNT) AMOUNT
    from FOOD_ORDER
    where date_format(PRODUCE_DATE, '%Y-%m') = '2022-05'
    group by PRODUCT_ID
)

# select * from may;

-- 이미 5월에 생산된 총 개수를 구해놨으므로, 그냥 그 식품의 가격과 곱하기만 하면 됨
select
    f.PRODUCT_ID PRODUCT_ID,
    f.PRODUCT_NAME PRODUCT_NAME,
    f.PRICE*m.AMOUNT TOTAL_SALES
from FOOD_PRODUCT f 
join MAY m on f.PRODUCT_ID = m.PRODUCT_ID
order by TOTAL_SALES desc, PRODUCT_ID