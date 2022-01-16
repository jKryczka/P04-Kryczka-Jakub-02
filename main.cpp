#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
void sasiedzi(int n, int** macierz)
{
    int i,j;
    int temp;
    for(i=0;i<n;i++)
    {
        temp=0;
        for(j=0;j<n;j++)
        {
            if(macierz[i][j]==1)
            {
                temp = temp + 1;
            }
        }
        if(temp>0)
        {
            cout<<"wierzcholek "<<i<<" ma "<<temp;
            if(temp==1)
            {
                cout<<" sasiada, jest to wierzcholek: ";
            }else
            {
                cout<<" sasiadow, sa to wierzcholki: ";
            }
            for(j=0;j<n;j++)
            {
                if(macierz[i][j]==1)
                {
                    cout<<j<<" ";
                }

            }
        }else
        {
            cout<<"Wierzcholek "<<i<<" nie ma sasiadow.";
        }
        cout<<endl;
    }
    cout<<endl;
}
void wszystkie(int n,int** macierz)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        temp=0;
        for(j=0;j<n;j++)
        {
            if(macierz[i][j]==1)
            {
                temp++;
            }
        }
        if(temp==n)
            cout<<"wierzcholek "<<i<<" jest sasiadem kazdego wierzcholka"<<endl;
    }
    cout<<endl;
}
void stopnie_wychodzace(int n, int** macierz)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        temp=0;
        for(j=0;j<n;j++)
        {
            if(macierz[i][j]==1)
                temp++;
        }
        cout<<"wierzcholek "<<i<<" ma stopien wychodzacy rowny: "<<temp<<endl;
    }
    cout<<endl;
}
void stopnie_wchodzace(int n,int** macierz)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        temp=0;
        for(j=0;j<n;j++)
        {
            if(macierz[j][i]==1)
                temp++;
        }
        cout<<"wierzcholek "<<i<<" ma stopien wchodzacy rowny: "<<temp<<endl;
    }
    cout<<endl;
}
void wierzcholki_izolowane(int n,int** macierz)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        temp=0;
        for(j=0;j<n;j++)
        {
            if(macierz[j][i]==1)
                temp=1;
            if(macierz[i][j]==1)
                temp=1;
        }
        if(temp==0)
            cout<<"wierzcholek "<<i<<" jest wierzcholkiem izolowanym"<<endl;

    }
    cout<<endl;
}

void petle(int n, int** macierz)
{
    int i, j;
    for( i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(macierz[i][j]==macierz[j][i]&&macierz[i][j]==1)
            {
                if(i==j)
                {
                    cout<<"wierzcholek "<<i<<" tworzy petle z samym soba"<<endl;
                }else
                {
                    cout<<"wierzcholek "<<i<<" i wierzcholek "<<j<<" tworza petle"<<endl;
                }
            }
        }
    }
    cout<<endl;
}



void krawedzie_dwukierunkowe(int n,int** macierz)
{

    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(macierz[i][j]==1&&macierz[j][i]==1)
            {
                cout<<"krawedz dwukierunkowa to krawedz pomiedzy wierzcholkiem "<<i<<" a "<<j<<endl;
            }
        }
    }
    cout<<endl;
}

int main()
{
    fstream plik;
    int n;
    plik.open("macierz.txt",ios::in);
    plik>>n;
    int** macierz = new int*[n];
    for (int i = 0; i < n; i++)
    {
     macierz[i] = new int[n];
    }
    int i;
    int j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            plik>>macierz[i][j];
        }
    }
    auto start = chrono::high_resolution_clock::now();  //start mierzenia czasu
    sasiedzi(n,macierz);
    wszystkie(n,macierz);
    stopnie_wychodzace(n, macierz);
    stopnie_wchodzace(n,macierz);
    wierzcholki_izolowane(n,macierz);
    petle(n, macierz);
    krawedzie_dwukierunkowe(n, macierz);
    auto finish = chrono::high_resolution_clock::now();    //stop mierzenia czasu
    chrono::duration<double> elapsed = finish - start;  //obliczenie ile czasu minelo
    cout<<"wykonanie programu zajelo: " << elapsed.count() << " sekund";

}

