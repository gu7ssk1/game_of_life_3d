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


const int height = 20;
const int width = 50;

// flag to end game if all life have died

bool gameover;

// count game iterations

int gamecount = 0;

// bool array to check living organizems

bool organizem[height][width];
bool organcopy[height][width];

// variable to count life in organizems

int lifecount = 0;

// function declarations

void setup();
void draw();
void logic();


// -------------------------------------
// main function call
// -------------------------------------

int main(void)
{
    setup();

    while(!gameover)
    {
        draw();
        logic();
        sleep(55);
        gamecount++;
        if (lifecount <= 0 || kbhit())
        {
            gameover = true;
            textcolor(2);
            printf("YOU DIED\n");
        }
    }
    return 0;
}

// -------------------------------------
// function defenitions
// -------------------------------------

void setup()
{
    for (int i = 0; i < height; i++)
    {
        //initialize organizem
        for (int j = 0; j < width; j++)
        {
            organizem[i][j] = false;
            organcopy[i][j] = false;
        }
    }

    // random setup for living organizems
    int randomcount = 50;

    for (int i = 0; i < randomcount; i++)
    {
        int rd_height = rand() % height;
        int rd_width = rand() % width;
        int rd_less = rand() % 10;
        if (organizem[rd_height][rd_width] == false && rd_less < 5)
        {
            organizem[rd_height][rd_width] = true;
            lifecount++;
            
        }
    }
    gameover = false;

}

void draw()
{
    // clear screen
    clrscr();

    // draw top wall
    for (int i = 0; i < width + 2; i++)
    {
        printf("-");
    }
    // draw side walls and organizem
    printf("\n");
    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j <= width; j++)
        {
            if (j == 0 || j == width)
            {
                printf("|");
            }
            else if (organizem[i][j] == true)
            {
                textbackground(2);
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
    for (int i = 0; i < width + 2; i++)
    {
        printf("-");
    }
    printf("\n");
     // display number of living organizems
     printf("Living organizems: %d", lifecount); 
     printf("Game iteration: %d", gamecount); 
}

void logic()
{
    // initialize neighbor count
    int neighbors = 0;
    
    for (int i = 1; i < height; i++)
    {
        for (int j = 1; j < width; j++)
        {
            int flag = conwaycheck(i, j, organizem[][]);
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
    for (int i = 0; i < height; i++)
        {
            for (int j = 0; j< width; j++)
                {
                    organizem[i][j] = organcopy[i][j];
                    organcopy[i][j] = false;
                }
        }
    
}
// function to check organizem suround
// according to conway GOL rules
int conwaycheck(int i, int j, bool array[][])
{
    int n = 0;
    int flag = 0;
    bool organflag = false;
    
    if (array[i][j] == true)
    {
        organflag = true;
    }
    for (int q = -1; q < 2; q++)
        {
            for (int p = -1; p < 2; p++)
                {
                    if (array[i + q][j + p] == true)
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
