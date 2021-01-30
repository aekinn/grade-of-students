#include <stdio.h>
#include <string.h>
#include <errno.h>
int main(){
int i;
char name[30],surname[30];
double midterm1, midterm2, average, finals, classavg;

FILE *grade;
grade = fopen("student.txt","r");

if(!grade){   // Test whether file has been opened
    fprintf(stderr, "Error opening file: %s", strerror(errno));
    exit(1);
}else{
    i=1;  // This counts number of the students
    while(fscanf(grade, "%s %s %lf %lf %lf", &name, &surname, &midterm1, &midterm2, &finals) != EOF){

    if(midterm1<0 || midterm1>100 || midterm2<0 || midterm2>100 || finals<0 || finals>100){ // Student grades were limited from 0 to 100.

        printf("%-7d Any of the grades in this line is undefined between 0 and 100!!! Fix the line of %d\n", i, i);
        i++;
        continue;
    }
    average = 0.3*midterm1 + 0.3*midterm2+0.4*finals;  // The percentages of the grades were determined.

    printf("%-7d %-10s %-18s %.2lf  ", i, name, surname, average);
    // Letter grades were given with respect to averages.
if(average >= 90 && average <=100)
  {
    printf("%s\n","AA");
  }
else if(average >=85 && average <90)
 {

    printf("%s\n","BA");
 }
else if(average >=80 && average  <85)
    {
    printf("%s\n","BB");
    }
else if(average >=75 && average  <80)
    {
    printf("%s\n","CB");
    }
else if(average >=70 && average  <75)
    {
    printf("%s\n","CC");
    }
else if(average >=65 && average  <70)
    {
    printf("%s\n","DC");
    }
else if(average >=60 && average  <65)
{
    printf("%s\n","DD");
}
else if(average >=50 && average  <60)
{
    printf("%s\n","FD");
}
else if(average >=0 && average  <50)
{
    printf("%s\n","FF");
}
classavg += average;  // Sum of all grades belonging to students
i++;
}
// Sum of all grades divided by the number of students gives the average of the class
printf("\nAverage of the class is %.2lf \n", classavg/i);
fclose(grade);
return 0;
}
}
