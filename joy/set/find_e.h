/*!
 * This file defines a macro to find an element in a set.
 *
 * @author Louis Dionne
 */

#ifndef JOY_SET_FIND_E_H
#define JOY_SET_FIND_E_H

#include <joy/search_value.h>

#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Return the specified value in a set.
 *
 * If the value is not found in the set, a preprocessor error is triggered.
 */
#define JOY_SET_FIND_E(set, value) \
    JOY_SET_FIND_E_S(CHAOS_PP_STATE(), set, value)

#define JOY_SET_FIND_E_S(s, set, value) \
    JOY_SEARCH_RESULT_VALUE_E(JOY_I_SET_FIND(s, set, value))

#endif /* !JOY_SET_FIND_E_H */
