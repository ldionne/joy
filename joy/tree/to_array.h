/*!
 * This file defines a macro to transform a tree into an array.
 *
 * @author Louis Dionne
 */

#ifndef JOY_TREE_TO_ARRAY_H
#define JOY_TREE_TO_ARRAY_H

#include <joy/tree/to_seq.h>

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/seq/to_array.h>


/*!
 * Transform a tree into an array.
 */
#define JOY_TREE_TO_ARRAY(root) \
    JOY_TREE_TO_ARRAY_S(CHAOS_PP_STATE(), root)

#define JOY_TREE_TO_ARRAY_S(s, root) \
    CHAOS_PP_SEQ_TO_ARRAY(JOY_TREE_TO_SEQ_S(s, root))

#endif /* !JOY_TREE_TO_ARRAY_H */
