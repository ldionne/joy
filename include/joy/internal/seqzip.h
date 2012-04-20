/*!
 * This file defines a Python-like zip function for sequences.
 *
 * @author Louis Dionne
 */

#ifndef JOY_INTERNAL_SEQZIP_H
#define JOY_INTERNAL_SEQZIP_H

#include <chaos/preprocessor/logical/or.h>
#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/recursion/basic.h>
#include <chaos/preprocessor/control/unless.h>
#include <chaos/preprocessor/seq/core.h>


#define JOY_SEQZIP(seq1, seq2) \
    JOY_SEQZIP_S(CHAOS_PP_STATE(), seq1, seq2)

#define JOY_SEQZIP_S(state, seq1, seq2)                                        \
    CHAOS_PP_EXPR_S(state)(                                                    \
        JOY_I_SEQZIP(CHAOS_PP_OBSTRUCT(), CHAOS_PP_NEXT(state), seq1, seq2)    \
    )                                                                          \
/**/

#define JOY_I_SEQZIP_ID() JOY_I_SEQZIP
#define JOY_I_SEQZIP(_, state, seq1, seq2)                                     \
    CHAOS_PP_UNLESS(                                                           \
        CHAOS_PP_OR (CHAOS_PP_SEQ_IS_NIL(seq1)) (CHAOS_PP_SEQ_IS_NIL(seq2))    \
    ) _(                                                                       \
        ((CHAOS_PP_SEQ_HEAD(seq1), CHAOS_PP_SEQ_HEAD(seq2)))                   \
        CHAOS_PP_EXPR_S _(state) (                                             \
            JOY_I_SEQZIP_ID _() (CHAOS_PP_OBSTRUCT _(), CHAOS_PP_NEXT(state),  \
                CHAOS_PP_SEQ_TAIL(seq1), CHAOS_PP_SEQ_TAIL(seq2)               \
            )                                                                  \
        )                                                                      \
    )                                                                          \
/**/

#define JOY_SEQUNZIP(seq) \
    JOY_SEQUNZIP_S(CHAOS_PP_STATE(), seq)

#define JOY_SEQUNZIP_S(state, seq)                                             \
    CHAOS_PP_EXPR_S(state) (                                                   \
        (CHAOS_PP_SEQ_TRANSFORM_S(state,                                       \
            JOY_I_SEQ_UNZIP_KEEP, seq, 0                                       \
        ),                                                                     \
        CHAOS_PP_SEQ_TRANSFORM_S(state,                                        \
            JOY_I_SEQ_UNZIP_KEEP, seq, 1                                       \
        ))                                                                     \
    )                                                                          \
/**/

#define JOY_I_SEQ_UNZIP_KEEP(state, pair, keep_at) \
    CHAOS_PP_TUPLE_ELEM(2, keep_at, pair)

#define JOY_SEQ_UNZIP(seq) \
    JOY_SEQ_UNZIP_S(CHAOS_PP_STATE(), seq)

#define JOY_SEQ_UNZIP_S(state, seq)                                            \
    JOY_SEQ_UNZIP_EXCEPTION_NOT_IMPLEMENTED(!)                                 \
/**/

#define JOY_SEQ_UNZIP_EXCEPTION_NOT_IMPLEMENTED()

#endif /* !JOY_INTERNAL_SEQZIP_H */
