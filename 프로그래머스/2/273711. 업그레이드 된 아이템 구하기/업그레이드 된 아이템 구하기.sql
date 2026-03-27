-- 코드를 작성해주세요

select distinct t1.item_id, t1.item_name, t1.rarity from item_info t1
	join item_tree t2 on t1.item_id = t2.item_id
    join (select distinct t1.item_id, t1.rarity, t1.item_name from item_info t1
	join item_tree t2 on t1.item_id = t2.parent_item_id
    where t1.rarity = 'RARE'
         ) as t3
    on t2.parent_item_id = t3.item_id
    order by item_id desc;