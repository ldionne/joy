/*!
 * This file defines an interface to fold preprocessor strings into one token.
 *
 * @author Louis Dionne
 */

#ifndef JOY_INTERNAL_STRCAT_H
#define JOY_INTERNAL_STRCAT_H

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/algorithm/fold_right.h>
#include <chaos/preprocessor/string/core.h>


#define JOY_STRING_CAT(string) \
    JOY_STRING_CAT_S(CHAOS_PP_STATE(), string)

#define JOY_STRING_CAT_S(state, string)                                        \
    CHAOS_PP_EXPR_S(state) (                                                   \
        CHAOS_PP_FOLD_RIGHT_S(state,                                           \
            JOY_I_STRING_CAT_TWO,                                              \
            (CHAOS_PP_STRING) string,                                          \
            /* no initial state of accumulation */                             \
        )                                                                      \
    )                                                                          \
/**/

#define JOY_I_STRING_CAT_TWO(state, head, tail) \
    CHAOS_PP_CAT(head, tail)

#endif /* !JOY_INTERNAL_STRCAT_H */
