#include <iostream>
#include <cstddef>

using namespace std;	

class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            }
            else {
                Node* cur;
                if(data <= root->data){
                    cur = insert(root->left, data);
                    root->left = cur;
                }
                else{
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
		

		/*The tree node has data, left child and right child 
		class Node {
		    int data;
		    Node* left;
		    Node* right;
		};

		*/
		    int height(Node* root) {
		        // Write your code here.
		        int lh = 0;
		        int rh = 0;
		        Node *prtR = root;
        
		        if (root == NULL)
		            return 0;

		        else {  
		            lh = height (prtR->left);
		            rh = height (prtR->right);
		        }
		        if (rh>rh)return (rh+1);
		        else return (lh+1);
		    }
		
		}; //End of Solution

		int main() {
		    Solution myTree;
		    Node* root = NULL;
		    int t;
		    int data;

		    cin >> t;

		    while(t-- > 0){
		        cin >> data;
		        root = myTree.insert(root, data);
		    }
		    int height = myTree.height(root);
		    cout << height;

		    return 0;
		}

		