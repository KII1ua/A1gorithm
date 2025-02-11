-- 코드를 입력하세요
-- 1. 생일이 3월인 여성 회원의 ID, 이름, 성별, 생년월일
-- 2. 전화번호가 NULL일 경우 출력 대상에서 제외
-- 3. 회원 ID를 기준으로 오름차순 정렬

-- 1. select member_id,  member_name, gender, date_of_birth from member_profile where month(date_of_birth) = '3';

-- 2. select member_id, member_name, gender, date_of_birth from member_profile where TLNO is not null;

-- 3. select * from member_profile order by member_id;

SELECT MEMBER_ID, MEMBER_NAME, GENDER, DATE_FORMAT(DATE_OF_BIRTH, '%Y-%m-%d') as DATE_OF_BIRTH FROM MEMBER_PROFILE WHERE MONTH(DATE_OF_BIRTH) = '3' AND GENDER = 'W' AND TLNO IS NOT NULL ORDER BY MEMBER_ID;