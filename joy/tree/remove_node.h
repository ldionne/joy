/*!
 * This file defines a macro to remove a known node from a tree.
 *
 * @author Louis Dionne
 */

#ifndef JOY_TREE_REMOVE_NODE_H
#define JOY_TREE_REMOVE_NODE_H

#include <joy/bnode.h>
#include <joy/tree/max.h>
#include <joy/tree/remove_max.h>

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/control/branch.h>


/*!
 * Perform removal of a node, acting differently whether it has zero, one or
 * two children.
 */
#define JOY_TREE_REMOVE_NODE(node) \
    JOY_TREE_REMOVE_NODE_S(CHAOS_PP_STATE(), node)

#define JOY_TREE_REMOVE_NODE_S(s, node) CHAOS_PP_BRANCH                        \
    (0xIF) (JOY_BNODE_IS_LEAF(node)) (                                         \
        JOY_BNODE_NULL()                                                       \
    ) (0xELIF) (JOY_BNODE_HAS_LCHILD(node)) (CHAOS_PP_BRANCH                   \
        (0xIF) (JOY_BNODE_HAS_RCHILD(node)) (                                  \
            JOY_BNODE_SET_CHILDREN(                                            \
                JOY_TREE_MAX_S(s, JOY_BNODE_LCHILD(node)),                     \
                JOY_TREE_REMOVE_MAX_S(s, JOY_BNODE_LCHILD(node)),              \
                JOY_BNODE_RCHILD(node)                                         \
            )                                                                  \
        ) (0xELSE) (                                                           \
            JOY_BNODE_LCHILD(node)                                             \
        ) (0xENDIF)                                                            \
    ) (0xELSE) (                                                               \
        JOY_BNODE_RCHILD(node)                                                 \
    ) (0xENDIF)                                                                \
/**/

#endif /* !JOY_TREE_REMOVE_NODE_H */
