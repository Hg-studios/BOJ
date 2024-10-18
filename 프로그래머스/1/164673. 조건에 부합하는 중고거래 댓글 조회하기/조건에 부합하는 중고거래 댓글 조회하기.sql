-- 코드를 입력하세요
SELECT TITLE, B.BOARD_ID, REPLY_ID, R.WRITER_ID, R.CONTENTS, DATE_FORMAT(R.CREATED_DATE, '%Y-%m-%d')
FROM USED_GOODS_BOARD B
    JOIN USED_GOODS_REPLY R
    ON B.BOARD_ID = R.BOARD_ID
WHERE DATE_FORMAT(B.CREATED_DATE, '%Y %m') = '2022 10'
ORDER BY R.CREATED_DATE, B.TITLE;

# SELECT *
# FROM USED_GOODS_BOARD
# WHERE DATE_FORMAT(CREATED_DATE, '%Y %m') = '2022 10';