#include <bits/stdc++.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;
const int RAN = 1e6 + 5;


struct par{
       int id, val;
       bool operator<(const par &rr){
         return rr.val > val;
       }
};

struct proyect{
       string name;
       int id, d, s, b, r;
       bool operator<(const proyect &rr){
         return rr.s > s;
       }
}pro[RAN];

int c, p, n, d, s, b, r, val, skill = 0;
char name_skill[250], name_p[250];

map <string, int> m;
vector <par> v[RAN], v1[RAN];
vector <par> sk[1000005];
bool mar[RAN];

string name[RAN];

int con=0;
string soll;

vector <int> aa;

int myrandom (int i) { return std::rand()%i;}

int poss[RAN];

int main(){

    std::srand ( unsigned ( std::time(0) ) );

    freopen ("f.txt", "r", stdin);
    freopen ("f_out.txt", "w", stdout);

    scanf ("%d%d", &c, &p);
    for (int i = 0; i < c; ++i){
         aa.push_back(i);
         scanf ("%s %d", name_p, &n);
         name[i] = (string)name_p;
         //printf ("%s %d\n", name_p, n);
         for (int j = 0; j < n; ++j){
              scanf ("%s %d", name_skill, &val);
              string s = (string)name_skill;
              if (!m.count(s))
                   m[s] = ++skill;

              v[i].push_back((par){m[s], val});
              sk[m[s]].push_back ((par){i, val});
              //printf ("%d %d\n", m[s], val);
         }
    }


    for (int i = 0; i < p; ++i){
         scanf ("%s %d %d %d %d", &name_p, &d, &s, &b, &r);
         string name = (string)name_p;
         pro[i] = (proyect){name, i, d, s, b, r};
         //printf ("%s %d\n", name_p, n);
         for (int j = 0; j < r; ++j){
              scanf ("%s %d", name_skill, &val);
              string s = (string)name_skill;
              if (!m.count(s))
                   m[s] = ++skill;
              //printf ("%s %d %d\n", name_p, m[s], val);
              v1[i].push_back((par){m[s], val});
         }
    }

    for (int i = 0; i < skill; ++i) sort (sk[i].begin(), sk[i].end());

    //sort (pro, pro + p);
    random_shuffle (pro, pro + p, myrandom);
   //for (auto u : aa) printf ("%d\n", u);

   // for (auto i : aa){
   for (int i = 0; i < p; ++i){
          int id = pro[i].id;
          d = pro[i].d;
          s = pro[i].s;
          b = pro[i].b;
          r = pro[i].r;
          vector <int> sol;

         for (int j = 0; j < r; ++j){
              int id_ = v1[id][j].id;
              int val = v1[id][j].val;
              random_shuffle (sk[id_].begin(), sk[id_].end(), myrandom);
              bool marr = false;
              for (int k = 0; k < (int)sk[id_].size(); ++k){
                   ++poss[id_];
                   if (sk[id_][k].val >= val && !mar[sk[id_][k].id]){

                       sol.push_back (sk[id_][k].id);
                       mar[sk[id_][k].id] = true;
                       marr = true;
                       break;
                   }
              }
         }

         if (r == (int)sol.size()){
            con++;
            soll = soll + pro[i].name + '\n';
            soll = soll + name[sol[0]];
           // printf ("%s\n%s\n", pro[i].name.c_str(), name[sol[0]].c_str());
            for (int k = 1; k < (int)sol.size(); ++k){
                 soll = soll + ' ' + name[sol[k]];
                 //printf ("%d %s\n", i, name[sol[k]].c_str());
            }
            soll = soll + '\n';

         }
        for (auto u : sol)
             mar[u] = false;
        sol.clear();
    }
   // printf ("--------------\n\n");

    printf ("%d\n%s", con, soll.c_str());


    return 0;
}
