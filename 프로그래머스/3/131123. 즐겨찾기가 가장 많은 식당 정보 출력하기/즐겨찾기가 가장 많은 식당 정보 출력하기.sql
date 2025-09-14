# select REST_ID, rank() over (order by VIEWS desc) rank
# from REST_INFO
# group by FOOD_TYPE

select FOOD_TYPE,
        REST_ID, 
        REST_NAME,
        FAVORITES
from (
    SELECT 
        FOOD_TYPE,
        REST_ID, 
        REST_NAME,
        FAVORITES,
        RANK() OVER (partition by FOOD_TYPE ORDER BY FAVORITES DESC) AS rnk
    FROM REST_INFO
) t
where t.rnk=1
order by FOOD_TYPE desc

# ====

# SELECT *
# FROM (
#   SELECT
#     FOOD_TYPE,
#     REST_ID,
#     VIEWS,
#     RANK() OVER (PARTITION BY FOOD_TYPE ORDER BY VIEWS DESC) AS rnk
#   FROM REST_INFO
# ) t
# WHERE t.rnk = 1;


# with top_rank as (
#     select FOOD_TYPE, max(FAVORITES) FAV
#     from REST_INFO
#     group by FOOD_TYPE
# )



# select 
# r.FOOD_TYPE
# # r.REST_ID, r.REST_NAME, r.FAVORITES
# from REST_INFO r
# join top_rank t on r.FOOD_TYPE = t.FOOD_TYPE
# group by r.FOOD_TYPE
# having r.FAVORITES = t.FAV
# order by r.FOOD_TYPE desc 