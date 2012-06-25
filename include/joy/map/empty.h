/*!
 * This file defines a macro to check whether a map is empty.
 *
 * @author Louis Dionne
 */

#ifndef JOY_MAP_EMPTY_H
#define JOY_MAP_EMPTY_H

#include <joy/map/core.h>
#include <joy/set/empty.h>


/*!
 * Return whether a map is empty.
 */
#define JOY_MAP_EMPTY(map) JOY_SET_EMPTY(JOY_I_MAP_SET(map))

#endif /* !JOY_MAP_EMPTY_H */
