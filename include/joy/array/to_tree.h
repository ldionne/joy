/*!
 * This file defines a macro to transform an array into a tree.
 *
 * @author Louis Dionne
 */

#ifndef JOY_ARRAY_TO_TREE_H
#define JOY_ARRAY_TO_TREE_H

#include <joy/seq/to_tree.h>

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/array/to_seq.h>


/*!
 * Transform an array into a tree.
 */
#define JOY_ARRAY_TO_TREE(compare, array) \
    JOY_ARRAY_TO_TREE_S(CHAOS_PP_STATE(), compare, array)

#define JOY_ARRAY_TO_TREE_S(s, compare, array) \
    JOY_SEQ_TO_TREE_S(s, compare, CHAOS_PP_ARRAY_TO_SEQ(array))

#endif /* !JOY_ARRAY_TO_TREE_H */
