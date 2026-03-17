#include "../headers/functions.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std ;

void genZaszlok()
{
    vector<string> szinek = {"feher", "fekete", "piros", "kek", "zold", "sarga"} ;
    vector<string> kozep  = {"feher", "fekete"} ;

    cout << "2.1 Zaszlok:\n" ;
    int db = 0 ;
    for (const string fel : szinek)
        for (const string koz : kozep)
            for (const string al : szinek)
            {
                cout << fel << " - " << koz << " - " << al << "\n" ;
                db++ ;
            }
    cout << "Osszes: " << db << "\n\n" ;
}

void bontasHelper(int marad, int darab, vector<int>& aktualis)
{
    if (darab == 0)
    {
        if (marad == 0)
        {
            for (int i = 0 ; i < aktualis.size() ; i++)
            {
                if (i) cout << " + " ;
                cout << aktualis[i] ;
            }
            cout << "\n" ;
        }
        return ;
    }
    for (int v = 1 ; v <= marad - (darab - 1) ; v++)
    {
        aktualis.push_back(v) ;
        bontasHelper(marad - v, darab - 1, aktualis) ;
        aktualis.pop_back() ;
    }
}

void osszegBontas(int n, int p)
{
    cout << "2.2 Osszegre bontas (" << n << " = " << p << " szam osszege):\n" ;
    vector<int> aktualis ;
    bontasHelper(n, p, aktualis) ;
    cout << "\n" ;
}

void delegacioHelper(int start, int n, int k, int q, vector<int>& aktualis, int nokSzama, int p)
{
    if (aktualis.size() == k)
    {
        if (nokSzama == q)
        {
            for (int i = 0 ; i < aktualis.size() ; i++)
            {
                if (i) cout << ", " ;
                cout << aktualis[i] ;
            }
            cout << "\n" ;
        }
        return ;
    }
    int marad = k - aktualis.size() ;
    for (int i = start ; i <= n - marad + 1 ; i++)
    {
        bool no = (i <= p) ;
        aktualis.push_back(i) ;
        delegacioHelper(i + 1, n, k, q, aktualis, nokSzama + (no ? 1 : 0), p) ;
        aktualis.pop_back() ;
    }
}

void delegacio(int n, int p, int k, int q)
{
    cout << "2.3 Delegacio (n=" << n << ", p=" << p
         << ", k=" << k << ", q=" << q << " no):\n" ;
    vector<int> aktualis ;
    delegacioHelper(1, n, k, q, aktualis, 0, p) ;
    cout << "\n" ;
}

void egyenlet()
{
    cout << "2.4 Egyenlet (3x + y + 4xz = 100):\n" ;
    int db = 0 ;
    for (int x = 0 ; x <= 33 ; x++)
        for (int z = 0 ; z <= 100 ; z++)
        {
            int y = 100 - 3 * x - 4 * x * z ;
            if (y >= 1)
            {
                cout << "x=" << x << "  y=" << y << "  z=" << z << "\n" ;
                db++ ;
            }
        }
    cout << "Osszes megoldas: " << db << "\n\n" ;
}

