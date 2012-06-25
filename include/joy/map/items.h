/*!
 * This file defines a macro to retrieve the items stored in a map.
 *
 * @author Louis Dionne
 */

#ifndef JOY_MAP_ITEMS_H
#define JOY_MAP_ITEMS_H

#include <joy/map/to_seq.h>

#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Return the keys and the values contained in a map as a sequence of tuples.
 */
#define JOY_MAP_ITEMS(map) \
    JOY_MAP_ITEMS_S(CHAOS_PP_STATE(), map)

#define JOY_MAP_ITEMS_S(s, map) \
    JOY_MAP_TO_SEQ_S(s, map)

#endif /* !JOY_MAP_ITEMS_H */
