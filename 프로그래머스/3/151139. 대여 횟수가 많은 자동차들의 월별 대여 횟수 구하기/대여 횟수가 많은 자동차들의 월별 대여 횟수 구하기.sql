select month(START_DATE) MONTH, CAR_ID, count(*) RECORDS
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
where CAR_ID in (
    -- 2022년 8월부터 2022년 10월까지 총 대여 횟수가 5회 이상인 자동차 뽑기
    select CAR_ID
    from CAR_RENTAL_COMPANY_RENTAL_HISTORY
    where date_format(START_DATE, '%Y-%m') >= '2022-08'
    and date_format(START_DATE, '%Y-%m') <= '2022-10'
    group by CAR_ID
    having count(*)>=5
)
-- 위에서 적용한 날짜 조건은 해당 자동차를 찾기 위함이었고, 해당 sql은 car_id만 반환하게 됨
-- 따라서 이 car_id에 해당하는 자동차라고 하더라도 8월~10월 사이가 아닐 수 있으므로
-- 다시 한 번 날짜에 대한 조건을 넣어서 걸러줘야 함
and date_format(START_DATE, '%Y-%m') >= '2022-08'
and date_format(START_DATE, '%Y-%m') <= '2022-10'
group by month(START_DATE), CAR_ID
order by MONTH, CAR_ID desc