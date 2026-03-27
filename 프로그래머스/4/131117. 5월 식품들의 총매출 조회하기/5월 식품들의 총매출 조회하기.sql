-- 코드를 입력하세요
SELECT t1.product_id, t1.product_name, t1.price * t2.amount as total_sales from food_product t1
join (select product_id, sum(amount) as amount from food_order
	where year(produce_date) = 2022 and month(produce_date) = 5
	group by product_id) as t2 on t1.product_id = t2.product_id
    order by total_sales desc, product_id asc;