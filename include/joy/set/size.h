/*!
 * This file defines a macro to find the number of elements in a set.
 *
 * @author Louis Dionne
 */

#ifndef JOY_SET_SIZE_H
#define JOY_SET_SIZE_H

#include <joy/set/core.h>
#include <joy/tree/size.h>

#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Return the number of elements in a set.
 */
#define JOY_SET_SIZE(set) \
    JOY_SET_SIZE_S(CHAOS_PP_STATE(), set)

#define JOY_SET_SIZE_S(s, set) \
    JOY_TREE_SIZE_S(s, JOY_I_SET_TREE(set))

#endif /* !JOY_SET_SIZE_H */
