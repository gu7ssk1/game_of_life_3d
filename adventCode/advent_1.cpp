#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

int buff;
int buff2;
std::vector <int> listA{};
std::vector <int> listB{};

void sorting(std::vector<int>& a);
int calculating(std::vector<int>& a, std::vector<int>& b);
int similar(std::vector<int>& a, std::vector<int>& b);

int main(void)
{
    std::ifstream file("input.txt");

    if (!file)
    {
        std::cerr << "error opening file \n";
        return 1;
    }

    while (file >> buff >> buff2)
    {
        listA.push_back(buff);
        listB.push_back(buff2);
    }

    sorting(listA);
    sorting(listB);




    /*for (int i = 0; i < listA.size(); i++)
    {
        for(int j = 0; j< listA.size(); j++)
        if (listA[j] < listA[i])
        {
            buff = listA[i];
            listA[i] = listA[j];
            listA[j] = buff;
        }
    }*/

    // ********* PRINT *********
    for (int i = 0; i < listA.size(); i++)
    {
        std::cout << listA[i] <<"   " << listB[i] << "\n";
    }
    
        std::cout << "difference: " << calculating(listA, listB) << "\n";
        std::cout << "similar count: " << similar(listA, listB) << "\n";

        
        system("pause");
        return 0;
    
}

void sorting(std::vector<int>& a)
{
    int buddy;
    for (int i = 0; i < a.size(); i++)
    {
        for(int j = 0; j < a.size(); j++)
        
        if (a[j] < a[i])
            {
                buddy = a[i];
                a[i] = a[j];
                a[j] = buddy;
            }
        
    }   
}
int calculating(std::vector<int>& a, std::vector<int>& b)
{
    int cal = 0;
    for (int i = 0; i < a.size(); i++)
    {
        cal += abs(a[i] - b[i]);
    }
    return cal;
}

int similar(std::vector<int>& a, std::vector<int>& b)
{
    int counter = 0;
    int c = 0;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            if (a[i] == b[j])
            {
                counter++;
            }
        }
        if (counter > 0)
        {
            c += a[i] * counter; 
        }
        counter = 0;
    }
    return c;
}