# RestoreTreeofNVerticesUsingPostandInOrderTraversal
Let 4 5 2 6 3 1 be the post-order traversal.
Let 4 2 5 1 3 6 be the in-order traversal.
From this, we can immediately discern a few things.
Firstly, the post-order traversal will always end with the root node.
Secondly, the first node will always be the left most leaf node of the tree.
	We can immediately do a few things, firstly, we can get the root node by looking at the post-order traversal and use it to split the in-order traversal down the middle, with all nodes on the left of the root node being in the left sub-tree and all nodes on the right being part of the right sub-tree. Using this knowledge, we can recursively divide the in-order sub tree to find which nodes are leaves and which are roots of the two subtrees. Because we know that all nodes on the left and right of the root node are part of a subtree, we can take a loot at the post-order traversal to find out which of these nodes are root nodes of their respective sub trees. With this, we recursively continue this process until we have fully searched all sub trees and rebuilt the tree.
