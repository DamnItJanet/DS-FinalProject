#ifndef AVLTREE
#define AVLTREE

#include <iostream>

/******************************************************************************/
/*                          TEMPLATED AVL TREE CLASS                          */
/******************************************************************************/
template<class T>
class AvlTree
{
/******************************************************************************/
/*              AVL TREE: PRIVATE MEMBER FUNCTIONS AND VARIABLES              */
/******************************************************************************/
    private:
        /**********************************************************************/
        /*                   TEMPLATED AVL TREE NODE CLASS                    */
        /**********************************************************************/
        template<class t>
        class AvlNode
        {
            public:
                /**************************************************************/
                /*  Default node constructor                                  */
                /*                                                            */
                /*  -- Creates a new AVL node and sets all variables          */
                /**************************************************************/
                AvlNode(const int& theElement,
                        AvlNode<t>* lt, AvlNode<t>* rt, int h = 0)
                    :element(theElement), left(lt), right(rt), height(h) {}

                // Height or depth of the node
                int height;
                // Element pointed to by the node
                t element;
                // Node less than the current node
                AvlNode<t>* left;
                // Node greater than the current node
                AvlNode<t>* right;
        };

        // Root node of the tree, ancestor to all other nodes
        AvlNode<T>* root;

        /**********************************************************************/
        /*  Private insert function                                           */
        /*                                                                    */
        /*  -- Inserts a node into the tree                                   */
        /*  -- Balances the tree afterward if necessary                       */
        /**********************************************************************/
        void insert(const T& val, AvlNode<T>*& rhs)
        {
            if (rhs == nullptr)
                // Makes rhs's element equal to val if rhs is null
                rhs = new AvlNode<T>(val, nullptr, nullptr);
            else if (val < rhs->element)
            {
                // If val is less than rhs, call insert for the left subtree
                insert(val, rhs->left);

                // Balances the tree if subtree heights differ by 2
                if (height(rhs->left) - height(rhs->right) == 2)
                {
                    // Imbalanced case 1
                    if (val < rhs->left->element)
                        rotateWithLeftChild(rhs);
                    // Imbalanced case 2
                    else
                        doubleWithLeftChild(rhs);
                }
            }
            else if (rhs->element < val)
            {
                // If val is greater than rhs, call insert for the right subtree
                insert(val, rhs->right);

                // Balances the tree if subtree heights differ by 2
                if (height(rhs->right) - height(rhs->left) == 2)
                {
                    // Imbalanced case 4
                    if (rhs->right->element < val)
                        rotateWithRightChild(rhs);
                    // Imbalanced case 3
                    else
                        doubleWithRightChild(rhs);
                }
            }

            // Updates the new node's height
            rhs->height = max(height(rhs->left), height(rhs->right)) + 1;
        }

        /**********************************************************************/
        /*  Private findMin function                                          */
        /*                                                                    */
        /*  -- Finds the minimum value in the tree                            */
        /**********************************************************************/
        AvlNode<T>* findMin(AvlNode<T>* rhs) const
        {
            // If the node is null then it returns nullptr
            if (rhs == nullptr)
                return nullptr;
            // If rhs's left child is null, then rhs must be the smallest value
            if (rhs->left == nullptr)
                return rhs;
            // Hasn't found the minimum so it calls itself on the left subtree
            return findMin(rhs->left);
        }

        /**********************************************************************/
        /*  Private findMax function                                          */
        /*                                                                    */
        /*  -- Finds the maximum value in the tree                            */
        /**********************************************************************/
        AvlNode<T>* findMax(AvlNode<T>* rhs) const
        {
            if(rhs != nullptr)
                // Interates through the right subtree of rhs
                while (rhs->right != nullptr)
                    rhs = rhs->right;
            // Once it gets to the end, it returns that last node
            return rhs;
        }

        /**********************************************************************/
        /*  Private lookFor function                                          */
        /*                                                                    */
        /*  -- Looks to see if the specified value is in the tree             */
        /**********************************************************************/
        bool lookFor(const T& val, AvlNode<T>* rhs) const
        {
            if (rhs == nullptr)
                // Returns false if the root is null
                return false;
            else if (val < rhs->element)
                // Looks through the left subtree if val is less than rhs
                return lookFor(val, rhs->left);
            else if (rhs->element < val)
                // Looks through the right subtree if val is less than rhs
                return lookFor(val, rhs->right);
            else
                // Returns true if it finds the value
                return true;
        }

        /**********************************************************************/
        /*  Private copy function                                             */
        /*                                                                    */
        /*  -- Copies the values of one node to another                       */
        /**********************************************************************/
        AvlNode<T>* copy(AvlNode<T>* rhs) const
        {
            if(rhs == nullptr)
                // Makes this node null if rhs is null
                return nullptr;
            else
                // Copies the values of rhs over to the this node
                return new AvlNode<T>(rhs->element, copy(rhs->left),
                                   copy(rhs->right), rhs->height);
        }

