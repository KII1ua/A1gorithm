select distinct ID, EMAIL, FIRST_NAME, LAST_NAME from developers join skillcodes as s
	where (s.name = 'Python' or s.name = 'C#') and (s.code & skill_code) != 0 order by ID;