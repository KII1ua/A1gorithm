-- 코드를 입력하세요
SELECT l.title, l.board_id, r.reply_id, r.writer_id, r.contents, DATE_FORMAT(r.created_date, '%Y-%m-%d') as CREATED_DATE
	from used_goods_board l join used_goods_reply r on l.board_id = r.board_id
    where YEAR(l.created_date) = 2022 and MONTH(l.created_date) = 10
    order by r.created_date, l.title ;