-- 코드를 입력하세요
SELECT p.product_code product_code, sum(p.price*o.sales_amount) sales
from product p join offline_sale o
on p.product_id = o.product_id
group by p.product_id
order by sales desc, p.product_code asc;


# SELECT p.product_id product_code, sales_amount
# from product p join offline_sale o
# on p.product_id = o.product_id
# # group by p.product_id
# where p.PRODUCT_CODE = 16;