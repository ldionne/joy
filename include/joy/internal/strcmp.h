/*!
 * This file defines an interface to compare preprocessor strings.
 *
 * @author Louis Dionne
 */

#ifndef JOY_INTERNAL_STRCMP_H
#define JOY_INTERNAL_STRCMP_H

#include <chaos/preprocessor/string/core.h>
#include <chaos/preprocessor/comparison/equal.h>
#include <chaos/preprocessor/comparison/not_equal.h>
#include <chaos/preprocessor/comparison/less.h>
#include <chaos/preprocessor/cat.h>
#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/recursion/basic.h>
#include <chaos/preprocessor/control/branch.h>
#include <chaos/preprocessor/control/if.h>


#define JOY_STRING_LESS(s1, s2) \
    JOY_STRING_LESS_S(CHAOS_PP_STATE(), s1, s2)

#define JOY_STRING_LESS_S(s, s1, s2)                                           \
    CHAOS_PP_EQUAL(                                                            \
        JOY_STRING_COMPARE_S(s, s1, s2),                                       \
        JOY_I_STRING_LESS_VALUE                                                \
    )                                                                          \
/**/

#define JOY_STRING_GREATER(s1, s2) \
    JOY_STRING_LESS(s2, s1)

#define JOY_STRING_GREATER_S(s, s1, s2) \
    JOY_STRING_LESS_S(s, s2, s1)

#define JOY_STRING_EQUAL(s1, s2) \
    JOY_STRING_EQUAL_S(CHAOS_PP_STATE(), s1, s2)

#define JOY_STRING_EQUAL_S(s, s1, s2)                                          \
    CHAOS_PP_EQUAL(                                                            \
        JOY_STRING_COMPARE_S(s, s1, s2),                                       \
        JOY_I_STRING_EQUAL_VALUE                                               \
    )                                                                          \
/**/

#define JOY_STRING_COMPARE(s1, s2) \
    JOY_STRING_COMPARE_S(CHAOS_PP_STATE(), s1, s2)

#define JOY_STRING_COMPARE_S(s, s1, s2)                                        \
    CHAOS_PP_EXPR_S(s) (                                                       \
        JOY_I_STRING_COMPARE(CHAOS_PP_OBSTRUCT(), CHAOS_PP_NEXT(s),            \
            s1, s2                                                             \
        )                                                                      \
    )                                                                          \
/**/

#define JOY_I_STRING_COMPARE(_, s, s1, s2) CHAOS_PP_BRANCH                     \
    (0xIF) (CHAOS_PP_STRING_IS_NIL(s1)) (                                      \
        CHAOS_PP_IF(CHAOS_PP_STRING_IS_CONS(s2)) (                             \
            JOY_I_STRING_LESS_VALUE,                                           \
            JOY_I_STRING_EQUAL_VALUE                                           \
        )                                                                      \
    ) (0xELIF) (CHAOS_PP_STRING_IS_NIL(s2)) (                                  \
        JOY_I_STRING_GREATER_VALUE                                             \
    ) (0xELSE) _(                                                              \
        CHAOS_PP_EXPR_S _(s) (                                                 \
            JOY_I_STRING_COMPARE_CONTINUE_MAYBE _(CHAOS_PP_OBSTRUCT _(),       \
                CHAOS_PP_NEXT(s),                                              \
                JOY_I_CHAR_COMPARE _(                                          \
                    CHAOS_PP_STRING_HEAD _(s1), CHAOS_PP_STRING_HEAD _(s2)     \
                ), s1, s2                                                      \
            )                                                                  \
        )                                                                      \
    ) (0xENDIF)                                                                \
/**/

#define JOY_I_STRING_COMPARE_CONTINUE_MAYBE(_, s, comparison, s1, s2)          \
    CHAOS_PP_IF(CHAOS_PP_NOT_EQUAL(comparison, JOY_I_STRING_EQUAL_VALUE)) _(   \
        comparison,                                                            \
        CHAOS_PP_EXPR_S _(s) (                                                 \
            JOY_I_STRING_COMPARE _(CHAOS_PP_OBSTRUCT _(), CHAOS_PP_NEXT(s),    \
                CHAOS_PP_STRING_TAIL _(s1), CHAOS_PP_STRING_TAIL _(s2)         \
            )                                                                  \
        )                                                                      \
    )                                                                          \
/**/

#define JOY_I_CHAR_COMPARE(a, b) \
    JOY_I_CHAR_COMPARE_I(JOY_I_CHAR_VALUE(a), JOY_I_CHAR_VALUE(b))

