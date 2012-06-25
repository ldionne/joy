/*!
 * This file defines a macro to a map into a sequence.
 *
 * @author Louis Dionne
 */

#ifndef JOY_MAP_TO_SEQ_H
#define JOY_MAP_TO_SEQ_H

#include <joy/map/core.h>
#include <joy/set/to_seq.h>

#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Transform a map into a sequence.
 */
#define JOY_MAP_TO_SEQ(map) \
    JOY_MAP_TO_SEQ_S(CHAOS_PP_STATE(), map)

#define JOY_MAP_TO_SEQ_S(s, map) \
    JOY_SET_TO_SEQ_S(s, JOY_I_MAP_SET(map))

#endif /* !JOY_MAP_TO_SEQ_H */
