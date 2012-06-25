/*!
 * This file defines a macro to transform a sequence into a map.
 *
 * @author Louis Dionne
 */

#ifndef JOY_SEQ_TO_MAP_H
#define JOY_SEQ_TO_MAP_H

#include <joy/seq/to_set.h>
#include <joy/set/value_cmp.h>
#include <joy/map/core.h>

#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Transform a sequence into a map.
 *
 * @note The sequence must be a sequence of (key, value) tuples.
 */
#define JOY_SEQ_TO_MAP(compare, seq) \
    JOY_SEQ_TO_MAP_S(CHAOS_PP_STATE(), compare, seq)

#define JOY_SEQ_TO_MAP_S(s, compare, seq) \
    JOY_I_SEQ_TO_MAP_I(s, JOY_MAP(compare), seq)

#define JOY_I_SEQ_TO_MAP_I(s, map, seq)                                        \
    JOY_I_MAP_SET_SET(                                                         \
        map, JOY_SEQ_TO_SET_S(s,                                               \
            JOY_SET_VALUE_CMP(JOY_I_MAP_SET(map)), seq                         \
        )                                                                      \
    )                                                                          \
/**/

#endif /* !JOY_SEQ_TO_MAP_H */
