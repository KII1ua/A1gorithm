-- 코드를 입력하세요

-- 1. 2022년 5월 1일을 기준으로 주문 ID, 제품 ID, 출고일자, 출고여부를 조회
-- 2. 출고여부는 2022년 5월 1일까지 출고완료로 이후 날짜는 출고 대기로 미정이면 출고미정
-- 3. 주문 ID를 기준으로 오름차순 정렬

SELECT ORDER_ID, PRODUCT_ID, DATE_FORMAT(OUT_DATE, '%Y-%m-%d') AS OUT_DATE,
CASE
	WHEN OUT_DATE IS NULL THEN '출고미정'
    WHEN OUT_DATE > '2022-05-01' THEN '출고대기'
    ELSE '출고완료'
END AS 출고여부
FROM FOOD_ORDER
ORDER BY ORDER_ID;