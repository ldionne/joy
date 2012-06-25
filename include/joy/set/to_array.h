/*!
 * This file defines a macro to transform a set into an array.
 *
 * @author Louis Dionne
 */

#ifndef JOY_SET_TO_ARRAY_H
#define JOY_SET_TO_ARRAY_H

#include <joy/set/core.h>
#include <joy/tree/to_array.h>

#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Transform a set into an array.
 */
#define JOY_SET_TO_ARRAY(set) \
    JOY_SET_TO_ARRAY_S(CHAOS_PP_STATE(), set)

#define JOY_SET_TO_ARRAY_S(s, set) \
    JOY_TREE_TO_ARRAY_S(s, JOY_I_SET_TREE(set))


#endif /* !JOY_SET_TO_ARRAY_H */
