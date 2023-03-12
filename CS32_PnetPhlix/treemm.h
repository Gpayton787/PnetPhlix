//
//  treemm.h
//  CS32_PnetPhlix
//
//  Created by Gregory Payton on 3/11/23.
//

#ifndef TREEMULTIMAP_INCLUDED
#define TREEMULTIMAP_INCLUDED

template <typename KeyType, typename ValueType>
class TreeMultimap
{
  public:
    class Iterator
    {
      public:
        Iterator()
        {
            // Replace this line with correct code.
        }

        ValueType& get_value() const
        {
            throw 1;  // Replace this line with correct code.
        }

        bool is_valid() const
        {
            return false;  // Replace this line with correct code.
        }

        void advance()
        {
            // Replace this line with correct code.
        }

      private:
    };

    TreeMultimap()
    {
        m_root = nullptr;
    }

    ~TreeMultimap()
    {
        delete_all(m_root);
    }

    void insert(const KeyType& key, const ValueType& value)
    {
        //create new node (if not already created
        insertHelper(m_root, key, value);
        
    }

    Iterator find(const KeyType& key) const
    {
        return Iterator();  // Replace this line with correct code.
    }

  private:
    
    struct Node{
        
        Node(KeyType key, ValueType val){
            m_key = key;
            m_vals.push_back(val);
        }
        
        KeyType m_key;
        std::vector<ValueType> m_vals;
        Node* left = nullptr;
        Node* right = nullptr;
    };
    
    Node* m_root;
    
    void delete_all(Node* &curr){
        if(curr == nullptr) return;
        delete_all(curr->left);
        delete_all(curr->right);
        delete curr;
    }
    void insertHelper(Node* &root, KeyType key, ValueType val){
        
        //If list is empty
        if(root == nullptr){
            root = new Node(key, val);
            return;
        }
        //If key has already been inserted
        else if(root->m_key == key){
            root->m_vals.push_back(val);
            return;
        }
        //If key is less than current Node
        if(key < root->m_key){
            //If currs left is empty
            if(root->left == nullptr){
                root->left = new Node(key, val);
                return;
            }
            //Otherwise continue on left subtree
            else insertHelper(root->left, key, val);
        }
        else{
            if(root->right == nullptr){
                root->right = new Node(key, val);
                return;
            }
            else insertHelper(root->right, key, val);
        }
    
    }
};

#endif // TREEMULTIMAP_INCLUDED

