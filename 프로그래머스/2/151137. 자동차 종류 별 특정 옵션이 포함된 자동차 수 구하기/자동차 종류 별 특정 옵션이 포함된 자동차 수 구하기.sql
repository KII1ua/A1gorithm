-- 코드를 입력하세요

-- 1. OPTIONS 컬럼에서 통풍시트, 열선시트, 가죽시트 중 하나 이상의 옵션이 포함된 자동차가
--    종류별로 몇 대인지

SELECT CAR_TYPE, COUNT(OPTIONS) AS CARS
FROM CAR_RENTAL_COMPANY_CAR
WHERE OPTIONS LIKE '%통풍시트%' or OPTIONS LIKE '%열선시트%' or OPTIONS LIKE '%가죽시트%'
GROUP BY CAR_TYPE
ORDER BY CAR_TYPE;