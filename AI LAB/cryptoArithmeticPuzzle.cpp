#include <bits/stdc++.h>
using namespace std;

vector<int> use(10);


struct node
{
    char c;
    int v;
};


int validate(node* nodeArr, const int cnt, string s1,
          string s2, string s3)
{
    int v1 = 0, v2 = 0, v3 = 0, m = 1, j, i;


    for (i = s1.length() - 1; i >= 0; i--)
    {
        char ch = s1[i];
        for (j = 0; j < cnt; j++)
            if (nodeArr[j].c == ch)
                break;

        v1 += m * nodeArr[j].v;
        m *= 10;
    }
    m = 1;


    for (i = s2.length() - 1; i >= 0; i--)
    {
        char ch = s2[i];
        for (j = 0; j < cnt; j++)
            if (nodeArr[j].c == ch)
                break;

        v2 += m * nodeArr[j].v;
        m *= 10;
    }
    m = 1;

    for (i = s3.length() - 1; i >= 0; i--)
    {
        char ch = s3[i];
        for (j = 0; j < cnt; j++)
            if (nodeArr[j].c == ch)
                break;

        v3 += m * nodeArr[j].v;
        m *= 10;
    }

    if (v3 == (v1 + v2))
        return 1;


    return 0;
}


bool permutation(const int cnt, node* nodeArr, int n,
                 string s1, string s2, string s3)
{

    if (n == cnt - 1)
    {


        for (int i = 0; i < 10; i++)
        {


            if (use[i] == 0)
            {


                nodeArr[n].v = i;


                if (validate(nodeArr, cnt, s1, s2, s3) == 1)
                {
                    cout << "\nSolution found: \n  ";
                    for(int l=0; l<s1.size(); l++)
                    {
                        for (int j = 0; j < cnt; j++)
                        {
                            if(nodeArr[j].c==s1[l])
                            {
                                cout << nodeArr[j].v<<" ";
                                break;
                            }
                        }
                    }
                    cout << endl;
                    cout << "  ";
                    for(int l=0; l<s2.size(); l++)
                    {
                        for (int j = 0; j < cnt; j++)
                        {
                            if(nodeArr[j].c==s2[l])
                            {
                                cout << nodeArr[j].v<<" ";
                                break;
                            }
                        }
                    }
                    cout << endl;
                    cout << "--------------\n";
                    for(int l=0; l<s3.size(); l++)
                    {
                        for (int j = 0; j < cnt; j++)
                        {
                            if(nodeArr[j].c==s3[l])
                            {
                                cout << nodeArr[j].v<<" ";
                                break;
                            }
                        }
                    }
                    cout << endl;
                    cout << endl;
                    for (int j = 0; j < cnt; j++)
                        cout << " " << nodeArr[j].c << " = "
                             << nodeArr[j].v;
                    return true;
                }
            }
        }
        return false;
    }

    for (int i = 0; i < 10; i++)
    {


        if (use[i] == 0)
        {

            nodeArr[n].v = i;


            use[i] = 1;


            if (permutation(cnt, nodeArr, n + 1, s1, s2, s3))
                return true;

            use[i] = 0;
        }
    }
    return false;
}

bool solveCryptographic(string s1, string s2,
                        string s3)
{

    int cnt = 0;


    int l1 = s1.length();
    int l2 = s2.length();
    int l3 = s3.length();

    vector<int> freq(26);

    for (int i = 0; i < l1; i++)
        ++freq[s1[i] - 'a'];

    for (int i = 0; i < l2; i++)
        ++freq[s2[i] - 'a'];

    for (int i = 0; i < l3; i++)
        ++freq[s3[i] - 'a'];


    for (int i = 0; i < 26; i++)
        if (freq[i] > 0)
            cnt++;


    if (cnt > 10)
    {
        cout << "Invalid strings";
        return 0;
    }


    node nodeArr[cnt];


    for (int i = 0, j = 0; i < 26; i++)
    {
        if (freq[i] > 0)
        {
            nodeArr[j].c = char(i + 'a');
            j++;
        }
    }
    return permutation(cnt, nodeArr, 0, s1, s2, s3);
}


int main()
{
    string s1 ;
    string s2 ;
    string s3 ;
    cout<<"Enter first string : "<<endl;
    cin>>s1;
    cout<<"Enter second string : "<<endl;
    cin>>s2;
    cout<<"Enter answer string : "<<endl;
    cin>>s3;

    if (solveCryptographic(s1, s2, s3) == false)
        cout << "No solution";
    return 0;
}