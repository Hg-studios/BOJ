-- 코드를 입력하세요
SELECT 
    CAR_ID, 
    MAX(IF(DATE_FORMAT(START_DATE,'%Y-%m-%d')<='2022-10-16' AND DATE_FORMAT(END_DATE,'%Y-%m-%d')>='2022-10-16', '대여중', '대여 가능')) AS AVAILABILITY
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
GROUP BY CAR_ID
ORDER BY CAR_ID DESC;





# select
#         car_id,
#         max(if('2022-10-16' between start_date and end_date, '대여중', '대여 가능')) as 'AVAILABILITY'
# from CAR_RENTAL_COMPANY_RENTAL_HISTORY
# group by car_id
# order by 1 desc