/*!
 * This file contains the tests for the tree data structure.
 *
 * @author Louis Dionne
 */

#ifndef NSTL_PP_TEST_TREE_H
#define NSTL_PP_TEST_TREE_H

#include "pp-tree.h"
#include "pp-assert.h"
#include <chaos/preprocessor.h>


#define seq (1) (2) (3) (4) (5) (6) (7)
#define less(state, a, b) CHAOS_PP_LESS(a, b)
#define tree NSTL_PP_SEQ_TO_TREE(less, seq)
#define ASSERT_CONTAINS(tree, elem, message) \
    ASSERT_TRUE(NSTL_PP_TREE_CONTAINS(tree, elem, less), message)


// emptyness
ASSERT_TRUE(NSTL_PP_TREE_EMPTY(NSTL_PP_TREE()), 
                                        "a newly created tree should be empty")


// membership
#define macro(s, elem, data) ASSERT_CONTAINS(tree, elem, \
                    "a tree should contain all the elements it is created with")
CHAOS_PP_EXPR(CHAOS_PP_SEQ_FOR_EACH(macro, seq, tree))
#undef macro



#undef ASSERT_CONTAINS
#undef less
#undef tree
#undef seq


#endif /* !NSTL_PP_TEST_TREE_H */
