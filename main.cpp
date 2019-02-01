#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <string>
using namespace std;

class LLNode{
  public:
    char data[2];
    LLNode *next;
};

class Node{
  public:
    char data[2];
    LLNode *head;
    bool flag;
};

int compare(char a[], char b[])
{
   int c = 0;

   while (a[c] == b[c]) {
      if (a[c] == '\0' || b[c] == '\0')
         break;
      c++;
   }

   if (a[c] == '\0' && b[c] == '\0')
      return 0;
   else
      return -1;
}

void traverse(vector<Node *> vec){
    stack <string> s;
    map<string, bool> visited;
    int i = 0;
    while(i<vec.size()){
        visited.insert(pair<string, bool>(vec[i]->data, false));
        i++;
    }
    s.push(vec[0]->data);
    while(!s.empty()){
        string c =  s.top();
        s.pop();
        if(!visited[c]){
            cout<<c<<"->";
            visited[c] = true;
        }
        i=0;
        char x[2];
        x[0] = c[0];
        x[1] = c[1];
        x[2] = '\0';
        while(compare(vec[i]->data,x) != 0){
            i++;
        }
        LLNode* temp = vec[i]->head;
        while(temp!=NULL){
            if(!visited[temp->data]){
                s.push(temp->data);
            }
            temp = temp->next;
        }
    }
}

int main()
{
    vector<Node *> vec;
    char stopper = 'y';
    while(stopper == 'y'){
        if(vec.size()==0){
            Node* node = new Node();
            cout<<"Enter node name(Length of input = 2 e.g. S1,S2...) : ";
            cin>>node->data;
            node->head = NULL;
            node->flag = 1;
            vec.push_back(node);
        }
        else{
            Node* node = new Node();
            cout<<"Enter node name(Length of input = 2 e.g. S1,S2...) : ";
            cin>>node->data;
            node->head = NULL;
            node->flag = 1;
            vec.push_back(node);
            char parent[2];
            char par = 'y';
            while(par == 'y'){
                cout<<"Parent node : ";
                cin>>parent;
                int i = 0;
                while(compare(vec[i]->data,parent) != 0){
                    i++;
                }
                vec[i]->flag = 0;
                LLNode* temp = new LLNode();
                temp->data[0] = node->data[0];
                temp->data[1] = node->data[1];
                temp->data[2] = node->data[2];
                temp->next = vec[i]->head;
                vec[i]->head = temp;
                cout<<"Any other parent?[y/n] : ";
                cin>>par;
                while(par!='y'&&par!='n'){
                    cout<<"Invalid Input, Enter again : ";
                    cin>>par;
                }
            }
        }
        cout<<"Do you want to enter any more node?[y/n] : ";
        cin>>stopper;
        while(stopper!='y'&&stopper!='n'){
            cout<<"Invalid Input, Enter again : ";
            cin>>stopper;
        }
    }
    int i = 0;
    while(i<vec.size()){
        if(vec[i]->flag == 1){
            cout<<vec[i]->data<<endl;
        }
        if(vec[i]->head!=NULL){
            LLNode* temp = vec[i]->head;
            cout<<vec[i]->data;
            while(temp!=NULL){
                cout<<"->"<<temp->data;
                temp = temp->next;
            }
            cout<<endl;
        }
        i++;
    }
    cout<<endl<<endl<<"Traversing from start to end using stack(DFS) : "<<endl;
    traverse(vec);
    cout<<endl<<endl;
    return 0;
}
