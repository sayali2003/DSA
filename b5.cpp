#include<iostream>
using namespace std;

//-----------------------------------------------------------------
struct node{
    char label[10];
    int count;
    struct node*child[10];
}*root;

class book{
    public:
    void create_tree();
    void display(node*r1);

    book(){
        root=NULL;
    }
};
//------------------------------------------------------------------
void book::create_tree(){
    int books,chapter,i,j,k;
    root=new node;
    cout<<"Enter the name of book:-";
    cin>>root->label;
    cout<<"Enter the number of chapters:-";
    cin>>chapter;
    root->count=chapter;
    for (i = 0; i <chapter; i++)
    {
        root->child[i] = new node;
        cout << "Enter the name of Chapter:- ";
        cin>>root->child[i]->label;
        cout << "Enter number of sections in Chapter :- ";
        cin >> root->child[i]->count;

        for (j = 0; j < root->child[i]->count; j++)
        {
            root->child[i]->child[j] = new node;
            cout << "Enter Section "<<j+1<<" name\n";
            cin>>root->child[i]->child[j]->label;

            for (k = 0; k < root->child[i]->count; k++)
            {
                root->child[i]->child[j]->child[k] = new node;
                cout << "Enter sub-Section "<<k+1<<" name\n";
                cin>>root->child[i]->child[j]->child[k]->label;
            }
        }
    }
}

        
//------------------------------------------------------------------

void book::display(node*r1){
    int i,j,k,tchapters;
    if(r1!=NULL){
        cout<<"------Book hierarchy------"<<endl;
        cout<<"book title:"<<r1->label<<endl;
        tchapters=r1->count;
        for(i=0;i<tchapters;i++){
            cout<<"\nchapter no:-"<<i+1<<endl;
            cout<<r1->child[i]->label;
            cout<<"\nsection :-";
            for(j=0;j<r1->child[i]->count;j++){
                cout<<r1->child[i]->child[j]->label;

                for(k=0;k<r1->child[i]->count;k++){
                cout<<r1->child[i]->child[j]->child[k]->label;
            }
            }
        }
    }
}
//---------------------------------------------------------------------
int main(){
    int choice;
    book gt;
    while(1){
        cout<<"Book tree creation"<<endl;
        cout<<"\n1.create"<<endl;
        cout<<"2.display"<<endl;

        cout<<"enter your choice:";
        cin>>choice;
        switch(choice){
            case 1:
            gt.create_tree();
            break;

            case 2:
            gt.display(root);
            break;

            case 3:
            cout<<"Program ended";
            break;

            default:
            cout<<"Wrong choice"<<endl;
        }
    }
}
//-----------------------------------------------------------------------