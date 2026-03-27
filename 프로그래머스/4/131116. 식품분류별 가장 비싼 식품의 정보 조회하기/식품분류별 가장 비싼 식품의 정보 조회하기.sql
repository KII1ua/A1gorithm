-- 코드를 입력하세요

select t1.category, t1.price as max_price, t1.product_name from food_product t1
	join (SELECT product_id, category, max(price) as max_price from food_product
	where category in ('과자', '국', '김치', '식용유')
	group by category) as t2 on t1.price = t2.max_price and t1.category = t2.category
    order by max_price desc;
