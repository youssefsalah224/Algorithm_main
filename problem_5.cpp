#include <bits/stdc++.h>
using namespace std;
  

struct Node
{
public:
    int num;
  
    Node **next;
    Node(int, int);
};
  
Node::Node(int num, int level)
{
    this->num = num;
  
    next = new Node*[level+1];
  
    // Fill next array with 0(NULL)
    memset(next, 0, sizeof(Node*)*(level+1));
};
  
class SkipList
{
private:
    int max_level;
    float P;                                               // P is the fraction of the nodes 
    int level;
    Node *header;
    
public:
    SkipList(int, float);
    int randomLevel();
    Node* createNode(int, int);
    void insert(int);
    void Delete(int);
    int search(int);
    int getLayers();
    void print_All_Layers();
    void printLayer(int a);
   
    
};
  
SkipList::SkipList(int max_level, float P)
{
    this->max_level = max_level;
    this->P = P;
    level = 0;
  
    header = new Node(-1, max_level);
};
  
int SkipList::randomLevel()                       //randomLevel for each node
{
    float r = (float)rand()/RAND_MAX;
    int lvl = 0;
    while (r < P && lvl < max_level)
    {
        lvl++;
        r = (float)rand()/RAND_MAX;
    }
    return lvl;
};
  
Node* SkipList::createNode(int num, int level)
{
    Node *node = new Node(num, level);
    return node;
};
  
  
  
  
  
void SkipList::insert(int num)
{
    Node *current = header;
  
  
    Node *newplace[max_level+1];
    memset(newplace, 0, sizeof(Node*)*(max_level+1));
  

    for (int i = level; i >= 0; i--)
    {
        while (current->next[i] != NULL &&
              current->next[i]->num < num)
            current = current->next[i];
        newplace[i] = current;
    }
  

    current = current->next[0];
    
    if (current == NULL || current->num != num)
    {
        int rlevel = randomLevel();
  

        if (rlevel > level)
        {
            for (int i=level+1;i<rlevel+1;i++)
                newplace[i] = header;
  
            level = rlevel;
        }
  
        Node* n = createNode(num, rlevel);
  
        for (int i=0;i<=rlevel;i++)
        {
            n->next[i] = newplace[i]->next[i];
            newplace[i]->next[i] = n;
        }
        cout << num << "   inserted"<<endl;
    }
};




void SkipList::printLayer(int a)
{
    if (a<=level)
    {
        Node *node = header->next[a];
        cout << "Level " << a << ": ";
        while (node != NULL)
        {
            cout << node->num<<" ";
            node = node->next[a];
        }
        cout << "\n";
    }

};









void SkipList::Delete(int num)
{
    Node *current = header;
  
    Node *newplace[max_level+1];
    memset(newplace, 0, sizeof(Node*)*(max_level+1));

    for(int i = level; i >= 0; i--)
    {
        while(current->next[i] != NULL  &&
              current->next[i]->num < num)
            current = current->next[i];
        newplace[i] = current;
    }
  
    current = current->next[0];
  
    if(current != NULL and current->num == num)
    {

        for(int i=0;i<=level;i++)
        {

            if(newplace[i]->next[i] != current)
                break;
  
            newplace[i]->next[i] = current->next[i];
        }
  
        while(level>0 &&
              header->next[level] == 0)
            level--;
         cout<<num<<"   Deleted "<<endl;
    }
};







  
void SkipList::print_All_Layers()
{
    
    for (int i=0;i<=level;i++)
    {
        Node *node = header->next[i];
        cout << "Level " << i << ": ";
        while (node != NULL)
        {
            cout << node->num<<" ";
            node = node->next[i];
        }
        cout << "\n";
    }
};



int SkipList::getLayers()
{
  int c=0;
    for (int i=0;i<=level;i++)
    {
        Node *node = header->next[i];
        c++;
        while (node != NULL)
        {
            node = node->next[i];
        }
    }
    cout<<" Number of layers = "<<c<<endl;
}





int SkipList::search(int num)
{
    
    Node *current = header;
    int c=0;
    bool flag=false;
  
    for(int i = level; i >= 0; i--)
    {
        
        while(current->next[i] && current->next[i]->num <= num && flag==false)
        
        { 
            c++;
            current = current->next[i];
            if(current && current->num == num)
        
        {
            flag=true;
            cout<<num<<"   Exist and Number of Search Steps = "<<c<<endl;
        }
        
     
            
        }
        
        
        
        
    }
     if(flag==false)
        cout<<" -1 "<<endl;
    current = current->next[0];


    

};

  
int main()
{

    srand((unsigned)time(0));
  
    SkipList skiplist(3, 0.5);
  
    skiplist.insert(2);
    skiplist.insert(10);
    skiplist.insert(15);
    skiplist.insert(16);
    skiplist.insert(96);
    skiplist.insert(91);
    skiplist.insert(89);
    skiplist.insert(86);
    skiplist.insert(71);
    skiplist.insert(31);
    
    skiplist.print_All_Layers();
    
    //int a;
    //cout<<"Enter the layer to print it's Numbers"<<endl;
    //cin>>a;
    // skiplist.printLayer(a);
    
    
    //skiplist.Delete(2);
    //skiplist.print_All_Layers();
   //skiplist.getLayers();
   
  // skiplist.search(31);
  // skiplist.search(100);
  

}
