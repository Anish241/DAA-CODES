// the program will create a file of 100000 random numbers stored in a file random_number.txt and then sort them using insertion sort
// The sorted numbers will be stored in a file named "insertion_sort.txt"
// The running time of the program will be stored in a file named "insertion_sort_time.txt"

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>


using namespace std;
using namespace std::chrono;

void insertion_sort(vector<int> &arr)
{
    int key;
    int j;
    for(int i = 1; i < arr.size(); i++)
    {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    ofstream fout;
    fout.open("random_number.txt");
    srand(time(NULL));
    for(int i = 0; i < 100000; i++)
    {
        fout << rand() << endl;
    }
    fout.close();

    ifstream fin;
    fin.open("random_number.txt");
    vector<int> arr;
    int temp;
    while(fin >> temp)
    {
        arr.push_back(temp);
    }
    fin.close();

    auto start = high_resolution_clock::now();
    insertion_sort(arr);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    fout.open("insertion_sort.txt");
    for(int i = 0; i < arr.size(); i++)
    {
        fout << arr[i] << endl;
    }
    fout.close();

    fout.open("insertion_sort_time.txt");
    fout << duration.count() << endl;
    fout.close();

    return 0;
}