/*!
 * This file defines a macro to transform a set into a tuple.
 *
 * @author Louis Dionne
 */

#ifndef JOY_SET_TO_TUPLE_H
#define JOY_SET_TO_TUPLE_H

#include <joy/set/core.h>
#include <joy/tree/to_tuple.h>

#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Transform a set into a tuple.
 */
#define JOY_SET_TO_TUPLE(set) \
    JOY_SET_TO_TUPLE_S(CHAOS_PP_STATE(), set)

#define JOY_SET_TO_TUPLE_S(s, set) \
    JOY_TREE_TO_TUPLE_S(s, JOY_I_SET_TREE(set))


#endif /* !JOY_SET_TO_TUPLE_H */
