/*!
 * This file defines a macro to insert an element into a tree.
 *
 * @author Louis Dionne
 */

#ifndef JOY_TREE_INSERT_H
#define JOY_TREE_INSERT_H

#include <joy/bnode.h>
#include <joy/tree/empty.h>

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/recursion/basic.h>
#include <chaos/preprocessor/control/branch.h>


/*!
 * Return a tree with a new element inserted.
 *
 * If an element in the tree is determined to be equal to @p data, the old
 * element is replaced with the new one.
 */
#define JOY_TREE_INSERT(root, data, compare) \
    JOY_TREE_INSERT_S(CHAOS_PP_STATE(), root, data, compare)

#define JOY_TREE_INSERT_S(s, root, data, compare)                              \
    CHAOS_PP_EXPR_S(s) (                                                       \
        JOY_I_TREE_INSERT(                                                     \
            CHAOS_PP_OBSTRUCT(), CHAOS_PP_NEXT(s), root, data, compare         \
        )                                                                      \
    )                                                                          \
/**/

#define JOY_I_TREE_INSERT_ID() JOY_I_TREE_INSERT
#define JOY_I_TREE_INSERT(_, s, root, data, compare) CHAOS_PP_BRANCH           \
    (0xIF) (JOY_TREE_EMPTY(root)) (                                            \
        JOY_BNODE_LEAF(data)                                                   \
    ) (0xELIF) _(compare _(s, data, JOY_BNODE_DATA(root))) (                   \
        JOY_BNODE_SET_LCHILD _(                                                \
            root,                                                              \
            CHAOS_PP_EXPR_S _(s) (                                             \
                JOY_I_TREE_INSERT_ID _()(CHAOS_PP_OBSTRUCT _(),                \
                    CHAOS_PP_NEXT(s), JOY_BNODE_LCHILD _(root), data, compare  \
                )                                                              \
            )                                                                  \
        )                                                                      \
    ) (0xELIF) (compare _(s, JOY_BNODE_DATA _(root), data)) (                  \
        JOY_BNODE_SET_RCHILD _(                                                \
            root,                                                              \
            CHAOS_PP_EXPR_S _(s) (                                             \
                JOY_I_TREE_INSERT_ID _()(CHAOS_PP_OBSTRUCT _(),                \
                    CHAOS_PP_NEXT(s), JOY_BNODE_RCHILD _(root), data, compare  \
                )                                                              \
            )                                                                  \
        )                                                                      \
    ) (0xELSE) (                                                               \
        JOY_BNODE_SET_DATA _(root, data)                                       \
    ) (0xENDIF)                                                                \
/**/

#endif /* !JOY_TREE_INSERT_H */
