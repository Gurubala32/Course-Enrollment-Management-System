# Course-Enrollment-Management-System

Description:
This C program manages student enrollment in multiple courses using linked lists. Each course has its own list of students, and the system allows adding/dropping students, searching, displaying, reversing, cloning, and counting students in a course. Each student record contains Roll Number and Name, and each course has a Course Name.

Features:
1. Add Course – Create a new course.
2. Add Student – Add a student to a specific course.
3. Drop Student – Remove a student from a course.
4. Search Student – Find a student in a course by roll number.
5. Display Students – Show all students enrolled in a course.
6. Reverse Student List – Reverse the student list in a course.
7. Clone Student List – Create a backup of a course's student list.
8. Count Students – Count the number of students in a course.
9. Exit – Close the program.

How it Works:
- Uses a struct Student with fields: Roll Number, Name, and pointer to the next student.
- Uses a struct Course with fields: Course Name, head of student list, and pointer to next course.
- Linked lists dynamically store courses and students.
- Provides a menu-driven interface for easy operation.
- Supports cloning and reversing of student lists within a course.

Compilation and Execution:
gcc studentsrecord_course.c -o studentsrecord_course
./studentsrecord_course

Sample Input/Output:
Enter choice: 1
Enter course name: Data Structures
Course Data Structures added.

Enter choice: 2
Enter course name: Data Structures
Enter roll no: 101
Enter name: Alice
Student Alice (Roll 101) added to Data Structures.

Enter choice: 5
Enter course name: Data Structures
Students in Data Structures:
Roll: 101, Name: Alice
