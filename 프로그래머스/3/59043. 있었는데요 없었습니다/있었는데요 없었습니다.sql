-- 코드를 입력하세요

-- 1. 보호 시작일보다 입양일이 더 빠른 동물의 아이디와 이름을 조회

SELECT a.ANIMAL_ID, a.name
FROM ANIMAL_INS a
JOIN ANIMAL_OUTS b
ON a.ANIMAL_ID = b.ANIMAL_ID
WHERE b.DATETIME < a.DATETIME
ORDER BY a.DATETIME;