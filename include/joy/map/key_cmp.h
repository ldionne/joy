/*!
 * This file defines a macro to retrieve the key comparator used in a map.
 *
 * @author Louis Dionne
 */

#ifndef JOY_MAP_KEY_CMP_H
#define JOY_MAP_KEY_CMP_H

#include <joy/pair.h>
#include <joy/map/core.h>


/*!
 * Return the macro used by a map to sort its element in strict weak ordering.
 */
#define JOY_MAP_KEY_CMP(map) JOY_PAIR_FIRST(map)

/*!
 * Use this macro to call your custom strict weak ordering operator.
 *
 * @param compare A predicate acting as a strict weak operator (<).
 */
#define JOY_MAP_KEY_CMP_ADJUST(compare, s, a, b) \
    compare(s, JOY_I_MAP_CELL_KEY(a), JOY_I_MAP_CELL_KEY(b))

#endif /* !JOY_MAP_KEY_CMP_H */
