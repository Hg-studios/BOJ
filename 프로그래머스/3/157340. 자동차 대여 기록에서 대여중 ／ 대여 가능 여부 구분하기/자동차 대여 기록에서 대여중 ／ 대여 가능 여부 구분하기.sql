# -- 코드를 입력하세요
# SELECT 
#     CAR_ID, 
#     MAX(IF(DATE_FORMAT(START_DATE,'%Y-%m-%d')<='2022-10-16' AND DATE_FORMAT(END_DATE,'%Y-%m-%d')>='2022-10-16', '대여중', '대여 가능')) AS AVAILABILITY
# FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
# GROUP BY CAR_ID
# ORDER BY CAR_ID DESC;





# # select
# #         car_id,
# #         max(if('2022-10-16' between start_date and end_date, '대여중', '대여 가능')) as 'AVAILABILITY'
# # from CAR_RENTAL_COMPANY_RENTAL_HISTORY
# # group by car_id
# # order by 1 desc


# select car_id, if(car_id in (select car_id from CAR_RENTAL_COMPANY_RENTAL_HISTORY
# where (START_DATE<='2022-10-16' AND
# END_DATE>='2022-10-16')
# ), '대여중','대여 가능') AS AVAILABILITY from CAR_RENTAL_COMPANY_RENTAL_HISTORY 
# group by car_id
# order by car_id desc;

SELECT CAR_ID, IF(CAR_ID IN 
                   # 대여중인 자동차들 조회
                   (SELECT CAR_ID
                    FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
                    WHERE START_DATE<='2022-10-16' AND END_DATE>='2022-10-16')
                # 대여중인 자동차들 중에 존재한다면 
                , '대여중', '대여 가능') AS AVAILABILITY
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
GROUP BY CAR_ID
ORDER BY CAR_ID DESC;

# IF(CAR_ID IN
#     (
#         SELECT CAR_ID  
#         FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
#         WHERE START_DATE<='2022-10-16' AND END_DATE>='2022-10-16'
#     ), '대여중', '대여 가능') AS AVAILABILITY


