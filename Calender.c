#include<stdio.h>
#include<stdlib.h>

int Get_1st_day(int year)
{   
    
    int days;
    // an algorithm to find the no. of days in that perticular year
    days= (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
    return days;
}

int main()
{   //enter the year
    int year, month, day, daysInMonth, weekday = 0, startingDay;
    printf("Enter your desired year: ");
    scanf("%d",&year);


    //enter the months name and no.of days in that month
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October","November", "December"};
    int monthDay[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    //condition for leap year
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        monthDay[1] =29;
    
    //checkinfg the first day of the year
    startingDay=Get_1st_day(year);

    
    for(month = 0; month < 12; month++ )
    {
        //printing the name of the month
        daysInMonth = monthDay[month];
        printf("\n\n--------------------%s------------------------", months[month]);
        printf("\n  Sun  Mon  Tue  Wed  Thurs  Fri  Sat \n");

        //printing the blank space to manage the staring of the month
        for(weekday = 0; weekday < startingDay; weekday++ )
            printf("     ");

        //printing days 
        for(day =1; day <= daysInMonth; day++)
        {
            printf("%5d",day);
            if(++weekday > 6)
            {
                printf("\n");
                weekday = 0;
            }
        startingDay=weekday;

        }
    }
    return 0;
}