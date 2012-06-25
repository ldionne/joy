/*!
 * This file defines a macro to transform an array into a map.
 *
 * @author Louis Dionne
 */

#ifndef JOY_ARRAY_TO_MAP_H
#define JOY_ARRAY_TO_MAP_H

#include <joy/seq/to_map.h>

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/array/to_seq.h>


/*!
 * Transform an array into a map.
 *
 * @note The array must be an array of (key, value) tuples.
 */
#define JOY_ARRAY_TO_MAP(compare, array) \
    JOY_ARRAY_TO_MAP_S(CHAOS_PP_STATE(), compare, array)

#define JOY_ARRAY_TO_MAP_S(s, compare, array) \
    JOY_SEQ_TO_MAP_S(s, compare, CHAOS_PP_ARRAY_TO_SEQ(array))

#endif /* !JOY_ARRAY_TO_MAP_H */
