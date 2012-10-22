/*
Progam to implement a binary tree
*/


#include<iostream>
using namespace std;

class node
{
   public:
   int d;
   node *llink;
   node *rlink;
   node()
   {
     d=0;
     llink=rlink=NULL;
   }
};

class BIN_TREE
{
  node *root;
  public:
  BIN_TREE()
  {
    root=NULL;
  }
  void manip();
  void cretree(node *);
  void inorder(node *);
  void preorder(node *);
  void postorder(node *);
};

void BIN_TREE::cretree(node* n)
{
  char ch;
  cout<<"\nEnter data :";
  cin>>n->d;
  cout<<"\nDoes "<<n->d<<" has left child(y/n) :";
  cin>>ch;
  if(ch=='y')
  {
    n->llink=new node;
    cretree(n->llink);
  }
  cout<<"\nDoes "<<n->d<<" has right child(y/n) :";
  cin>>ch;
  if(ch=='y')
  {
    n->rlink=new node;
    cretree(n->rlink);
  }
}
void BIN_TREE::manip()
{
   cout<<"\n\nCreate tree first \n\n";
   this->root=new node;
   cretree(this->root);
   int o;
   do
   {
      cout<<"\n\n1.Inorder\t2.Pre order \t3.Post Order\t4.Exit  :";
      cin>>o;
      switch(o)
      {
      case 1:cout<<"\n\n";
      inorder(root);
      break;
      case 2:cout<<"\n\n";
      preorder(root);
      break;
      case 3:cout<<"\n\n";
      postorder(root);
      break;
      }
   }while(o<4);
}



void BIN_TREE::inorder(node *n)
{
   if(n->llink!=NULL)
      inorder(n->llink);

   cout<<n->d<<" ";

   if(n->rlink!=NULL)
      inorder(n->rlink);
}

void BIN_TREE::preorder(node *n)
{

   cout<<n->d<<" ";

   if(n->llink!=NULL)
      preorder(n->llink);
   if(n->rlink!=NULL)
      preorder(n->rlink);

}

void BIN_TREE::postorder(node *n)
{
   if(n->llink!=NULL)
      postorder(n->llink);
   if(n->rlink!=NULL)
      postorder(n->rlink);
   cout<<n->d<<" ";
}

int main()
{
   
   BIN_TREE b;
   b.manip();
   return 0;
}

