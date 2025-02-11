#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>

int buff;
int buff2;
int safe_count = 0;
int counter_inc = 0;
int counter_dec = 0;
int increase = 0;
std::string line;
std::vector <int> list{};

void compare(int a, int b);

int main (void)
{
    std::ifstream file("input_2.txt");
    if (!file)
    {
        std::cerr<<"error loading file \n";
        return 1;
    }
    while (getline(file, line))
    {
        std::stringstream s(line);
        list.clear();
        
        while (s >> buff)
        {
            list.push_back(buff);
        }
        int size = list.size();
        int j = 1;

        for (int i = 0; i < size - 1; i++)
        {

            int q = list[i];
            int p = list[j];

            if (q < p && increase != 2)
            {
                increase = 1;
            }
            else if (q > p && increase != 1)
            {
                increase = 2;
            }
            else
            {
                break;
            }

           if (q < p && abs(q - p) < 4 && abs(q - p) > 0 && increase == 1)
           {
            counter_inc++;
           }
           else if (q > p && abs(q - p) < 4 && abs(q - p) > 0 && increase == 2)
           {
            counter_dec++;
           }
           else
           {
            break;
           }
           j++;
        }
        if (counter_inc == size - 1  || counter_dec == size - 1 )
        {
            safe_count++;
        }
        counter_inc = 0;
        counter_dec = 0;
        increase = 0;
    }
    std::cout << "safe count is " << safe_count << std::endl;
    
    return 0;
}



void compare(int a, int b)
{
    
    if (0 < abs(a - b) < 4)
    {
        if (a < b)
        {
            counter_inc ++;
        }
        else if (a > b)
        {
            counter_dec ++;
        }
    }
}