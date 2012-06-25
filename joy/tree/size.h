/*!
 * This file defines a macro to count the number of nodes in a tree.
 *
 * @author Louis Dionne
 */

#ifndef JOY_TREE_SIZE_H
#define JOY_TREE_SIZE_H

#include <joy/bnode.h>
#include <joy/tree/empty.h>

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/recursion/basic.h>
#include <chaos/preprocessor/control/branch.h>
#include <chaos/preprocessor/arithmetic/inc.h>
#include <chaos/preprocessor/arithmetic/add.h>


/*!
 * Return the number of elements in a tree.
 */
#define JOY_TREE_SIZE(root) \
    JOY_TREE_SIZE_S(CHAOS_PP_STATE(), root)

#define JOY_TREE_SIZE_S(s, root)                                               \
    CHAOS_PP_EXPR_S(s) (                                                       \
        JOY_I_TREE_SIZE(                                                       \
            CHAOS_PP_OBSTRUCT(), CHAOS_PP_NEXT(s), root                        \
        )                                                                      \
    )                                                                          \
/**/

#define JOY_I_TREE_SIZE_ID() JOY_I_TREE_SIZE
#define JOY_I_TREE_SIZE(_, s, root) CHAOS_PP_BRANCH                            \
    (0xIF) (JOY_TREE_EMPTY(root)) (                                            \
        0                                                                      \
    ) (0xELSE) _(                                                              \
        CHAOS_PP_INC _(                                                        \
            CHAOS_PP_ADD _(                                                    \
                CHAOS_PP_EXPR_S _(s) (                                         \
                    JOY_I_TREE_SIZE_ID _()(CHAOS_PP_OBSTRUCT _(),              \
                        CHAOS_PP_NEXT(s), JOY_BNODE_LCHILD _(root)             \
                    )                                                          \
                ),                                                             \
                CHAOS_PP_EXPR_S _(s) (                                         \
                    JOY_I_TREE_SIZE_ID _()(CHAOS_PP_OBSTRUCT _(),              \
                        CHAOS_PP_NEXT(s), JOY_BNODE_RCHILD _(root)             \
                    )                                                          \
                )                                                              \
            )                                                                  \
        )                                                                      \
    ) (0xENDIF)                                                                \
/**/

#endif /* !JOY_TREE_SIZE_H */
