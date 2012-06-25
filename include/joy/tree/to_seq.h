/*!
 * This file defines a macro to transform a tree into a sequence.
 *
 * @author Louis Dionne
 */

#ifndef JOY_TREE_TO_SEQ_H
#define JOY_TREE_TO_SEQ_H

#include <joy/tree/empty.h>
#include <joy/bnode.h>

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/recursion/basic.h>
#include <chaos/preprocessor/control/branch.h>
#include <chaos/preprocessor/logical/not.h>


/*!
 * Transform a tree into a sequence.
 */
#define JOY_TREE_TO_SEQ(root) \
    JOY_TREE_TO_SEQ_S(CHAOS_PP_STATE(), root)

#define JOY_TREE_TO_SEQ_S(s, root)                                             \
    CHAOS_PP_EXPR_S(s) (                                                       \
        JOY_I_TREE_TO_SEQ(                                                     \
            CHAOS_PP_OBSTRUCT(), CHAOS_PP_NEXT(s), root                        \
        )                                                                      \
    )                                                                          \
/**/

#define JOY_I_TREE_TO_SEQ_ID() JOY_I_TREE_TO_SEQ
#define JOY_I_TREE_TO_SEQ(_, s, root) CHAOS_PP_BRANCH                          \
    (0xIF) (CHAOS_PP_NOT(JOY_TREE_EMPTY(root))) _(                             \
        CHAOS_PP_EXPR_S _(s) (                                                 \
            JOY_I_TREE_TO_SEQ_ID _() (CHAOS_PP_OBSTRUCT _(),                   \
                CHAOS_PP_NEXT(s), JOY_BNODE_LCHILD _(root)                     \
            )                                                                  \
        )                                                                      \
        (JOY_BNODE_DATA(root))                                                 \
        CHAOS_PP_EXPR_S _(s) (                                                 \
            JOY_I_TREE_TO_SEQ_ID _() (CHAOS_PP_OBSTRUCT _(),                   \
                CHAOS_PP_NEXT(s), JOY_BNODE_RCHILD _(root)                     \
            )                                                                  \
        )                                                                      \
    ) (0xENDIF)                                                                \
/**/

#endif /* !JOY_TREE_TO_SEQ_H */
