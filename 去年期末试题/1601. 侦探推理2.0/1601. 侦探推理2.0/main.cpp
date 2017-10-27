//
//  main.cpp
//  1601. 侦探推理2.0
//
//  Created by lyc on 2017/1/11.
//  Copyright © 2017年 lyc. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;
int m,n,p,wn[20],today=-1,criminal,found,commit[21];
char name[20][100][251],day[7][11]={"Monday.","Tuesday.","Wednesday.","Thursday.","Friday.","Saturday.", "Sunday."};
bool lie[20];
char lastcriminal[21]="---",thiscriminal[21];

bool putin(int pos, bool com)
{
    if (com==1)
    {
        if ((name[pos][0] == thiscriminal || thiscriminal[0] == '-') && (commit[pos] == -1 || commit[pos] == 1))
        {
            strcpy(thiscriminal, name[pos][0]);
            commit[pos] = com;
            return true;
        }
        else
            return false;
    }
    else
    {
        if (commit[pos] == -1 || commit[pos] == 0)
        {
            commit[pos] = com;
            return true;
        }
        else
            return false;
    }
}
int search(char * s)
{
    int i;
    for (i=0; i<m; i++)
        if (strcmp(name[i][0], s) == 0)
            return i;
    return -1;
}

void detect(int lien, int first)
{
    if (found >= 2)
        return;
    if (lien<n)
    {
        int i;
        for (i=first; i<=m+lien-n; i++)
        {
            lie[i] = 1;
            detect(lien+1,i+1);
            lie[i] = 0;
        }
    }
    else
    {
        today = -1;
        int man,word,i0;
        for (i0=0; i0<m; i0++)
            commit[i0] = -1;
        thiscriminal[0] = '-';
        
        for (man=0; man<m; m++)
        {
            for (word=1; word<=wn[man]; word++)
            {
                int i,j;
                if (name[man][word][1] != ' ' && name[man][word][0] == 'T')
                    for (i=0; i<7; i++)
                    {
                        bool findday = 1;
                        for (j=0; j<3; j++)
                            if (name[man][word][9+i] != day[j][i])
                                findday = 0;
                        if (findday)
                        {
                            if (today == -1)
                            {
                                today = i;
                                break;
                            }
                            else if (today != i)
                                return;  //  wrong 1
                        }
                    }
                
                else if (name[man][word][1] != ' ' && name[man][word][0] == 'I' && name[man][word][5] != 'n')
                {
                    for (i=0; i<m; i++)
                        if (!putin(i, i==man ? 1 : 0))
                            return;
                }
                
                else if (name[man][word][1] != ' ' && name[man][word][0] == 'I' && name[man][word][5] == 'n')
                {
                    
                }
            }
        }
        if (strcmp(lastcriminal, thiscriminal) == 0 || lastcriminal[0]=='-')
        {
            strcpy(lastcriminal, thiscriminal);
            found++;
        }
        
    }
}
int main()
{
    int i,peo;
    char sub[22],a;
    cin >> m >> n >> p;
    for (i=0; i<m; i++)
    {
        cin >> name[i][0];
        lie[i] = wn[i] = 0;
    }
    for (i=0; i<m; i++)
    {
        cin >> sub;
        sub[strlen(sub)-1] = '\0';
        peo = search(sub);
        a = getchar();
        cin.getline(name[peo][++wn[peo]], 250);
    }
    
    return 0;
}
