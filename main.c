#include <stdio.h>
#include <string.h>
#include <stdbool.h>

    typedef struct{
        char firstName[50];
        char lastName[50];
        char city[50];
        int birthYear;
    } Student;

void inputStudent(Student* student){

    printf("Enter firstname: ");
    scanf(" %s", student->firstName);
    printf("Enter lastname: ");
    scanf(" %s", student->lastName);
    printf("Enter city: ");
    scanf(" %s", student->city);
    printf("Enter birthyear: ");
    scanf(" %d", &student->birthYear);

}

void printStudent(const Student* student){

    printf("FIRSTNAME: %s\n", student->firstName);
    printf("LASTTNAME: %s\n", student->lastName);
    printf("CITY: %s\n", student->city);
    printf("BIRTHYEAR: %d\n", student->birthYear);

}

int main(){

    /*Student student1;
    Student student2;
    inputStudent(&student1);
    inputStudent(&student2);
    printStudent(&student1);     
    printStudent(&student2);*/

    Student studentlist[10];
    int howManyStudent = 0;

    while(true){

        inputStudent(&studentlist[howManyStudent]);
        howManyStudent++;
        char userCont[100] = "";
        printf("Do u want to enter another student?: (YES/NO)");
        scanf(" %s", userCont);

        if(howManyStudent > 9 || strcmp("NO",userCont) == 0)
            break;
    }
    printf("----------PRINTA ALLA STUDENTER--------\n");

    Student* oldest = &studentlist[0];

    for(int i=0; i < howManyStudent; i++){

        if(studentlist[i].birthYear < oldest->birthYear)
            oldest = &studentlist[i];
        printf("STUDENT%d\n", i+1);
        printStudent(&studentlist[i]);
    }

    printf("OLDEST STUDENT IS: %s %s", oldest->firstName, oldest->lastName);

    return 0;
}