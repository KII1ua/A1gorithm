-- 코드를 작성해주세요

select item_id, item_name, rarity from item_info
	where item_id not in (
select t1.item_id from item_tree t1
	join item_tree t2 on t1.item_id = t2.parent_item_id
    group by t1.item_id
)
order by item_id desc;