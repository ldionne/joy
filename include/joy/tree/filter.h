/*!
 * This file defines a macro to filter out elements of a tree.
 *
 * @author Louis Dionne
 */

#ifndef JOY_TREE_FILTER_H
#define JOY_TREE_FILTER_H

#include <joy/bnode.h>
#include <joy/tree/empty.h>
#include <joy/tree/remove_node.h>

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/recursion/basic.h>
#include <chaos/preprocessor/control/branch.h>
#include <chaos/preprocessor/control/if.h>


/*!
 * Filter nodes of the tree according to a predicate.
 *
 * @param predicate A macro(s, element, auxiliary_data) to determine
 *                  whether to keep an element.
 * @param data Auxiliary data passed to the predicate.
 */
#define JOY_TREE_FILTER(root, predicate, data) \
    JOY_TREE_FILTER_S(CHAOS_PP_STATE(), root, predicate, data)

#define JOY_TREE_FILTER_S(s, root, predicate, data)                            \
    CHAOS_PP_EXPR_S(s) (                                                       \
        JOY_I_TREE_FILTER(                                                     \
            CHAOS_PP_OBSTRUCT(), CHAOS_PP_NEXT(s), root, predicate, data       \
        )                                                                      \
    )                                                                          \
/**/

#define JOY_I_TREE_FILTER_ID() JOY_I_TREE_FILTER
#define JOY_I_TREE_FILTER(_, s, root, predicate, data) CHAOS_PP_BRANCH         \
        (0xIF) (JOY_TREE_EMPTY(root)) (                                        \
            root                                                               \
        ) (0xELSE) _(                                                          \
            JOY_I_TREE_FILTER_APPLY_UNLESS _(s,                                \
                predicate _(s, JOY_BNODE_DATA _(root), data),                  \
                JOY_TREE_REMOVE_NODE_S,                                        \
                JOY_BNODE_SET_CHILDREN _(root,                                 \
                    CHAOS_PP_EXPR_S _(s) (                                     \
                        JOY_I_TREE_FILTER_ID _() (CHAOS_PP_OBSTRUCT _(),       \
                            CHAOS_PP_NEXT(s), JOY_BNODE_LCHILD _(root),        \
                                                            predicate, data    \
                        )                                                      \
                    ),                                                         \
                    CHAOS_PP_EXPR_S _(s) (                                     \
                        JOY_I_TREE_FILTER_ID _() (CHAOS_PP_OBSTRUCT _(),       \
                            CHAOS_PP_NEXT(s), JOY_BNODE_RCHILD _(root),        \
                                                            predicate, data    \
                        )                                                      \
                    )                                                          \
                )                                                              \
            )                                                                  \
        ) (0xENDIF)                                                            \
/**/

#define JOY_I_TREE_FILTER_APPLY_UNLESS(s, cond, macro, arg)                    \
    CHAOS_PP_IF(cond) (                                                        \
        arg,                                                                   \
        macro(s, arg)                                                          \
    )                                                                          \
/**/

#endif /* !JOY_TREE_FILTER_H */
