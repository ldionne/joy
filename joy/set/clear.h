/*!
 * This file defines a macro to remove all the elements from a set.
 *
 * @author Louis Dionne
 */

#ifndef JOY_SET_CLEAR_H
#define JOY_SET_CLEAR_H

#include <joy/set/core.h>
#include <joy/tree/clear.h>


/*!
 * Return a set with all elements removed from it.
 */
#define JOY_SET_CLEAR(set) \
    JOY_I_SET_SET_TREE(set, JOY_TREE_CLEAR(JOY_I_SET_TREE(set)))

#endif /* !JOY_SET_CLEAR_H */
