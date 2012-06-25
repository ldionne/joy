/*!
 * This file defines a macro to determine whether a tree contains an element.
 *
 * @author Louis Dionne
 */

#ifndef JOY_TREE_CONTAINS_H
#define JOY_TREE_CONTAINS_H

#include <joy/search_result.h>
#include <joy/tree/search.h>

#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Return whether a tree contains a specified data element.
 */
#define JOY_TREE_CONTAINS(root, data, compare) \
    JOY_TREE_CONTAINS_S(CHAOS_PP_STATE(), root, data, compare)

#define JOY_TREE_CONTAINS_S(s, root, data, compare) \
    JOY_SEARCH_RESULT_FOUND(JOY_TREE_SEARCH_S(s, root, data, compare))

#endif /* !JOY_TREE_CONTAINS_H */
