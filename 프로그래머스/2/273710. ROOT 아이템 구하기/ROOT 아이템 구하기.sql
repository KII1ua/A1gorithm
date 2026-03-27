-- 코드를 작성해주세요
select t1.item_id, t2.item_name from item_tree t1
    join item_info t2 on t1.item_id = t2.item_id
    where parent_item_id is null
    order by t1.item_id asc;