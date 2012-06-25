/*!
 * This file defines a macro to retrieve the maximum element of a tree.
 *
 * @author Louis Dionne
 */

#ifndef JOY_TREE_MAX_H
#define JOY_TREE_MAX_H

#include <joy/bnode.h>

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/recursion/basic.h>
#include <chaos/preprocessor/control/branch.h>


/*!
 * Return the maximum node of a tree.
 */
#define JOY_TREE_MAX(root) \
    JOY_TREE_MAX_S(CHAOS_PP_STATE(), root)

#define JOY_TREE_MAX_S(s, root)                                                \
    CHAOS_PP_EXPR_S(s) (                                                       \
        JOY_I_TREE_MAX(                                                        \
            CHAOS_PP_OBSTRUCT(), CHAOS_PP_NEXT(s), root                        \
        )                                                                      \
    )                                                                          \
/**/

#define JOY_I_TREE_MAX_ID() JOY_I_TREE_MAX
#define JOY_I_TREE_MAX(_, s, root) CHAOS_PP_BRANCH                             \
    (0xIF) (JOY_BNODE_HAS_RCHILD(root)) _(                                     \
        CHAOS_PP_EXPR_S _(s) (                                                 \
            JOY_I_TREE_MAX_ID _()(CHAOS_PP_OBSTRUCT _(),                       \
                CHAOS_PP_NEXT(s), JOY_BNODE_RCHILD _(root)                     \
            )                                                                  \
        )                                                                      \
    ) (0xELSE) (                                                               \
        root                                                                   \
    ) (0xENDIF)                                                                \
/**/

#endif /* !JOY_TREE_MAX_H */