        /**********************************************************************/
        /*  Private makeEmpty function                                        */
        /*                                                                    */
        /*  -- Deletes all the nodes in a tree                                */
        /**********************************************************************/
        void makeEmpty(AvlNode<T>*& rhs)
        {
            if (rhs != nullptr)
            {
                // Delete left subtree of rhs
                makeEmpty(rhs->left);
                // Delete right subtree of rhs
                makeEmpty(rhs->right);
                // Delete rhs node
                delete rhs;
            }
            // Set rhs to null
            rhs = nullptr;
        }

        /**********************************************************************/
        /*  Private height function                                           */
        /*                                                                    */
        /*  -- Returns the height of the node or -1 if rhs is null            */
        /**********************************************************************/
        int height(AvlNode<T>* rhs) const
        {
            return rhs == nullptr ? -1:rhs->height;
        }

        /**********************************************************************/
        /*  Private max function                                              */
        /*                                                                    */
        /*  -- Returns the larger of the two values                           */
        /**********************************************************************/
        T max(T lhs, T rhs) const
        {
            return lhs > rhs ? lhs:rhs;
        }

        /**********************************************************************/
        /*  Private single left rotation function                             */
        /*                                                                    */
        /*  -- Case 1: Left subtree of the left child                         */
        /*  -- Rotates tree node with left child                              */
        /*  -- Updates the heights and sets a new root                        */
        /**********************************************************************/
        void rotateWithLeftChild(AvlNode<T>*& k2)
        {
            // New node k1 = k2's left child
            AvlNode<T>* k1 = k2->left;
            // Move k2's left child to be k1's right child
            k2->left = k1->right;
            // Move k1's right child to be k2
            k1->right = k2;

            // Update heights
            k2->height = max(height(k2->left), height(k2->right)) + 1;
            k1->height = max(height(k1->left), height(k1->right)) + 1;
            // Update root
            k2 = k1;
        }

        /**********************************************************************/
        /*  Private single right rotation function                            */
        /*                                                                    */
        /*  -- Case 4: Right subtree of the right child                       */
        /*  -- Rotates tree node with right child                             */
        /*  -- Updates the heights and sets a new root                        */
        /**********************************************************************/
        void rotateWithRightChild(AvlNode<T>*& k2)
        {
            // New node k1 = k2's right child
            AvlNode<T>* k1 = k2->right;
            // Move k2's right child to be k1's left child
            k2->right = k1->left;
            // Move k1's left child to be k2
            k1->left = k2;

            // Update heights
            k2->height = max(height(k2->left), height(k2->right)) + 1;
            k1->height = max(height(k1->left), height(k1->right)) + 1;
            // Update root
            k2 = k1;
        }

        /**********************************************************************/
        /*  Private double left rotation function                             */
        /*                                                                    */
        /*  -- Case 2: Right subtree of the left child                        */
        /*  -- Rotates tree node with right child                             */
        /*  -- Updates the heights and sets a new root                        */
        /*  -- Rotates tree node with left child                              */
        /*  -- Updates the heights and sets a new root                        */
        /**********************************************************************/
        void doubleWithLeftChild(AvlNode<T>*& k1)
        {
            rotateWithRightChild(k1->left);
            rotateWithLeftChild(k1);
        }

        /**********************************************************************/
        /*  Private double right rotation function                            */
        /*                                                                    */
        /*  -- Case 3: Left subtree of the right child                        */
        /*  -- Rotates tree node with left child                              */
        /*  -- Updates the heights and sets a new root                        */
        /*  -- Rotates tree node with right child                             */
        /*  -- Updates the heights and sets a new root                        */
        /**********************************************************************/
        void doubleWithRightChild(AvlNode<T>*& k1)
        {
            rotateWithLeftChild(k1->right);
            rotateWithRightChild(k1);
        }

/******************************************************************************/
/*                      AVL TREE: PUBLIC MEMBER FUNCTIONS                     */
/******************************************************************************/
    public:
        /**********************************************************************/
        /*  Default tree constructor                                          */
        /*                                                                    */
        /*  -- Creates a new AVL tree with a null root                        */
        /**********************************************************************/
        AvlTree():root(nullptr) {}

        /**********************************************************************/
        /*  Tree copy constructor                                             */
        /*                                                                    */
        /*  -- Creates a new AVL tree with the same values as the old tree    */
        /**********************************************************************/
        AvlTree(const AvlTree<T>& rhs):root(nullptr)
        {
            *this = rhs;
        }

