-- 코드를 입력하세요

-- 1. 입양을 못 간 동물 중, 가장 오래 보호소에 있었던 동물 3마리의 이름과 보호 시작일 조회
-- 2. 보호 시작일 기준으로 조회

SELECT a.NAME, a.DATETIME
FROM ANIMAL_INS a
LEFT OUTER JOIN ANIMAL_OUTS b
ON a.ANIMAL_ID = b.ANIMAL_ID
WHERE b.ANIMAL_ID IS NULL
ORDER BY a.DATETIME
LIMIT 3;