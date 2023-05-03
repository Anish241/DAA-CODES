// the program will create a file of 100000 random numbers stored in a file random_number.txt and then sort them using merge sort
// The sorted numbers will be stored in a file named "merge_sort.txt"
// The running time of the program will be stored in a file named "merge_sort_time.txt"

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>


using namespace std;
using namespace std::chrono;

void merge(vector<int> &arr, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    vector<int> L;
    vector<int> R;

    for(int i = 0; i < n1; i++)
    {
        L.push_back(arr[p + i]);
    }
    for(int i = 0; i < n2; i++)
    {
        R.push_back(arr[q + i + 1]);
    }

    int i = 0;
    int j = 0;
    int k = p;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }

        k++;
    }

    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int> &arr, int p, int r)
{
    if(p < r)
    {
        int q = (p + r) / 2;
        merge_sort(arr, p, q);
        merge_sort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

int main()
{
    ofstream fout;
    fout.open("random_number.txt");
    srand(time(NULL));
    for(int i = 0; i < 100000; i++)
    {
        //the range of random numbers is from 0 to 999999
        fout << rand() % 1000000 << endl;
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
    merge_sort(arr, 0, arr.size() - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    fout.open("merge_sort.txt");
    for(int i = 0; i < arr.size(); i++)
    {
        fout << arr[i] << endl;
    }
    fout.close();

    fout.open("merge_sort_time.txt");
    fout << duration.count() << endl;
    fout.close();

    return 0;
}