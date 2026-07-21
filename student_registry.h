#ifndef STUDENT_REGISTRY_H
#define STUDENT_REGISTRY_H

#define MAX_STUDENTS 100
#define NAME_LEN 100
#define MAJOR_LEN 50

typedef struct {
    int id;
    char name[NAME_LEN];
    char major[MAJOR_LEN];
    float gpa;
    int credits;
} Student;

void addStudent();
void displayAllStudents();
void searchByID();
void findByGPA();
void findByMajor();
void saveStudentsToFile();
void loadStudentsFromFile();

#endif
