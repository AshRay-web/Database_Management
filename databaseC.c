#include<stdio.h>
#include <stdlib.h>

struct Student{
    char name[50];
    int id;
    int age;
    float gpa;
};

void addStudent(FILE *file){
    struct Student student;

    printf("Enter Student Id : ");
    scanf("%d", &student.id);

    printf("Enter Student age : " );
    scanf("%d" ,&student.age);

    printf("Enter student gpa : ");
    scanf("%f", &student.gpa);

    printf("Enter student name : ");
    scanf("%s",student.name);

    fwrite(&student, sizeof(struct Student) , 1 , file);
    printf("Student added successfully ! \n");
}

void displayStudents(FILE *file){
    struct Student student;
    rewind(file);

    printf("\nStudent Database:\n ");
    printf("ID\tName\tAge\tGPA\n");
    while (fread(&student, sizeof(struct Student) , 1, file)){
        printf("%d\t%s\t%d\t%.2f\n" , student.id , student.name , student.age, student.gpa);
    }
}

void searchStudent(FILE *file, int id){
    struct Student student;
    rewind(file);

    while (fread(&student , sizeof(struct Student) , 1, file )){

        if(student.id == id){
            printf("Student Found:\n");
            printf("ID: %d , Name : %s , Age: %d , GPA : %.2f \n", student.id, student.name, student.age, student.gpa);
            return;
        }
    }
    printf("Student with ID %d not found \n" , id);
}


int main() {
    FILE *file;
    int choice, id;

    file = fopen("students.dat", "ab+"); // Open file in append and read mode

    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    while (1) {
        printf("\n");
    printf("\033[1;36m=========================================\033[0m\n"); // Cyan border
    printf("\033[1;36m|      \033[1;33mSTUDENT DATABASE SYSTEM\033[1;36m          |\033[0m\n"); // Yellow text, cyan border
    printf("\033[1;36m=========================================\033[0m\n");
    printf("\033[1;36m|                                       |\033[0m\n");
    printf("\033[1;36m|   \033[1;32m1. Add Student\033[1;36m                      |\033[0m\n"); // Green text
    printf("\033[1;36m|   \033[1;32m2. Display All Students\033[1;36m             |\033[0m\n");
    printf("\033[1;36m|   \033[1;32m3. Search Student\033[1;36m                   |\033[0m\n");
    printf("\033[1;36m|   \033[1;31m4. Exit\033[1;36m                             |\033[0m\n"); // Red text
    printf("\033[1;36m|                                       |\033[0m\n");
    printf("\033[1;36m=========================================\033[0m\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(file);
                break;
            case 2:
                displayStudents(file);
                break;
            case 3:
                printf("Enter Student ID to search: ");
                scanf("%d", &id);
                searchStudent(file, id);
                break;
            case 4:
                fclose(file);
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}




