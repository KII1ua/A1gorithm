-- 코드를 입력하세요
SELECT title, ur.board_id, ur.reply_id, ur.writer_id, ur.contents, DATE_FORMAT(ur.created_date, "%Y-%m-%d") as CREATED_DATE from used_goods_board as ub
	join used_goods_reply as ur on ub.board_id = ur.board_id
    where YEAR(ub.created_date) = 2022 and MONTH(ub.created_date) = 10
    order by ur.created_date, ub.title;