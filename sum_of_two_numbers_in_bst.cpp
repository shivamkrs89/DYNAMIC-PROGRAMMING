You are given two binary search trees a and b and an integer target. Return whether there's a number in a and a number in b such that their sum equals to target

Constraints

    n ≤ 100,000 where n is the number of nodes in a
    m ≤ 100,000 where m is the number of nodes in b
https://binarysearch.com/problems/Sum-of-Two-Numbers-in-BSTs
//code
/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
bool solve(Tree* a, Tree* b, int target) {
    if(a==NULL || b==NULL)
    return 0;
    if(a->val+b->val==target)
    return 1;

    else if(a->val+b->val>target)
    {
        return solve(a->left,b,target) || solve(a,b->left,target);
    }
    else
    {
             return solve(a->right,b,target) || solve(a,b->right,target);
    }

}
