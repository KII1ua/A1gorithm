-- 코드를 작성해주세요
select l.id as ID,
	case when r.cnt is null then 0
    else r.cnt
    end as CHILD_COUNT
from ecoli_data l
	left join (select parent_id, count(parent_id) as cnt from ecoli_data
	where parent_id is not null
	group by parent_id) as r
    on l.id = r.parent_id;