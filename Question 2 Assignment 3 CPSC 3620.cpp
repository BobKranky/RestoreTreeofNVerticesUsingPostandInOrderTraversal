// Hasan Raza
// Algorithm to Restore a Tree of N Vertices When only PostOrder and InOrder traversal is known.\

#include <iostream>
#include <vector>

const std::vector<int> postOrder = {4, 5, 2, 6, 3, 1};
const std::vector<int> inOrder = {4, 2, 5, 1, 3, 6};

// Tree Representation
//            1
//         /    \
//        2      3
//      /   \      \
//     4     5       6

// Subtree Vectors
std::vector<int> leftSubtree;
std::vector<int> rightSubtree;
std::vector<int> postLeftSubtree;
std::vector<int> postRightSubtree;

// Pre order traversal storage
std::vector<int> preOrderTraversal;

// Function to split the inorder array into left and right subtrees
void SplitInOrder(std::vector<int> tree, std::vector<int> pOrder, int* rootPointer)
{
    int root = pOrder.back();   // Root node will always be the rightmost node in the Post Order

    if (rootPointer != nullptr) {
        *rootPointer = root;
    }
    int leftSize = 0;
    // Find the index of the root in the inOrder array
    for (int i = 0; i < tree.size(); i++)
    {
        if (tree[i] == root)
        {
            leftSize = i;
            break;
        }
    }

    // Creating local copies of subtrees so that they are not overrided in recursive calls
    std::vector<int> localLeftSubtree;
    std::vector<int> localPostLeftSubtree;
    std::vector<int> localRightSubtree;
    std::vector<int> localPostRightSubtree;

    // Fill local left subtree
    for (int i = 0; i < leftSize; i++)
    {
        localLeftSubtree.push_back(tree[i]);
        localPostLeftSubtree.push_back(pOrder[i]);
    }

    // Fill local right subtree
    for (int i = leftSize + 1; i < tree.size(); i++)
    {
        localRightSubtree.push_back(tree[i]);
    }

    // Fill local postRightSubtree by matching nodes in postOrder with right subtree
    for (int i = 0; i < pOrder.size(); i++)
    {
        for (int j = 0; j < localRightSubtree.size(); j++)
        {
            if (pOrder[i] == localRightSubtree[j])
            {
                localPostRightSubtree.push_back(pOrder[i]);
            }
        }
    }
    // Once leaf nodes have been found, Output them alongside the pre order traversal.
    if (localPostLeftSubtree.size()==1 && localPostRightSubtree.size()==0 )
    {
        std::cout << "Root node is " << root << " has a single branch with root of: " << localPostLeftSubtree.back() << std::endl;
        preOrderTraversal.push_back(root);
        preOrderTraversal.push_back(localPostLeftSubtree.back());
    }
    else if (localPostLeftSubtree.size()==0 && localPostRightSubtree.size()==1 )
    {
        std::cout << "Root node is " << root << " has a single branch with root of: " << localPostRightSubtree.back() << std::endl;
        preOrderTraversal.push_back(root);
        preOrderTraversal.push_back(localPostRightSubtree.back());
    }
    else if(localPostLeftSubtree.size() == 1 && localPostRightSubtree.size()==1 )
    {
        std::cout << "Root node is " << root << " has a left branch with a child, " << localPostLeftSubtree.back() << ", and right branch with child of " << localPostRightSubtree.back() << std::endl;
        preOrderTraversal.push_back(root);
        preOrderTraversal.push_back(localPostLeftSubtree.back());
        preOrderTraversal.push_back(localPostRightSubtree.back());
    }
    else
    {
        std::cout << "Root node is " << root << " has a left branch with a child, " << localPostLeftSubtree.back() << ", and right branch with child of " << localPostRightSubtree.back() << std::endl;
    }

    // Recursive calls with local subtrees
    if (localLeftSubtree.size() > 1)
    {
        SplitInOrder(localLeftSubtree, localPostLeftSubtree, rootPointer);
    }

    if (localRightSubtree.size() > 1)
    {
        SplitInOrder(localRightSubtree, localPostRightSubtree, rootPointer);
    }
}

int main()
{
    // Setting up pointer
    int* rootPointer = nullptr;
    rootPointer = new int;

    // Calling SplitInOrder to process the given inOrder and postOrder
    preOrderTraversal.push_back(postOrder.back());
    SplitInOrder(inOrder, postOrder, rootPointer);

    std::cout << "The preorder traversal is: ";
    for (int i = 0; i < preOrderTraversal.size(); i++)
    {
        std::cout << preOrderTraversal.at(i) << " ";
    }
    return 0;
}

//Output below

// Root node is 1 has a left branch with root of: 2 and right branch with root of 3
// Root node is 2 has a left branch with root of: 4 and right branch with root of 5
// Root node is 3 has a single branch with root of: 6
// The preorder traversal is: 1 2 4 5 3 6
