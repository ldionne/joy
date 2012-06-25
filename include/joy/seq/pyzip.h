/*!
 * This file defines a Python-like zip function for sequences.
 *
 * @author Louis Dionne
 */

#ifndef JOY_SEQ_PYZIP_H
#define JOY_SEQ_PYZIP_H

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/recursion/basic.h>
#include <chaos/preprocessor/control/unless.h>
#include <chaos/preprocessor/logical/or.h>
#include <chaos/preprocessor/seq/core.h>


#define JOY_SEQ_PYZIP(seq1, seq2) \
    JOY_SEQ_PYZIP_S(CHAOS_PP_STATE(), seq1, seq2)

#define JOY_SEQ_PYZIP_S(s, seq1, seq2)                                         \
    CHAOS_PP_EXPR_S(s)(                                                        \
        JOY_I_SEQ_PYZIP(CHAOS_PP_OBSTRUCT(), CHAOS_PP_NEXT(s), seq1, seq2)     \
    )                                                                          \
/**/

#define JOY_I_SEQ_PYZIP_ID() JOY_I_SEQ_PYZIP
#define JOY_I_SEQ_PYZIP(_, s, seq1, seq2)                                      \
    CHAOS_PP_UNLESS(                                                           \
        CHAOS_PP_OR(CHAOS_PP_SEQ_IS_NIL(seq1)) (CHAOS_PP_SEQ_IS_NIL(seq2))     \
    ) _(                                                                       \
        ((CHAOS_PP_SEQ_HEAD(seq1), CHAOS_PP_SEQ_HEAD(seq2)))                   \
        CHAOS_PP_EXPR_S _(s) (                                                 \
            JOY_I_SEQ_PYZIP_ID _() (CHAOS_PP_OBSTRUCT _(), CHAOS_PP_NEXT(s),   \
                CHAOS_PP_SEQ_TAIL(seq1), CHAOS_PP_SEQ_TAIL(seq2)               \
            )                                                                  \
        )                                                                      \
    )                                                                          \
/**/

#endif /* !JOY_SEQ_PYZIP_H */
