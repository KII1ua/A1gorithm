-- 코드를 작성해주세요
select YEAR(l.differentiation_date) as YEAR, r.cnt - l.size_of_colony as YEAR_DEV, l.ID as ID from ecoli_data l
join 
(select max(size_of_colony) as cnt, year(differentiation_date) as dt from ecoli_data
	group by year(differentiation_date)) as r on YEAR(l.differentiation_date) = r.dt
    order by YEAR asc, YEAR_DEV asc;