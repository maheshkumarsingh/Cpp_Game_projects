#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include <unistd.h>
int main()
{
    int h = 0, m = 0, s = 0;
    system("cls");
    printf("enter time in this format HH:MM:SS\n");
    scanf("%d%d%d", &h, &m, &s);
    start:
    for (h; h < 24; h++)
    {
        for (m; m < 60; m++)
        {
            for (s; s < 60; s++)
            {
                system("cls");
                printf("%02d : %02d : %02d ", h, m, s);
                if (h < 12)
                {
                    printf("AM");
                }
                else
                {
                    printf("PM");
                }
                for (double i = 0; i < 99999999; i++)
                {
                    i++;
                    i--;
                }
            }
            s = 0;
        }
        m=0;
    }
    h=0;
    goto start;
    //getch();

    return 0;
}