-- 코드를 입력하세요
SELECT  o.animal_id,
        o.name
FROM    animal_outs AS o
LEFT OUTER JOIN animal_ins AS i ON(o.animal_id = i.animal_id)
WHERE   i.animal_id IS NULL
ORDER BY 1