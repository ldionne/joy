/*!
 * This file defines a macro to search for an element in a tree.
 *
 * @author Louis Dionne
 */

#ifndef JOY_TREE_SEARCH_H
#define JOY_TREE_SEARCH_H

#include <joy/search_result.h>
#include <joy/bnode.h>
#include <joy/tree/search_node.h>

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/control/if.h>


/*!
 * Return a search result object containing the data element in the tree
 * which is equal to the data argument.
 *
 * @param compare A macro acting as the strict weak ordering operator (<).
 */
#define JOY_TREE_SEARCH(root, data, compare) \
    JOY_TREE_SEARCH_S(CHAOS_PP_STATE(), root, data, compare)

#define JOY_TREE_SEARCH_S(s, root, data, compare)                              \
    JOY_I_TREE_SEARCH_REWRAP(                                                  \
        JOY_TREE_SEARCH_NODE_S(s, root, data, compare)                         \
    )                                                                          \
/**/

#define JOY_I_TREE_SEARCH_REWRAP(result)                                       \
    CHAOS_PP_IF(JOY_SEARCH_RESULT_FOUND(result)) (                             \
        JOY_SEARCH_RESULT(                                                     \
            JOY_BNODE_DATA(JOY_SEARCH_RESULT_VALUE(result)), 1                 \
        ),                                                                     \
        result                                                                 \
    )                                                                          \
/**/

#endif /* !JOY_TREE_SEARCH_H */
