/*!
 * This file defines a macro to transform a sequence into a set.
 *
 * @author Louis Dionne
 */

#ifndef JOY_SEQ_TO_SET_H
#define JOY_SEQ_TO_SET_H

#include <joy/seq/to_tree.h>
#include <joy/set/core.h>

#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Transform a sequence into a set.
 */
#define JOY_SEQ_TO_SET(compare, seq) \
    JOY_SEQ_TO_SET_S(CHAOS_PP_STATE(), compare, seq)

#define JOY_SEQ_TO_SET_S(s, compare, seq)                                      \
    JOY_I_SET_SET_TREE(                                                        \
        JOY_SET(compare), JOY_SEQ_TO_TREE_S(s, compare, seq)                   \
    )                                                                          \
/**/

#endif /* !JOY_SEQ_TO_SET_H */
