/*!
 * This file defines a macro to a map into an array.
 *
 * @author Louis Dionne
 */

#ifndef JOY_MAP_TO_ARRAY_H
#define JOY_MAP_TO_ARRAY_H

#include <joy/map/to_seq.h>

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/seq/to_array.h>


/*!
 * Transform a map into an array.
 */
#define JOY_MAP_TO_ARRAY(map) \
    JOY_MAP_TO_ARRAY_S(CHAOS_PP_STATE(), map)

#define JOY_MAP_TO_ARRAY_S(s, map) \
    CHAOS_PP_SEQ_TO_ARRAY(JOY_MAP_TO_SEQ_S(s, map))

#endif /* !JOY_MAP_TO_ARRAY_H */
