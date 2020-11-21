/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    bool flag;
    node* child[26];
    int value;
    int mx;
    node(){
        flag = false;
        for(int i = 0; i < 26; i ++){
            child[i] = NULL;
        }
        value = -1;
        mx = -1;
    }
} node;

void insert_into_trie(string &s, int value, node *root){
    int len = s.size();
    for(int i = 0; i < len; i ++){
        if(root->child[s[i] - 'a'] == NULL){
            root->child[s[i] - 'a'] = new node();
        }
        root = root->child[s[i] - 'a'];
    }
    root->bool = true;
    root->value = value;
    return;
}
// void get_value(string s, node* root){
//     int len = s.size();
//     for(int i = 0; i < )
// }
int main(){
    int n, q;
    cin >> n >> q;
    string s;
    int value;
    node *root = new node();
    for(int i = 0; i < n; i ++){
        cin >> s >> value;
        insert_into_trie(s, value, root);
    }
    for(int i = 0; i < q; i ++){
        cin >> s;
        cout << -1 << "\n";
    }

    return 0;
}
