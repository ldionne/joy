/*!
 * This file defines a macro to a map into a tuple.
 *
 * @author Louis Dionne
 */

#ifndef JOY_MAP_TO_TUPLE_H
#define JOY_MAP_TO_TUPLE_H

#include <joy/map/to_seq.h>

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/seq/to_tuple.h>


/*!
 * Transform a map into a tuple.
 */
#define JOY_MAP_TO_TUPLE(map) \
    JOY_MAP_TO_TUPLE_S(CHAOS_PP_STATE(), map)

#define JOY_MAP_TO_TUPLE_S(s, map) \
    CHAOS_PP_SEQ_TO_TUPLE(JOY_MAP_TO_SEQ_S(s, map))

#endif /* !JOY_MAP_TO_TUPLE_H */
