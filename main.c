#include <stdio.h>
#include "student_registry.h"

int main() {
    int choice;
    loadStudentsFromFile();

    do {
        printf("\n--- Dr. Santos' Student Registry ---\n");
        printf("1. Add new student\n2. Display all students\n3. Search by ID\n");
        printf("4. Search by GPA\n5. Search by Major\n6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                addStudent(); 
                break;
            case 2: 
                displayAllStudents(); 
                break;
            case 3: 
                searchByID(); 
                break;
            case 4: 
                findByGPA(); 
                break;
            case 5: 
                findByMajor(); 
                break;
            case 6: 
                saveStudentsToFile(); 
                printf("Data saved successfully. Exiting.\n"); 
                break;
            default: 
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
