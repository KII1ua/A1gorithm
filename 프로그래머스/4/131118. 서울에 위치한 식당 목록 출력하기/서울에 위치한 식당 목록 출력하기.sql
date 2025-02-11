-- 코드를 입력하세요

-- 1. 서울에 위치한 식당들의 식당 ID, 식당 이름, 음식 종류, 즐겨찾기 수, 주소, 리뷰 평균 점수를 조회
-- 2. 리뷰 평균점수는 소수점 세번째 자리에서 반올림 후 결과는 평균 점수를 기준으로 내림차순 정렬
-- 3. 만약 평균점수가 같다면 즐겨찾기 수를 기준으로 내림차순 정렬


-- 1. SELECT a.REST_ID, b.REST_NAME, b.FOOD_TYPE, b.FAVORITES, b.ADDRESS from REST_REVIEW a join REST_INFO b on a.REST_ID = b.REST_ID;

SELECT a.REST_ID, b.REST_NAME, b.FOOD_TYPE, b.FAVORITES, b.ADDRESS, ROUND(AVG(a.REVIEW_SCORE), 2) as SCORE from REST_REVIEW a join REST_INFO b on a.REST_ID = b.REST_ID group by a.REST_ID HAVING b.ADDRESS LIKE "서울%" ORDER BY SCORE DESC, B.FAVORITES DESC;