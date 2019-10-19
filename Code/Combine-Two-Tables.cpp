# Write your MySQL query statement below
select Person.FirstName, Person.LastName, Address.City, Address.State from Person left join Address on Person.PersonId=Address.PersonId



# select * from student left join course on student.ID=course.ID