/*!
 * This file defines a macro to transform a string into a tuple.
 *
 * @author Louis Dionne
 */

#ifndef JOY_STRING_TO_TUPLE_H
#define JOY_STRING_TO_TUPLE_H

#include <chaos/preprocessor/algorithm/enumerate.h>
#include <chaos/preprocessor/limits.h>
#include <chaos/preprocessor/string/core.h>


/*!
 * Transform a string into a tuple.
 */
#define JOY_STRING_TO_TUPLE(string) \
    JOY_STRING_TO_TUPLE_S(CHAOS_PP_LIMIT_EXPR, string)

#define JOY_STRING_TO_TUPLE_S(s, string) \
    (CHAOS_PP_ENUMERATE_BYPASS(s, (CHAOS_PP_STRING) string))

#endif /* !JOY_STRING_TO_TUPLE_H */
