/*!
 * This file defines a macro to transform a sequence into a tree.
 *
 * @author Louis Dionne
 */

#ifndef JOY_SEQ_TO_TREE_H
#define JOY_SEQ_TO_TREE_H

#include <joy/tree/core.h>
#include <joy/bnode.h>

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/seq/fold_left.h>
#include <chaos/preprocessor/seq/core.h>
#include <chaos/preprocessor/generics/strip.h>
#include <chaos/preprocessor/algorithm/merge_sort.h>


/*!
 * Transform a sequence into a tree.
 */
#define JOY_SEQ_TO_TREE(compare, seq) \
    JOY_SEQ_TO_TREE_S(CHAOS_PP_STATE(), compare, seq)

#define JOY_SEQ_TO_TREE_S(s, compare, seq)                                     \
    CHAOS_PP_EXPR_S(s) (                                                       \
        CHAOS_PP_SEQ_FOLD_LEFT_S(CHAOS_PP_NEXT(s),                             \
            JOY_I_SEQ_TO_TREE_ACCUMULATE,                                      \
            JOY_I_SEQ_TO_TREE_PREPARE(CHAOS_PP_NEXT(s),                        \
                compare, seq                                                   \
            ),                                                                 \
            JOY_TREE()                                                         \
        )                                                                      \
    )                                                                          \
/**/

#define JOY_I_SEQ_TO_TREE_PREPARE(s, compare, seq)                             \
    CHAOS_PP_STRIP(                                                            \
        CHAOS_PP_EXPR_S(s) (CHAOS_PP_MERGE_SORT_S(CHAOS_PP_NEXT(s),            \
            compare, (CHAOS_PP_SEQ) seq                                        \
        ))                                                                     \
    )                                                                          \
/**/

#define JOY_I_SEQ_TO_TREE_ACCUMULATE(s, elem, tree) \
    JOY_BNODE(tree, elem, JOY_TREE())

#endif /* !JOY_SEQ_TO_TREE_H */
