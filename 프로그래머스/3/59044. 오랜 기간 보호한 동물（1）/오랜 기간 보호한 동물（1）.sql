-- 코드를 입력하세요

select t1.name, t1.datetime from animal_ins t1
	where animal_id not in (select t1.animal_id from animal_ins t1
	join animal_outs t2 on t1.animal_id = t2.animal_id)
    order by datetime asc limit 3;