//
//  treemm.h
//  CS32_PnetPhlix
//
//  Created by Gregory Payton on 3/11/23.
//

#ifndef TREEMULTIMAP_INCLUDED
#define TREEMULTIMAP_INCLUDED
#include <list>


template <typename KeyType, typename ValueType>
class TreeMultimap
{
  public:
    class Iterator
    {
      public:
        Iterator()
        {
            m_object = nullptr;
        }
        Iterator(std::list<ValueType>* p){
            m_object = p;
            it = (*m_object).begin();
        }

        ValueType& get_value() const
        {
            return (*it);
        }

        bool is_valid() const
        {
            if(m_object!= nullptr && it != (*m_object).end()) return true;
            else return false;
        }

        void advance()
        {
            it++;
        }

      private:
        std::list<ValueType>* m_object;
        typename std::list<ValueType>::iterator it;
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
        Node* ptr_to_key_node = findHelper(key, m_root);
        if(ptr_to_key_node == nullptr) return Iterator();
        //This line is kind of confusing, it's getting the address of vector stored in the node
        else return Iterator(&(ptr_to_key_node->m_vals));
    }

  private:
    
    struct Node{
        
        Node(KeyType key, ValueType val){
            m_key = key;
            m_vals.push_back(val);
        }
        
        KeyType m_key;
        std::list<ValueType> m_vals;
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
    
    Node* findHelper(const KeyType& key, Node* curr) const{
        //This helper function will return a pointer to the Node, if the key is found, otherwise it will return nullptr
        if(curr == nullptr) return nullptr;
        else if(key == curr->m_key) return curr;
        else if(key < curr->m_key) return findHelper(key, curr->left);
        else return findHelper(key, curr->right);
    }
};

#endif // TREEMULTIMAP_INCLUDED

