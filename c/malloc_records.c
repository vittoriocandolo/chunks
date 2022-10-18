#include <stdio.h>
#include <stdlib.h>

struct course
{
    int marks;
    char subject[30];
};

int main()
{
    struct course *ptr;
    int i, noOfRecords;
    printf("Enter number of records: ");
    scanf("%d", &noOfRecords);

    ptr = (struct course *)malloc(sizeof(struct course) * noOfRecords);

    for(i = 0; i < noOfRecords; i++)
    {
        printf("Enter name of the subject and marks respectively:\n");
        scanf("%s %d", &(ptr + i)->subject, &(ptr + i)->marks);
    }

    printf("Displaying information:\n");

    for(i = 0; i < noOfRecords; i++)
    {
        printf("%s\t%d\n", (ptr + i)->subject, (ptr + i)->marks);
    }

    return 0;
}

