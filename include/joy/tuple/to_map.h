/*!
 * This file defines a macro to transform a tuple into a map.
 *
 * @author Louis Dionne
 */

#ifndef JOY_TUPLE_TO_MAP_H
#define JOY_TUPLE_TO_MAP_H

#include <joy/seq/to_map.h>

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/tuple/to_seq.h>
#include <chaos/preprocessor/tuple/size.h>


/*!
 * Transform a tuple into a map.
 *
 * @note The tuple must be a tuple of (key, value) tuples.
 */
#define JOY_TUPLE_TO_MAP(compare, tuple) \
    JOY_TUPLE_TO_MAP_S(CHAOS_PP_STATE(), compare, tuple)

#define JOY_TUPLE_TO_MAP_S(s, compare, tuple)                                  \
    JOY_SEQ_TO_MAP_S(s,                                                        \
        compare, CHAOS_PP_TUPLE_TO_SEQ(CHAOS_PP_TUPLE_SIZE(tuple), tuple)      \
    )                                                                          \
/**/

#endif /* !JOY_TUPLE_TO_MAP_H */
