#include <stdio.h>
#include <string.h>

#define MAX_COURSES 5
#define MAX_STUDENTS 100

typedef struct Course
{
    char name[50];
    char code[10];
    char instructor[50];
    int student_count;
} Course;

typedef struct Student
{
    char name[50];
    int roll_number;
    Course courses[MAX_COURSES];
    int course_count;
} Student;

void enroll_student(const char *filename);
void display_courses(const char *filename, int roll_number);
void generate_report(const char *filename);
void modify_enrollment(const char *filename, int roll_number);

void store_data(const char *filename, Student students[], int *student_count);
void load_data(const char *filename, Student students[], int *student_count);

int main()
{
    const char *filename = "student_course_data.dat";
    Student students[MAX_STUDENTS];
    int student_count = 0;
    load_data(filename, students, &student_count);

    int choice;
    do
    {
        printf("\nStudent Course Enrollment System\n");
        printf("1. Enroll Student\n");
        printf("2. Display Courses of a Student\n");
        printf("3. Generate Report on Course Enrollments\n");
        printf("4. Modify Student Enrollment\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enroll_student(filename);
            break;
        case 2:
            {
                int roll_number;
                printf("Enter student roll number: ");
                scanf("%d", &roll_number);
                display_courses(filename, roll_number);
                break;
            }
        case 3:
            generate_report(filename);
            break;
        case 4:
            {
                int roll_number;
                printf("Enter student roll number: ");
                scanf("%d", &roll_number);
                modify_enrollment(filename, roll_number);
                break;
            }
        case 5:
            printf("Exiting the system.\n");
            break;
        default:
            printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void enroll_student(const char *filename)
{
    FILE *file = fopen(filename, "ab");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    Student student;
    printf("Enter student name: ");
    scanf(" %[^\n]", student.name);
    printf("Enter roll number: ");
    scanf("%d", &student.roll_number);
    student.course_count = 0;

    int num_courses;
    printf("Enter number of courses to enroll in: ");
    scanf("%d", &num_courses);

    for (int i = 0; i < num_courses; i++)
    {
        Course course;
        printf("Enter course name: ");
        scanf(" %[^\n]", course.name);
        printf("Enter course code: ");
        scanf(" %[^\n]", course.code);
        printf("Enter course instructor: ");
        scanf(" %[^\n]", course.instructor);
        course.student_count = 1; // Initial student enrollment
        student.courses[student.course_count++] = course;
    }

    fwrite(&student, sizeof(Student), 1, file);
    fclose(file);
}

void display_courses(const char *filename, int roll_number)
{
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    Student student;
    int found = 0;
    while (fread(&student, sizeof(Student), 1, file))
    {
        if (student.roll_number == roll_number)
        {
            found = 1;
            printf("Courses enrolled by student %s (Roll No: %d):\n", student.name, student.roll_number);
            for (int i = 0; i < student.course_count; i++)
            {
                printf("Course Name: %s, Code: %s, Instructor: %s\n",
                       student.courses[i].name, student.courses[i].code, student.courses[i].instructor);
            }
            break;
        }
    }

    if (!found)
    {
        printf("Student not found.\n");
    }

    fclose(file);
}

void generate_report(const char *filename)
{
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    Course courses[MAX_COURSES];
    int course_count = 0;

    Student student;
    while (fread(&student, sizeof(Student), 1, file))
    {
        for (int i = 0; i < student.course_count; i++)
        {
            int found = 0;
            for (int j = 0; j < course_count; j++)
            {
                if (strcmp(courses[j].code, student.courses[i].code) == 0)
                {
                    courses[j].student_count++;
                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                courses[course_count] = student.courses[i];
                courses[course_count].student_count = 1;
                course_count++;
            }
        }
    }

    printf("\nCourse Enrollment Report:\n");
    for (int i = 0; i < course_count; i++)
    {
        printf("Course: %s, Code: %s, Instructor: %s, Enrolled Students: %d\n",
               courses[i].name, courses[i].code, courses[i].instructor, courses[i].student_count);
    }

    fclose(file);
}

void modify_enrollment(const char *filename, int roll_number)
{
    FILE *file = fopen(filename, "r+b");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    Student student;
    int found = 0;
    while (fread(&student, sizeof(Student), 1, file))
    {
        if (student.roll_number == roll_number)
        {
            found = 1;
            int course_choice;
            printf("Modify courses for student %s (Roll No: %d):\n", student.name, student.roll_number);
            printf("1. Add course\n2. Remove course\nEnter your choice: ");
            scanf("%d", &course_choice);

            if (course_choice == 1)
            {
                if (student.course_count < MAX_COURSES)
                {
                    Course course;
                    printf("Enter course name: ");
                    scanf(" %[^\n]", course.name);
                    printf("Enter course code: ");
                    scanf(" %[^\n]", course.code);
                    printf("Enter course instructor: ");
                    scanf(" %[^\n]", course.instructor);
                    course.student_count = 1; // Initial enrollment
                    student.courses[student.course_count++] = course;
                    fseek(file, -sizeof(Student), SEEK_CUR);
                    fwrite(&student, sizeof(Student), 1, file);
                    printf("Course added successfully.\n");
                }
                else
                {
                    printf("Cannot add more courses, maximum limit reached.\n");
                }
            }
            else if (course_choice == 2)
            {
                printf("Enter the course code to remove: ");
                char course_code[10];
                scanf(" %[^\n]", course_code);

                int removed = 0;
                for (int i = 0; i < student.course_count; i++)
                {
                    if (strcmp(student.courses[i].code, course_code) == 0)
                    {
                        removed = 1;
                        for (int j = i; j < student.course_count - 1; j++)
                        {
                            student.courses[j] = student.courses[j + 1];
                        }
                        student.course_count--;
                        fseek(file, -sizeof(Student), SEEK_CUR);
                        fwrite(&student, sizeof(Student), 1, file);
                        printf("Course removed successfully.\n");
                        break;
                    }
                }
                if (!removed)
                {
                    printf("Course not found.\n");
                }
            }
            break;
        }
    }

    if (!found)
    {
        printf("Student not found.\n");
    }

    fclose(file);
}

void store_data(const char *filename, Student students[], int *student_count)
{
    FILE *file = fopen(filename, "wb");
    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }
    fwrite(students, sizeof(Student), *student_count, file);
    fclose(file);
}

void load_data(const char *filename, Student students[], int *student_count)
{
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        printf("Error opening file for reading.\n");
        return;
    }
    while (fread(&students[*student_count], sizeof(Student), 1, file))
    {
        (*student_count)++;
    }
    fclose(file);
}
