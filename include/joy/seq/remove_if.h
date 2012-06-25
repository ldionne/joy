/*!
 * This file defines a macro to remove specific elements in a sequence.
 *
 * @author Louis Dionne
 */

#ifndef JOY_SEQ_REMOVE_IF_H
#define JOY_SEQ_REMOVE_IF_H

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/seq/filter.h>
#include <chaos/preprocessor/logical/not.h>


/*!
 * Return a sequence with all the elements for which @p pred returned true
 * removed.
 */
#define JOY_SEQ_REMOVE_IF(pred, seq, data) \
    JOY_SEQ_REMOVE_IF_S(CHAOS_PP_STATE(), pred, seq, data)

#define JOY_SEQ_REMOVE_IF_S(s, pred, seq, data)                                \
    CHAOS_PP_EXPR_S(s)(                                                        \
        CHAOS_PP_SEQ_FILTER_S(s, JOY_I_SEQ_REMOVE_IF, seq, JOY_PAIR(pred, data)) \
    )                                                                          \
/**/

#define JOY_I_SEQ_REMOVE_IF(s, elem, data)                                     \
    CHAOS_PP_NOT(                                                              \
        JOY_PAIR_FIRST(data)(s, elem, JOY_PAIR_SECOND(data))                   \
    )                                                                          \
/**/

#endif /* !JOY_SEQ_REMOVE_IF_H */
