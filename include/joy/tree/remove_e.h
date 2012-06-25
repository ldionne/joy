/*!
 * This file defines a macro to remove an element of a tree.
 *
 * @author Louis Dionne
 */

#ifndef JOY_TREE_REMOVE_E_H
#define JOY_TREE_REMOVE_E_H

#include <joy/tree/remove.h>
#include <joy/tree/contains.h>

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/control/if.h>


/*!
 * Return a tree with an element removed.
 *
 * If the element can't be found, a preprocessor error is triggered.
 */
#define JOY_TREE_REMOVE_E(root, data, compare) \
    JOY_TREE_REMOVE_E_S(CHAOS_PP_STATE(), root, data, compare)

#define JOY_TREE_REMOVE_E_S(s, root, data, compare) \
    CHAOS_PP_IF(JOY_TREE_CONTAINS_S(s, root, data, compare)) ( \
        JOY_TREE_REMOVE_S(s, root, data, compare), \
        JOY_I_TREE_REMOVE_E_REMOVE_INEXISTANT_ELEMENT_EXCEPTION(!) \
    )
#define JOY_I_TREE_REMOVE_E_REMOVE_INEXISTANT_ELEMENT_EXCEPTION()

#endif /* !JOY_TREE_REMOVE_E_H */
