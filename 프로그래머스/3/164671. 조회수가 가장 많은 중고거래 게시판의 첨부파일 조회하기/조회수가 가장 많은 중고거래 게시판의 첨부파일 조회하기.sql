-- 코드를 입력하세요
select concat('/home/grep/src/', t1.board_id, '/', t1.file_id, t1.file_name, t1.file_ext) as file_path from used_goods_file t1
	join (select board_id from used_goods_board
	order by views desc limit 1) as t2
    on t1.board_id = t2.board_id
    order by t1.file_id desc;