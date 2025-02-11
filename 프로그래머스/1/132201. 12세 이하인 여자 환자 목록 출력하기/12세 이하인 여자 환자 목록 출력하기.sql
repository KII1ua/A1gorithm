-- 코드를 입력하세요

-- 1. 12세 이하인 여자 환자 (PT_NAME, PT_NO, GEND_CD, AGE, TLNO)
-- 2. 전화번호가 null일 경우 'NONE' 으로 출력
-- 3. 나이를 기준으로 내림차순 정렬, 나이가 같다면ㅇ 환자 이름을 기준으로 오름차순 정렬

SELECT PT_NAME, PT_NO, GEND_CD, AGE, IFNULL(TLNO, 'NONE') AS TLNO FROM PATIENT where GEND_CD = 'W' and AGE <= 12 ORDER BY AGE DESC, PT_NAME ASC;