/*!
 * This file defines a macro to find an element in a sequence.
 *
 * @author Louis Dionne
 */

#ifndef JOY_SEQ_FIND_FIRST_H
#define JOY_SEQ_FIND_FIRST_H

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/seq/filter.h>
#include <chaos/preprocessor/seq/core.h>


/*!
 * Return the first element of a sequence for which @p pred returned true.
 */
#define JOY_SEQ_FIND_FIRST(pred, seq, data) \
    JOY_SEQ_FIND_FIRST_S(CHAOS_PP_STATE(), pred, seq, data)

#define JOY_SEQ_FIND_FIRST_S(s, pred, seq, data)                               \
    CHAOS_PP_SEQ_HEAD(                                                         \
        CHAOS_PP_EXPR_S(s)(CHAOS_PP_SEQ_FILTER_S(s, pred, seq, data))          \
    )                                                                          \
/**/

#endif /* !JOY_SEQ_FIND_FIRST_H */
