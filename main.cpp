#include <iostream>

using namespace std;

int main()
{
    pair<int, int> adj[7][7];
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (i != j)
            {
                adj[i][j].first = 1;
            }
            else
            {
                adj[i][j].first = 0;
            }
            adj[i][j].second = 0;
        }
    }
    adj[0][1].second = 670;
    adj[0][2].second = 758;
    adj[0][3].second = 427;
    adj[0][4].second = 581;
    adj[0][5].second = 211;
    adj[0][6].second = 369;
    adj[1][2].second = 361;
    adj[1][3].second = 252;
    adj[1][4].second = 132;
    adj[1][5].second = 492;
    adj[1][6].second = 680;
    adj[2][3].second = 332;
    adj[2][4].second = 493;
    adj[2][5].second = 690;
    adj[2][6].second = 759;
    adj[3][4].second = 357;
    adj[3][5].second = 394;
    adj[3][6].second = 431;
    adj[4][5].second = 391;
    adj[4][6].second = 650;
    adj[5][6].second = 521;

    adj[1][0].second = 670;
    adj[2][0].second = 758;
    adj[3][0].second = 427;
    adj[4][0].second = 581;
    adj[5][0].second = 211;
    adj[6][0].second = 369;
    adj[2][1].second = 361;
    adj[3][1].second = 252;
    adj[4][1].second = 132;
    adj[5][1].second = 492;
    adj[6][1].second = 680;
    adj[3][2].second = 332;
    adj[4][2].second = 493;
    adj[5][2].second = 690;
    adj[6][2].second = 759;
    adj[4][3].second = 357;
    adj[5][3].second = 394;
    adj[6][3].second = 431;
    adj[5][4].second = 391;
    adj[6][4].second = 650;
    adj[6][5].second = 521;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cout << "( " << adj[i][j].first << ", " << adj[i][j].second << ") ";
        }
        cout << endl;
    }
    cout << endl;
    int suma_wag = 0;
    int nast_wiersz = 2;
    int kolejne_miasto = 0;
    int il_odwiedzone = 1;
    int odwiedzone[7];
    for (int i = 0; i < 7; i++)
    {
        odwiedzone[i] = 0;
    }
    while (il_odwiedzone != 7)
    {
        int min = 1000;
        for (int j = 0; j < 7; j++)
        {
            if (odwiedzone[j] == 0)
            {
                if (adj[nast_wiersz][j].first == 1)
                {
                    if (min > adj[nast_wiersz][j].second)
                    {
                        min = adj[nast_wiersz][j].second;
                        kolejne_miasto = j;
                    }
                }
            }
            odwiedzone[nast_wiersz] = 1;
        }
        cout << nast_wiersz << " -> " << kolejne_miasto << endl;
        cout << "Odleglosc: " << min << endl;
        nast_wiersz = kolejne_miasto;
        suma_wag = suma_wag + min;
        il_odwiedzone++;
    }
    cout << "Suma  odleglosci: " << suma_wag;
}