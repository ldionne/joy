/*!
 * This file defines a macro to find an element in a sequence.
 *
 * @author Louis Dionne
 */

#ifndef JOY_SEQ_FIND_FIRST_H
#define JOY_SEQ_FIND_FIRST_H

#include <chaos/preprocessor/control/if.h>
#include <chaos/preprocessor/control/inline_when.h>
#include <chaos/preprocessor/recursion/basic.h>
#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/seq/core.h>


/*!
 * Return the first element of a sequence for which @p pred returned true.
 */
#define JOY_SEQ_FIND_FIRST(pred, seq, data) \
    JOY_SEQ_FIND_FIRST_S(CHAOS_PP_STATE(), pred, seq, data)

#define JOY_SEQ_FIND_FIRST_S(s, pred, seq, data)                               \
    CHAOS_PP_EXPR_S(s)(                                                        \
        JOY_I_SEQ_FIND_FIRST(                                                  \
            CHAOS_PP_OBSTRUCT(),                                               \
            CHAOS_PP_NEXT(s),                                                  \
            pred, seq, data))                                                  \
/**/

#define JOY_I_SEQ_FIND_FIRST_ID() JOY_I_SEQ_FIND_FIRST
#define JOY_I_SEQ_FIND_FIRST(_, s, pred, seq, data)                            \
    CHAOS_PP_INLINE_WHEN _(CHAOS_PP_SEQ_IS_CONS _(seq)) (                      \
        CHAOS_PP_IF _(pred _(s, CHAOS_PP_SEQ_HEAD _(seq), data)) (             \
            CHAOS_PP_SEQ_HEAD _(seq),                                          \
                                                                               \
            CHAOS_PP_EXPR_S _(s)(                                              \
                JOY_I_SEQ_FIND_FIRST_ID _()(                                   \
                    CHAOS_PP_OBSTRUCT _(),                                     \
                    CHAOS_PP_NEXT(s),                                          \
                    pred,                                                      \
                    CHAOS_PP_SEQ_TAIL _(seq),                                  \
                    data))))                                                   \
/**/

#endif /* !JOY_SEQ_FIND_FIRST_H */
