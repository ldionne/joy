/*!
 * This file defines the core data structure of the map.
 *
 * @author Louis Dionne
 */

#ifndef JOY_MAP_CORE_H
#define JOY_MAP_CORE_H

#include <joy/pair.h>
#include <joy/set/core.h>


/*!
 * Return an empty map with a defined macro to sort its element in strict
 * weak ordering.
 */
#define JOY_MAP(key_cmp) JOY_PAIR(key_cmp, JOY_SET(key_cmp))

#define JOY_I_MAP_SET(map) JOY_PAIR_SECOND(map)
#define JOY_I_MAP_SET_SET(map, set) JOY_PAIR_SET_SECOND(map, set)

#define JOY_I_MAP_CELL(key, value) JOY_PAIR(key, value)
#define JOY_I_MAP_CELL_KEY(cell) JOY_PAIR_FIRST(cell)
#define JOY_I_MAP_CELL_VALUE(cell) JOY_PAIR_SECOND(cell)

#endif /* !JOY_MAP_CORE_H */
