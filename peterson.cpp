#include<bits/stdc++.h>
using namespace std;

struct NODE{
    string word;
    string meaning;
    NODE *RC;
    NODE *LC;
};
class BST{
  private:
    NODE *root;
  public:
    BST(){
        root=NULL;
    }
    void addnode(string word,string meaning){
        NODE *p=new NODE;
        p->word=word;
        p->meaning=meaning;
        p->RC=NULL;
        p->LC=NULL;
        if(root==NULL)
            root=p;
        else{
            NODE *cur=root,*f;
            while(cur){
                f=cur;
                if(cur->word==word){
                    cout<<"Duplicate Word!!\n";
                    return ;
                }
                else if(cur->word>word)
                        cur=cur->LC;
                    else if(cur->word<word)
                            cur=cur->RC;
            }
            if(f->word<word){
                    f->RC=p;
            }
            else{
                f->LC=p;
            }
        }
    }
    void displaynode(NODE *t){
       
        if(t){
            displaynode(t->LC);
            cout<<t->word<<"::"<<t->meaning<<endl;
            displaynode(t->RC);
        }
    }
    NODE *getroot(){
        return root;
    }
    void updatenode(string word){
        if(root==NULL){
            cout<<"Tree is empty!!\n";
            return;
        }
        NODE *cur=root;
        while(cur){
            if(cur->word==word){
                cout<<"Enter a new meaning ::";
                cin>>cur->meaning;
                return;
            }
            else if(cur->word<word)
                cur=cur->RC;
            else if(cur->word>word)
                cur=cur->LC;
        }
        cout<<"No word found!!\n";
        
    }
    void searchnode(string word){
        if(root==NULL){
            cout<<"Tree is empty!!\n";
            return;
        }
        NODE *cur=root;
        int count=0;
        while(cur){
            count++;
            if(cur->word==word){
                cout<<"Word found!!! in"<<count<<"iterations\n";
                cout<<cur->word<<"::"<<cur->meaning;
                return;
            }
            else if(cur->word<word){
                cur=cur->RC;
            }
            else 
                cur=cur->LC;
        }
        cout<<"Word Not Found!!\n";
        
    }
    void deletenode(NODE *d){
        if(d){
            deletenode(d->LC);
            deletenode(d->RC);
            delete d;
        }
    }
    void setrootnull(){
       root=NULL;
    }
};

int main(){
    BST b1;
    int choice=0;
    string word,meaning;
    while(choice !=8){
         cout<<"Enter the choice \n1->add Node::\n2->Display node::\n3->update node::\n4->search node::\n5Delete BST\n8->exit::";
         cin>>choice;
         switch(choice){
             case 1:{
                
                cout<<"Enter the word and it's meaning :: ";
                cin>>word>>meaning;
                b1.addnode(word,meaning);
                break;
             }
            case 2:{
                 cout<<"**************Displaying output********************"<<endl;
                b1.displaynode(b1.getroot());
                break;
            }
            case 3:{
                cout<<"Enter the word:: ";
                cin>>word;
                b1.updatenode(word);
                break;
                
            }
            case 4:{
                cout<<"Enter the word to search::";
                cin>>word;
                b1.searchnode(word);
                break;
            }
            case 5:{
                b1.deletenode(b1.getroot());
                b1.setrootnull();
                cout<<"Tree deleted successfully!!!\n";
                break;
            }
            case 8:{
                choice=8;
                break;
         }
         }
    }
    return 0;
}