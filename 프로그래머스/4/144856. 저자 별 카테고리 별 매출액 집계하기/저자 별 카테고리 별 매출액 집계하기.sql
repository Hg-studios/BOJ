select a.AUTHOR_ID, a.AUTHOR_NAME, b.CATEGORY, sum(SALES*PRICE) TOTAL_SALES
from book b
join author a on b.AUTHOR_ID = a.AUTHOR_ID
join BOOK_SALES s on b.BOOK_ID = s.BOOK_ID
where date_format(SALES_DATE, '%Y-%m') = '2022-01'
group by a.AUTHOR_ID, b.CATEGORY
order by AUTHOR_ID, CATEGORY desc