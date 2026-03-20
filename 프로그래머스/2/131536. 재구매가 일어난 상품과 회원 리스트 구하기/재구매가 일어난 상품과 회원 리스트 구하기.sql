-- 코드를 입력하세요

-- 1. 동일한 회원이 동일한 상품을 재구매한 데이터를 구하영 재구매한 회원 ID와 재구매한 상품 ID를 출력
-- 2. 회원 ID를 기준으로 오름차순 정렬, 같다면 상품 ID를 기준으로 내림차순 정렬

select user_id, product_id from online_sale group by user_id, product_id
	having count(*) >= 2 order by user_id asc, product_id desc;