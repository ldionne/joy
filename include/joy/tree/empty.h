/*!
 * This file defines a macro to find out whether a tree is empty.
 *
 * @author Louis Dionne
 */

#ifndef JOY_TREE_EMPTY_H
#define JOY_TREE_EMPTY_H

#include <joy/bnode.h>


/*!
 * Return whether a tree is empty.
 */
#define JOY_TREE_EMPTY(root) JOY_BNODE_IS_NULL(root)

#endif /* !JOY_TREE_EMPTY_H */
