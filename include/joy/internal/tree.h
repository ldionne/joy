/*!
 * This file defines an interface to manipulate a generic binary tree.
 *
 * @author Louis Dionne
 */

#ifndef JOY_INTERNAL_TREE_H
#define JOY_INTERNAL_TREE_H

#include "bnode.h"
#include "search_result.h"
#include <chaos/preprocessor/control/branch.h>
#include <chaos/preprocessor/control/if.h>
#include <chaos/preprocessor/arithmetic/add.h>
#include <chaos/preprocessor/arithmetic/inc.h>
#include <chaos/preprocessor/logical/not.h>

#include <chaos/preprocessor/tuple/elem.h>
#include <chaos/preprocessor/tuple/to_seq.h>
#include <chaos/preprocessor/tuple/size.h>
#include <chaos/preprocessor/array/to_seq.h>
#include <chaos/preprocessor/seq/core.h>
#include <chaos/preprocessor/seq/fold_left.h>
#include <chaos/preprocessor/seq/to_tuple.h>
#include <chaos/preprocessor/seq/to_array.h>

#include <chaos/preprocessor/recursion/basic.h>
#include <chaos/preprocessor/recursion/expr.h>

#include <chaos/preprocessor/generics/strip.h>
#include <chaos/preprocessor/algorithm/merge_sort.h>


/*!
 * Create a new empty tree.
 */
#define JOY_TREE() JOY_BNODE_NULL()

/*!
 * Return whether a tree is empty.
 */
#define JOY_TREE_EMPTY(root) JOY_BNODE_IS_NULL(root)

/*!
 * Return a tree with no elements left in it.
 */
#define JOY_TREE_CLEAR(root) JOY_TREE()

/*!
 * Return a search result object containing the node in the tree whose data
 * element is equal to the data argument.
 *
 * @param compare A macro acting as the strict weak ordering operator (<).
 *                  Its prototype must match :
 *                  @code compare(s, data1, data2) @endcode
 */
#define JOY_TREE_SEARCH_NODE(root, data, compare) \
    JOY_TREE_SEARCH_NODE_S(CHAOS_PP_STATE(), root, data, compare)

#define JOY_TREE_SEARCH_NODE_S(s, root, data, compare)                         \
    CHAOS_PP_EXPR_S(s) (                                                       \
        JOY_I_TREE_SEARCH_NODE(                                                \
            CHAOS_PP_OBSTRUCT(), CHAOS_PP_NEXT(s), root, data, compare         \
        )                                                                      \
    )                                                                          \
/**/

#define JOY_I_TREE_SEARCH_NODE_ID() JOY_I_TREE_SEARCH_NODE
#define JOY_I_TREE_SEARCH_NODE(_, s, root, data, compare) CHAOS_PP_BRANCH      \
    (0xIF) (JOY_TREE_EMPTY(root)) (                                            \
        JOY_SEARCH_RESULT(root, 0)                                             \
    ) (0xELIF) _(compare _(s, data, JOY_BNODE_DATA(root))) (                   \
        CHAOS_PP_EXPR_S _(s) (                                                 \
            JOY_I_TREE_SEARCH_NODE_ID _() (CHAOS_PP_OBSTRUCT _(),              \
                CHAOS_PP_NEXT(s), JOY_BNODE_LCHILD _(root), data, compare      \
            )                                                                  \
        )                                                                      \
    ) (0xELIF) (compare _(s, JOY_BNODE_DATA _(root), data)) (                  \
        CHAOS_PP_EXPR_S _(s) (                                                 \
            JOY_I_TREE_SEARCH_NODE_ID _() (CHAOS_PP_OBSTRUCT _(),              \
                CHAOS_PP_NEXT(s), JOY_BNODE_RCHILD _(root), data, compare      \
            )                                                                  \
        )                                                                      \
    ) (0xELSE) (                                                               \
        JOY_SEARCH_RESULT _(root, 1)                                           \
    ) (0xENDIF)                                                                \
/**/

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

/*!
 * Return whether a tree contains a specified data element.
 */
#define JOY_TREE_CONTAINS(root, data, compare) \
    JOY_TREE_CONTAINS_S(CHAOS_PP_STATE(), root, data, compare)

