-- 코드를 입력하세요
-- 1. 자동차 종류가 세단, suv인 자동차 중 2022년 11월 1일 부터 2022년 11월 30일까지 대여 가능하고
-- 2. 30일간의 대여 금액이 50만원 이상, 200만원 미만인 자동차에 대해 대여 금액 리스트를 출력
-- 3. 대여 금액을 기준으로 내림차순 정렬 같은 경우 자동차 종류를 기준으로 오름차순 정렬, 같은 경우 자동차 id를 기준으로 내림차순 정렬
SELECT t1.car_id, t1.car_type, floor(daily_fee * 30 * (100 - discount_rate) / 100) as fee from car_rental_company_car t1
    join car_rental_company_discount_plan t2
    on t1.car_type = t2.car_type and t2.duration_type = '30일 이상'
	where (t1.car_type = '세단' or t1.car_type = 'SUV')
    and car_id not in (select distinct car_id from car_rental_company_rental_history
	where start_date <= '2022-11-30' and end_date >= '2022-11-01')
    having fee >= 500000 and fee < 2000000;