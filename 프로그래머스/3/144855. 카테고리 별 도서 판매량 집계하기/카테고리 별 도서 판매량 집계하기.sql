select category, sum(sales) TOTAL_SALES
from BOOK b join BOOK_SALES s 
on b.BOOK_ID = s.BOOK_ID
where date_format(s.SALES_DATE, '%Y-%m') = '2022-01'
group by category
order by category