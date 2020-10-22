bool abc(Node *root,int n,vector<Node*> &v)
{
 if(root==NULL)
 return false;
 v.push_back(root);
 if(root->data==n)
 return true;
 if((root->left && abc(root->left,n,v))||(root->right && abc(root->right,n,v)))
 {
     return true;
 }
 v.pop_back();
 return false;
}

Node* lca(Node* root ,int n1 ,int n2 )
{
 vector<Node * >v1,v2;
  if ( abc(root,n1,v1)==false || abc(root,n2,v2)==false) 
          return NULL; 
  
    
int i; 
    for (i = 0; i < v1.size() && i < v2.size() ; i++) 
        if (v1[i] !=v2[i]) 
            break; 
    return v1[i-1]; 
}
int pqr(Node *root,int n,int h)
{
    if(root==NULL)
    return -1;
    if(root->data == n)
    return h;
    else
    {
       int t=pqr(root->left,n,h+1);
        return (t!=-1)?t:pqr(root->right,n,h+1);
        
    }
}
int findDist(Node* root, int a, int b) 
{
    int h1=0,h2=0;
Node *temp=lca(root,a,b);
int x=pqr(temp,a,h1);
int y=pqr(temp,b,h2);
return x+y;
}
