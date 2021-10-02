#include <iostream>
#include <conio.h>
#include <windows.h>
#include <unistd.h>
using namespace std;
bool gameover;
const int width = 10;
const int height = 10;
int x, y, fruitX, fruitY, score;
int tailX[100],tailY[100];
int ntail;

enum edirection
{
    STOP = 0,
    LEFT,   //left=1
    RIGHT,  //right=2
    UP,     //up=3
    DOWN    //down=4
};

edirection dir;

void setup()
{
    gameover = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;  //create random number from 0 to width-1
    fruitY = rand() % height; //create random number from 0 to height-1
    score = 0;
}
void draw()
{
    system("cls");
    for (int i = 0; i < width + 2; i++) //upper row
    {
        cout << "#";
    }
    cout << endl;
    for (int i = 0; i < height; i++) //1st column
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#";
            if (i == y && j == x)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << "*";
            else
            {
                bool print=false;
                for(int k=0;k<ntail;k++)
                {
                    if(tailX[k]==j && tailY[k]==i)
                    {
                        cout<<"o";
                        print=true;
                    }
                }
                if(!print)
                cout << " ";
            }    
            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }
    for (int i = 0; i < width + 2; i++)
    {
        cout << "#";
    }
    cout << endl;
    cout<<"Score= "<<score<<endl;
}
void input()
{
    if(_kbhit())   //to check keyboard ip is given or not if given True otherwise false
         
    {
        switch(_getch())  //to convert character to ascii value w--up a-left s-down d-right
        {
            case 'a':
            dir=LEFT;
            break;
            case 's':
            dir=DOWN;
            break;
            case 'd':
            dir=RIGHT;
            break;
            case 'w':
            dir=UP;
            break;
            case 'x':
            gameover=true;
            break;
        }
    }
}
void logic()
{
    int prevX=tailX[0];
    int prevY=tailY[0];
    int prev2X,prev2Y;
    tailX[0]=x;
    tailY[0]=y;
    for(int i=1;i<ntail;i++)
    {
        prev2X=tailX[i];
        prev2Y=tailY[i];
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prev2X;
        prevY=prev2Y;

    }
    switch(dir)
    {
        case LEFT:
        x--;
        break;
        case RIGHT:
        x++;
        break;
        case UP:
        y--;
        break;
        case DOWN:
        y++;
        break;
        default:
        break;
    }
    // if(x>width || x< 0 || y>height || y< 0)   //gameover if it touches wall
    //    gameover=true;
    if(x>=width) x=0; else if(x<0) x=width-1;
    if(y>=height) y=0; else if(y<0) y=height-1;
      for(int i=0;i<ntail;i++)
      {
          if(tailX[i]==x && tailY[i]==y)  //gamover if it crosses it tail
            gameover=true;
      }
    
    if(x == fruitX && y== fruitY)    //yha pe score increase hoga if it eats fruit
    {
        score+=10;
        fruitX = rand() % width;  
        fruitY = rand() % height;
        ntail++;
    }    
}
int main(void)
{
    setup();
    while (!gameover)
    {
        draw();
        input();
        logic();
        sleep(1);
    }

    return 0;
}