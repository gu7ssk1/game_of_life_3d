// c program to implament a 2d version 
// of 'game of life'

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

// -------------------------------------     
// initialization
// -------------------------------------


#define HEIGHT 20
#define WIDTH 100

// flag to end game if all life have died

bool gameover = false;

// count game iterations

int gamecount = 0;

// bool array to check living organizems

bool organizem[HEIGHT][WIDTH];
bool organcopy[HEIGHT][WIDTH];

// variable to count life in organizems

int lifecount = 0;

// function declarations

void setup();
void draw();
void logic();
int conwaycheck(int row, int col, bool array[HEIGHT][WIDTH], bool s);


// -------------------------------------
// main function call
// -------------------------------------

int main(void)
{
    setup();

    while(gameover == false)
    {
        draw();
        Sleep(100);
        gamecount++;
        //printf("this life : %d\n",lifecount);
        if (lifecount == 0)
        {
            gameover = true;
            system("color 40");
            printf("YOU DIED\n");
            system("color 07");
        }
        logic();

         // copy buffer array to real array
    // and re-initialize buffer array
    for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j< WIDTH; j++)
                {
                    organizem[i][j] = organcopy[i][j];
                    //organcopy[i][j] = false;
                }
        }
    }
    return 0;
}

// -------------------------------------
// function defenitions
// -------------------------------------

void setup()
{
    for (int i = 0; i < HEIGHT; i++)
    {
        //initialize organizem
        for (int j = 0; j < WIDTH; j++)
        {
            organizem[i][j] = false;
            organcopy[i][j] = false;
        }
    }

    // random setup for living organizems
    int randomcount = 9;

    for (int i = 0; i < randomcount; i++)
    {
        int rd_HEIGHT = rand() % HEIGHT;
        int rd_WIDTH = rand() % WIDTH;
        if (organizem[rd_HEIGHT][rd_WIDTH] == false)
        {
            organizem[rd_HEIGHT][rd_WIDTH] = true;
            lifecount++;
            
        }
    }
    gameover = false;

}

void draw()
{
    // clear screen
    system("cls");

    // draw top wall
    for (int i = 0; i <= WIDTH; i++)
    {
        printf("_");
    }
    // draw side walls and organizem
    printf("\n");
    //system("color 04");
    for(int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j <= WIDTH ; j++)
        {
            if (j == 0 || j == WIDTH)
            {
                printf("|");
            }
            else if (organizem[i][j] == true)
            {
                printf("#");
            }
            else
            {
                printf(".");
            }
            
        }
    printf("\n");
    }
    //system("color 07");
    // draw bottom wall
    for (int i = 0; i <= WIDTH; i++)
    {
        printf("_");
    }
    printf("\n");
     // display number of living organizems
     printf("Living organizems: %d\n", lifecount); 
     printf("Game iteration: %d\n", gamecount); 
}

void logic()
{
    // initialize neighbor count
    int neighbors = 0;
    
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            bool s = organizem[i][j];
            int flag = conwaycheck(i, j, organizem, s);
            switch(flag)
            
                {
                    case 0:
                        organcopy[i][j] = false;
                        lifecount--;
                        break;
                    case 1:
                        organcopy[i][j] = true;
                        break;
                    case 2:
                        organcopy[i][j] = true;
                        lifecount++;
                        break;
                    case 3:
                        organcopy[i][j] = false;
                        break;
                }
           
        }
        
    }
   
    
}
// function to check organizem suround
// according to conway GOL rules
int conwaycheck(int row, int col, bool array[HEIGHT][WIDTH], bool s)
{
    int n = 0;
    int flag = 0;

    for (int q = -1; q < 2; q++)
        {
            for (int p = -1; p < 2; p++)
                {
                    if (array[row + q][col + p] == true)
                    {
                        n++;
                    }
                }
        }
    if (s == true)  
    {
        if(n < 3 || n > 4)
        {
            return flag = 0;
            n = 0;
        }
        else
        {
            return flag = 1;
            n = 0;
        }
    }
    else
    {
        if (n == 3)
        {
            return flag = 2;
            n = 0;
        }
        else
        {
            return flag = 3;
            n = 0;
        }
    }


}