#define JOY_TREE_CONTAINS_S(s, root, data, compare) \
    JOY_SEARCH_RESULT_FOUND(JOY_TREE_SEARCH_S(s, root, data, compare))

/*!
 * Return the minimum node of a tree.
 */
#define JOY_TREE_MIN(root) \
    JOY_TREE_MIN_S(CHAOS_PP_STATE(), root)

#define JOY_TREE_MIN_S(s, root)                                                \
    CHAOS_PP_EXPR_S(s) (                                                       \
        JOY_I_TREE_MIN(                                                        \
            CHAOS_PP_OBSTRUCT(), CHAOS_PP_NEXT(s), root                        \
        )                                                                      \
    )                                                                          \
/**/

#define JOY_I_TREE_MIN_ID() JOY_I_TREE_MIN
#define JOY_I_TREE_MIN(_, s, root) CHAOS_PP_BRANCH                             \
    (0xIF) (JOY_BNODE_HAS_LCHILD(root)) _(                                     \
        CHAOS_PP_EXPR_S _(s) (                                                 \
            JOY_I_TREE_MIN_ID _()(CHAOS_PP_OBSTRUCT _(),                       \
                CHAOS_PP_NEXT(s), JOY_BNODE_LCHILD _(root)                     \
            )                                                                  \
        )                                                                      \
    ) (0xELSE) (                                                               \
        root                                                                   \
    ) (0xENDIF)                                                                \
/**/

/*!
 * Return the maximum node of a tree.
 */
#define JOY_TREE_MAX(root) \
    JOY_TREE_MAX_S(CHAOS_PP_STATE(), root)

#define JOY_TREE_MAX_S(s, root)                                                \
    CHAOS_PP_EXPR_S(s) (                                                       \
        JOY_I_TREE_MAX(                                                        \
            CHAOS_PP_OBSTRUCT(), CHAOS_PP_NEXT(s), root                        \
        )                                                                      \
    )                                                                          \
/**/

#define JOY_I_TREE_MAX_ID() JOY_I_TREE_MAX
#define JOY_I_TREE_MAX(_, s, root) CHAOS_PP_BRANCH                             \
    (0xIF) (JOY_BNODE_HAS_RCHILD(root)) _(                                     \
        CHAOS_PP_EXPR_S _(s) (                                                 \
            JOY_I_TREE_MAX_ID _()(CHAOS_PP_OBSTRUCT _(),                       \
                CHAOS_PP_NEXT(s), JOY_BNODE_RCHILD _(root)                     \
            )                                                                  \
        )                                                                      \
    ) (0xELSE) (                                                               \
        root                                                                   \
    ) (0xENDIF)                                                                \
/**/

/*!
 * Return the number of elements in a tree.
 */
#define JOY_TREE_SIZE(root) \
    JOY_TREE_SIZE_S(CHAOS_PP_STATE(), root)

#define JOY_TREE_SIZE_S(s, root)                                               \
    CHAOS_PP_EXPR_S(s) (                                                       \
        JOY_I_TREE_SIZE(                                                       \
            CHAOS_PP_OBSTRUCT(), CHAOS_PP_NEXT(s), root                        \
        )                                                                      \
    )                                                                          \
/**/

#define JOY_I_TREE_SIZE_ID() JOY_I_TREE_SIZE
#define JOY_I_TREE_SIZE(_, s, root) CHAOS_PP_BRANCH                            \
    (0xIF) (JOY_TREE_EMPTY(root)) (                                            \
        0                                                                      \
    ) (0xELSE) _(                                                              \
        CHAOS_PP_INC _(                                                        \
            CHAOS_PP_ADD _(                                                    \
                CHAOS_PP_EXPR_S _(s) (                                         \
                    JOY_I_TREE_SIZE_ID _()(CHAOS_PP_OBSTRUCT _(),              \
                        CHAOS_PP_NEXT(s), JOY_BNODE_LCHILD _(root)             \
                    )                                                          \
                ),                                                             \
                CHAOS_PP_EXPR_S _(s) (                                         \
                    JOY_I_TREE_SIZE_ID _()(CHAOS_PP_OBSTRUCT _(),              \
                        CHAOS_PP_NEXT(s), JOY_BNODE_RCHILD _(root)             \
                    )                                                          \
                )                                                              \
            )                                                                  \
        )                                                                      \
    ) (0xENDIF)                                                                \
