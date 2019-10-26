SELECT
    table_schema AS 'DB Name',
    ROUND(SUM(data_length + index_length) / 1024 / 1024, 1) AS 'DB Size in MB'
FROM
    information_schema.tables
GROUP BY
    table_schema;