/*!
 * This file defines a macro to transform an array into a set.
 *
 * @author Louis Dionne
 */

#ifndef JOY_ARRAY_TO_SET_H
#define JOY_ARRAY_TO_SET_H

#include <joy/seq/to_set.h>

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/array/to_seq.h>


/*!
 * Transform an array into a set.
 */
#define JOY_ARRAY_TO_SET(compare, array) \
    JOY_ARRAY_TO_SET_S(CHAOS_PP_STATE(), compare, array)

#define JOY_ARRAY_TO_SET_S(s, compare, array) \
    JOY_SEQ_TO_SET_S(s, compare, CHAOS_PP_ARRAY_TO_SEQ(array))

#endif /* !JOY_ARRAY_TO_SET_H */
