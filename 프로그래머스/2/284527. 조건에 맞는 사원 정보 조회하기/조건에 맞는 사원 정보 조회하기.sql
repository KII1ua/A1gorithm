-- 코드를 작성해주세요
with tb1 as (
    select emp_no, sum(score) as score from hr_grade
        where year = 2022
        group by emp_no
),

tb2 as (select emp_no, score from tb1
	order by score desc limit 1
)

select tb2.score, tb2.emp_no, emp_name, position, email from hr_employees lt
	join tb2 on lt.emp_no = tb2.emp_no;