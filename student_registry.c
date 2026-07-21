#include <stdio.h>
#include <string.h>
#include "student_registry.h"

Student registry[MAX_STUDENTS];
int studentCount = 0;

void loadStudentsFromFile() {
    FILE *file = fopen("students.dat", "r");
    if (file == NULL) return; 

    studentCount = 0;
    while (studentCount < MAX_STUDENTS && 
           fscanf(file, "%d|%[^|]|%[^|]|%f|%d\n", 
                  &registry[studentCount].id, 
                  registry[studentCount].name, 
                  registry[studentCount].major, 
                  &registry[studentCount].gpa, 
                  &registry[studentCount].credits) == 5) {
        studentCount++;
    }
    fclose(file);
}

void saveStudentsToFile() {
    FILE *file = fopen("students.dat", "w");
    if (file == NULL) {
        printf("Error: Could not open file for saving.\n");
        return;
    }
    
    int i;
    for (i = 0; i < studentCount; i++) {
        fprintf(file, "%d|%s|%s|%.2f|%d\n", 
                registry[i].id, 
                registry[i].name, 
                registry[i].major, 
                registry[i].gpa, 
                registry[i].credits);
    }
    fclose(file);
}

void addStudent() {
    int numToAdd;
    int i;
    
    printf("\nHow many students would you like to add? ");
    scanf("%d", &numToAdd);

    if (studentCount + numToAdd > MAX_STUDENTS) {
        printf("Error: Only %d slots remaining. Cannot add %d students.\n", MAX_STUDENTS - studentCount, numToAdd);
        return;
    }

    for (i = 0; i < numToAdd; i++) {
        printf("\n--- Entering details for student #%d ---\n", i + 1);
        printf("ID: "); 
        scanf("%d", &registry[studentCount].id);
        printf("Name: "); 
        scanf(" %[^\n]s", registry[studentCount].name);
        printf("Major: "); 
        scanf(" %[^\n]s", registry[studentCount].major);
        printf("GPA: "); 
        scanf("%f", &registry[studentCount].gpa);
        printf("Credits: "); 
        scanf("%d", &registry[studentCount].credits);
        
        studentCount++;
        printf("Student saved.\n");
    }
}

void displayAllStudents() {
    int i;
    
    if (studentCount == 0) {
        printf("\nNo students registered yet.\n");
        return;
    }

    printf("\n%-6s %-20s %-10s %-6s %-8s\n", "ID", "Name", "Major", "GPA", "Credits");
    printf("------------------------------------------------------------\n");
    
    for (i = 0; i < studentCount; i++) {
        printf("%-6d %-20s %-10s %-6.2f %-8d\n", 
               registry[i].id, 
               registry[i].name, 
               registry[i].major, 
               registry[i].gpa, 
               registry[i].credits);
    }
}

void searchByID() {
    int id, found = 0;
    int i;
    
    printf("Enter Student ID: ");
    scanf("%d", &id);
    
    for (i = 0; i < studentCount; i++) {
        if (registry[i].id == id) {
            printf("Found: %s\nMajor: %s\nGPA: %.2f\n", registry[i].name, registry[i].major, registry[i].gpa);
            found = 1;
        }
    }
    if (!found) printf("Student not found.\n");
}

void findByGPA() {
    float threshold;
    int i;
    
    printf("\nEnter GPA threshold: "); 
    scanf("%f", &threshold);
    
    for (i = 0; i < studentCount; i++) {
        if (registry[i].gpa >= threshold) {
            printf("- %s (GPA: %.2f)\n", registry[i].name, registry[i].gpa);
        }
    }
}

void findByMajor() {
    char major[MAJOR_LEN];
    int count = 0;
    int i;
    
    printf("Enter Major: ");
    scanf("%s", major);
    
    for (i = 0; i < studentCount; i++) {
        if (strcmp(registry[i].major, major) == 0) {
            printf("- %s\n", registry[i].name);
            count++;
        }
    }
    printf("Found %d student(s) in %s.\n", count, major);
}
