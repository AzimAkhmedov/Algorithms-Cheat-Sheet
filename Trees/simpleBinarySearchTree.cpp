    /******************************************************************************
    
                                  Online C++ Compiler.
                   Code, Compile, Run and Debug C++ program online.
    Write your code in this editor and press "Run" button to compile and execute it.
    
    *******************************************************************************/
    
    #include <iostream>
    #include <queue>
    using namespace std;
    struct TreeNode
    {
      int val;
      TreeNode *left;
      TreeNode *right;
    
        TreeNode ()
      {
        val = 0;
        left = nullptr;
        right = nullptr;
      }
      TreeNode (int v)
      {
        val = v;
        left = nullptr;
        right = nullptr;
      }
    
      TreeNode *insort (TreeNode * root, int v)
      {
        if (!root)
          {
    
    	return root = new TreeNode (v);
          }
        if (root->val < v)
          {
    	root->right = insort (root->right, v);
          }
        else if (root->val > v)
          {
    	root->left = insort (root->left, v);
          }
        return root;
      }
      TreeNode *deleteNode (TreeNode * root, int v)
      {
        if (!root)
          return root;
    
    
        if (root->val > v)
          {
    	root->left = deleteNode (root->left, v);
    	return root;
          }
        else if (root->val < v)
          {
    	root->right = deleteNode (root->right, v);
    	return root;
          }
    
        if (root->left == NULL)
          {
    	TreeNode *temp = root->right;
    	delete root;
    	return temp;
          }
        else if (root->right == NULL)
          {
    	TreeNode *temp = root->left;
    	delete root;
    	return temp;
          }
        else
          {
    
    	TreeNode *Parent = root;
    
    	TreeNode *succ = root->right;
    	while (!succ->left)
    	  {
    	    Parent = succ;
    	    succ = succ->left;
    	  }
    
    	if (Parent != root)
    	  Parent->left = succ->right;
    	else
    	  Parent->right = succ->right;
    
    	root->val = succ->val;
    	delete succ;
    	return root;
          }
      }
    
      void inorder (TreeNode * root)
      {
    
        if (root != NULL)
          {
    
    	inorder (root->left);
    	cout << root->val << " ";
    	inorder (root->right);
          }
      }
    
      void preorder (TreeNode * root)
      {
        if (!root)
          return;
        cout << root->val << " ";
        preorder (root->left);
        preorder (root->right);
      } 
      void postorder (TreeNode * root)
      {
        if (!root)
          return;
        postorder (root->left);
        postorder (root->right);
        cout << root->val << " ";
      }
     TreeNode* search(TreeNode* root, int v)
    {
        if (!root  || root->val == v) return root;
     
        if (root->val < v) return search(root->right, v);
     
        return search(root->left, v);
    }
    
        int getMaxLevel(TreeNode *root) {
            if (root == nullptr) { return 0; }
    
            queue<TreeNode *> q;
            q.push(root);
            int level = 0;
    
            while (!q.empty()) {
                int size = q.size();
    
                while (size--) {
                    TreeNode *front = q.front();
                    q.pop();
    
                    if (front->left == nullptr && front->right == nullptr) { return level; }
    
                    if (front->left) { q.push(front->left); }
    
                    if (front->right) { q.push(front->right); }
                }
                level++;
            }
    
            return -1;
        }
    
        int getMinLevel(TreeNode *root) {
            if (root == nullptr) { return 0; }
    
            queue<TreeNode *> q;
            q.push(root);
            int level = 0;
    
            while (!q.empty()) {
                int size = q.size();
    
                while (size--) {
                    TreeNode *front = q.front();
                    q.pop();
    
                    if (front->left == nullptr && front->right == nullptr) { return level; }
    
                    if (front->left) { q.push(front->left); }
    
                    if (front->right) { q.push(front->right); }
                }
                level++;
            }
    
            return -1;
        }
    
    };
    
    int main(){
      TreeNode *root = new TreeNode (10);
      root->insort (root, 50);
      root->insort (root, 30);
      root->insort (root, 20);
      root->insort (root, 90);
      root->insort (root, 60);
      cout<<" Inorder \n";
      
      root->inorder (root);
      cout<<"\n Postorder \n";
      root->postorder(root);
      cout<<"\n Preorder \n";
      root->preorder(root);
      root = root->deleteNode (root, 20);
      cout << endl << " Deleting 20: " << endl;
      root->inorder (root);
      cout<<endl<<"Search: 90 and found: "<<root->search(root, 90)->val<<endl;
      
      cout<<"Min Level: "<<root->getMinLevel(root)<<endl;
      cout<<"Max Level: "<<root->getMaxLevel(root)<<endl;
      return 0;
    }
