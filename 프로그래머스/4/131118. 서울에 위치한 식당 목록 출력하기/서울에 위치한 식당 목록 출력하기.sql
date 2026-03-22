-- 코드를 입력하세요
select l.rest_id, l.rest_name, l.food_type, l.favorites, l.address, rtb.score from rest_info l
	join (SELECT rest_id, ROUND(avg(review_score), 2) as score from rest_review
	group by rest_id) as rtb
    on l.rest_id = rtb.rest_id
    where l.address like '서울%'
    order by rtb.score desc, l.favorites desc;