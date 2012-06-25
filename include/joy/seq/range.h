/*!
 * This file defines a Python-like range function for sequences.
 *
 * @author Louis Dionne
 */

#ifndef JOY_SEQ_RANGE_H
#define JOY_SEQ_RANGE_H

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/repetition/repeat_from_to.h>


#define JOY_SEQ_RANGE(from, to) \
    JOY_SEQ_RANGE_S(CHAOS_PP_STATE(), from, to)

#define JOY_SEQ_RANGE_S(s, from, to)                                           \
    CHAOS_PP_EXPR_S(s)(                                                        \
        CHAOS_PP_REPEAT_FROM_TO_S(s, from, to, JOY_I_SEQ_RANGE, ~)             \
    )                                                                          \
/**/

#define JOY_I_SEQ_RANGE(s, n, useless) (n)

#endif /* !JOY_SEQ_RANGE_H */
