# 0x1D. C - Binary trees

# Resources

<strong>Read or watch:</strong>

* [Binary tree](https://en.wikipedia.org/wiki/Binary_tree) (note the first line: `Not to be confused with B-tree.`)

* [Data Structure and Algorithms - Tree](https://www.tutorialspoint.com/data_structures_algorithms/tree_data_structure.htm)

* [Tree Traversal](https://www.tutorialspoint.com/data_structures_algorithms/tree_traversal.htm)

* [Binary Search Tree](https://en.wikipedia.org/wiki/Binary_search_tree)

* [Data structures: Binary Tree](https://www.youtube.com/watch?v=H5JubkIy_p8)

#  Learning Objectives

At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

# General
* What is a binary tree

* What is the difference between a binary tree and a Binary Search Tree

* What is the possible gain in terms of time complexity compared to linked lists

* What are the depth, the height, the size of a binary tree

* What are the different traversal methods to go through a binary tree

* What is a complete, a full, a perfect, a balanced binary tree

# Requirements

##  General

* Allowed editors: `vi`, `vim`, `emacs`

* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`

* All your files should end with a new line

* A `README.md` file, at the root of the folder of the project, is mandatory

* Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl) and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl)

* You are not allowed to use global variables

* No more than 5 functions per file

* You are allowed to use the standard library

* In the following examples, the `main.c` files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own `main.c` files at compilation. Our `main.c` files might be different from the one shown in the examples

* The prototypes of all your functions should be included in your header file called `binary_trees.h`

* Don’t forget to push your header file

* All your header files should be include guarded

##  GitHub

 <strong>There should be one project repository per group. If you clone/fork/whatever a project repository with the same name before the second deadline, you risk a 0% score.</strong>
 
<details> 
<summary markdown="span"> <strong>More  info</strong> </summary>

## Data structures

Please use the following data structures and types for binary trees. Don’t forget to include them in your header file.

    Basic Binary Tree
    /**
    * struct binary_tree_s - Binary tree node
    *
    * @n: Integer stored in the node
    * @`parent`: Pointer to the `parent` node
    * @left: Pointer to the left child node
    * @right: Pointer to the right child node
    */
    struct binary_tree_s
    {
        int n;
        struct binary_tree_s *`parent`;
        struct binary_tree_s *left;
        struct binary_tree_s *right;
    };

    typedef struct binary_tree_s binary_tree_t;


## Binary Search Tree
`typedef struct binary_tree_s bst_t;`
## AVL Tree
`typedef struct binary_tree_s avl_t;`
## Max Binary Heap
`typedef struct binary_tree_s heap_t;`

<strong>Note</strong>: For tasks 0 to 23 (included), you have to deal with simple binary trees. They are not BSTs, thus they don’t follow any kind of rule.

## Print function
To match the examples in the tasks, you are given this [function](https://github.com/holbertonschool/0x1C.c)

This function is used only for visualization purposes. You don’t have to push it to your repo. It may not be used during the correction
</details>
<br  />

# Tasks
## Task 0. [New Node.](https://github.com/rmarcais/binary_trees/blob/main/0-binary_tree_node.c)
Write a function that creates a binary tree node


* Prototype: `binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);`

* Where ``parent`` is a pointer to the ``parent`` node of the node to create

* And ``value`` is the ``value`` to put in the new node

* When created, a node does not have any child

* Your function must return a pointer to the new node, or ``NULL`` on failure

<details>
<summary markdown="span"><strong>More</strong></summary>

    #include <stdlib.h>
    #include "binary_trees.h"

    **
    * main - Entry point
    *
    * Return: Always 0 (Success)
    */
    int main(void)
    {
       binary_tree_t *root;

       root = binary_tree_node(`NULL`, 98);

       root->left = binary_tree_node(root, 12);
       root->left->left = binary_tree_node(root->left, 6);
       root->left->right = binary_tree_node(root->left, 16);

       root->right = binary_tree_node(root, 402);
       root->right->left = binary_tree_node(root->right, 256);
       root->right->right = binary_tree_node(root->right, 512);

       binary_tree_print(root);
       return (0);
    }
`output`:

           .-------(098)-------.
      .--(012)--.         .--(402)--.
    (006)     (016)     (256)     (512)

`command to compile our program`:

    gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-binary_tree_node.c -o 0-node

and you can execute the file by entering `./0-node`
</details>
<br  />

## Task 1. [Insert Left.](https://github.com/rmarcais/binary_trees/blob/main/1-binary_tree_insert_left.c)
Write a function that inserts a node as the left-child of another node


* Prototype: `binary_tree_t binary_tree_insert_left(binary_tree_t *parent, int value);`

* Where `parent` is a pointer to the node to insert the left-child in

* And `value` is the `value` to store in the new node

* Your function must return a pointer to the created node, or `NULL` on failure or if `parent` is `NULL`

* If `parent` already has a left-child, the new node must take its place, and the old left-child must be set as the left-child of the new node.
<details>
<summary markdown="span"><strong>More</strong></summary>

    #include <stdlib.h>
    #include <stdio.h>
    #include "binary_trees.h"

    /**
     * main - Entry point
     *
     * Return: Always 0 (Success)
     */
    int main(void)
    {
        binary_tree_t *root;

        root = binary_tree_node(NULL, 98);
        root->left = binary_tree_node(root, 12);
        root->right = binary_tree_node(root, 402);
        binary_tree_print(root);
        printf("\n");
        binary_tree_insert_left(root->right, 128);
        binary_tree_insert_left(root, 54);
        binary_tree_print(root);
        return (0);
    }

`output`:

    .--(098)--.
    (012)     (402)

        .--(098)-------.
    .--(054)       .--(402)
    (012)          (128)   

`command to compile our program`:

    gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 1-main.c 1-binary_tree_insert_left.c 0-binary_tree_node.c -o 1-left

and you can execute the file by entering `./1-left`
</details>
<br  />

## Task2. [Insert Right.](https://github.com/rmarcais/binary_trees/blob/main/2-binary_tree_insert_right.c)

Write a function that inserts a node as the right-child of another node


* Prototype: `binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);`

* Where `parent` is a pointer to the node to insert the right-child in

* And `value` is the `value` to store in the new node

* Your function must return a pointer to the created node, or `NULL` on failure or if `parent` is `NULL`

* If `parent` already has a right-child, the new node must take its place, and the old right-child must be set as the right-child of the new node.
<details>
<summary markdown="span"><strong>More</strong></summary>

    #include <stdlib.h>
    #include <stdio.h>
    #include "binary_trees.h"

    /**
     * main - Entry point
     *
     * Return: Always 0 (Success)
     */
    int main(void)
    {
        binary_tree_t *root;

        root = binary_tree_node(NULL, 98);
        root->left = binary_tree_node(root, 12);
        root->right = binary_tree_node(root, 402);
        binary_tree_print(root);
        printf("\n");
        binary_tree_insert_right(root->left, 54);
        binary_tree_insert_right(root, 128);
        binary_tree_print(root);
        return (0);
    }
`output`:

      .--(098)--.
    (012)     (402)

      .-------(098)--.
    (012)--.       (128)--.
         (054)          (402)

`command to compile our program`:

    gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 2-main.c 2-binary_tree_insert_right.c 0-binary_tree_node.c -o 2-right

and you can execute the file by entering `./2-right`
</details>
<br  />

## Task3. [Delete.](https://github.com/rmarcais/binary_trees/blob/main/3-binary_tree_delete.c)
Write a function that deletes an entire binary tree


* Prototype: `void binary_tree_delete(binary_tree_t *tree);`

* Where `tree` is a pointer to the root node of the `tree` to delete

* If `tree` is `NULL`, do nothing

<details>
<summary markdown="span"><strong>More</strong></summary>

    #include <stdlib.h>
    #include <stdio.h>
    #include "binary_trees.h"

    /**
     * main - Entry point
     *
     * Return: Always 0 (Success)
     */
    int main(void)
    {
        binary_tree_t *root;

        root = binary_tree_node(NULL, 98);
        root->left = binary_tree_node(root, 12);
        root->right = binary_tree_node(root, 402);
        binary_tree_insert_right(root->left, 54);
        binary_tree_insert_right(root, 128);
        binary_tree_print(root);
        binary_tree_delete(root);
        return (0);
    }
`output`:

    ==13264== Memcheck, a memory error detector
    ==13264== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
    ==13264== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
    ==13264== Command: ./3-del
    ==13264== 
    .-------(098)--.
    (012)--.       (128)--.
        (054)          (402)
    ==13264== 
    ==13264== HEAP SUMMARY:
    ==13264==     in use at exit: 0 bytes in 0 blocks
    ==13264==   total heap usage: 9 allocs, 9 frees, 949 bytes allocated
    ==13264== 
    ==13264== All heap blocks were freed -- no leaks are possible
    ==13264== 
    ==13264== For counts of detected and suppressed errors, rerun with: -v
    ==13264== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
`command to compile our program`:

    gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 3-main.c 3-binary_tree_delete.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 3-del

and you can execute the file by entering `valgrind ./3-del`

Here we use `valgrind` to see if there is memory leak
</details>
<br  />

## Task4. [Is leaf.](https://github.com/rmarcais/binary_trees/blob/main/4-binary_tree_is_leaf.c)
Write a function that checks if a node is a leaf


* Prototype: `int binary_tree_is_leaf(const binary_tree_t *node);`

* Where `node` is a pointer to the `node` to check

* Your function must return `1` if `node` is a leaf, otherwise `0`

* If `node` is `NULL`, return `0`
<details>
<summary markdown="span"><strong>More</strong></summary>

    #include <stdlib.h>
    #include <stdio.h>
    #include "binary_trees.h"

    /**
     * main - Entry point
     *
     * Return: Always 0 (Success)
     */
    int main(void)
    {
        binary_tree_t *root;
        int ret;

        root = binary_tree_node(NULL, 98);
        root->left = binary_tree_node(root, 12);
        root->right = binary_tree_node(root, 402);
        binary_tree_insert_right(root->left, 54);
        binary_tree_insert_right(root, 128);
        binary_tree_print(root);

        ret = binary_tree_is_leaf(root);
        printf("Is %d a leaf: %d\n", root->n, ret);
        ret = binary_tree_is_leaf(root->right);
        printf("Is %d a leaf: %d\n", root->right->n, ret);
        ret = binary_tree_is_leaf(root->right->right);
        printf("Is %d a leaf: %d\n", root->right->right->n, ret);
        return (0);
    }
`output`:

    .-------(098)--.
    (012)--.       (128)--.
        (054)          (402)
`command to compile our program`:

    gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 4-binary_tree_is_leaf.c 4-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 4-leaf

and you can execute the file by entering `./4-leaf`
</details>
<br  />

## Task5. [Is root.](https://github.com/rmarcais/binary_trees/blob/main/5-binary_tree_is_root.c)
Write a function that checks if a given node is a root


* Prototype: `int binary_tree_is_root(const binary_tree_t *node);`

* Where `node` is a pointer to the `node` to check

* Your function must return `1` if `node` is a root, otherwise `0`

* If node is `NULL`, return `0`
<details>
<summary markdown="span"><strong>More</strong></summary>

    #include <stdlib.h>
    #include <stdio.h>
    #include "binary_trees.h"

    /**
    * main - Entry point
    *
    * Return: Always 0 (Success)
    */
    int main(void)
    {
        binary_tree_t *root;
        int ret;

        root = binary_tree_node(NULL, 98);
        root->left = binary_tree_node(root, 12);
        root->right = binary_tree_node(root, 402);
        binary_tree_insert_right(root->left, 54);
        binary_tree_insert_right(root, 128);
        binary_tree_print(root);

        ret = binary_tree_is_root(root);
        printf("Is %d a root: %d\n", root->n, ret);
        ret = binary_tree_is_root(root->right);
        printf("Is %d a root: %d\n", root->right->n, ret);
        ret = binary_tree_is_root(root->right->right);
        printf("Is %d a root: %d\n", root->right->right->n, ret);
        return (0);
    }
`output`:

    .-------(098)--.
    (012)--.       (128)--.
        (054)          (402)
    Is 98 a root: 1
    Is 128 a root: 0
    Is 402 a root: 0
`command to compile our program`:

    gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 5-binary_tree_is_root.c 5-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 5-root

and you can execute the file by entering `./5-root`
</details>
<br  />

## Task6. [Pre-order traversal.](https://github.com/rmarcais/binary_trees/blob/main/5-binary_tree_is_root.c)
Write a function that goes through a binary tree using pre-order traversal


* Prototype: `void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));`

* Where `tree` is a pointer to the root node of the `tree` to traverse

* And `func` is a pointer to a function to call for each node. The value in the node must be passed as a parameter to this function.

* If `tree` or `func` is `NULL`, do nothing
<details>
<summary markdown="span"><strong>More</strong></summary>

    #include <stdlib.h>
    #include <stdio.h>
    #include "binary_trees.h"

    /**
     * print_num - Prints a number
     *
     * @n: Number to be printed
     */
    void print_num(int n)
    {
        printf("%d\n", n);
    }

    /**
     * main - Entry point
     *
     * Return: Always 0 (Success)
     */
    int main(void)
    {
        binary_tree_t *root;

        root = binary_tree_node(NULL, 98);
        root->left = binary_tree_node(root, 12);
        root->right = binary_tree_node(root, 402);
        root->left->left = binary_tree_node(root->left, 6);
        root->left->right = binary_tree_node(root->left, 56);
        root->right->left = binary_tree_node(root->right, 256);
        root->right->right = binary_tree_node(root->right, 512);

        binary_tree_print(root);
        binary_tree_preorder(root, &print_num);
        return (0);
    }
`output`:

        .-------(098)-------.
    .--(012)--.         .--(402)--.
    (006)     (056)     (256)     (512)
    98
    12
    6
    56
    402
    256
`command to compile our program`:

    gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 6-main.c 6-binary_tree_preorder.c 0-binary_tree_node.c -o 6-pre

and you can execute the file by entering `./6-pre`
</details>
<br  />

## Task7. [In-order traversal.](https://github.com/rmarcais/binary_trees/blob/main/7-binary_tree_inorder.c)
Write a function that goes through a binary tree using in-order traversal


* Prototype: `void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));`

* Where `tree` is a pointer to the root node of the `tree` to traverse

* And `func` is a pointer to a function to call for each node. The value in the node must be passed as a parameter to this function.

* If `tree` or `func` is `NULL`, do nothing
<details>
<summary markdown="span"><strong>More</strong></summary>

    #include <stdlib.h>
    #include <stdio.h>
    #include "binary_trees.h"

    /**
     * print_num - Prints a number
     *
     * @n: Number to be printed
     */
    void print_num(int n)
    {
        printf("%d\n", n);
    }

    /**
     * main - Entry point
     *
     * Return: Always 0 (Success)
     */
    int main(void)
    {
        binary_tree_t *root;

        root = binary_tree_node(NULL, 98);
        root->left = binary_tree_node(root, 12);
        root->right = binary_tree_node(root, 402);
        root->left->left = binary_tree_node(root->left, 6);
        root->left->right = binary_tree_node(root->left, 56);
        root->right->left = binary_tree_node(root->right, 256);
        root->right->right = binary_tree_node(root->right, 512);

        binary_tree_print(root);
        binary_tree_inorder(root, &print_num);
        return (0);
    }
`output`:

        .-------(098)-------.
    .--(012)--.         .--(402)--.
    (006)     (056)     (256)     (512)
    6
    12
    56
    98
    256
    402
    512
`command to compile our program`:

    gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 7-main.c 7-binary_tree_inorder.c 0-binary_tree_node.c -o 7-in

and you can execute the file by entering `./7-in`
</details>
<br  />

## Task8. [Post-order traversal.](https://github.com/rmarcais/binary_trees/blob/main/8-binary_tree_postorder.c)
Write a function that goes through a binary tree using post-order traversal


* Prototype: `void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));`

* Where `tree` is a pointer to the root node of the `tree` to traverse

* And `func` is a pointer to a function to call for each node. The value in the node must be passed as a parameter to this function.

* If `tree` or `func` is `NULL`, do nothing
<details>
<summary markdown="span"><strong>More</strong></summary>

    #include <stdlib.h>
    #include <stdio.h>
    #include "binary_trees.h"

    /**
     * print_num - Prints a number
     *
     * @n: Number to be printed
     */
    void print_num(int n)
    {
        printf("%d\n", n);
    }

    /**
     * main - Entry point
     *
     * Return: Always 0 (Success)
     */
    int main(void)
    {
        binary_tree_t *root;

        root = binary_tree_node(NULL, 98);
        root->left = binary_tree_node(root, 12);
        root->right = binary_tree_node(root, 402);
        root->left->left = binary_tree_node(root->left, 6);
        root->left->right = binary_tree_node(root->left, 56);
        root->right->left = binary_tree_node(root->right, 256);
        root->right->right = binary_tree_node(root->right, 512);

        binary_tree_print(root);
        binary_tree_postorder(root, &print_num);
        return (0);
    }
`output`:

        .-------(098)-------.
    .--(012)--.         .--(402)--.
    (006)     (056)     (256)     (512)
    6
    56
    12
    256
    512
    402
    98
`command to compile our program`:

    gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 8-main.c 8-binary_tree_postorder.c 0-binary_tree_node.c -o 8-post

and you can execute the file by entering `./8-post`
</details>
<br  />

## Task9. [Height.](https://github.com/rmarcais/binary_trees/blob/main/9-binary_tree_height.c)
Write a function that measures the height of a binary tree


* Prototype: `size_t binary_tree_height(const binary_tree_t *tree);`

* Where `tree` is a pointer to the root node of the `tree` to measure the height.

* If `tree` is `NULL`, your function must return `0`
<details>
<summary markdown="span"><strong>More</strong></summary>

    #include <stdlib.h>
    #include <stdio.h>
    #include "binary_trees.h"

    /**
    * main - Entry point
    *
    * Return: Always 0 (Success)
    */
    int main(void)
    {
        binary_tree_t *root;
        size_t height;

        root = binary_tree_node(NULL, 98);
        root->left = binary_tree_node(root, 12);
        root->right = binary_tree_node(root, 402);
        binary_tree_insert_right(root->left, 54);
        binary_tree_insert_right(root, 128);
        binary_tree_print(root);

        height = binary_tree_height(root);
        printf("Height from %d: %lu\n", root->n, height);
        height = binary_tree_height(root->right);
        printf("Height from %d: %lu\n", root->right->n, height);
        height = binary_tree_height(root->left->right);
        printf("Height from %d: %lu\n", root->left->right->n, height);
        return (0);
    }
`output`:

    .-------(098)--.
    (012)--.       (128)--.
        (054)          (402)
    Height from 98: 2
    Height from 128: 1
    Height from 54: 0
`command to compile our program`:

    gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 9-binary_tree_height.c 9-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 9-height

and you can execute the file by entering `./9-height`
</details>
<br  />

## Task10. [Depth.](https://github.com/rmarcais/binary_trees/blob/main/10-binary_tree_depth.c)
Write a function that measures the depth of a node in a binary tree


* Prototype: `size_t binary_tree_depth(const binary_tree_t *tree);`

* Where `tree` is a pointer to the node to measure the depth

* If `tree` is `NULL`, your function must return `0`
<details>
<summary markdown="span"><strong>More</strong></summary>

    #include <stdlib.h>
    #include <stdio.h>
    #include "binary_trees.h"

    /**
    * main - Entry point
    *
    * Return: Always 0 (Success)
    */
    int main(void)
    {
        binary_tree_t *root;
        size_t depth;

        root = binary_tree_node(NULL, 98);
        root->left = binary_tree_node(root, 12);
        root->right = binary_tree_node(root, 402);
        binary_tree_insert_right(root->left, 54);
        binary_tree_insert_right(root, 128);
        binary_tree_print(root);

        depth = binary_tree_depth(root);
        printf("Depth of %d: %lu\n", root->n, depth);
        depth = binary_tree_depth(root->right);
        printf("Depth of %d: %lu\n", root->right->n, depth);
        depth = binary_tree_depth(root->left->right);
        printf("Depth of %d: %lu\n", root->left->right->n, depth);
        return (0);
    }
`output`:

    .-------(098)--.
    (012)--.       (128)--.
        (054)          (402)
    Depth of 98: 0
    Depth of 128: 1
    Depth of 54: 2
`command to compile our program`:

    gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 10-binary_tree_depth.c 10-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 10-depth

and you can execute the file by entering `./10-depth`
</details>
<br  />

## Task11. [Size.](https://github.com/rmarcais/binary_trees/blob/main/11-binary_tree_size.c)
Write a function that measures the size of a binary tree


* Prototype: `size_t binary_tree_size(const binary_tree_t *tree);`

* Where `tree` is a pointer to the root node of the `tree` to measure the size

* If `tree` is `NULL`, the function must return `0`
<details>
<summary markdown="span"><strong>More</strong></summary>

    #include <stdlib.h>
    #include <stdio.h>
    #include "binary_trees.h"

    /**
    * main - Entry point
    *
    * Return: Always 0 (Success)
    */
    int main(void)
    {
        binary_tree_t *root;
        size_t size;

        root = binary_tree_node(NULL, 98);
        root->left = binary_tree_node(root, 12);
        root->right = binary_tree_node(root, 402);
        binary_tree_insert_right(root->left, 54);
        binary_tree_insert_right(root, 128);
        binary_tree_print(root);

        size = binary_tree_size(root);
        printf("Size of %d: %lu\n", root->n, size);
        size = binary_tree_size(root->right);
        printf("Size of %d: %lu\n", root->right->n, size);
        size = binary_tree_size(root->left->right);
        printf("Size of %d: %lu\n", root->left->right->n, size);
        return (0);
    }
`output`:

    .-------(098)--.
    (012)--.       (128)--.
        (054)          (402)
    Size of 98: 5
    Size of 128: 2
    Size of 54: 1
`command to compile our program`:

    gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 11-binary_tree_size.c 11-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 11-size

and you can execute the file by entering `./11-size`
</details>
<br  />

## Task12. [Leaves.](https://github.com/rmarcais/binary_trees/blob/main/12-binary_tree_leaves.c)
Write a function that counts the leaves in a binary tree


* Prototype: `size_t binary_tree_leaves(const binary_tree_t *tree);`

* Where `tree` is a pointer to the root node of the `tree` to count the number of leaves

* If `tree` is `NULL`, the function must return 0

* A `NULL` pointer is not a leaf
<details>
<summary markdown="span"><strong>More</strong></summary>

    #include <stdlib.h>
    #include <stdio.h>
    #include "binary_trees.h"

    /**
    * main - Entry point
    *
    * Return: Always 0 (Success)
    */
    int main(void)
    {
        binary_tree_t *root;
        size_t leaves;

        root = binary_tree_node(NULL, 98);
        root->left = binary_tree_node(root, 12);
        root->right = binary_tree_node(root, 402);
        binary_tree_insert_right(root->left, 54);
        binary_tree_insert_right(root, 128);
        binary_tree_print(root);

        leaves = binary_tree_leaves(root);
        printf("Leaves in %d: %lu\n", root->n, leaves);
        leaves = binary_tree_leaves(root->right);
        printf("Leaves in %d: %lu\n", root->right->n, leaves);
        leaves = binary_tree_leaves(root->left->right);
        printf("Leaves in %d: %lu\n", root->left->right->n, leaves);
        return (0);
    }
`output`:

    .-------(098)--.
    (012)--.       (128)--.
        (054)          (402)
    Leaves in 98: 2
    Leaves in 128: 1
    Leaves in 54: 1
`command to compile our program`:

    gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 12-binary_tree_leaves.c 12-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 12-leaves

and you can execute the file by entering `./12-leaves`
</details>
<br  />

## Task13. [Nodes.](https://github.com/rmarcais/binary_trees/blob/main/13-binary_tree_nodes.c)
Write a function that counts the nodes with at least 1 child in a binary tree


* Prototype: `size_t binary_tree_nodes(const binary_tree_t *tree);`

* Where `tree` is a pointer to the root node of the `tree` to count the number of nodes

* If `tree` is `NULL`, the function must return `0`

* A `NULL` pointer is not a node
<details>
<summary markdown="span"><strong>More</strong></summary>

    #include <stdlib.h>
    #include <stdio.h>
    #include "binary_trees.h"

    /**
    * main - Entry point
    *
    * Return: Always 0 (Success)
    */
    int main(void)
    {
        binary_tree_t *root;
        size_t nodes;

        root = binary_tree_node(NULL, 98);
        root->left = binary_tree_node(root, 12);
        root->right = binary_tree_node(root, 402);
        binary_tree_insert_right(root->left, 54);
        binary_tree_insert_right(root, 128);
        binary_tree_print(root);

        nodes = binary_tree_nodes(root);
        printf("Nodes in %d: %lu\n", root->n, nodes);
        nodes = binary_tree_nodes(root->right);
        printf("Nodes in %d: %lu\n", root->right->n, nodes);
        nodes = binary_tree_nodes(root->left->right);
        printf("Nodes in %d: %lu\n", root->left->right->n, nodes);
        return (0);
    }
`output`:

    .-------(098)--.
    (012)--.       (128)--.
        (054)          (402)
    Nodes in 98: 3
    Nodes in 128: 1
    Nodes in 54: 0
`command to compile our program`:

    gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 13-binary_tree_nodes.c 13-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 13-nodes

and you can execute the file by entering `./13-nodes`
</details>
<br  />

## Task14. [Balance factor.](https://github.com/rmarcais/binary_trees/blob/main/14-binary_tree_balance.c)
Write a function that measures the balance factor of a binary tree


* Prototype: `int binary_tree_balance(const binary_tree_t *tree);`

* Where `tree` is a pointer to the root node of the `tree` to measure the balance factor

* If `tree` is `NULL`, return `0`
<details>
<summary markdown="span"><strong>More</strong></summary>

    #include <stdlib.h>
    #include <stdio.h>
    #include "binary_trees.h"

    /**
    * main - Entry point
    *
    * Return: Always 0 (Success)
    */
    int main(void)
    {
        binary_tree_t *root;
        int balance;

        root = binary_tree_node(NULL, 98);
        root->left = binary_tree_node(root, 12);
        root->right = binary_tree_node(root, 402);
        binary_tree_insert_right(root->left, 54);
        binary_tree_insert_right(root, 128);
        binary_tree_insert_left(root, 45);
        binary_tree_insert_right(root->left, 50);
        binary_tree_insert_left(root->left->left, 10);
        binary_tree_insert_left(root->left->left->left, 8);
        binary_tree_print(root);

        balance = binary_tree_balance(root);
        printf("Balance of %d: %+d\n", root->n, balance);
        balance = binary_tree_balance(root->right);
        printf("Balance of %d: %+d\n", root->right->n, balance);
        balance = binary_tree_balance(root->left->left->right);
        printf("Balance of %d: %+d\n", root->left->left->right->n, balance);
        return (0);
    }
`output`:

                        .-------(098)--.
                .-------(045)--.       (128)--.
        .--(012)--.       (050)          (402)
    .--(010)     (054)
    (008)
    Balance of 98: +2
    Balance of 128: -1
    Balance of 54: +0
`command to compile our program`:

    gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 14-binary_tree_balance.c 14-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c 1-binary_tree_insert_left.c -o 14-balance

and you can execute the file by entering `./14-balance`
</details>
<br  />

## Task15. [Is full.](https://github.com/rmarcais/binary_trees/blob/main/15-binary_tree_is_full.c)
Write a function that checks if a binary tree is full


* Prototype: `int binary_tree_is_full(const binary_tree_t *tree);`

* Where `tree` is a pointer to the root node of the `tree` to check

* If `tree` is `NULL`, your function must return `0`
<details>
<summary markdown="span"><strong>More</strong></summary>

    #include <stdlib.h>
    #include <stdio.h>
    #include "binary_trees.h"

    /**
    * main - Entry point
    *
    * Return: Always 0 (Success)
    */
    int main(void)
    {
        binary_tree_t *root;
        int full;

        root = binary_tree_node(NULL, 98);
        root->left = binary_tree_node(root, 12);
        root->right = binary_tree_node(root, 402);
        binary_tree_insert_right(root->left, 54);
        binary_tree_insert_right(root, 128);
        root->left->left = binary_tree_node(root->left, 10);
        binary_tree_print(root);

        full = binary_tree_is_full(root);
        printf("Is %d full: %d\n", root->n, full);
        full = binary_tree_is_full(root->left);
        printf("Is %d full: %d\n", root->left->n, full);
        full = binary_tree_is_full(root->right);
        printf("Is %d full: %d\n", root->right->n, full);
        return (0);
    }
`output`:

        .-------(098)--.
    .--(012)--.       (128)--.
    (010)     (054)          (402)
    Is 98 full: 0
    Is 12 full: 1
    Is 128 full: 0
`command to compile our program`:

    gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 15-binary_tree_is_full.c 15-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 15-full

and you can execute the file by entering `./15-full`
</details>
<br  />

## Task16. [Is perfect.](https://github.com/rmarcais/binary_trees/blob/main/16-binary_tree_is_perfect.c)
Write a function that checks if a binary tree is perfect


* Prototype: `int binary_tree_is_perfect(const binary_tree_t *tree);`

* Where `tree` is a pointer to the root node of the `tree` to check

* If `tree` is `NULL`, your function must return `0`
<details>
<summary markdown="span"><strong>More</strong></summary>

    #include <stdlib.h>
    #include <stdio.h>
    #include "binary_trees.h"

    /**
    * main - Entry point
    *
    * Return: Always 0 (Success)
    */
    int main(void)
    {
        binary_tree_t *root;
        int perfect;

        root = binary_tree_node(NULL, 98);
        root->left = binary_tree_node(root, 12);
        root->right = binary_tree_node(root, 402);
        binary_tree_insert_right(root->left, 54);
        binary_tree_insert_right(root, 128);
        root->left->left = binary_tree_node(root->left, 10);
        root->right->left = binary_tree_node(root->right, 10);

        binary_tree_print(root);
        perfect = binary_tree_is_perfect(root);
        printf("Perfect: %d\n\n", perfect);

        root->right->right->left = binary_tree_node(root->right->right, 10);
        binary_tree_print(root);
        perfect = binary_tree_is_perfect(root);
        printf("Perfect: %d\n\n", perfect);

        root->right->right->right = binary_tree_node(root->right->right, 10);
        binary_tree_print(root);
        perfect = binary_tree_is_perfect(root);
        printf("Perfect: %d\n", perfect);
        return (0);
    }
`output`:

        .-------(098)-------.
    .--(012)--.         .--(128)--.
    (010)     (054)     (010)     (402)
    Perfect: 1

        .-------(098)-------.
    .--(012)--.         .--(128)-------.
    (010)     (054)     (010)       .--(402)
                                (010)
    Perfect: 0

        .-------(098)-------.
    .--(012)--.         .--(128)-------.
    (010)     (054)     (010)       .--(402)--.
                                (010)     (010)
    Perfect: 0
`command to compile our program`:

    gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 16-binary_tree_is_perfect.c 16-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 16-perfect

and you can execute the file by entering `./16-perfect`
</details>
<br  />

## Task17. [Sibling.](https://github.com/rmarcais/binary_trees/blob/main/17-binary_tree_sibling.c)
Write a function that finds the sibling of a node


* Prototype: `binary_tree_t *binary_tree_sibling(binary_tree_t *node);`

* Where `node` is a pointer to the `node` to find the sibling

* Your function must return a pointer to the sibling `node`

* If `node` is `NULL` or the parent is `NULL`, return `NULL`

* If `node` has no sibling, return `NULL`
<details>
<summary markdown="span"><strong>More</strong></summary>

    #include <stdlib.h>
    #include <stdio.h>
    #include "binary_trees.h"

    /**
    * main - Entry point
    *
    * Return: Always 0 (Success)
    */
    int main(void)
    {
        binary_tree_t *root;
        binary_tree_t *sibling;

        root = binary_tree_node(NULL, 98);
        root->left = binary_tree_node(root, 12);
        root->right = binary_tree_node(root, 128);
        root->left->right = binary_tree_node(root->left, 54);
        root->right->right = binary_tree_node(root->right, 402);
        root->left->left = binary_tree_node(root->left, 10);
        root->right->left = binary_tree_node(root->right, 110);
        root->right->right->left = binary_tree_node(root->right->right, 200);
        root->right->right->right = binary_tree_node(root->right->right, 512);

        binary_tree_print(root);
        sibling = binary_tree_sibling(root->left);
        printf("Sibling of %d: %d\n", root->left->n, sibling->n);
        sibling = binary_tree_sibling(root->right->left);
        printf("Sibling of %d: %d\n", root->right->left->n, sibling->n);
        sibling = binary_tree_sibling(root->left->right);
        printf("Sibling of %d: %d\n", root->left->right->n, sibling->n);
        sibling = binary_tree_sibling(root);
        printf("Sibling of %d: %p\n", root->n, (void *)sibling);
        return (0);
    }
`output`:

        .-------(098)-------.
    .--(012)--.         .--(128)-------.
    (010)     (054)     (110)       .--(402)--.
                                (200)     (512)
    Sibling of 12: 128
    Sibling of 110: 402
    Sibling of 54: 10
    Sibling of 98: (nil)
`command to compile our program`:

    gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 17-main.c 17-binary_tree_sibling.c 0-binary_tree_node.c -o 17-sibling

and you can execute the file by entering `./17-sibling`
</details>
<br  />

## Task18. [Uncle.](https://github.com/rmarcais/binary_trees/blob/main/18-binary_tree_uncle.c)
Write a function that finds the uncle of a node


* Prototype: `binary_tree_t *binary_tree_uncle(binary_tree_t *node);`

* Where `node` is a pointer to the `node` to find the uncle

* Your function must return a pointer to the uncle `node`

* If `node` is `NULL`, return `NULL`

* If `node` has no uncle, return `NULL`
<details>
<summary markdown="span"><strong>More</strong></summary>

    #include <stdlib.h>
    #include <stdio.h>
    #include "binary_trees.h"

    /**
    * main - Entry point
    *
    * Return: Always 0 (Success)
    */
    int main(void)
    {
        binary_tree_t *root;
        binary_tree_t *uncle;

        root = binary_tree_node(NULL, 98);
        root->left = binary_tree_node(root, 12);
        root->right = binary_tree_node(root, 128);
        root->left->right = binary_tree_node(root->left, 54);
        root->right->right = binary_tree_node(root->right, 402);
        root->left->left = binary_tree_node(root->left, 10);
        root->right->left = binary_tree_node(root->right, 110);
        root->right->right->left = binary_tree_node(root->right->right, 200);
        root->right->right->right = binary_tree_node(root->right->right, 512);

        binary_tree_print(root);
        uncle = binary_tree_uncle(root->right->left);
        printf("Uncle of %d: %d\n", root->right->left->n, uncle->n);
        uncle = binary_tree_uncle(root->left->right);
        printf("Uncle of %d: %d\n", root->left->right->n, uncle->n);
        uncle = binary_tree_uncle(root->left);
        printf("Uncle of %d: %p\n", root->left->n, (void *)uncle);
        return (0);
    }
`output`:

        .-------(098)-------.
    .--(012)--.         .--(128)-------.
    (010)     (054)     (110)       .--(402)--.
                                (200)     (512)
    Uncle of 110: 12
    Uncle of 54: 128
    Uncle of 12: (nil)
`command to compile our program`:

    gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 18-main.c 18-binary_tree_uncle.c 0-binary_tree_node.c -o 18-uncle

and you can execute the file by entering `./18-uncle`
</details>
<br  />

## Task19. [Lowest common ancestor.](https://github.com/rmarcais/binary_trees/blob/main/100-binary_trees_ancestor.c)
Write a function that finds the lowest common ancestor of two nodes


* Prototype: `binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second);`

* Where `first` is a pointer to the `first` node

* And `second` is a pointer to the `second` node

* Your function must return a pointer to the lowest common ancestor node of the two given nodes

* If no common ancestor was found, your function must return `NULL`
<details>
<summary markdown="span"><strong>More</strong></summary>

    #include <stdlib.h>
    #include <stdio.h>
    #include "binary_trees.h"

    /**
    * launch_test - Test ancestor function and print informations
    *
    * @n1: First node
    * @n2: Second node
    */
    void launch_test(binary_tree_t *n1, binary_tree_t *n2)
    {
        binary_tree_t *ancestor;

        ancestor = binary_trees_ancestor(n1, n2);
        printf("Ancestor of [%d] & [%d]: ", n1->n, n2->n);
        if (!ancestor)
            printf("(nil)\n");
        else
            printf("%d\n", ancestor->n);
    }

    /**
    * main - Entry point
    *
    * Return: Always 0 (Success)
    */
    int main(void)
    {
        binary_tree_t *root;

        root = binary_tree_node(NULL, 98);
        root->left = binary_tree_node(root, 12);
        root->right = binary_tree_node(root, 402);
        root->left->right = binary_tree_node(root->left, 54);
        root->right->right = binary_tree_node(root->right, 128);
        root->left->left = binary_tree_node(root->left, 10);
        root->right->left = binary_tree_node(root->right, 45);
        root->right->right->left = binary_tree_node(root->right->right, 92);
        root->right->right->right = binary_tree_node(root->right->right, 65);
        binary_tree_print(root);

        launch_test(root->left, root->right);
        launch_test(root->right->left, root->right->right->right);
        launch_test(root->right->right, root->right->right->right);
        return (0);
    }
`output`:

        .-------(098)-------.
    .--(012)--.         .--(402)-------.
    (010)     (054)     (045)       .--(128)--.
                                (092)     (065)
    Ancestor of [12] & [402]: 98
    Ancestor of [45] & [65]: 402
    Ancestor of [128] & [65]: 128
`command to compile our program`:

    gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 100-main.c 100-binary_trees_ancestor.c 0-binary_tree_node.c -o 100-ancestor

and you can execute the file by entering `./100-ancestor`
</details>
<br  />

## Task20. [Lower-order traversal.](https://github.com/rmarcais/binary_trees/blob/main/101-binary_tree_levelorder.c)
Write a function that goes through a binary tree using level-order traversal


* Prototype: `void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));`

* Where `tree` is a pointer to the root node of the `tree` to traverse

* And `func` is a pointer to a function to call for each node. The value in the node must be passed as a parameter to this function.

* If `tree` or `func` is NULL, do nothing
<details>
<summary markdown="span"><strong>More</strong></summary>

    #include <stdlib.h>
    #include <stdio.h>
    #include "binary_trees.h"

    /**
    * print_num - Prints a number
    *
    * @n: Number to be printed
    */
    void print_num(int n)
    {
        printf("%d\n", n);
    }

    /**
    * main - Entry point
    *
    * Return: Always 0 (Success)
    */
    int main(void)
    {
        binary_tree_t *root;

        root = binary_tree_node(NULL, 98);
        root->left = binary_tree_node(root, 12);
        root->right = binary_tree_node(root, 402);
        root->left->left = binary_tree_node(root->left, 6);
        root->left->right = binary_tree_node(root->left, 56);
        root->right->left = binary_tree_node(root->right, 256);
        root->right->right = binary_tree_node(root->right, 512);

        binary_tree_print(root);
        binary_tree_levelorder(root, &print_num);
        binary_tree_delete(root);
        return (0);
    }
`output`:

    ==23445== Memcheck, a memory error detector
    ==23445== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
    ==23445== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
    ==23445== Command: ./101-lvl
    ==23445== 
        .-------(098)-------.
    .--(012)--.         .--(402)--.
    (006)     (056)     (256)     (512)
    98
    12
    402
    6
    56
    256
    512
    ==23445== 
    ==23445== HEAP SUMMARY:
    ==23445==     in use at exit: 0 bytes in 0 blocks
    ==23445==   total heap usage: 19 allocs, 19 frees, 1,197 bytes allocated
    ==23445== 
    ==23445== All heap blocks were freed -- no leaks are possible
    ==23445== 
    ==23445== For counts of detected and suppressed errors, rerun with: -v
    ==23445== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
`command to compile our program`:

    gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 101-main.c 101-binary_tree_levelorder.c 0-binary_tree_node.c 3-binary_tree_delete.c -o 101-lvl

and you can execute the file by entering `./101-lvl`
</details>
<br  />

## Task21. [Is complete.](https://github.com/rmarcais/binary_trees/blob/main/102-binary_tree_is_complete.c)
Write a function that checks if a binary tree is complete


* Prototype: `int binary_tree_is_complete(const binary_tree_t *tree);`

* Where `tree` is a pointer to the root node of the `tree` to check

* If `tree` is `NULL`, your function must return `0`
<details>
<summary markdown="span"><strong>More</strong></summary>

    #include <stdlib.h>
    #include <stdio.h>
    #include "binary_trees.h"

    /**
    * main - Entry point
    *
    * Return: Always 0 (Success)
    */
    int main(void)
    {
        binary_tree_t *root;
        int complete;

        root = binary_tree_node(NULL, 98);
        root->left = binary_tree_node(root, 12);
        root->right = binary_tree_node(root, 128);
        root->left->right = binary_tree_node(root->left, 54);
        root->right->right = binary_tree_node(root, 402);
        root->left->left = binary_tree_node(root->left, 10);

        binary_tree_print(root);
        complete = binary_tree_is_complete(root);
        printf("Is %d complete: %d\n", root->n, complete);
        complete = binary_tree_is_complete(root->left);
        printf("Is %d complete: %d\n", root->left->n, complete);

        root->right->left = binary_tree_node(root->right, 112);
        binary_tree_print(root);
        complete = binary_tree_is_complete(root);
        printf("Is %d complete: %d\n", root->n, complete);

        root->left->left->left = binary_tree_node(root->left->left, 8);
        binary_tree_print(root);
        complete = binary_tree_is_complete(root);
        printf("Is %d complete: %d\n", root->n, complete);

        root->left->right->left = binary_tree_node(root->left->right, 23);
        binary_tree_print(root);
        complete = binary_tree_is_complete(root);
        printf("Is %d complete: %d\n", root->n, complete);

        binary_tree_delete(root);
        return (0);
    }
`output`:

        .-------(098)--.
    .--(012)--.       (128)--.
    (010)     (054)          (402)
    Is 98 complete: 0
    Is 12 complete: 1
        .-------(098)-------.
    .--(012)--.         .--(128)--.
    (010)     (054)     (112)     (402)
    Is 98 complete: 1
                .-------(098)-------.
        .--(012)--.         .--(128)--.
    .--(010)     (054)     (112)     (402)
    (008)
    Is 98 complete: 1
                .------------(098)-------.
        .--(012)-------.         .--(128)--.
    .--(010)       .--(054)     (112)     (402)
    (008)          (023)
    Is 98 complete: 0
`command to compile our program`:

    gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 102-main.c 102-binary_tree_is_complete.c 0-binary_tree_node.c 3-binary_tree_delete.c -o 102-complete

and you can execute the file by entering `./102-complete`

</details>
<br  />

## Task22. [Rotate left.](https://github.com/rmarcais/binary_trees/blob/main/103-binary_tree_rotate_left.c)
Write a function that performs a left-rotation on a binary tree


* Prototype: `binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);`

* Where `tree` is a pointer to the root node of the `tree` to rotate

* Your function must return a pointer to the new root node of the `tree` once rotated
<details>
<summary markdown="span"><strong>More</strong></summary>

    #include <stdlib.h>
    #include <stdio.h>
    #include "binary_trees.h"

    /**
    * main - Entry point
    *
    * Return: 0 on success, error code on failure
    */
    int main(void)
    {
        binary_tree_t *root;

        root = binary_tree_node(NULL, 98);
        root->right = binary_tree_node(root, 128);
        root->right->right = binary_tree_node(root->right, 402);
        binary_tree_print(root);
        printf("Rotate-left %d\n", root->n);
        root = binary_tree_rotate_left(root);
        binary_tree_print(root);
        printf("\n");

        root->right->right = binary_tree_node(root->right, 450);
        root->right->left = binary_tree_node(root->right, 420);
        binary_tree_print(root);
        printf("Rotate-left %d\n", root->n);
        root = binary_tree_rotate_left(root);
        binary_tree_print(root);
        return (0);
    }
`output`:

    (098)--.
        (128)--.
            (402)
    Rotate-left 98
    .--(128)--.
    (098)     (402)

    .--(128)-------.
    (098)       .--(402)--.
            (420)     (450)
    Rotate-left 128
        .-------(402)--.
    .--(128)--.       (450)
    (098)     (420)
`command to compile our program`:

    gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 103-binary_tree_rotate_left.c 103-main.c 0-binary_tree_node.c -o 103-rotl

and you can execute the file by entering `./103-rotl`
</details>
<br  />

## Task23. [Rotate right.](https://github.com/rmarcais/binary_trees/blob/main/104-binary_tree_rotate_right.c)
Write a function that performs a right-rotation on a binary tree


* Prototype: `binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);`

* Where `tree` is a pointer to the root node of the `tree` to rotate

* Your function must return a pointer to the new root node of the `tree` once rotated
<details>
<summary markdown="span"><strong>More</strong></summary>

    #include <stdlib.h>
    #include <stdio.h>
    #include "binary_trees.h"

    /**
    * main - Entry point
    *
    * Return: 0 on success, error code on failure
    */
    int main(void)
    {
        binary_tree_t *root;

        root = binary_tree_node(NULL, 98);
        root->left = binary_tree_node(root, 64);
        root->left->left = binary_tree_node(root->left, 32);
        binary_tree_print(root);
        printf("Rotate-right %d\n", root->n);
        root = binary_tree_rotate_right(root);
        binary_tree_print(root);
        printf("\n");

        root->left->left = binary_tree_node(root->left, 20);
        root->left->right = binary_tree_node(root->left, 56);
        binary_tree_print(root);
        printf("Rotate-right %d\n", root->n);
        root = binary_tree_rotate_right(root);
        binary_tree_print(root);
        return (0);
    }
`output`:

        .--(098)
    .--(064)
    (032)
    Rotate-right 98
    .--(064)--.
    (032)     (098)

        .-------(064)--.
    .--(032)--.       (098)
    (020)     (056)
    Rotate-right 64
    .--(032)-------.
    (020)       .--(064)--.
            (056)     (098)
`command to compile our program`:

    gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 104-binary_tree_rotate_right.c 104-main.c 0-binary_tree_node.c -o 104-rotr

and you can execute the file by entering `./104-rotr`
</details>
<br  />

## Task24. [Is bst.](https://github.com/rmarcais/binary_trees/blob/main/110-binary_tree_is_bst.c)
Write a function that checks if a binary tree is a valid Binary Search Tree


* Prototype: `int binary_tree_is_bst(const binary_tree_t *tree);`

* Where `tree` is a pointer to the root node of the `tree` to check

* Your function must return `1` if `tree` is a valid BST, and `0` otherwise

* If `tree` is `NULL`, return `0`

Properties of a Binary Search Tree:


* The left subtree of a node contains only nodes with values less than the node’s value

* The right subtree of a node contains only nodes with values greater than the node’s value

* The left and right subtree each must also be a binary search tree

* There must be no duplicate values
<details>
<summary markdown="span"><strong>More</strong></summary>

    #include <stdlib.h>
    #include <stdio.h>
    #include "binary_trees.h"

    /**
    * main - Entry point
    *
    * Return: Always 0 (Success)
    */
    int main(void)
    {
        binary_tree_t *root;
        int bst;

        root = binary_tree_node(NULL, 98);
        root->left = binary_tree_node(root, 12);
        root->right = binary_tree_node(root, 128);
        root->left->right = binary_tree_node(root->left, 54);
        root->right->right = binary_tree_node(root, 402);
        root->left->left = binary_tree_node(root->left, 10);

        binary_tree_print(root);
        bst = binary_tree_is_bst(root);
        printf("Is %d bst: %d\n", root->n, bst);
        bst = binary_tree_is_bst(root->left);
        printf("Is %d bst: %d\n", root->left->n, bst);

        root->right->left = binary_tree_node(root->right, 97);
        binary_tree_print(root);
        bst = binary_tree_is_bst(root);
        printf("Is %d bst: %d\n", root->n, bst);
        return (0);
    }
`output`:

        .-------(098)--.
    .--(012)--.       (128)--.
    (010)     (054)          (402)
    Is 98 bst: 1
    Is 12 bst: 1
        .-------(098)-------.
    .--(012)--.         .--(128)--.
    (010)     (054)     (097)     (402)
    Is 98 bst: 0
`command to compile our program`:

    gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 110-main.c 110-binary_tree_is_bst.c 0-binary_tree_node.c -o 110-is_bst

and you can execute the file by entering `./110-is_bst`
</details>
<br  />

## Task25. [BST - Insert.](https://github.com/rmarcais/binary_trees/blob/main/111-bst_insert.c)
Write a function that inserts a value in a Binary Search Tree


* Prototype: `bst_t *bst_insert(bst_t **tree, int value);`

* Where `tree` is a double pointer to the root node of the BST to insert the `value`

* And `value` is the `value` to store in the node to be inserted

* Your function must return a pointer to the created node, or `NULL` on failure

* If the address stored in `tree` is `NULL`, the created node must become the root node.

* If the `value` is already present in the `tree`, it must be ignored
<details>
<summary markdown="span"><strong>More</strong></summary>

    #include <stdlib.h>
    #include <stdio.h>
    #include "binary_trees.h"

    /**
    * main - Entry point
    *
    * Return: Always 0 (Success)
    */
    int main(void)
    {
        bst_t *root;
        bst_t *node;

        root = NULL;
        node = bst_insert(&root, 98);
        printf("Inserted: %d\n", node->n);
        node = bst_insert(&root, 402);
        printf("Inserted: %d\n", node->n);
        node = bst_insert(&root, 12);
        printf("Inserted: %d\n", node->n);
        node = bst_insert(&root, 46);
        printf("Inserted: %d\n", node->n);
        node = bst_insert(&root, 128);
        printf("Inserted: %d\n", node->n);
        node = bst_insert(&root, 256);
        printf("Inserted: %d\n", node->n);
        node = bst_insert(&root, 512);
        printf("Inserted: %d\n", node->n);
        node = bst_insert(&root, 1);
        printf("Inserted: %d\n", node->n);
        node = bst_insert(&root, 128);
        printf("Node should be nil -> %p\n", (void *)node);
        binary_tree_print(root);
        return (0);
    }
`output`:

    Inserted: 98
    Inserted: 402
    Inserted: 12
    Inserted: 46
    Inserted: 128
    Inserted: 256
    Inserted: 512
    Inserted: 1
    Node should be nil -> (nil)
        .-------(098)------------.
    .--(012)--.         .-------(402)--.
    (001)     (046)     (128)--.       (512)
                            (256)
`command to compile our program`:

    gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 111-bst_insert.c 111-main.c 0-binary_tree_node.c -o 111-bst_insert

and you can execute the file by entering `./111-bst_insert`
</details>
<br  />

## Task26. [BST- Array to bst.](https://github.com/rmarcais/binary_trees/blob/main/112-array_to_bst.c)
Write a function that builds a Binary Search Tree from an array


* Prototype: `bst_t *array_to_bst(int *array, size_t size);`

* Where `array` is a pointer to the first element of the `array` to be converted

* And `size` is the number of element in the `array`

* Your function must return a pointer to the root node of the created BST, or `NULL` on failure

* If a value of the `array` is already present in the tree, this value must be ignored
<details>
<summary markdown="span"><strong>More</strong></summary>

    #include <stdlib.h>
    #include "binary_trees.h"

    /**
    * main - Entry point
    *
    * Return: 0 on success, error code on failure
    */
    int main(void)
    {
        bst_t *tree;
        int array[] = {
            79, 47, 68, 87, 84, 91, 21, 32, 34, 2,
            20, 22, 98, 1, 62, 95
        };
        size_t n = sizeof(array) / sizeof(array[0]);

        tree = array_to_bst(array, n);
        if (!tree)
            return (1);
        binary_tree_print(tree);
        return (0);
    }
`output`:

                                        .------------(079)-------.
                    .-----------------(047)-------.         .--(087)--.
        .-------(021)-------.              .--(068)     (084)     (091)-------.
    .--(002)--.         .--(032)--.       (062)                           .--(098)
    (001)     (020)     (022)     (034)                                   (095)
`command to compile our program`:

    gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 112-array_to_bst.c 112-main.c 111-bst_insert.c 0-binary_tree_node.c -o 112-bst_array

and you can execute the file by entering `./112-bst_array`
</details>
<br  />

## Task.27 [BST - Search.](https://github.com/rmarcais/binary_trees/blob/main/113-bst_search.c)
Write a function that searches for a value in a Binary Search Tree


* Prototype:`bst_t *bst_search(const bst_t *tree, int value);`

* Where `tree` is a pointer to the root node of the BST to search

* And `value` is the `value` to search in the `tree`

* Your function must return a pointer to the node containing a `value` equals to `value`

* If `tree` is `NULL` or if nothing is found, your function must return `NULL`
<details>
<summary markdown="span"><strong>More</strong></summary>

    #include <stdlib.h>
    #include <stdio.h>
    #include "binary_trees.h"

    /**
    * main - Entry point
    *
    * Return: 0 on success, error code on failure
    */
    int main(void)
    {
        bst_t *tree;
        int array[] = {
            79, 47, 68, 87, 84, 91, 21, 32, 34, 2,
            20, 22, 98, 1, 62, 95
        };
        size_t n = sizeof(array) / sizeof(array[0]);
        bst_t *node;

        tree = array_to_bst(array, n);
        if (!tree)
            return (1);
        binary_tree_print(tree);
        node = bst_search(tree, 32);
        printf("Found: %d\n", node->n);
        binary_tree_print(node);
        node = bst_search(tree, 512);
        printf("Node should be nil -> %p\n", (void *)node);
        return (0);
    }
`output`:

                                        .------------(079)-------.
                    .-----------------(047)-------.         .--(087)--.
        .-------(021)-------.              .--(068)     (084)     (091)-------.
    .--(002)--.         .--(032)--.       (062)                           .--(098)
    (001)     (020)     (022)     (034)                                   (095)
    Found: 32
    .--(032)--.
    (022)     (034)
    Node should be nil -> (nil)
`command to compile our program`:

    gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 113-bst_search.c 113-main.c 112-array_to_bst.c 111-bst_insert.c 0-binary_tree_node.c -o 113-bst_search

and you can execute the file by entering `./113-bst_search`
</details>
<br  />

## Task28. [BST - Remove.](https://github.com/rmarcais/binary_trees/blob/main/114-bst_remove.c)
Write a function that removes a node from a Binary Search Tree


* Prototype: `bst_t *bst_remove(bst_t *root, int value);`

* Where `root` is a pointer to the `root` node of the `tree` where you will remove a node

* And `value` is the `value` to remove in the `tree`

* Once located, the node containing a value equals to value must be removed and freed

* If the node to be deleted has two children, it must be replaced with its first `in-order successor` (not predecessor)

* Your function must return a pointer to the new root node of the tree after removing the desired value
<details>
<summary markdown="span"><strong>More</strong></summary>

    #include <stdlib.h>
    #include <stdio.h>
    #include "binary_trees.h"

    /**
    * main - Entry point
    *
    * Return: 0 on success, error code on failure
    */
    int main(void)
    {
        bst_t *tree;
        int array[] = {
            79, 47, 68, 87, 84, 91, 21, 32, 34, 2,
            20, 22, 98, 1, 62, 95
        };
        size_t n = sizeof(array) / sizeof(array[0]);

        tree = array_to_bst(array, n);
        if (!tree)
            return (1);
        binary_tree_print(tree);

        tree = bst_remove(tree, 79);
        printf("Removed 79...\n");
        binary_tree_print(tree);

        tree = bst_remove(tree, 21);
        printf("Removed 21...\n");
        binary_tree_print(tree);

        tree = bst_remove(tree, 68);
        printf("Removed 68...\n");
        binary_tree_print(tree);
        binary_tree_delete(tree);
        return (0);
    }
`output`:

    ==14720== Memcheck, a memory error detector
    ==14720== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
    ==14720== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
    ==14720== Command: ./114-bst_rm
    ==14720== 
                                        .------------(079)-------.
                    .-----------------(047)-------.         .--(087)--.
        .-------(021)-------.              .--(068)     (084)     (091)-------.
    .--(002)--.         .--(032)--.       (062)                           .--(098)
    (001)     (020)     (022)     (034)                                   (095)
    Removed 79...
                                        .------------(084)--.
                    .-----------------(047)-------.       (087)--.
        .-------(021)-------.              .--(068)          (091)-------.
    .--(002)--.         .--(032)--.       (062)                      .--(098)
    (001)     (020)     (022)     (034)                              (095)
    Removed 21...
                                    .------------(084)--.
                    .------------(047)-------.       (087)--.
        .-------(022)--.              .--(068)          (091)-------.
    .--(002)--.       (032)--.       (062)                      .--(098)
    (001)     (020)          (034)                              (095)
    Removed 68...
                                    .-------(084)--.
                    .------------(047)--.       (087)--.
        .-------(022)--.            (062)          (091)-------.
    .--(002)--.       (032)--.                             .--(098)
    (001)     (020)          (034)                         (095)
    ==14720== 
    ==14720== HEAP SUMMARY:
    ==14720==     in use at exit: 0 bytes in 0 blocks
    ==14720==   total heap usage: 40 allocs, 40 frees, 5,772 bytes allocated
    ==14720== 
    ==14720== All heap blocks were freed -- no leaks are possible
    ==14720== 
    ==14720== For counts of detected and suppressed errors, rerun with: -v
    ==14720== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
`command to compile our program`:

    gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 114-bst_remove.c 114-main.c 112-array_to_bst.c 111-bst_insert.c 0-binary_tree_node.c 3-binary_tree_delete.c -o 114-bst_rm

and you can execute the file by entering `valgrind ./114-bst_rm`

Here we use `valgrind` to see if there is memory leak
</details>
<br  />

## Task29. [Big O #BST.](https://github.com/rmarcais/binary_trees/blob/main/115-O)
What are the average time complexities of those operations on a Binary Search Tree (one answer per line):


* Inserting the value `n`

* Removing the node with the value `n`

* Searching for a node in a BST of size n

## Task30 [Is AVL.](https://github.com/rmarcais/binary_trees/blob/main/120-binary_tree_is_avl.c)
Write a function that checks if a binary tree is a valid AVL Tree


* Prototype: `int binary_tree_is_avl(const binary_tree_t *tree);`

* Where `tree` is a pointer to the root node of the `tree` to check

* Your function must return `1` if `tree` is a valid AVL `Tree`, and `0` otherwise

* If `tree` is `NULL`, return `0`

 Properties of an AVL Tree:

* An AVL Tree is a BST

* The difference between heights of left and right subtrees cannot be more than one

* The left and right subtrees must also be AVL trees
<details>
<summary markdown="span"><strong>More</strong></summary>

    #include <stdlib.h>
    #include <stdio.h>
    #include "binary_trees.h"

    /**
    * basic_tree - Build a basic binary tree
    *
    * Return: A pointer to the created tree
    */
    binary_tree_t *basic_tree(void)
    {
        binary_tree_t *root;

        root = binary_tree_node(NULL, 98);
        root->left = binary_tree_node(root, 12);
        root->right = binary_tree_node(root, 128);
        root->left->right = binary_tree_node(root->left, 54);
        root->right->right = binary_tree_node(root, 402);
        root->left->left = binary_tree_node(root->left, 10);
        return (root);
    }

    /**
    * main - Entry point
    *
    * Return: Always 0 (Success)
    */
    int main(void)
    {
        binary_tree_t *root;
        int avl;

        root = basic_tree();

        binary_tree_print(root);
        avl = binary_tree_is_avl(root);
        printf("Is %d avl: %d\n", root->n, avl);
        avl = binary_tree_is_avl(root->left);
        printf("Is %d avl: %d\n", root->left->n, avl);

        root->right->left = binary_tree_node(root->right, 97);
        binary_tree_print(root);
        avl = binary_tree_is_avl(root);
        printf("Is %d avl: %d\n", root->n, avl);

        root = basic_tree();
        root->right->right->right = binary_tree_node(root->right->right, 430);
        binary_tree_print(root);
        avl = binary_tree_is_avl(root);
        printf("Is %d avl: %d\n", root->n, avl);

        root->right->right->right->left = binary_tree_node(root->right->right->right, 420);
        binary_tree_print(root);
        avl = binary_tree_is_avl(root);
        printf("Is %d avl: %d\n", root->n, avl);
        return (0);
    }
`output`:

        .-------(098)--.
    .--(012)--.       (128)--.
    (010)     (054)          (402)
    Is 98 avl: 1
    Is 12 avl: 1
        .-------(098)-------.
    .--(012)--.         .--(128)--.
    (010)     (054)     (097)     (402)
    Is 98 avl: 0
        .-------(098)--.
    .--(012)--.       (128)--.
    (010)     (054)          (402)--.
                                (430)
    Is 98 avl: 0
        .-------(098)--.
    .--(012)--.       (128)--.
    (010)     (054)          (402)-------.
                                    .--(430)
                                (420)
    Is 98 avl: 0
`command to compile our program`:

    gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 120-main.c 120-binary_tree_is_avl.c 0-binary_tree_node.c -o 120-is_avl

and you can execute the file by entering `./120-is_avl`
</details>
<br  />

## Task35. [Big O #AVL Tree.](https://github.com/rmarcais/binary_trees/blob/main/125-O)
What are the average time complexities of those operations on an AVL Tree (one answer per line):


* Inserting the value `n`

* Removing the node with the value `n`

* Searching for a node in an AVL tree of size n

## Task41. [Big O #Binary Heap.](https://github.com/rmarcais/binary_trees/blob/main/135-O)
What are the average time complexities of those operations on a Binary Heap (one answer per line):


* Inserting the value `n`

* Extracting the root `node`

* Searching for a node in a binary heap of size n

## Clone the Repo

If you want to clone the repo to test our work, you can use this command on your terminal:

    git clone git@github.com:rmarcais/binary_trees.git

## Authors

<div class="author" style='background-color: #002060; color: #ffffff; border-left: solid  #DC0932 4px; border-radius: 4px; padding:0.7em;'>
<span>
<p style='margin-top:1em; text-align:left'>
<b> Anthony Lacoste </b>
</p>
<p style='margin-left:1em;'>
<a href="https://github.com/Anthony-6"> <img src="images/github_logo_icon_143772.png" alt="git" width="50"/>
<a href="https://www.linkedin.com/in/anthonylacoste-dev/"> <img src="images/Linkedin-logo-Transparent-Image-1024x1024.png" alt="linkedin" width="50"/>
</p>
</a>
</span>
</div>

<br/>

<div class="author" style='background-color: #FFFFFF; color: #000000
; border-left: solid  #30251F 4px; border-radius: 4px; padding:0.7em;'>
<span>
<p style='margin-top:1em; text-align:left'>
<b> Rémi Marçais </b>
</p>
<p style='margin-left:1em;'>
<a href="https://github.com/rmarcais"> <img src="images/github_logo_icon_143772.png" alt="git" width="50"/>
</a>
<a href="https://www.linkedin.com/in/elodieriou-dev/"> <img src="images/Linkedin-logo-Transparent-Image-1024x1024.png" alt="linkedin" width="50"/>
</p>
</a>
</span>
</div>

<br/>
<div class="author" style='background-color: #DC0932; color: #000000
; border-left: solid  #002060 4px; border-radius: 4px; padding:0.7em;'>
<span>
<p style='margin-top:1em; text-align:left'>
<b> Elodie Riou </b>
</p>
<p style='margin-left:1em;'>
<a href="https://github.com/rmarcais"> <img src="images/github_logo_icon_143772.png" alt="git" width="50"/>
<a href="https://www.linkedin.com/in/r%C3%A9mi-mar%C3%A7ais-274a4421a/"> <img src="images/Linkedin-logo-Transparent-Image-1024x1024.png" alt="linkedin" width="50"/>
</p>
</span>
</div>
