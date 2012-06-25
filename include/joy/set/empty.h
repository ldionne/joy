/*!
 * This file defines a macro to check whether a set is empty.
 *
 * @author Louis Dionne
 */

#ifndef JOY_SET_EMPTY_H
#define JOY_SET_EMPTY_H

#include <joy/set/core.h>
#include <joy/tree/empty.h>


/*!
 * Return whether a set is empty.
 */
#define JOY_SET_EMPTY(set) JOY_TREE_EMPTY(JOY_I_SET_TREE(set))

#endif /* !JOY_SET_EMPTY_H */
