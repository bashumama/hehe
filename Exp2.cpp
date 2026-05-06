#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

struct NODE{
    char data;
    NODE *RC;
    NODE *LC;
};

class Exptree{
    private:
        NODE *root;
        stack<NODE *>s;
        char exp[20];
    public: 
        Exptree(){root=NULL;}
        void readexp(){
            cout<<"Enter the expression::";
            cin>>exp;       
        }
        void printexp(){
            cout<<exp<<endl;
        }
        bool isoperand(char token){
            return ((token>='a' && token<='z') || (token>='A' && token<='Z' ));
        }
         bool isoperator(char token){
            return (token=='+' ||token=='-'||token=='*'||token=='/');
        }
        void gentree(){
          NODE *p;
          for(int i=strlen(exp)-1;i>=0;i--){
            p=new NODE;
            p->data=exp[i];
            p->RC=NULL;
            p->LC=NULL;
            if(isoperand(exp[i])){
                s.push(p);
            }
            else if(isoperator(exp[i])){
                p->LC=s.top();
                s.pop();
                p->RC=s.top();
                s.pop();
                s.push(p);
            }
          }
          root=s.top();
          s.pop();
        }
        void displayexptree(NODE *t){
            if(t){
                displayexptree(t->LC);
                cout<<t->data;
                displayexptree(t->RC);
            }
        }
        NODE *getroot(){
            return root;
        }
        void nonrecdisplay(NODE *root){
            stack<NODE *>stack1;
            stack<NODE *>stack2;
            NODE *p;
            if(root==NULL){
                return;
            }
            stack1.push(root);
            while(!stack1.empty()){
                p=stack1.top();
                stack1.pop();
                stack2.push(p);
            if(p->LC){
                stack1.push(p->LC);
            }
            if(p->RC){
                stack1.push(p->RC);
            }
        }
            while(!stack2.empty()){
                p=stack2.top();
                stack2.pop();
                cout<<p->data<<" ";
            }

        }
};
int main(){
    Exptree e;
   int choice=0;
   while(choice!=6){
        cout<<"Enter the choise::";
        cin>>choice;
        switch(choice){
            case 1:{
                e.readexp();
                break;
            }
            case 2:{
                e.printexp();
                break;
            }
            case 3:{
                e.gentree();
                break;
            }
            case 4:{
                e.displayexptree(e.getroot());
                break;
            }
            case 5:{
                e.nonrecdisplay(e.getroot());
                break;
            }
            case 6:{
                cout<<"Thank you for using our program \n";
                choice=6;
                break;
            }
            default:
                cout<<"wrong choice entered\n";
        }
   }
}