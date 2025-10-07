#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Student {
    int rollNo;
    char name[50];
    struct Student* next;
} Student;


typedef struct Course {
    char courseName[50];
    Student* head; 
    struct Course* nextCourse; 
} Course;


Student* createStudent(int rollNo, char name[]) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    newStudent->rollNo = rollNo;
    strcpy(newStudent->name, name);
    newStudent->next = NULL;
    return newStudent;
}


Course* createCourse(char courseName[]) {
    Course* newCourse = (Course*)malloc(sizeof(Course));
    strcpy(newCourse->courseName, courseName);
    newCourse->head = NULL;
    newCourse->nextCourse = NULL;
    return newCourse;
}


Course* findCourse(Course* head, char courseName[]) {
    while (head != NULL) {
        if (strcmp(head->courseName, courseName) == 0)
            return head;
        head = head->nextCourse;
    }
    return NULL;
}


Course* addCourse(Course* head, char courseName[]) {
    if (findCourse(head, courseName) != NULL) {
        printf("Course %s already exists.\n", courseName);
        return head;
    }
    Course* newCourse = createCourse(courseName);
    newCourse->nextCourse = head;
    head = newCourse;
    printf("Course %s added.\n", courseName);
    return head;
}


void addStudent(Course* course, int rollNo, char name[]) {
    if (course == NULL) return;
    Student* newStudent = createStudent(rollNo, name);
    newStudent->next = course->head;
    course->head = newStudent;
    printf("Student %s (Roll %d) added to %s.\n", name, rollNo, course->courseName);
}


void dropStudent(Course* course, int rollNo) {
    if (course == NULL) return;
    Student* temp = course->head;
    Student* prev = NULL;

    while (temp != NULL && temp->rollNo != rollNo) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student with Roll %d not found in %s.\n", rollNo, course->courseName);
        return;
    }

    if (prev == NULL) {
        course->head = temp->next;
    } else {
        prev->next = temp->next;
    }

    printf("Student with Roll %d dropped from %s.\n", rollNo, course->courseName);
    free(temp);
}


void searchStudent(Course* course, int rollNo) {
    if (course == NULL) return;
    Student* temp = course->head;
    while (temp != NULL) {
        if (temp->rollNo == rollNo) {
            printf("Found: %s (Roll %d) in %s.\n", temp->name, rollNo, course->courseName);
            return;
        }
        temp = temp->next;
    }
    printf("Student with Roll %d not found in %s.\n", rollNo, course->courseName);
}


void displayStudents(Course* course) {
    if (course == NULL) return;
    Student* temp = course->head;
    if (temp == NULL) {
        printf("No students enrolled in %s.\n", course->courseName);
        return;
    }
    printf("Students in %s:\n", course->courseName);
    while (temp != NULL) {
        printf("Roll: %d, Name: %s\n", temp->rollNo, temp->name);
        temp = temp->next;
    }
}


void reverseList(Course* course) {
    if (course == NULL) return;
    Student* prev = NULL;
    Student* curr = course->head;
    Student* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    course->head = prev;
    printf("Student list reversed for %s.\n", course->courseName);
}


Student* cloneList(Student* head) {
    if (head == NULL) return NULL;

    Student* newHead = createStudent(head->rollNo, head->name);
    Student* temp1 = head->next;
    Student* temp2 = newHead;

    while (temp1 != NULL) {
        temp2->next = createStudent(temp1->rollNo, temp1->name);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return newHead;
}


int countStudents(Course* course) {
    if (course == NULL) return 0;
    int count = 0;
    Student* temp = course->head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}


int main() {
    Course* courseList = NULL;
    int choice, roll;
    char name[50], courseName[50];

    while (1) {
        printf("\n--- Course Enrollment System ---\n");
        printf("1. Add Course\n");
        printf("2. Add Student\n");
        printf("3. Drop Student\n");
        printf("4. Search Student\n");
        printf("5. Display Students\n");
        printf("6. Reverse Student List\n");
        printf("7. Clone Student List\n");
        printf("8. Count Students\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter course name: ");
                scanf(" %[^\n]", courseName);
                courseList = addCourse(courseList, courseName);
                break;

            case 2:
                printf("Enter course name: ");
                scanf(" %[^\n]", courseName);
                {
                    Course* c = findCourse(courseList, courseName);
                    if (c == NULL) { printf("Course not found.\n"); break; }
                    printf("Enter roll no: "); scanf("%d", &roll);
                    printf("Enter name: "); scanf(" %[^\n]", name);
                    addStudent(c, roll, name);
                }
                break;

            case 3:
                printf("Enter course name: ");
                scanf(" %[^\n]", courseName);
                {
                    Course* c = findCourse(courseList, courseName);
                    if (c == NULL) { printf("Course not found.\n"); break; }
                    printf("Enter roll no: "); scanf("%d", &roll);
                    dropStudent(c, roll);
                }
                break;

            case 4:
                printf("Enter course name: ");
                scanf(" %[^\n]", courseName);
                {
                    Course* c = findCourse(courseList, courseName);
                    if (c == NULL) { printf("Course not found.\n"); break; }
                    printf("Enter roll no: "); scanf("%d", &roll);
                    searchStudent(c, roll);
                }
                break;

            case 5:
                printf("Enter course name: ");
                scanf(" %[^\n]", courseName);
                {
                    Course* c = findCourse(courseList, courseName);
                    if (c == NULL) { printf("Course not found.\n"); break; }
                    displayStudents(c);
                }
                break;

            case 6:
                printf("Enter course name: ");
                scanf(" %[^\n]", courseName);
                {
                    Course* c = findCourse(courseList, courseName);
                    if (c == NULL) { printf("Course not found.\n"); break; }
                    reverseList(c);
                }
                break;

            case 7:
                printf("Enter course name: ");
                scanf(" %[^\n]", courseName);
                {
                    Course* c = findCourse(courseList, courseName);
                    if (c == NULL) { printf("Course not found.\n"); break; }
                    Course* backup = createCourse("Backup");
                    backup->head = cloneList(c->head);
                    printf("Backup of %s created.\n", c->courseName);
                    displayStudents(backup);
                }
                break;

            case 8:
                printf("Enter course name: ");
                scanf(" %[^\n]", courseName);
                {
                    Course* c = findCourse(courseList, courseName);
                    if (c == NULL) { printf("Course not found.\n"); break; }
                    printf("Total students in %s: %d\n", c->courseName, countStudents(c));
                }
                break;

            case 9:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}