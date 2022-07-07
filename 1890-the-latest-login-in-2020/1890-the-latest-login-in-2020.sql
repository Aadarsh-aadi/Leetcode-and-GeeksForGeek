SELECT
    user_id, 
    max(time_stamp) as last_stamp 
FROM 
    Logins 
WHERE 
    time_stamp BETWEEN '2020-01-01' AND '2020-12-31 23:59:59'
GROUP BY
    user_id