/*!
 * This file defines a macro to transform a tree into a tuple.
 *
 * @author Louis Dionne
 */

#ifndef JOY_TREE_TO_TUPLE_H
#define JOY_TREE_TO_TUPLE_H

#include <joy/tree/to_seq.h>

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/seq/to_tuple.h>


/*!
 * Transform a tree into a tuple.
 */
#define JOY_TREE_TO_TUPLE(root) \
    JOY_TREE_TO_TUPLE_S(CHAOS_PP_STATE(), root)

#define JOY_TREE_TO_TUPLE_S(s, root) \
    CHAOS_PP_SEQ_TO_TUPLE(JOY_TREE_TO_SEQ_S(s, root))

#endif /* !JOY_TREE_TO_TUPLE_H */
