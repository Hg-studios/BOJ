select u.USER_ID, NICKNAME, sum(b.price) TOTAL_SALES
from USED_GOODS_BOARD b join USED_GOODS_USER u
on b.WRITER_ID = u.USER_ID
where b.STATUS = 'DONE'
group by u.USER_ID
having sum(b.price) >= 700000
order by TOTAL_SALES