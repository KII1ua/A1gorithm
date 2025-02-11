-- 코드를 입력하세요

-- 1. 강원도에 위치한 식품공장의 공장 ID, 공장 이름, 주소를 조회
-- 2. 공장 ID를 기준으로 오름차순으로 정렬

SELECT FACTORY_ID, FACTORY_NAME, ADDRESS FROM FOOD_FACTORY where address LIKE '강원도%' order by FACTORY_ID;