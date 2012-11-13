/*
Progam to implement a binary Search tree
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
  void inorder(node *);
  void preorder(node *);
  void postorder(node *);
  node* btdel(node *, int);
};

void inserttree(node *n, int d)
{
   
   node *temp, *back, *l=n;
   temp = new  node;
   temp->d = d;
   
   while(l!=NULL)
   {
      back=l;
      if(l->d>=d)
        l=l->llink;
      else
        l=l->rlink;
   }
   if(back->d>=d)
      back->llink = temp;
   else
      back->rlink = temp;
      
   
}

void BIN_TREE::manip()
{
   char ch;
   int d;
   
   cout<<"\n\nCreate tree first \n\n";
   this->root=new node;
   cout<<"Enter data :";
   cin>>d;
   root->d=d;
   cout<<"Enter more(y/n) :";
   cin>>ch;
   while(ch=='y')
   {
   
   cout<<"Enter data :";
   cin>>d;
   inserttree(root,d);
   cout<<"Enter more(y/n) :";
   cin>>ch;
   }
   int o;
   do
   {
      cout<<"\n\n1.Inorder\t2.Pre order \t3.Post Order\t4.Delete\t5.Exit  :";
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
      case 4:cout<<"\n\nEnter data to be deleted :";
      cin>>d;
      root = btdel(root,d);
      break;
      }
   }while(o<5);
}



void BIN_TREE::inorder(node *n)
{
   if(n==NULL)
   {
      cout<<"Empty tree";
      return;
   }
   if(n->llink!=NULL)
      inorder(n->llink);

   cout<<n->d<<" ";

   if(n->rlink!=NULL)
      inorder(n->rlink);
}

void BIN_TREE::preorder(node *n)
{

   if(n==NULL)
   {
      cout<<"Empty tree";
      return;
   }
   cout<<n->d<<" ";

   if(n->llink!=NULL)
      preorder(n->llink);
   if(n->rlink!=NULL)
      preorder(n->rlink);

}

void BIN_TREE::postorder(node *n)
{
   if(n==NULL)
   {
      cout<<"Empty tree";
      return;
   }
   if(n->llink!=NULL)
      postorder(n->llink);
   if(n->rlink!=NULL)
      postorder(n->rlink);
   cout<<n->d<<" ";
}

node* BIN_TREE::btdel(node *n, int d)
{
   node *temp;
   if(n==NULL)
   {
      cout<<"Element not found";
   }
   else if (d < n->d)
   {
      n->llink = btdel(n->llink, d);
   }
   else if(d > n->d)
   {
      n->rlink = btdel(n->rlink, d);
   }
   else
   {
      if(n->llink &&  n->rlink)
      {
         //find min of right subtree and repalce current node value with that min value
         temp = n->rlink;
         while(temp->llink != NULL)
             temp = temp->llink;
         n->d = temp->d;
         //after replacing value of current node delete the min value node in right subtree
         n->rlink = btdel(n->rlink , temp->d);
      }
      else
      {
          temp = n;
          if(n->llink == NULL)
            n = n->rlink;
          else
            n = n->llink;
          delete(temp);
      }
   }
   return n;
}

int main()
{
   
   BIN_TREE b;
   b.manip();
   return 0;
}

