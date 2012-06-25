/*!
 * This file defines a macro to find out whether some element is in a sequence.
 *
 * @author Louis Dionne
 */

#ifndef JOY_SEQ_CONTAINS_H
#define JOY_SEQ_CONTAINS_H

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/seq/filter.h>
#include <chaos/preprocessor/seq/core.h>


/*!
 * Return whether @p pred returned true for an element in the sequence.
 */
#define JOY_SEQ_CONTAINS(pred, seq, data) \
    JOY_SEQ_CONTAINS_S(CHAOS_PP_STATE(), pred, seq, data)

#define JOY_SEQ_CONTAINS_S(s, pred, seq, data)                                 \
    CHAOS_PP_SEQ_IS_CONS(                                                      \
        CHAOS_PP_EXPR_S(s)(CHAOS_PP_SEQ_FILTER_S(s, pred, seq, data))          \
    )                                                                          \
/**/

#endif /* !JOY_SEQ_CONTAINS_H */
