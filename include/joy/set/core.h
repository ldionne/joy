/*!
 * This file defines the core data structure of the set.
 *
 * @author Louis Dionne
 */

#ifndef JOY_SET_CORE_H
#define JOY_SET_CORE_H

#include <joy/pair.h>
#include <joy/tree/core.h>


/*!
 * Return an empty set with a given macro to sort its element.
 */
#define JOY_SET(value_cmp) JOY_PAIR(value_cmp, JOY_TREE())

#define JOY_I_SET_TREE(set) JOY_PAIR_SECOND(set)
#define JOY_I_SET_SET_TREE(set, tree) JOY_PAIR_SET_SECOND(set, tree)

#endif /* !JOY_SET_CORE_H */
