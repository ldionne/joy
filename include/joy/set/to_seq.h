/*!
 * This file defines a macro to transform a set into a sequence.
 *
 * @author Louis Dionne
 */

#ifndef JOY_SET_TO_SEQ_H
#define JOY_SET_TO_SEQ_H

#include <joy/set/core.h>
#include <joy/tree/to_seq.h>

#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Transform a set into a sequence.
 */
#define JOY_SET_TO_SEQ(set) \
    JOY_SET_TO_SEQ_S(CHAOS_PP_STATE(), set)

#define JOY_SET_TO_SEQ_S(s, set) \
    JOY_TREE_TO_SEQ_S(s, JOY_I_SET_TREE(set))


#endif /* !JOY_SET_TO_SEQ_H */
