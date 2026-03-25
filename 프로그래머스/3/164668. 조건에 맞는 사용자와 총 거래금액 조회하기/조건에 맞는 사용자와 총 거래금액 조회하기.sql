-- 코드를 입력하세요
SELECT rt.user_id, rt.nickname, sum(lt.price) as total_sales from used_goods_board lt
	join used_goods_user rt on lt.writer_id = rt.user_id
    where lt.status = 'DONE'
    group by rt.user_id
    having total_sales >= 700000
    order by total_sales;