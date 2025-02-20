-- 코드를 입력하세요

-- 1. 상품코드 별 매출액(판매가 * 판매량) 합계를 출력
-- 2. 매출액을 기준으로 내림차순 정렬 같다면 상품코드를 기준으로 오름차순 정렬

SELECT a.PRODUCT_CODE, SUM(b.SALES_AMOUNT * a.PRICE) AS SALES
FROM PRODUCT a
JOIN OFFLINE_SALE b
ON a.PRODUCT_ID = b.PRODUCT_ID
GROUP BY a.PRODUCT_ID
ORDER BY SALES DESC, a.PRODUCT_CODE