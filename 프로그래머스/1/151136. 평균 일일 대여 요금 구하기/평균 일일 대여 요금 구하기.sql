-- 코드를 입력하세요
SELECT ROUND(SUM(DAILY_FEE)/COUNT(CAR_ID),0) AS AVERAGE_FEE
FROM CAR_RENTAL_COMPANY_CAR
WHERE CAR_TYPE = "SUV"

# SELECT * FROM CAR_RENTAL_COMPANY_CAR WHERE CAR_TYPE = "SUV";