/**/

/*!
 * Return the tree with a new element inserted.
 *
 * If an element in the tree is determined to be equal to the data argument,
 * the old element is replaced with the new one.
 */
#define JOY_TREE_INSERT(root, data, compare) \
    JOY_TREE_INSERT_S(CHAOS_PP_STATE(), root, data, compare)

#define JOY_TREE_INSERT_S(s, root, data, compare)                              \
    CHAOS_PP_EXPR_S(s) (                                                       \
        JOY_I_TREE_INSERT(                                                     \
            CHAOS_PP_OBSTRUCT(), CHAOS_PP_NEXT(s), root, data, compare         \
        )                                                                      \
    )                                                                          \
/**/

#define JOY_I_TREE_INSERT_ID() JOY_I_TREE_INSERT
#define JOY_I_TREE_INSERT(_, s, root, data, compare) CHAOS_PP_BRANCH           \
    (0xIF) (JOY_TREE_EMPTY(root)) (                                            \
        JOY_BNODE_LEAF(data)                                                   \
    ) (0xELIF) _(compare _(s, data, JOY_BNODE_DATA(root))) (                   \
        JOY_BNODE_SET_LCHILD _(                                                \
            root,                                                              \
            CHAOS_PP_EXPR_S _(s) (                                             \
                JOY_I_TREE_INSERT_ID _()(CHAOS_PP_OBSTRUCT _(),                \
                    CHAOS_PP_NEXT(s), JOY_BNODE_LCHILD _(root), data, compare  \
                )                                                              \
            )                                                                  \
        )                                                                      \
    ) (0xELIF) (compare _(s, JOY_BNODE_DATA _(root), data)) (                  \
        JOY_BNODE_SET_RCHILD _(                                                \
            root,                                                              \
            CHAOS_PP_EXPR_S _(s) (                                             \
                JOY_I_TREE_INSERT_ID _()(CHAOS_PP_OBSTRUCT _(),                \
                    CHAOS_PP_NEXT(s), JOY_BNODE_RCHILD _(root), data, compare  \
                )                                                              \
            )                                                                  \
        )                                                                      \
    ) (0xELSE) (                                                               \
        JOY_BNODE_SET_DATA _(root, data)                                       \
    ) (0xENDIF)                                                                \
/**/

/*!
 * Return the tree with a new element inserted.
 *
 * If an element in the tree is determined to be equal to the data argument,
 * a preprocessor error is triggered.
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

/*!
 * Return the tree with an element removed.
 *
 * If the element can't be found, nothing is done.
 */
#define JOY_TREE_REMOVE(root, data, compare) \
    JOY_TREE_REMOVE_S(CHAOS_PP_STATE(), root, data, compare)

#define JOY_TREE_REMOVE_S(s, root, data, compare)                              \
    CHAOS_PP_EXPR_S(s) (                                                       \
        JOY_I_TREE_REMOVE(                                                     \
            CHAOS_PP_OBSTRUCT(), CHAOS_PP_NEXT(s), root, data, compare         \
        )                                                                      \
    )                                                                          \
/**/

#define JOY_I_TREE_REMOVE_ID() JOY_I_TREE_REMOVE
#define JOY_I_TREE_REMOVE(_, s, root, data, compare) CHAOS_PP_BRANCH           \
    (0xIF) (JOY_TREE_EMPTY(root)) (                                            \
        root                                                                   \
    ) (0xELIF) _(compare _(s, data, JOY_BNODE_DATA(root))) (                   \
        JOY_BNODE_SET_LCHILD _(                                                \
            root,                                                              \
            CHAOS_PP_EXPR_S _(s) (                                             \
                JOY_I_TREE_REMOVE_ID _()(CHAOS_PP_OBSTRUCT _(),                \
                    CHAOS_PP_NEXT(s), JOY_BNODE_LCHILD _(root), data, compare  \
                )                                                              \
            )                                                                  \
        )                                                                      \
    ) (0xELIF) (compare _(s, JOY_BNODE_DATA _(root), data)) (                  \
        JOY_BNODE_SET_RCHILD _(                                                \
            root,                                                              \
            CHAOS_PP_EXPR_S _(s) (                                             \
                JOY_I_TREE_REMOVE_ID _()(CHAOS_PP_OBSTRUCT _(),                \
                    CHAOS_PP_NEXT(s), JOY_BNODE_RCHILD _(root), data, compare  \
                )                                                              \
            )                                                                  \
        )                                                                      \
    ) (0xELSE) (                                                               \
        JOY_I_TREE_REMOVE_NODE _(root)                                         \
    ) (0xENDIF)                                                                \
