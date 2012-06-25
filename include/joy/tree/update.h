/*!
 * This file defines a macro to update the content of a tree.
 *
 * @author Louis Dionne
 */

#ifndef JOY_TREE_UPDATE_H
#define JOY_TREE_UPDATE_H

#include <joy/pair.h>
#include <joy/seq/to_tree.h>
#include <joy/tree/to_seq.h>
#include <joy/tree/filter.h>
#include <joy/tree/contains.h>

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/tuple/elem.h>
#include <chaos/preprocessor/logical/not.h>


/*!
 * Update the content of a tree with the content of another.
 */
#define JOY_TREE_UPDATE(root, other, compare) \
    JOY_TREE_UPDATE_S(CHAOS_PP_STATE(), root, other, compare)

#define JOY_TREE_UPDATE_S(s, root, other, compare)                             \
    JOY_SEQ_TO_TREE_S(s, compare,                                              \
        JOY_TREE_TO_SEQ_S(s,                                                   \
            JOY_I_TREE_UPDATE_PREPARE(s, root, other, compare)                 \
        )                                                                      \
        JOY_TREE_TO_SEQ_S(s, other)                                            \
    )                                                                          \
/**/

#define JOY_I_TREE_UPDATE_PREPARE(s, root, other, compare)                     \
    JOY_TREE_FILTER_S(s,                                                       \
        root, JOY_I_TREE_UPDATE_PRED, JOY_PAIR(other, compare)                 \
    )                                                                          \
/**/

#define JOY_I_TREE_UPDATE_PRED(s, elem, info)                                  \
    CHAOS_PP_NOT(JOY_TREE_CONTAINS_S(s,                                        \
        JOY_PAIR_FIRST(info),                                                  \
        elem,                                                                  \
        JOY_PAIR_SECOND(info)                                                  \
    ))                                                                         \
/**/

#endif /* !JOY_TREE_UPDATE_H*/
