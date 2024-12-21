// c program to implament a 2d version 
// of 'game of life'

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

//      
// initialization
// 


const int height = 20;
const int width = 50;

// flag to end game if all life have died

int gameover;

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


// 
// main function call
// 

int main(void)
{
    setup();

    while(!gameover)
    {
        draw();
        logic();
        sleep(40);
        gamecount++;
    }
    return 0;
}

// --
// function defenitions
// --

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
    int gameover = 0;

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
    
    int neighbors = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
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
            }
            
        }
        
    }
    
    
}
bool conwaycheck(int row, int col)
{

}