#define JOY_I_CHAR_COMPARE_I(a, b) CHAOS_PP_BRANCH                             \
    (0xIF) (CHAOS_PP_EQUAL(a, b)) (                                            \
        JOY_I_STRING_EQUAL_VALUE                                               \
    ) (0xELIF) (CHAOS_PP_LESS(a, b)) (                                         \
        JOY_I_STRING_LESS_VALUE                                                \
    ) (0xELSE) (                                                               \
        JOY_I_STRING_GREATER_VALUE                                             \
    ) (0xENDIF)                                                                \
/**/

#define JOY_I_STRING_LESS_VALUE 1
#define JOY_I_STRING_EQUAL_VALUE 0
#define JOY_I_STRING_GREATER_VALUE 2


#define JOY_I_CHAR_VALUE(c) CHAOS_PP_CAT(JOY_I_CHAR_VALUE_, c)

#define JOY_I_CHAR_VALUE__ 95
#define JOY_I_CHAR_VALUE_0 48
#define JOY_I_CHAR_VALUE_1 49
#define JOY_I_CHAR_VALUE_2 50
#define JOY_I_CHAR_VALUE_3 51
#define JOY_I_CHAR_VALUE_4 52
#define JOY_I_CHAR_VALUE_5 53
#define JOY_I_CHAR_VALUE_6 54
#define JOY_I_CHAR_VALUE_7 55
#define JOY_I_CHAR_VALUE_8 56
#define JOY_I_CHAR_VALUE_9 57
#define JOY_I_CHAR_VALUE_a 97
#define JOY_I_CHAR_VALUE_b 98
#define JOY_I_CHAR_VALUE_c 99
#define JOY_I_CHAR_VALUE_d 100
#define JOY_I_CHAR_VALUE_e 101
#define JOY_I_CHAR_VALUE_f 102
#define JOY_I_CHAR_VALUE_g 103
#define JOY_I_CHAR_VALUE_h 104
#define JOY_I_CHAR_VALUE_i 105
#define JOY_I_CHAR_VALUE_j 106
#define JOY_I_CHAR_VALUE_k 107
#define JOY_I_CHAR_VALUE_l 108
#define JOY_I_CHAR_VALUE_m 109
#define JOY_I_CHAR_VALUE_n 110
#define JOY_I_CHAR_VALUE_o 111
#define JOY_I_CHAR_VALUE_p 112
#define JOY_I_CHAR_VALUE_q 113
#define JOY_I_CHAR_VALUE_r 114
#define JOY_I_CHAR_VALUE_s 115
#define JOY_I_CHAR_VALUE_t 116
#define JOY_I_CHAR_VALUE_u 117
#define JOY_I_CHAR_VALUE_v 118
#define JOY_I_CHAR_VALUE_w 119
#define JOY_I_CHAR_VALUE_x 120
#define JOY_I_CHAR_VALUE_y 121
#define JOY_I_CHAR_VALUE_z 122
#define JOY_I_CHAR_VALUE_A 65
#define JOY_I_CHAR_VALUE_B 66
#define JOY_I_CHAR_VALUE_C 67
#define JOY_I_CHAR_VALUE_D 68
#define JOY_I_CHAR_VALUE_E 69
#define JOY_I_CHAR_VALUE_F 70
#define JOY_I_CHAR_VALUE_G 71
#define JOY_I_CHAR_VALUE_H 72
#define JOY_I_CHAR_VALUE_I 73
#define JOY_I_CHAR_VALUE_J 74
#define JOY_I_CHAR_VALUE_K 75
#define JOY_I_CHAR_VALUE_L 76
#define JOY_I_CHAR_VALUE_M 77
#define JOY_I_CHAR_VALUE_N 78
#define JOY_I_CHAR_VALUE_O 79
#define JOY_I_CHAR_VALUE_P 80
#define JOY_I_CHAR_VALUE_Q 81
#define JOY_I_CHAR_VALUE_R 82
#define JOY_I_CHAR_VALUE_S 83
#define JOY_I_CHAR_VALUE_T 84
#define JOY_I_CHAR_VALUE_U 85
#define JOY_I_CHAR_VALUE_V 86
#define JOY_I_CHAR_VALUE_W 87
#define JOY_I_CHAR_VALUE_X 88
#define JOY_I_CHAR_VALUE_Y 89
#define JOY_I_CHAR_VALUE_Z 90

#endif /* !JOY_INTERNAL_STRCMP_H */
