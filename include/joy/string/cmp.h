/*!
 * This file defines an interface to compare preprocessor strings.
 *
 * @author Louis Dionne
 */

#ifndef JOY_STRING_CMP_H
#define JOY_STRING_CMP_H

#include <joy/char/cmp.h>

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/recursion/basic.h>
#include <chaos/preprocessor/control/branch.h>
#include <chaos/preprocessor/control/if.h>
#include <chaos/preprocessor/string/core.h>
#include <chaos/preprocessor/comparison/not_equal.h>


#define JOY_STRING_CMP(s1, s2) \
    JOY_STRING_CMP_S(CHAOS_PP_STATE(), s1, s2)

#define JOY_STRING_CMP_S(s, s1, s2)                                            \
    CHAOS_PP_EXPR_S(s) (                                                       \
        JOY_I_STRING_CMP(CHAOS_PP_OBSTRUCT(), CHAOS_PP_NEXT(s),                \
            s1, s2                                                             \
        )                                                                      \
    )                                                                          \
/**/

#define JOY_I_STRING_CMP(_, s, s1, s2) CHAOS_PP_BRANCH                         \
    (0xIF) (CHAOS_PP_STRING_IS_NIL(s1)) (                                      \
        CHAOS_PP_IF(CHAOS_PP_STRING_IS_CONS(s2)) (                             \
            JOY_STRING_CMP_LESSER,                                             \
            JOY_STRING_CMP_EQUAL                                               \
        )                                                                      \
    ) (0xELIF) (CHAOS_PP_STRING_IS_NIL(s2)) (                                  \
        JOY_STRING_CMP_GREATER                                                 \
    ) (0xELSE) _(                                                              \
        CHAOS_PP_EXPR_S _(s) (                                                 \
            JOY_I_STRING_CMP_CONTINUE_MAYBE _(CHAOS_PP_OBSTRUCT _(),           \
                CHAOS_PP_NEXT(s),                                              \
                JOY_CHAR_CMP _(                                                \
                    CHAOS_PP_STRING_HEAD _(s1), CHAOS_PP_STRING_HEAD _(s2)     \
                ), s1, s2                                                      \
            )                                                                  \
        )                                                                      \
    ) (0xENDIF)                                                                \
/**/

#define JOY_I_STRING_CMP_CONTINUE_MAYBE(_, s, comparison, s1, s2)              \
    CHAOS_PP_IF(CHAOS_PP_NOT_EQUAL(comparison, JOY_CHAR_CMP_EQUAL)) _(         \
        comparison,                                                            \
        CHAOS_PP_EXPR_S _(s) (                                                 \
            JOY_I_STRING_CMP _(CHAOS_PP_OBSTRUCT _(), CHAOS_PP_NEXT(s),        \
                CHAOS_PP_STRING_TAIL _(s1), CHAOS_PP_STRING_TAIL _(s2)         \
            )                                                                  \
        )                                                                      \
    )                                                                          \
/**/

#define JOY_STRING_CMP_EQUAL JOY_CHAR_CMP_EQUAL
#define JOY_STRING_CMP_LESSER JOY_CHAR_CMP_LESSER
#define JOY_STRING_CMP_GREATER JOY_CHAR_CMP_GREATER

#endif /* !JOY_STRING_CMP_H */
