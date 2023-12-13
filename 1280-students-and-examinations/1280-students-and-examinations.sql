# Write your MySQL query statement below
SELECT s.student_id, s.student_name, Sub.subject_name, COUNT(e.subject_name) AS attended_exams
FROM
    Students s
CROSS JOIN 
    Subjects Sub
LEFT JOIN 
    Examinations e
ON
    s.student_id = e.student_id AND Sub.subject_name = e.subject_name
GROUP BY
    s.student_id, s.student_name, Sub.subject_name
ORDER BY
    s.student_id, Sub.subject_name;