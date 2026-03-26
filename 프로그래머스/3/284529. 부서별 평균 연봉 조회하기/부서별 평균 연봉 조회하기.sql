-- 코드를 작성해주세요
with tb2 as (select dept_id, round(avg(sal),0) as avg_sal from hr_employees
	group by dept_id)

select tb1.dept_id, tb1.dept_name_en, tb2.avg_sal as avg_sal from hr_department tb1
	join tb2 on tb1.dept_id = tb2.dept_id
    order by avg_sal desc;