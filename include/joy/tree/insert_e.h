/*!
 * This file defines a macro to insert an element into a tree.
 *
 * @author Louis Dionne
 */

#ifndef JOY_TREE_INSERT_E_H
#define JOY_TREE_INSERT_E_H

#include <joy/tree/contains.h>
#include <joy/tree/insert.h>

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/control/if.h>


/*!
 * Return the tree with a new element inserted.
 *
 * If an element in the tree is determined to be equal to @p data, a
 * preprocessor error is triggered.
 */
#define JOY_TREE_INSERT_E(root, data, compare) \
    JOY_TREE_INSERT_E_S(CHAOS_PP_STATE(), root, data, compare)

#define JOY_TREE_INSERT_E_S(s, root, data, compare)                            \
    CHAOS_PP_IF(JOY_TREE_CONTAINS_S(s, root, data, compare)) (                 \
        JOY_I_TREE_INSERT_E_INSERT_EXISTANT_ELEMENT_EXCEPTION(!),              \
        JOY_TREE_INSERT_S(s, root, data, compare),                             \
    )                                                                          \
/**/
#define JOY_I_TREE_INSERT_E_INSERT_EXISTANT_ELEMENT_EXCEPTION()

#endif /* !JOY_TREE_INSERT_E_H */
