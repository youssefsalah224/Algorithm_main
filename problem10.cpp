#include<iostream>
using namespace std;

struct node {

  struct node *node1;
  struct node *node2;
  int node1_lenght ;
  int node2_lenght ;
  int Hight;
  int counter ;
  long int key;
};



int treehight(struct node *n){
  if(n == NULL){
    return 0;
  }
  else{
    return n->Hight;
  }
}
struct node* leftRotate(struct node *B){      // node left notation
  struct node *A = B->node2;
  struct node *C = A->node1;
  A->node1 = B;
  B->node2 = C;

  B->Hight = max(treehight(B->node1),treehight(B->node2))+1;
  A->Hight = max(treehight(A->node1),treehight(A->node2))+1;
  B->node2_lenght = A->node1_lenght;
  A->node1_lenght = (B->node1_lenght + B->node2_lenght)+1;
  return A;

}

struct node* rightRotate(struct node *B){   // node right rotation
  struct node *A = B->node1;
  struct node *C = A->node2;
  A->node2 = B;
  B->node1 = C;
  B->Hight = max(treehight(B->node1),treehight(B->node2))+1;
  A->Hight = max(treehight(A->node1),treehight(A->node2))+1;
  B->node1_lenght = A->node2_lenght;

  A->node2_lenght = (B->node2_lenght+B->node1_lenght)+1;
  return A;
}


int treebalance(struct node *n){
  if(n == NULL){
    return 0;
  }
  return treehight(n->node1) - treehight(n->node2);
}

struct node* insertnode(struct node *n, long int key){
  if(n == NULL){
    struct node* dum = new node();
    dum->key = key;
    dum->node1 = NULL;
    dum->node2 = NULL;
    dum->Hight = 1;
    dum->node1_lenght = 0;
    dum->node2_lenght = 0;
    dum->counter = 1;
    return dum;
  }
  if(key == n->key)
  {                        //increment the counter if key found
    n->counter+=1;
    return n;
  }
  if(key < n->key){
    n->node1 = insertnode(n->node1,key);
  }
  else if(key > n->key){
    n->node2 = insertnode(n->node2,key);
  }
  else{
    return n;
  }
  n->Hight = max(treehight(n->node1),treehight(n->node2))+1;
  if(n->node2 != NULL ){  //right node value
  n->node2_lenght = (n->node2->node2_lenght)+ (n->node2->node1_lenght)+1;
}
  if(n->node1 != NULL){    //left node value
  n->node1_lenght = (n->node1->node2_lenght)+ (n->node1->node1_lenght)+1;
}
  int balance = treebalance(n);
  if(balance > 1 && key < n->node1->key){
    return rightRotate(n);
  }
  if(balance < -1 && key > n->node2->key){
    return leftRotate(n);
  }
  if(balance > 1 && key > n->node1->key){
    n->node1 = leftRotate(n->node1);
    return rightRotate(n);
  }
  if(balance < -1 && key < n->node2->key){
    n->node2 = rightRotate(n->node2);
    return leftRotate(n);
  }


  return n;

}

int selectnode(struct node *node3,long int i){
  if(node3 == NULL)
  {
    return -1;
  }
  int k = node3->node1_lenght+1;

  if(i == k){
    return node3->key;
  }
  if(i<k ){
    return selectnode(node3->node1,i);
  }
  else{
    return selectnode(node3->node2,i - k);
  }
}

int level(struct node *node3, long int key){

   if(node3->key == key){
     return node3->node1_lenght + 1;
   }
   else if ( node3->key < key){
     return  (node3->node1_lenght)+ 1 + level(node3->node2,key);
   }
   else{
     return level(node3->node1,key);
   }

}
bool foundnew(struct node *node3, long int key){
  if(node3==NULL){
    return false;
  }
  if(node3->key == key){
    return true;
  }
  else if(node3->key < key){
    return foundnew(node3->node2,key);
  }
  else{
    return foundnew(node3->node1,key);
  }
}
struct node* getmin(struct node *n){
  struct node *currentnode = n;
  while(currentnode->node1 != NULL){
    currentnode = currentnode->node1;
  }
  return currentnode;
}

struct node* deletenode(struct node* node3, long int key){
  if(node3==NULL){
    return node3;
  }
  if(key < node3->key){

    node3->node1 = deletenode(node3->node1,key);
    node3->node1_lenght-=1;
  }
  else if(key > node3->key){

    node3->node2 = deletenode(node3->node2,key);
    node3->node2_lenght-=1;
  }
  else{
    if((node3->node1 == NULL) || (node3->node2 == NULL)){
      struct node *dum = node3->node1 ? node3->node1 : node3->node2;
      if(dum == NULL){
        dum = node3;
        node3 = NULL;
      }
      else{
        node3 = dum;
      }
    }
    else{
      struct node *dum = getmin(node3->node2);
      node3->key = dum->key;
      node3->node2_lenght = (node3->node2_lenght)-1;
      node3->node2 = deletenode(node3->node2,dum->key);
    }
  }
  if(node3 == NULL){
    return node3;
  }
  node3->Hight = 1 + max(treehight(node3->node1),treehight(node3->node2));
  if(node3->node2 != NULL ){
  node3->node2_lenght = (node3->node2->node2_lenght)+ (node3->node2->node1_lenght)+1;
}
  if(node3->node1 != NULL){
  node3->node1_lenght = (node3->node1->node2_lenght)+ (node3->node1->node1_lenght)+1;
}
  int balance  = treebalance(node3);

  if (balance > 1 && treebalance(node3->node1) >= 0)
        return rightRotate(node3);

    if (balance > 1 && treebalance(node3->node1) < 0)
    {   node3->node1 =  leftRotate(node3->node1);
        return rightRotate(node3);
    }
    if (balance < -1 && treebalance(node3->node2) <= 0)
        return leftRotate(node3);
    if (balance < -1 && treebalance(node3->node2) > 0)
    {
        node3->node2 = rightRotate(node3->node2);
        return leftRotate(node3);
    }
    return node3;

}


int main()
{
 int A;
 long int K;
 int C=0;
 struct node* node3=NULL;

 while(cin>>A)
 {
     if(A==1)
    {
        cin>>K; // list insertation
        node3 = insertnode(node3,K);
    }

    else if(A==2)
    {
        cin>>K;
        node3 = deletenode(node3,K);//deletion

    }
    else if(A==3)
    {
        cin>>K;
        if(!foundnew(node3,K))
            cout<<"result:" <<-1<<endl;
        else
            cout<<"result :" <<level(node3, K)<<endl;
    }
    else if(A==4)
    {
        cin>>K;
        cout<<"result :" <<selectnode(node3, K)<<endl;
    }
    else
        break;
}
}
