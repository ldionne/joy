/*!
 * This file defines a macro to check whether a set contains a given element.
 *
 * @author Louis Dionne
 */

#ifndef JOY_SET_CONTAINS_H
#define JOY_SET_CONTAINS_H

#include <joy/set/core.h>
#include <joy/set/value_cmp.h>
#include <joy/tree/contains.h>

#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Return whether a set contains a given element.
 */
#define JOY_SET_CONTAINS(set, value) \
    JOY_SET_CONTAINS_S(CHAOS_PP_STATE(), set, value)

#define JOY_SET_CONTAINS_S(s, set, value)                                      \
    JOY_TREE_CONTAINS_S(s,                                                     \
        JOY_I_SET_TREE(set), value, JOY_SET_VALUE_CMP(set)                     \
    )                                                                          \
/**/

#endif /* !JOY_SET_CONTAINS_H */
