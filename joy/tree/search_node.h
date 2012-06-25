/*!
 * This file defines a macro to search into a binary tree.
 *
 * @author Louis Dionne
 */

#ifndef JOY_TREE_SEARCH_NODE_H
#define JOY_TREE_SEARCH_NODE_H

#include <joy/search_result.h>
#include <joy/bnode.h>
#include <joy/tree/empty.h>

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/recursion/basic.h>
#include <chaos/preprocessor/control/branch.h>


/*!
 * Return a search result object containing the node in the tree whose data
 * element is equal to the data argument.
 *
 * @param compare A macro acting as the strict weak ordering operator (<).
 *                Its prototype must match :
 *                @code compare(s, data1, data2) @endcode
 */
#define JOY_TREE_SEARCH_NODE(root, data, compare) \
    JOY_TREE_SEARCH_NODE_S(CHAOS_PP_STATE(), root, data, compare)

#define JOY_TREE_SEARCH_NODE_S(s, root, data, compare)                         \
    CHAOS_PP_EXPR_S(s) (                                                       \
        JOY_I_TREE_SEARCH_NODE(                                                \
            CHAOS_PP_OBSTRUCT(), CHAOS_PP_NEXT(s), root, data, compare         \
        )                                                                      \
    )                                                                          \
/**/

#define JOY_I_TREE_SEARCH_NODE_ID() JOY_I_TREE_SEARCH_NODE
#define JOY_I_TREE_SEARCH_NODE(_, s, root, data, compare) CHAOS_PP_BRANCH      \
    (0xIF) (JOY_TREE_EMPTY(root)) (                                            \
        JOY_SEARCH_RESULT(root, 0)                                             \
    ) (0xELIF) _(compare _(s, data, JOY_BNODE_DATA(root))) (                   \
        CHAOS_PP_EXPR_S _(s) (                                                 \
            JOY_I_TREE_SEARCH_NODE_ID _() (CHAOS_PP_OBSTRUCT _(),              \
                CHAOS_PP_NEXT(s), JOY_BNODE_LCHILD _(root), data, compare      \
            )                                                                  \
        )                                                                      \
    ) (0xELIF) (compare _(s, JOY_BNODE_DATA _(root), data)) (                  \
        CHAOS_PP_EXPR_S _(s) (                                                 \
            JOY_I_TREE_SEARCH_NODE_ID _() (CHAOS_PP_OBSTRUCT _(),              \
                CHAOS_PP_NEXT(s), JOY_BNODE_RCHILD _(root), data, compare      \
            )                                                                  \
        )                                                                      \
    ) (0xELSE) (                                                               \
        JOY_SEARCH_RESULT _(root, 1)                                           \
    ) (0xENDIF)                                                                \
/**/

#endif /* !JOY_TREE_SEARCH_NODE_H */
