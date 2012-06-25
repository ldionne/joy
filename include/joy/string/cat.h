/*!
 * This file defines an interface to fold preprocessor strings into one token.
 *
 * @author Louis Dionne
 */

#ifndef JOY_STRING_CAT_H
#define JOY_STRING_CAT_H

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/algorithm/fold_right.h>
#include <chaos/preprocessor/string/core.h>


#define JOY_STRING_CAT(string) \
    JOY_STRING_CAT_S(CHAOS_PP_STATE(), string)

#define JOY_STRING_CAT_S(s, string)                                            \
    CHAOS_PP_EXPR_S(s) (                                                       \
        CHAOS_PP_FOLD_RIGHT_S(s,                                               \
            JOY_I_STRING_CAT_TWO,                                              \
            (CHAOS_PP_STRING) string,                                          \
            /* no initial state of accumulation */                             \
        )                                                                      \
    )                                                                          \
/**/

#define JOY_I_STRING_CAT_TWO(s, head, tail) \
    CHAOS_PP_CAT(head, tail)

#endif /* !JOY_STRING_CAT_H */
