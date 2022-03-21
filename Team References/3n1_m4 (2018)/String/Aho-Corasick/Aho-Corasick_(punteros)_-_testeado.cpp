// Aho Corasick

struct node{
    int pos;
    node* fail;
    node* link;
    node* next[26];
    node(){
        pos = -1;fail = link = NULL;
        for (int i = 0; i < 26; i++) next[ i ] = NULL;
    }
};
node* root = new node();

void insert(char* patt, int idx){
    node* curr=root;
    for (int j=0;patt[j];j++){
        if (curr->next[patt[j] - 'a'] == NULL)
            curr->next[patt[j] - 'a'] = new node();
        curr = curr->next[patt[j] - 'a'];
    }
    curr->pos = idx;
}

void aho_corasick(){
    queue<node*> Q;
    for (int i = 0;i<26;i++)
        if ( root->next[i] ){
            root->next[i]->fail = root;
            Q.push( root->next[i] );
        }else root->next[i] = root;
    while ( !Q.empty() ){
        node* t = Q.front(); Q.pop();
        for (int i = 0; i < 26; i++)
            if ( t->next[i] ){
                Q.push( t->next[i] );
                node* r = t->fail;
                while ( !r->next[i] ) r = r->fail;
                t->next[i]->fail = r->next[i];
                if ( r->next[i]->pos != -1 )
                  t->next[i]->link = r->next[i];
                else /////multiple matches in the same node/////
                  t->next[i]->link = r->next[i]->link; 
            }
    }
}

void match(char text[]){

    n = strlen( text );
    node* state = root;
    for (int i = 0; i < n; i++){
        while (state->next[ text[i]-'a' ] == NULL)
            state = state->fail;
        state = state->next[ text[i]-'a' ];

        ///////////////////
        if (state->pos != -1)
        cout<< state->pos<<" found at "<< i << endl;

        for (node* r = state->link; r != NULL; r = r->link)
            cout<< r->pos<<" found in position "<< i << endl;
        ///////////////////
    }
}
