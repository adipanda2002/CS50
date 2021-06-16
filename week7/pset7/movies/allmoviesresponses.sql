--1
SELECT title FROM movies WHERE year = 2008;

--2
SELECT birth FROM people WHERE name = "Emma Stone";

--3
SELECT title FROM movies WHERE year >= 2018 ORDER BY title;

--4
SELECT COUNT(movie_id) FROM ratings WHERE rating = 10.0;

--5
SELECT title, year FROM movies WHERE title LIKE "Harry Potter%" ORDER BY year;

--6
SELECT AVG(rating)
FROM ratings JOIN movies ON movies.id = ratings.movie_id
WHERE year = 2012;

--7
SELECT title, rating
FROM movies JOIN ratings ON movies.id = ratings.movie_id
WHERE year = 2010
ORDER BY rating DESC, title;

--8
SELECT name
FROM people JOIN stars ON people.id = stars.person_id
JOIN movies ON movies.id = stars.movie_id
WHERE title = "Toy Story";

--9
SELECT DISTINCT name
FROM people JOIN stars ON people.id = stars.person_id
JOIN movies ON movies.id = stars.movie_id
WHERE year = 2004
ORDER BY birth;

--10
SELECT name FROM people
JOIN directors ON directors.person_id = people.id
JOIN ratings ON directors.movie_id = ratings.movie_id
WHERE rating >= 9.0;

--11
SELECT DISTINCT title
FROM people JOIN stars ON people.id = stars.person_id
JOIN ratings ON ratings.movie_id = stars.movie_id
JOIN movies ON movies.id = stars.movie_id
WHERE name = "Chadwick Boseman"
ORDER BY rating DESC LIMIT 5;

--12
SELECT title FROM people
JOIN stars ON stars.person_id = people.id
JOIN movies ON stars.movie_id = movies.id
WHERE name = "Johnny Depp"
AND movie_id IN (
    SELECT movie_id
    FROM people JOIN stars ON stars.person_id = people.id
    WHERE name = "Helena Bonham Carter"
);

--13
SELECT DISTINCT name
FROM people JOIN stars ON stars.person_id = people.id
WHERE name != "Kevin Bacon"
AND movie_id IN(
    SELECT movie_id
    FROM people JOIN stars ON stars.person_id = people.id
    WHERE name = "Kevin Bacon" AND birth = 1958
);
