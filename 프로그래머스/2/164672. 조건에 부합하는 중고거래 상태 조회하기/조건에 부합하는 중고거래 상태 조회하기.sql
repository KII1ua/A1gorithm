-- 코드를 입력하세요

-- 1. 2022년 10월 5일에 등록된 중고거래 게시물의 게시글 ID, 작성자 ID, 게시글 제목, 가격, 거래 상태를 조회하는 SQL 작성
-- 2. 거래상태가 SALE이면 판매중, RESERVED면 예약중, DONE이면 거래완료 출력
-- 3. 결과는 게시글 ID를 기준으로 내림차순 정렬

SELECT BOARD_ID, WRITER_ID, TITLE, PRICE,
CASE
	WHEN (`STATUS` = 'SALE') THEN '판매중'
    WHEN (`STATUS` = 'RESERVED') THEN '예약중'
    ELSE '거래완료'
END
AS STATUS
FROM USED_GOODS_BOARD
WHERE YEAR(CREATED_DATE) = '2022' AND MONTH(CREATED_DATE) = '10' AND DAY(CREATED_DATE) = '5'
ORDER BY BOARD_ID DESC;