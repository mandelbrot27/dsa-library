#include<bits/stdc++.h>
using namespace std;

class node{
    public:
       int val=0;
       char label='0';
       node* left;
       node* right;

       node(int x)
       {
           val=x;
           left=NULL;
           right=NULL;
       }
};

struct Comp{
    bool operator()(const node* a, const node* b){
        return a->val>b->val;
    }
};

node* huffman_tree(string s)
{
    map<char,int> cnt;
    for (auto i: s) cnt[i]++;
    priority_queue<node*,vector<node*>,Comp> pq;

    for (auto &[x,y]: cnt)
    {
        node* a = new node(y);
        a->label=x;
        pq.push(a);
    }


    while(pq.size()>1)
    {
        node* a= pq.top();
        pq.pop();
        node* b= pq.top();
        pq.pop();
        node* c= new node(a->val + b->val);

        c->left=a;
        c->right=b;

        pq.push(c);
    }
    
    node* c=pq.top();
    return c;
}

void huffman_code(node* t,map<char,string>& mp,string res="")
{
    node root=*t;
    if (root.label!='0')
    {
        mp[root.label]=res;
        return;
    }

    res.push_back('0');
    huffman_code(root.left,mp,res);
    res.pop_back();

    res.push_back('1');
    huffman_code(root.right,mp,res);
    res.pop_back();


}

int main()
{
    string s; //cin>>s;
    s="aaabbccccccddddddddeeffffff";

    node* t=huffman_tree(s);
    map<char,string> code;

    huffman_code(t,code);
    string res="";
    for(auto i: s)
    {
        res+=code[i];
    }
    cout<<res<<"\n";
}
