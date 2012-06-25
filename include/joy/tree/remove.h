/*!
 * This file defines a macro to remove an element of a tree.
 *
 * @author Louis Dionne
 */

#ifndef JOY_TREE_REMOVE_H
#define JOY_TREE_REMOVE_H

#include <joy/bnode.h>
#include <joy/tree/empty.h>
#include <joy/tree/remove_node.h>

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/recursion/basic.h>
#include <chaos/preprocessor/control/branch.h>


/*!
 * Return a tree with an element removed.
 *
 * If the element can't be found, nothing is done.
 */
#define JOY_TREE_REMOVE(root, data, compare) \
    JOY_TREE_REMOVE_S(CHAOS_PP_STATE(), root, data, compare)

#define JOY_TREE_REMOVE_S(s, root, data, compare)                              \
    CHAOS_PP_EXPR_S(s) (                                                       \
        JOY_I_TREE_REMOVE(                                                     \
            CHAOS_PP_OBSTRUCT(), CHAOS_PP_NEXT(s), root, data, compare         \
        )                                                                      \
    )                                                                          \
/**/

#define JOY_I_TREE_REMOVE_ID() JOY_I_TREE_REMOVE
#define JOY_I_TREE_REMOVE(_, s, root, data, compare) CHAOS_PP_BRANCH           \
    (0xIF) (JOY_TREE_EMPTY(root)) (                                            \
        root                                                                   \
    ) (0xELIF) _(compare _(s, data, JOY_BNODE_DATA(root))) (                   \
        JOY_BNODE_SET_LCHILD _(                                                \
            root,                                                              \
            CHAOS_PP_EXPR_S _(s) (                                             \
                JOY_I_TREE_REMOVE_ID _()(CHAOS_PP_OBSTRUCT _(),                \
                    CHAOS_PP_NEXT(s), JOY_BNODE_LCHILD _(root), data, compare  \
                )                                                              \
            )                                                                  \
        )                                                                      \
    ) (0xELIF) (compare _(s, JOY_BNODE_DATA _(root), data)) (                  \
        JOY_BNODE_SET_RCHILD _(                                                \
            root,                                                              \
            CHAOS_PP_EXPR_S _(s) (                                             \
                JOY_I_TREE_REMOVE_ID _()(CHAOS_PP_OBSTRUCT _(),                \
                    CHAOS_PP_NEXT(s), JOY_BNODE_RCHILD _(root), data, compare  \
                )                                                              \
            )                                                                  \
        )                                                                      \
    ) (0xELSE) (                                                               \
        JOY_TREE_REMOVE_NODE_S _(s, root)                                      \
    ) (0xENDIF)                                                                \
/**/

#endif /* !JOY_TREE_REMOVE_H */
