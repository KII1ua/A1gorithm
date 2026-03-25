-- 코드를 입력하세요
select t1.food_type, t1.rest_id, t1.rest_name, t2.cnt from rest_info t1
join (SELECT food_type, max(favorites) as cnt from rest_info
	group by food_type) as t2 on t1.favorites = t2.cnt and t1.food_type = t2.food_type
    order by food_type desc;