/*!
 * This file defines the inverse operation of joy/seq/pyzip.h.
 *
 * @author Louis Dionne
 */

#ifndef JOY_SEQ_PYUNZIP_H
#define JOY_SEQ_PYUNZIP_H

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/seq/transform.h>
#include <chaos/preprocessor/tuple/elem.h>


#define JOY_SEQ_PYUNZIP(seq) \
    JOY_SEQ_PYUNZIP_S(CHAOS_PP_STATE(), seq)

#define JOY_SEQ_PYUNZIP_S(s, seq)                                              \
    CHAOS_PP_EXPR_S(s) (                                                       \
        (CHAOS_PP_SEQ_TRANSFORM_S(s,                                           \
            JOY_I_SEQ_PYUNZIP_KEEP, seq, 0                                     \
        ),                                                                     \
        CHAOS_PP_SEQ_TRANSFORM_S(s,                                            \
            JOY_I_SEQ_PYUNZIP_KEEP, seq, 1                                     \
        ))                                                                     \
    )                                                                          \
/**/

#define JOY_I_SEQ_PYUNZIP_KEEP(s, pair, keep_at) \
    CHAOS_PP_TUPLE_ELEM(2, keep_at, pair)

#endif /* !JOY_SEQ_PYUNZIP_H */
