// a cs50 final exercise by Guri 'gursski':
// c program to implament a simple console 
// version of John Horton Conway's 'game of life'

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

// -------------------------------------     
// initialization zone
// -------------------------------------

#define HEIGHT 20
#define WIDTH 100

// flag to end game if all life have died
bool gameover = false;

// count game iterations
int gamecount = 0;

// bool array for living organizems
bool organizem[HEIGHT][WIDTH];
bool organcopy[HEIGHT][WIDTH];

// bool organizems for user input
bool organuser1[4][4] = {
    {0,1,1,0},
    {1,1,1,0},
    {0,0,1,0},
    {0,1,1,0}
};
bool organuser2[4][4] = {
    {0,1,0,1},
    {0,1,0,1},
    {1,0,1,0},
    {1,1,1,0}
};

// variable to count living organizems
int lifecount = 0;

// function declarations
void setup();
void draw();
void logic();
int conwaycheck(int row, int col, bool array[HEIGHT][WIDTH], bool s);
void printuser(bool array[4][4]);


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

        // check if gameover (user press esc)
        if (lifecount == 0 || gameover == true)
        {
            gameover = true;
            system("color 40");
            Sleep(1000);
            gotoxy(HEIGHT/2,WIDTH/2);
            printf("YOU DIED\n");
            Sleep(1000); 
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
// different function defenitions
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

    // add organizems by user keystrokes
    system("cls");
    printf("add organizems to random location with keys 'A' and 'B' \n");
    printf("A\n______\n");
    printuser(organuser1);
    printf("\n");
    printf("B\n______\n");
    printuser(organuser2);

    printf("press any key to continue");
    getch();
}

void draw()
{
    // clear screen
    system("cls");

    // functionality to detect user key stroke
    // and insert user organizem by key
    if (kbhit())
    {
        int ch = getch();
        if (ch == 'a' || ch == 'A')
        {
            int randomh = rand() % HEIGHT;
            int randomw = rand() % WIDTH;
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (organuser1[i][j] == 1)
                    {
                        lifecount++;
                        organizem[randomh + i][randomw + j] = true;
                    }
                }
            }
            
        }
        else if (ch == 'b' || ch == 'B')
        {
            int randomh = rand() % HEIGHT;
            int randomw = rand() % WIDTH;
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (organuser2[i][j] == 1)
                    {
                        lifecount++;
                        organizem[randomh + i][randomw + j] = true;
                    }
                }
            }
        }
        // check esc key
        else if (ch == 27)
        {
            gameover = true;
        }
    }

    // draw top wall
    for (int i = 0; i <= WIDTH; i++)
    {
        printf("_");
    }
    // draw side walls and organizem
    printf("\n");
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
    // initialize neighbor count for each organ
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

// function to check organizem surounding
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
 
// function to draw user organ options
    void printuser(bool array[4][4])
    {
        for(int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (array[i][j] == 0)
                {
                    printf(" ");
                }
                else if (array[i][j] == 1)
                {
                    printf("#");
                }
            }
            printf("\n");
        }    
    }
