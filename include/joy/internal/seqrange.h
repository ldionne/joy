/*!
 * This file defines a Python-like range function for sequences.
 *
 * @author Louis Dionne
 */

#ifndef JOY_INTERNAL_SEQRANGE_H
#define JOY_INTERNAL_SEQRANGE_H

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/repetition/repeat_from_to.h>


#define JOY_SEQRANGE(from, to) \
    JOY_SEQRANGE_S(CHAOS_PP_STATE(), from, to)

#define JOY_SEQRANGE_S(state, from, to)                                        \
    CHAOS_PP_EXPR_S(state)(                                                    \
        CHAOS_PP_REPEAT_FROM_TO_S(state, from, to, JOY_I_SEQRANGE, ~)          \
    )                                                                          \
/**/

#define JOY_I_SEQRANGE(state, n, useless) (n)

#endif /* !JOY_INTERNAL_SEQRANGE_H */