/**/

/*!
 * Return the tree with an element removed.
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

/*!
 * Return a tree with its maximum element removed.
 */
#define JOY_TREE_REMOVE_MAX(root) \
    JOY_TREE_REMOVE_MAX_S(CHAOS_PP_STATE(), root)

#define JOY_TREE_REMOVE_MAX_S(s, root)                                         \
    CHAOS_PP_EXPR_S(s) (                                                       \
        JOY_I_TREE_REMOVE_MAX(                                                 \
            CHAOS_PP_OBSTRUCT(), CHAOS_PP_NEXT(s), root                        \
        )                                                                      \
    )                                                                          \
/**/

#define JOY_I_TREE_REMOVE_MAX_ID() JOY_I_TREE_REMOVE_MAX
#define JOY_I_TREE_REMOVE_MAX(_, s, root) CHAOS_PP_BRANCH                      \
    (0xIF) (JOY_BNODE_HAS_RCHILD(root)) _(                                     \
        JOY_BNODE_SET_RCHILD _(                                                \
            root,                                                              \
            CHAOS_PP_EXPR_S _(s) (                                             \
                JOY_I_TREE_REMOVE_MAX_ID _() (CHAOS_PP_OBSTRUCT _(),           \
                    CHAOS_PP_NEXT(s), JOY_BNODE_RCHILD _(root)                 \
                )                                                              \
            )                                                                  \
        )                                                                      \
    ) (0xELSE) (                                                               \
        JOY_BNODE_NULL()                                                       \
    ) (0xENDIF)                                                                \
/**/

/*!
 * Return a tree with its minimum element removed.
 */
#define JOY_TREE_REMOVE_MIN(root) \
    JOY_TREE_REMOVE_MIN_S(CHAOS_PP_STATE(), root)

#define JOY_TREE_REMOVE_MIN_S(s, root)                                         \
    CHAOS_PP_EXPR_S(s) (                                                       \
        JOY_I_TREE_REMOVE_MIN(                                                 \
            CHAOS_PP_OBSTRUCT(), CHAOS_PP_NEXT(s), root                        \
        )                                                                      \
    )                                                                          \
/**/

#define JOY_I_TREE_REMOVE_MIN_ID() JOY_I_TREE_REMOVE_MIN
#define JOY_I_TREE_REMOVE_MIN(_, s, root) CHAOS_PP_BRANCH                      \
    (0xIF) (JOY_BNODE_HAS_LCHILD(root)) _(                                     \
        JOY_BNODE_SET_LCHILD _(                                                \
            root,                                                              \
            CHAOS_PP_EXPR_S _(s) (                                             \
                JOY_I_TREE_REMOVE_MIN_ID _() (CHAOS_PP_OBSTRUCT _(),           \
                    CHAOS_PP_NEXT(s), JOY_BNODE_LCHILD _(root)                 \
                )                                                              \
            )                                                                  \
        )                                                                      \
    ) (0xELSE) (                                                               \
        JOY_BNODE_NULL()                                                       \
    ) (0xENDIF)                                                                \
/**/

/*!
 * Perform removal of a node, acting differently whether it has zero, one or
 * two children.
 */
#define JOY_I_TREE_REMOVE_NODE(node) CHAOS_PP_BRANCH                           \
    (0xIF) (JOY_BNODE_IS_LEAF(node)) (                                         \
        JOY_BNODE_NULL()                                                       \
    ) (0xELIF) (JOY_BNODE_HAS_LCHILD(node)) (CHAOS_PP_BRANCH                   \
        (0xIF) (JOY_BNODE_HAS_RCHILD(node)) (                                  \
            JOY_BNODE_SET_CHILDREN(                                            \
                JOY_TREE_MAX(JOY_BNODE_LCHILD(node)),                          \
                JOY_TREE_REMOVE_MAX(JOY_BNODE_LCHILD(node)),                   \
                JOY_BNODE_RCHILD(node)                                         \
            )                                                                  \
        ) (0xELSE) (                                                           \
            JOY_BNODE_LCHILD(node)                                             \
        ) (0xENDIF)                                                            \
    ) (0xELSE) (                                                               \
        JOY_BNODE_RCHILD(node)                                                 \
    ) (0xENDIF)                                                                \
