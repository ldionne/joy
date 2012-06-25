/*!
 * This file defines a macro to find an element in a set.
 *
 * @author Louis Dionne
 */

#ifndef JOY_SET_FIND_H
#define JOY_SET_FIND_H

#include <joy/search_result.h>
#include <joy/set/core.h>
#include <joy/set/value_cmp.h>
#include <joy/tree/search.h>

#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Return the specified value in a set.
 *
 * If the value is not found in the set, default is returned.
 */
#define JOY_SET_FIND(set, value, default) \
    JOY_SET_FIND_S(CHAOS_PP_STATE(), set, value, default)

#define JOY_SET_FIND_S(s, set, value, default) \
    JOY_SEARCH_RESULT_VALUE_D(JOY_I_SET_FIND(s, set, value), default)

#define JOY_I_SET_FIND(s, set, value)                                          \
    JOY_TREE_SEARCH_S(s,                                                       \
        JOY_I_SET_TREE(set), value, JOY_SET_VALUE_CMP(set)                     \
    )                                                                          \
/**/

#endif /* !JOY_SET_FIND_H */