        /**********************************************************************/
        /*  Tree destructor                                                   */
        /*                                                                    */
        /*  -- Deletes all data in the tree at the end of the scope           */
        /**********************************************************************/
        ~AvlTree()
        {
            makeEmpty();
        }

        /**********************************************************************/
        /*  Overloaded assignment operator                                    */
        /*                                                                    */
        /*  -- Copies the values of one tree over to another                  */
        /**********************************************************************/
        const AvlTree<T>& operator=( const AvlTree<T>& rhs )
        {
            if(this != &rhs)
            {
                // Empty the tree if isn't the same as rhs
                makeEmpty();
                // Copy rhs's root to this's root
                root = copy(rhs.root);
            }
            return *this;
        }

        /**********************************************************************/
        /*  Public interface lookFor function                                 */
        /*                                                                    */
        /*  -- Calls the private lookFor function that looks to see if the    */
        /*     value is in the tree                                           */
        /**********************************************************************/
        bool lookFor(const T& val) const
        {
            return lookFor(val, root);
        }

        /**********************************************************************/
        /*  Public interface makeEmpty function                               */
        /*                                                                    */
        /*  -- Calls the private makeEmpty function that deletes the values   */
        /*     in the tree                                                    */
        /**********************************************************************/
        void makeEmpty()
        {
            // Calls private function that does all the work
            makeEmpty(root);
        }

        /**********************************************************************/
        /*  Public interface insert function                                  */
        /*                                                                    */
        /*  -- Calls the private insert function that inserts the value into  */
        /*     the tree                                                       */
        /**********************************************************************/
        void insert(const T& val)
        {
            insert(val, root);
        }

        /**********************************************************************/
        /*  Public interface findMin function                                 */
        /*                                                                    */
        /*  -- Calls the private findMin function that looks for the minimum  */
        /*     value in the tree                                              */
        /**********************************************************************/
        const T& findMin() const
        {
            if (isEmpty())
                std::cout << "There are no values in the tree!" << std::endl;
            // Gets the minimum value returned by the private function
            return findMin(root)->element;
        }

        /**********************************************************************/
        /*  Public interface findMax function                                 */
        /*                                                                    */
        /*  -- Calls the private findMax function that looks for the maximum  */
        /*     value in the tree                                              */
        /**********************************************************************/
        const T& findMax() const
        {
            if (isEmpty())
                std::cout << "There are no values in the tree!" << std::endl;
            // Gets the maximum value returned by the private function
            return findMax(root)->element;
        }

        /**********************************************************************/
        /*  Pre-order traversal of the tree                                   */
        /*                                                                    */
        /*  -- Prints the nodes of the tree in a pre-order traversal          */
        /**********************************************************************/
        void printPreOrder(AvlNode<T>* rhs)
        {
            if (rhs != nullptr)
            {
                // Visits the current node
                std::cout << visit(rhs) << std::endl;
                // Prints the left children of the current node
                printPreOrder(rhs->left);
                // Prints the right children of the current node
                printPreOrder(rhs->right);
            }
        }

        /**********************************************************************/
        /*  In-order traversal of the tree                                    */
        /*                                                                    */
        /*  -- Prints the nodes of the tree in an in-order traversal          */
        /**********************************************************************/
        void printInOrder(AvlNode<T>* rhs)
        {
            if (rhs != nullptr)
            {
                // Prints the left children of the current node
                printInOrder(rhs->left);
                // Visits the current node
                std::cout << visit(rhs) << std::endl;
                // Prints the right children of the current node
                printInOrder(rhs->right);
            }
        }

        /**********************************************************************/
        /*  Post-order traversal of the tree                                  */
        /*                                                                    */
        /*  -- Prints the nodes of the tree in a post-order traversal         */
        /**********************************************************************/
        void printPostOrder(AvlNode<T>* rhs)
        {
            if (rhs != nullptr)
            {
                // Prints the left children of the current node
                printPostOrder(rhs->left);
                // Prints the right children of the current node
                printPostOrder(rhs->right);
                // Visits the current node
                std::cout << visit(rhs) << std::endl;
            }
        }

        /**********************************************************************/
        /*  Visit function                                                    */
        /*                                                                    */
        /*  -- Prints the element of specified node                           */
        /**********************************************************************/
        T visit(AvlNode<T>* rhs)
        {
            return rhs->element;
        }

        /**********************************************************************/
        /*                      Getter for the root node                      */
        /**********************************************************************/
        AvlNode<T>* getRoot()
        {
            return root;
        }

        /**********************************************************************/
        /*  isEmpty function                                                  */
        /*                                                                    */
        /*  -- Checks to see if the tree is empty                             */
        /**********************************************************************/
        bool isEmpty() const
        {
            return root == nullptr;
        }
};

#endif // AVLTREE

