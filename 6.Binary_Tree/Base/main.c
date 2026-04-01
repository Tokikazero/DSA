#include "bst.h"
#include <stdio.h>

int main(void)
{
    Tree *tree = CreateTree();
    if (!tree)
        return 1;

    TreeInsert(tree, 7);
    TreeInsert(tree, 4);
    TreeInsert(tree, 9);
    TreeInsert(tree, 1);
    TreeInsert(tree, 6);
    TreeInsert(tree, 8);
    TreeInsert(tree, 10);

    printf("Inorder: \n");
    TreePrintInorder(tree); // expected: 1 4 6 7 8 9 10

    int x = 6;
    printf("\nFind %d: %s\n", x, TreeFind(tree, x) ? "FOUND" : "NOT FOUND");

    x = 5;
    printf("Find %d: %s\n", x, TreeFind(tree, x) ? "FOUND" : "NOT FOUND");

    return 0;


    // part 2:
    // Tree *tree = createTree();

    // int values[] = {7, 4, 9, 1, 6, 8, 10};
    // int n = sizeof(values) / sizeof(values[0]);

    // for (int i = 0; i < n; i++)
    //     TreeInsert(tree, values[i]);

    // printf("Inorder   (sorted): ");
    // tree_print_inorder(tree);

    // printf("Preorder  (DFS):    ");
    // tree_print_preorder(tree);

    // printf("Postorder (DFS):    ");
    // tree_print_postorder(tree);

    // printf("BFS Level-Order:    ");
    // tree_print_bfs(tree);

    // int x = 6;
    // printf("\nFind %d: %s\n", x, tree_find(tree, x) ? "FOUND" : "NOT FOUND");

    // x = 11;
    // printf("Find %d: %s\n", x, tree_find(tree, x) ? "FOUND" : "NOT FOUND");

    // return 0;
}
