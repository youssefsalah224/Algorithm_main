#include<iostream>
using namespace std;

struct node {
  struct node *node1;
  struct node *node2;
  int node1_lenght;
  int node2_lenght ;
  int height;
  int counter ;
  int key;
};
int treehight(struct node *n){
  if(n == NULL){
    return 0;
  }
  else{
    return n->height;
  }
}
struct node* leftRotate(struct node *B){  //tree left rotation
  struct node *A = B->node2;
  struct node *z = A->node1;
  A->node1 = B;
  B->node2 = z;
  B->height = max(treehight(B->node1),treehight(B->node2))+1;
  A->height = max(treehight(A->node1),treehight(A->node2))+1;
  B->node2_lenght = A->node1_lenght;
  A->node1_lenght= (B->node1_lenght+ B->node2_lenght)+1;
  return A;
}
struct node* rightRotate(struct node *y){ //tree right rotation
  struct node *A = y->node1;
  struct node *B = A->node2;
  A->node2 = B;
  B->node1 = B;
  B->height = max(treehight(B->node1),treehight(B->node2))+1;
  A->height = max(treehight(A->node1),treehight(A->node2))+1;
  B->node1_lenght= A->node2_lenght;
  A->node2_lenght = (B->node2_lenght+B->node1_lenght)+1;
  return A;
}

int treebalance(struct node *balance){   //obtain the balance
  if(balance == NULL){
    return 0;
  }
  return treehight(balance->node1) - treehight(balance->node2);
}
struct node* insert(struct node *newnode, int key){ //inserting
  if(newnode == NULL){
    struct node* dum = new node();
    dum->key = key;
    dum->node1 = NULL;
    dum->node2 = NULL;
    dum->height = 1;
    dum->counter = 1;
    dum->node1_lenght= 0;
    dum->node2_lenght = 0;
     return dum;
  }
  if(key == newnode->key)
  {
    newnode->counter+=1;
    return newnode;
  }
  if(key < newnode->key){
    newnode->node1 = insert(newnode->node1,key);
  }
  else if(key > newnode->key){
    newnode->node2 = insert(newnode->node2,key);
  }
  else{
    return newnode;
  }
  newnode->height = max(treehight(newnode->node1),treehight(newnode->node2))+1;
  if(newnode->node2 != NULL ){
  newnode->node2_lenght = (newnode->node2->node2_lenght)+ (newnode->node2->node1_lenght)+1;//update the nodes value
}
  if(newnode->node1 != NULL){
  newnode->node1_lenght= (newnode->node1->node2_lenght)+ (newnode->node1->node1_lenght)+1;//update the nodes value
}
  int balance = treebalance(newnode);
  if(balance > 1 && key < newnode->node1->key){
    return rightRotate(newnode);
  }
  if(balance < -1 && key > newnode->node2->key){
    return leftRotate(newnode);
  }
  if(balance > 1 && key > newnode->node1->key){
    newnode->node1 = leftRotate(newnode->node1);
    return rightRotate(newnode);
  }
  if(balance < -1 && key < newnode->node2->key){
    newnode->node2 = rightRotate(newnode->node2);
    return leftRotate(newnode);
  }
  return newnode;
}

int selectnode(struct node *root,int i){
  if(root == NULL)
  {
    return -1;
  }
  int k = root->node1_lenght+1;
  if(i == k){
    return root->key;
  }
  if(i<k ){
    return selectnode(root->node1,i);
  }
  else{
    return selectnode(root->node2,i - k);
  }
}
int level(struct node *root, int key){

   if(root->key == key){
     return root->node1_lenght+ 1;
   }
   else if ( root->key < key){
     return  (root->node1_lenght)+ 1 + level(root->node2,key);
   }
   else{
     return level(root->node1,key);
   }
}
bool fondnew(struct node *root, int key){
  if(root==NULL){
    return false;
  }
  if(root->key == key){
    return true;
  }
  else if(root->key < key){
    return fondnew(root->node2,key);
  }
  else{
    return fondnew(root->node1,key);
  }
}
int main()
{
  int c;
  cin>>c;
  struct node *root = NULL;
  for(int i=0; i< c;i++)
{
    int k;
    cin>>k;
    if(k==1)
    {
      int key;
      cin>>key;
      root = insert(root,key);
    }
    else if(k==2)
    {
       int key;
       cin>>key;
       if(fondnew(root,key)==false)
        {
         cout<<"output:"<<-1<<endl;
       }
       else
        {
         cout<<"output:"<<level(root,key)<<endl;
       }
     }
  }

}
