//Console Calendar Program

#include <cstdio>

int date(int dd, int mm, int yyyy)
{
    int number;
    int first_two_digits;
    int last_two_digits;
    int century_number;
    int division;
    int sum;
    int mod7;

    if( mm == 1 )
    {
        number = 0;
    }
    else if( mm == 2 )
    {
        number = 3;
    }
    else if( mm == 3 )
    {
        number = 3;
    }
    else if( mm == 4 )
    {
        number = 6;
    }
    else if( mm == 5 )
    {
        number = 1;
    }
    else if( mm == 6 )
    {
        number = 4;
    }
    else if( mm == 7 )
    {
        number = 6;
    }
    else if( mm == 8 )
    {
        number = 2;
    }
    else if( mm == 9 )
    {
        number = 5;
    }
    else if( mm == 10 )
    {
        number = 0;
    }
    else if( mm == 11 )
    {
        number = 3;
    }
    else if( mm == 12 )
    {
        number = 5;
    }

    /**
    first_two_digits = (total digits in yyyy - last_two digits)
    if, yyyy = 23142, then first_two_digits = 231
    */
    first_two_digits = (yyyy / 100);

    if( (first_two_digits % 4) == 0 )
    {
        century_number = 6;
    }
    else if( (first_two_digits % 4) == 1 )
    {
        century_number = 4;
    }
    else if( (first_two_digits % 4) == 2 )
    {
        century_number = 2;
    }
    else if( (first_two_digits % 4) == 3 )
    {
        century_number = 0;
    }

    last_two_digits = (yyyy % 100);
    division = (last_two_digits / 4);
    sum = (number + dd + century_number + last_two_digits + division);
    mod7 = (sum % 7);

    if((yyyy % 4) == 0)
    {
        mod7--;
    }

    return mod7;
}

void printCalendar(int mod7, int yyyy)
{
    int totalDaysInMonth;
    int counter;

    for( int month = 1; month < 13; month++ )
    {
        counter = 0;

        if( month == 1 )
        {
            printf("\nJanuary %d\n", yyyy);
            totalDaysInMonth = 31;
        }
        else if( month == 2 )
        {
            printf("\nFebruary %d\n", yyyy);

            if( (yyyy % 4) == 0 )
            {
                totalDaysInMonth = 29;
            }
            else
            {
                totalDaysInMonth = 28;
            }
        }
        else if( month == 3 )
        {
            printf("\nMarch %d\n", yyyy);
            totalDaysInMonth = 31;
        }
        else if( month == 4 )
        {
            printf("\nApril %d\n", yyyy);
            totalDaysInMonth = 30;
        }
        else if( month == 5 )
        {
            printf("\nMay %d\n", yyyy);
            totalDaysInMonth = 31;
        }
        else if( month == 6 )
        {
            printf("\nJune %d\n", yyyy);
            totalDaysInMonth = 30;
        }
        else if( month == 7 )
        {
            printf("\nJuly %d\n", yyyy);
            totalDaysInMonth = 31;
        }
        else if( month == 8 )
        {
            printf("\nAugust %d\n", yyyy);
            totalDaysInMonth = 31;
        }
        else if( month == 9 )
        {
            printf("\nSeptember %d\n", yyyy);
            totalDaysInMonth = 30;
        }
        else if( month == 10 )
        {
            printf("\nOctober %d\n", yyyy);
            totalDaysInMonth = 31;
        }
        else if( month == 11 )
        {
            printf("\nNovember %d\n", yyyy);
            totalDaysInMonth = 30;
        }
        else if( month == 12 )
        {
            printf("\nDecember %d\n", yyyy);
            totalDaysInMonth = 31;
        }

        printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat\n\n");

        for( int i = 0; i < mod7; i++ )
        {
            printf("\t");
            counter++;
        }
        for( int day = 1; day <= totalDaysInMonth; day++ )
        {
            printf("%d", day);
            counter++;

            if( counter < 7 )
            {
                printf("\t");
            }
            else if( counter == 7 )
            {
                printf("\n");
                counter = 0;
            }
        }

        mod7 = counter;
        printf("\n");
    }

    printf("\n");
}

int main()
{
    int yyyy;
    int mod7;

    printf("\n\n\t-----\tConsole Calendar Program\t-----");
    printf("\n\t-----\tDeveloped by Khaled Hasan Rony\t-----");

    printf("\n\n\nEnter year (in digits): ");
    scanf("%d", &yyyy);

    mod7 = date(1, 1, yyyy);

    printCalendar(mod7, yyyy);

    return 0;
}