/**/

/*!
 * Filter nodes of the tree according to a predicate.
 *
 * @param predicate A macro(s, element, auxiliary_data) to determine
 *                  whether to keep an element.
 * @param data Auxiliary data passed to the predicate.
 */
#define JOY_TREE_FILTER(root, predicate, data) \
    JOY_TREE_FILTER_S(CHAOS_PP_STATE(), root, predicate, data)

#define JOY_TREE_FILTER_S(s, root, predicate, data)                            \
    CHAOS_PP_EXPR_S(s) (                                                       \
        JOY_I_TREE_FILTER(                                                     \
            CHAOS_PP_OBSTRUCT(), CHAOS_PP_NEXT(s), root, predicate, data       \
        )                                                                      \
    )                                                                          \
/**/

#define JOY_I_TREE_FILTER_ID() JOY_I_TREE_FILTER
#define JOY_I_TREE_FILTER(_, s, root, predicate, data) CHAOS_PP_BRANCH         \
        (0xIF) (JOY_TREE_EMPTY(root)) (                                        \
            root                                                               \
        ) (0xELSE) _(                                                          \
            JOY_I_TREE_FILTER_APPLY_UNLESS _(                                  \
                predicate _(s, JOY_BNODE_DATA _(root), data),                  \
                JOY_I_TREE_REMOVE_NODE,                                        \
                JOY_BNODE_SET_CHILDREN _(root,                                 \
                    CHAOS_PP_EXPR_S _(s) (                                     \
                        JOY_I_TREE_FILTER_ID _() (CHAOS_PP_OBSTRUCT _(),       \
                            CHAOS_PP_NEXT(s), JOY_BNODE_LCHILD _(root),        \
                                                            predicate, data    \
                        )                                                      \
                    ),                                                         \
                    CHAOS_PP_EXPR_S _(s) (                                     \
                        JOY_I_TREE_FILTER_ID _() (CHAOS_PP_OBSTRUCT _(),       \
                            CHAOS_PP_NEXT(s), JOY_BNODE_RCHILD _(root),        \
                                                            predicate, data    \
                        )                                                      \
                    )                                                          \
                )                                                              \
            )                                                                  \
        ) (0xENDIF)                                                            \
/**/

#define JOY_I_TREE_FILTER_APPLY_UNLESS(cond, macro, arg)                       \
    CHAOS_PP_IF(cond) (                                                        \
        arg,                                                                   \
        macro(arg)                                                             \
    )                                                                          \
/**/

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
        root, JOY_I_TREE_UPDATE_PRED, (other, compare)                         \
    )                                                                          \
/**/

#define JOY_I_TREE_UPDATE_PRED(s, elem, info)                                  \
    CHAOS_PP_NOT(JOY_TREE_CONTAINS_S(s,                                        \
        CHAOS_PP_TUPLE_ELEM(2, 0, info),                                       \
        elem,                                                                  \
        CHAOS_PP_TUPLE_ELEM(2, 1, info)                                        \
    ))                                                                         \
/**/

/*!
 * Transform a tuple into a tree.
 */
#define JOY_TUPLE_TO_TREE(compare, tuple) \
    JOY_TUPLE_TO_TREE_S(CHAOS_PP_STATE(), compare, tuple)

#define JOY_TUPLE_TO_TREE_S(s, compare, tuple)                                 \
    JOY_SEQ_TO_TREE_S(s,                                                       \
        compare, CHAOS_PP_TUPLE_TO_SEQ(CHAOS_PP_TUPLE_SIZE(tuple), tuple)      \
    )                                                                          \
/**/

/*!
 * Transform an array into a tree.
 */
