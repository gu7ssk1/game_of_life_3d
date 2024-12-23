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
        logic();
        Sleep(55);
        gamecount++;
        if (lifecount <= 0)
        {
            gameover = true;
            //system("color 40");
            printf("YOU DIED\n");
            system("color 07");
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
    int randomcount = 50;

    for (int i = 0; i < randomcount; i++)
    {
        int rd_HEIGHT = rand() % 10;
        int rd_WIDTH = rand() % 10;
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
    //system("cls");

    // draw top wall
    for (int i = 0; i < WIDTH + 2; i++)
    {
        printf("-");
    }
    // draw side walls and organizem
    printf("\n");
    for(int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j <= WIDTH; j++)
        {
            if (j == 0 || j == WIDTH)
            {
                printf("|");
            }
            else if (organizem[i][j] == true)
            {
                //system("color 04");
                printf("#");
            }
            else
            {
                printf(".");
            }
            
        }
    printf("\n");
    }
    // draw bottom wall
    for (int i = 0; i < WIDTH + 2; i++)
    {
        printf("-");
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
    
    for (int i = 1; i < HEIGHT; i++)
    {
        for (int j = 1; j < WIDTH; j++)
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
                    case 2:
                        organcopy[i][j] = true;
                        lifecount++;
                        
                }
            /* in case conway function doesn't work
            if (organizem[i][j] == true)
            {
                for (int q = -1; q < 2; q++)
                {
                    for (int p = -1; p < 2; p++)
                    {
                        if (organizem[i + q][j + p] == true && (q!=0 && p!=0))
                        {
                            neighbors++;
                            
                        }
                    
                    }
                    
                }
                if (neighbors < 2 || neighbors > 3)
                {
                    organcopy[i][j] = false;
                }
                else
                {
                    organcopy[i][j] = true;
                }
            }
            else
            {
                
            }
            */
            
        }
        
    }
    // copy buffer array to real array
    // and re-initialize buffer array
    for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j< WIDTH; j++)
                {
                    organizem[i][j] = organcopy[i][j];
                    organcopy[i][j] = false;
                }
        }
    
}
// function to check organizem suround
// according to conway GOL rules
int conwaycheck(int row, int col, bool array[HEIGHT][WIDTH], bool s)
{
    int n = 0;
    int flag = 0;
    bool organflag = false;
    
    if (s == true)
    {
        organflag = true;
    }
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
    if (n < 2 || n > 3 )
    {
        return flag = 0;
    }
    else if ((n == 2 || n == 3) && organflag == true)
    {
        return flag = 1;
    }
    else if (n == 3 && organflag == false)
    {
        return flag = 2;
    }
    
    
}
