#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<double>&,int,int);

int partition(vector<double>&, int,int);

int main()
{

    std::vector<double> v;
    std::mt19937 generator (123);
    std::uniform_real_distribution<double> dis(0.0, 1000.0);

    double rando;


    for( int i = 0; i < 1000; i++){
        rando = dis(generator);
        v.push_back(rando);
    }
    quickSort(v, 0, 1000);



    for(int i = 0; i < 1000; i++){
        std::cout << v[i] << "\n";
    }


}

void quickSort(vector<double>& A, int p,int q)
{
    int r;
    if(p<q)
    {
        r=partition(A, p,q);
        quickSort(A,p,r);
        quickSort(A,r+1,q);
    }
}


int partition(vector<double>& A, int p,int q)
{
    int x= A[p];
    int i=p;
    int j;

    for(j=p+1; j<q; j++)
    {
        if(A[j]<=x)
        {
            i=i+1;
            swap(A[i],A[j]);
        }

    }

    swap(A[i],A[p]);
    return i;
}