#define JOY_ARRAY_TO_TREE(compare, array) \
    JOY_ARRAY_TO_TREE_S(CHAOS_PP_STATE(), compare, array)

#define JOY_ARRAY_TO_TREE_S(s, compare, array) \
    JOY_SEQ_TO_TREE_S(s, compare, CHAOS_PP_ARRAY_TO_SEQ(array))

/*!
 * Transform a sequence into a tree.
 */
#define JOY_SEQ_TO_TREE(compare, seq) \
    JOY_SEQ_TO_TREE_S(CHAOS_PP_STATE(), compare, seq)

#define JOY_SEQ_TO_TREE_S(s, compare, seq)                                     \
    CHAOS_PP_EXPR_S(s) (                                                       \
        CHAOS_PP_SEQ_FOLD_LEFT_S(CHAOS_PP_NEXT(s),                             \
            JOY_I_SEQ_TO_TREE_ACCUMULATE,                                      \
            JOY_I_SEQ_TO_TREE_PREPARE(CHAOS_PP_NEXT(s),                        \
                compare, seq                                                   \
            ),                                                                 \
            JOY_TREE()                                                         \
        )                                                                      \
    )                                                                          \
/**/

#define JOY_I_SEQ_TO_TREE_PREPARE(s, compare, seq)                             \
    CHAOS_PP_STRIP(                                                            \
            CHAOS_PP_EXPR_S(s) (CHAOS_PP_MERGE_SORT_S(CHAOS_PP_NEXT(s),        \
                compare, (CHAOS_PP_SEQ) seq                                    \
            ))                                                                 \
    )                                                                          \
/**/

#define JOY_I_SEQ_TO_TREE_ACCUMULATE(s, elem, tree) \
    JOY_BNODE(tree, elem, JOY_TREE())

/*!
 * Transform a tree into a sequence.
 */
#define JOY_TREE_TO_SEQ(root) \
    JOY_TREE_TO_SEQ_S(CHAOS_PP_STATE(), root)

#define JOY_TREE_TO_SEQ_S(s, root)                                             \
    CHAOS_PP_EXPR_S(s) (                                                       \
        JOY_I_TREE_TO_SEQ(                                                     \
            CHAOS_PP_OBSTRUCT(), CHAOS_PP_NEXT(s), root                        \
        )                                                                      \
    )                                                                          \
/**/

#define JOY_I_TREE_TO_SEQ_ID() JOY_I_TREE_TO_SEQ
#define JOY_I_TREE_TO_SEQ(_, s, root) CHAOS_PP_BRANCH                          \
    (0xIF) (CHAOS_PP_NOT(JOY_TREE_EMPTY(root))) _(                             \
        CHAOS_PP_EXPR_S _(s) (                                                 \
            JOY_I_TREE_TO_SEQ_ID _() (CHAOS_PP_OBSTRUCT _(),                   \
                CHAOS_PP_NEXT(s), JOY_BNODE_LCHILD _(root)                     \
            )                                                                  \
        )                                                                      \
        (JOY_BNODE_DATA(root))                                                 \
        CHAOS_PP_EXPR_S _(s) (                                                 \
            JOY_I_TREE_TO_SEQ_ID _() (CHAOS_PP_OBSTRUCT _(),                   \
                CHAOS_PP_NEXT(s), JOY_BNODE_RCHILD _(root)                     \
            )                                                                  \
        )                                                                      \
    ) (0xENDIF)                                                                \
/**/

/*!
 * Transform a tree into an array.
 */
#define JOY_TREE_TO_ARRAY(root) \
    JOY_TREE_TO_ARRAY_S(CHAOS_PP_STATE(), root)

#define JOY_TREE_TO_ARRAY_S(s, root) \
    CHAOS_PP_SEQ_TO_ARRAY(JOY_TREE_TO_SEQ_S(s, root))

/*!
 * Transform a tree into a tuple.
 */
#define JOY_TREE_TO_TUPLE(root) \
    JOY_TREE_TO_TUPLE_S(CHAOS_PP_STATE(), root)

#define JOY_TREE_TO_TUPLE_S(s, root) \
    CHAOS_PP_SEQ_TO_TUPLE(JOY_TREE_TO_SEQ_S(s, root))

#endif /* !JOY_INTERNAL_TREE_H */
