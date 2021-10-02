#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;
int main()
{
    int hh, mm, sec;
    cout << "enter HH:MM:SS" << endl;
    cin >> hh >> mm >> sec;
    while (true)
    {
        system("cls");
        if (hh < 12)
        {
            cout<<" ==^=====^==\n |";
            cout <<" "<< hh << ":" << mm << ":" << sec;
            cout << " AM ";
            cout<<"|\n ==========";
            sec++;
            if (sec == 60)
            {
                mm++;
                sec = 0;
                if (mm == 60)
                {
                    hh++;
                    mm = 0;
                }
            }
            sleep(1);
        }
        else if (hh >= 12 && hh < 24)
        {
            if (hh == 12)
            {
                cout << hh << ":" << mm << ":" << sec;
            }
            else
            {
                cout << hh - 12 << ":" << mm << ":" << sec;
            }
            cout << " PM";
            sec++;
            if (sec == 60)
            {
                mm++;
                sec = 0;
                if (mm == 60)
                {
                    hh++;
                    mm = 0;
                    if (hh == 24)
                    {
                        hh = 0;
                    }
                }
            }
            sleep(1);
        }
        else
        {
            cout << "please enter in HH:MM:SS format only";
        }

        //usleep(1000000);
    }
    getch();
    return 0;
}