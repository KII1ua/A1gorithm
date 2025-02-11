-- 코드를 입력하세요

-- 1. 상반기 아이스크림 총주문량이 3000보다 높으면서 아이스크림의 주 성분이 과일인 아이스크림의 맛을
-- 2. 총주문량이 큰 순서대로 출력

select a.FLAVOR from FIRST_HALF a join ICECREAM_INFO b on a.flavor = b.flavor
where a.TOTAL_ORDER > 3000 and b.INGREDIENT_TYPE = 'fruit_based'
order by a.TOTAL_ORDER DESC;