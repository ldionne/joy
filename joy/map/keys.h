/*!
 * This file defines a macro to retrieve the keys stored in a map.
 *
 * @author Louis Dionne
 */

#ifndef JOY_MAP_KEYS_H
#define JOY_MAP_KEYS_H

#include <joy/map/core.h>
#include <joy/map/to_seq.h>

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/seq/transform.h>


/*!
 * Return the keys contained in a map in a sequence.
 */
#define JOY_MAP_KEYS(map) \
    JOY_MAP_KEYS_S(CHAOS_PP_STATE(), map)

#define JOY_MAP_KEYS_S(s, map)                                                 \
    CHAOS_PP_EXPR_S(s) (                                                       \
        CHAOS_PP_SEQ_TRANSFORM_S(s,                                            \
            JOY_I_MAP_KEYS_ACCUMULATE, JOY_MAP_TO_SEQ_S(s, map), ~             \
        )                                                                      \
    )                                                                          \
/**/

#define JOY_I_MAP_KEYS_ACCUMULATE(s, elem, _) \
    JOY_I_MAP_CELL_KEY(elem)

#endif /* !JOY_MAP_KEYS_H */
