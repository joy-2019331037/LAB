#include <bits/stdc++.h>

using namespace std;

struct puzzle {
    int blank;
    vector < int > p;

    puzzle () {
        p = vector < int > (9, 0);
    }
};

map < vector < int >, vector < int > > par;
queue < puzzle > q;

void add_to_q (const puzzle &u, const puzzle &p) {
    if (par.count(u.p)) return;
    par[u.p] = p.p;
    q.push (u);
}

int step = 0;
void print_result (const vector < int > &p) {
    if (p != par[p])
        print_result(par[p]);

    cout << "Step " << step++ << ":\n";
    for (int i = 0; i < 9; i++) {
        cout << p[i] << " \n"[i % 3 == 2];
    }
    cout << "\n\n";
}

bool solvability(const puzzle p)
{
    int bugi=0;
    int done[9] = {0};
    for(int i=0;i<9;i++){
        for(int j=p.p[i]-1;j>=0;j--){
            if(!done[j])bugi++;
        }
        done[p.p[i] - 1]++;
    }
    if(bugi%2){
        cout << "Unsolvable!!!" << endl;
        return false;
    }
    else {
        cout << "Solvable !" << endl;
        return true;
    }
}


int main() {
    here1:
    cout << "Enter the 8-Puzzle:\n";
    puzzle p;
    for (int i = 0; i < 9; i++) {
        cin >> p.p[i];
        if (!p.p[i]) p.blank = i;
    }
    par[p.p] = p.p;
    q.push (p);

    puzzle res;
    for (int i = 0; i < 8; i++) 
        res.p[i] = i + 1;
    res.blank = 8;
    
    //.........................
    if(!solvability(p))return 0;
    //.........................

    while (q.size ()) {
        puzzle p = q.front ();
        q.pop ();
        if (p.p == res.p) break;

        if (p.blank % 3 >= 1) {
            puzzle p1;

            p1.blank = p.blank - 1;
            p1.p = p.p;
            swap (p1.p[p.blank], p1.p[p1.blank]);

            add_to_q(p1, p);
        }

        if (p.blank % 3 <= 1) {
            puzzle p1;

            p1.blank = p.blank + 1;
            p1.p = p.p;
            swap (p1.p[p.blank], p1.p[p1.blank]);

            add_to_q(p1, p);
        }

        if (p.blank / 3 >= 1) {
            puzzle p1;

            p1.blank = p.blank - 3;
            p1.p = p.p;
            swap (p1.p[p.blank], p1.p[p1.blank]);

            add_to_q(p1, p);
        }

        if (p.blank / 3 <= 1) {
            puzzle p1;

            p1.blank = p.blank + 3;
            p1.p = p.p;
            swap (p1.p[p.blank], p1.p[p1.blank]);

            add_to_q(p1, p);
        }

    }

    cout << "Here are the steps:\n";

    print_result(res.p);

}
