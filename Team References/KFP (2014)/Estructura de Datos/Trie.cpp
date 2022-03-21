 # include <cstdio>
 # include <cstring>
 using namespace std;

 int n, q, i, j, ls, sol;
 char s[505];

 struct Trie{
    Trie *son[255];
    int end;
 }T, *p = &T;

 int main(){

    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%s", &s);
        ls = strlen(s);
        p = &T;
        for(j = 0; j < ls; j++){
            if(p -> son[s[j]] == NULL)
                p -> son[s[j]] = new Trie();
            p = p -> son[s[j]];
        }
    }

   
 scanf("%d", &q);
    for(i = 1; i <= q; i++){
        scanf("%s", &s);
        ls = strlen(s);
        p = &T;
        for(j = 0; j < ls; j++){
            if(p -> son[s[j]] == NULL)
                break;
            p = p -> son[s[j]];
            if(j == ls-1)
                sol++;
        }
    }

    printf("%d", sol);
 return 0;
 }
