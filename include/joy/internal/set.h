/*!
 * This file defines an interface to manipulate a generic set container.
 *
 * @author Louis Dionne
 */

#ifndef JOY_INTERNAL_SET_H
#define JOY_INTERNAL_SET_H

#include "tree.h"
#include "pair.h"
#include <chaos/preprocessor/logical/not.h>
#include <chaos/preprocessor/tuple/size.h>
#include <chaos/preprocessor/tuple/to_seq.h>
#include <chaos/preprocessor/array/to_seq.h>
#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Return an empty set with a defined macro to sort its element in strict
 * weak ordering.
 */
#define JOY_SET(value_comp) JOY_PAIR(value_comp, JOY_TREE())

/*!
 * Return the macro used by a set to sort its element in strict weak ordering.
 */
#define JOY_SET_VALUE_COMP(set) JOY_PAIR_FIRST(set)

#define JOY_I_SET_TREE(set) JOY_PAIR_SECOND(set)
#define JOY_I_SET_SET_TREE(set, tree) JOY_PAIR_SET_SECOND(set, tree)

/*!
 * Return whether a set is empty.
 */
#define JOY_SET_EMPTY(set) JOY_TREE_EMPTY(JOY_I_SET_TREE(set))

/*!
 * Return the number of elements in a set.
 */
#define JOY_SET_SIZE(set) \
    JOY_SET_SIZE_S(CHAOS_PP_STATE(), set)

#define JOY_SET_SIZE_S(s, set) \
    JOY_TREE_SIZE_S(s, JOY_I_SET_TREE(set))

/*!
 * Return a set with all elements removed from it.
 */
#define JOY_SET_CLEAR(set) \
    JOY_I_SET_SET_TREE(set, JOY_TREE_CLEAR(JOY_I_SET_TREE(set)))

/*!
 * Return the specified value in a set.
 *
 * If the value is not found in the set, default is returned.
 */
#define JOY_SET_FIND(set, value, default) \
    JOY_SET_FIND_S(CHAOS_PP_STATE(), set, value, default)

#define JOY_SET_FIND_S(s, set, value, default) \
    JOY_SEARCH_RESULT_VALUE_D(JOY_I_SET_FIND(s, set, value), default)

#define JOY_I_SET_FIND(s, set, value)                                          \
    JOY_TREE_SEARCH_S(s,                                                       \
        JOY_I_SET_TREE(set), value, JOY_SET_VALUE_COMP(set)                    \
    )                                                                          \
/**/

/*!
 * Return the specified value in a set.
 *
 * If the value is not found in the set, a preprocessor error is triggered.
 */
#define JOY_SET_FIND_E(set, value) \
    JOY_SET_FIND_E_S(CHAOS_PP_STATE(), set, value)

#define JOY_SET_FIND_E_S(s, set, value) \
    JOY_SEARCH_RESULT_VALUE_E(JOY_I_SET_FIND(s, set, value))

/*!
 * Return whether a set contains the specified element.
 */
#define JOY_SET_CONTAINS(set, value) \
    JOY_SET_CONTAINS_S(CHAOS_PP_STATE(), set, value)

#define JOY_SET_CONTAINS_S(s, set, value)                                      \
    JOY_TREE_CONTAINS_S(s,                                                     \
        JOY_I_SET_TREE(set), value, JOY_SET_VALUE_COMP(set)                    \
    )                                                                          \
/**/

/*!
 * Add an element to a set and return the set thus created.
 *
 * If the element is already present in the set, it is replaced with the new
 * one.
 */
#define JOY_SET_ADD(set, value) \
    JOY_SET_ADD_S(CHAOS_PP_STATE(), set, value)

#define JOY_SET_ADD_S(s, set, value)                                           \
    JOY_I_SET_SET_TREE(                                                        \
        set, JOY_TREE_INSERT_S(s,                                              \
            JOY_I_SET_TREE(set), value, JOY_SET_VALUE_COMP(set)                \
        )                                                                      \
    )                                                                          \
/**/

/*!
 * Remove an element from a set and return the set thus created.
 *
 * If the element is not found in the set, nothing happens.
 */
#define JOY_SET_DISCARD(set, value) \
    JOY_SET_DISCARD_S(CHAOS_PP_STATE(), set, value)

#define JOY_SET_DISCARD_S(s, set, value)                                       \
    JOY_I_SET_SET_TREE(                                                        \
        set, JOY_TREE_REMOVE_S(s,                                              \
            JOY_I_SET_TREE(set), value, JOY_SET_VALUE_COMP(set)                \
        )                                                                      \
    )                                                                          \
/**/

/*!
 * Remove an element from a set and return the set thus created.
 *
 * If the element is not found in the set, a preprocessor error is triggered.
 */
#define JOY_SET_REMOVE(set, value) \
    JOY_SET_REMOVE_S(CHAOS_PP_STATE(), set, value)

#define JOY_SET_REMOVE_S(s, set, value)                                        \
    JOY_I_SET_SET_TREE(                                                        \
        set, JOY_TREE_REMOVE_E_S(s,                                            \
            JOY_I_SET_TREE(set), value, JOY_SET_VALUE_COMP(set)                \
        )                                                                      \
    )                                                                          \
/**/

/*!
 * Filter elements of a set according to a predicate.
 *
 * @param predicate A macro(s, element, auxiliary_data) to determine
 *                  whether to keep an element.
 * @param data Auxiliary data passed to the predicate.
 */
#define JOY_SET_FILTER(set, predicate, data) \
    JOY_SET_FILTER_S(CHAOS_PP_STATE(), set, predicate, data)

#define JOY_SET_FILTER_S(s, set, predicate, data)                              \
    JOY_I_SET_SET_TREE(set,                                                    \
        JOY_TREE_FILTER_S(s, JOY_I_SET_TREE(set), predicate, data)             \
    )                                                                          \
/**/

/*!
 * Return the union of two sets as a new set.
 *
 * (i.e. all elements that are in either set.)
 *
 * @note The comparator function taken is the one in the first set. If the
 *          two comparators are different, it is undefined behavior.
 */
#define JOY_SET_UNION(a, b) \
    JOY_SET_UNION_S(CHAOS_PP_STATE(), a, b)

#define JOY_SET_UNION_S(s, a, b)                                               \
    JOY_SEQ_TO_SET_S(s,                                                        \
        JOY_SET_VALUE_COMP(a),                                                 \
        JOY_SET_TO_SEQ_S(s, a) JOY_SET_TO_SEQ_S(s, b)                          \
    )                                                                          \
/**/

/*!
 * Return the difference of two sets as a new set.
 *
 * (i.e. all elements that are in this set but not the other.)
 */
#define JOY_SET_DIFFERENCE(a, b) \
    JOY_SET_DIFFERENCE_S(CHAOS_PP_STATE(), a, b)

#define JOY_SET_DIFFERENCE_S(s, a, b) \
    JOY_SET_FILTER_S(s, a, JOY_I_SET_DIFFERENCE, b)

#define JOY_I_SET_DIFFERENCE(s, element, other) \
    CHAOS_PP_NOT(JOY_SET_CONTAINS_S(s, other, element))

/*!
 * Return the intersection of two sets as a new set.
 *
 * (i.e. all elements that are in both sets.)
 */
#define JOY_SET_INTERSECTION(a, b) \
    JOY_SET_INTERSECTION_S(CHAOS_PP_STATE(), a, b)

#define JOY_SET_INTERSECTION_S(s, a, b) \
    JOY_SET_FILTER_S(s, a, JOY_I_SET_INTERSECTION, b)

#define JOY_I_SET_INTERSECTION(s, element, other) \
    JOY_SET_CONTAINS_S(s, other, element)

/*!
 * Return the symmetric difference of two sets as a new set.
 *
 * (i.e. all elements that are in exactly one of the sets.)
 */
#define JOY_SET_SYMMETRIC_DIFFERENCE(a, b) \
    JOY_SET_SYMMETRIC_DIFFERENCE_S(CHAOS_PP_STATE(), a, b)

#define JOY_SET_SYMMETRIC_DIFFERENCE_S(s, a, b)                                \
    JOY_SET_UNION_S(s,                                                         \
        JOY_SET_DIFFERENCE_S(s, a, b), JOY_SET_DIFFERENCE_S(s, b, a)           \
    )                                                                          \
/**/

/*!
 * Update the content of a set with the content of another.
 */
#define JOY_SET_UPDATE(a, b) \
    JOY_SET_UPDATE_S(CHAOS_PP_STATE(), a, b)

#define JOY_SET_UPDATE_S(state, a, b)                                          \
    JOY_I_SET_SET_TREE(a,                                                      \
        JOY_TREE_UPDATE_S(state,                                               \
            JOY_I_SET_TREE(a),                                                 \
            JOY_I_SET_TREE(b),                                                 \
            JOY_SET_VALUE_COMP(a)                                              \
        )                                                                      \
    )                                                                          \
/**/

/*!
 * Transform a tuple into a set.
 */
#define JOY_TUPLE_TO_SET(compare, tuple) \
    JOY_TUPLE_TO_SET_S(CHAOS_PP_STATE(), compare, tuple)

#define JOY_TUPLE_TO_SET_S(s, compare, tuple)                                  \
    JOY_SEQ_TO_SET_S(s,                                                        \
        compare, CHAOS_PP_TUPLE_TO_SEQ(CHAOS_PP_TUPLE_SIZE(tuple), tuple)      \
    )                                                                          \
/**/

/*!
 * Transform an array into a set.
 */
#define JOY_ARRAY_TO_SET(compare, array) \
    JOY_ARRAY_TO_SET_S(CHAOS_PP_STATE(), compare, array)

#define JOY_ARRAY_TO_SET_S(s, compare, array) \
    JOY_SEQ_TO_SET_S(s, compare, CHAOS_PP_ARRAY_TO_SEQ(array))

/*!
 * Transform a sequence into a set.
 */
#define JOY_SEQ_TO_SET(compare, seq) \
    JOY_SEQ_TO_SET_S(CHAOS_PP_STATE(), compare, seq)

#define JOY_SEQ_TO_SET_S(s, compare, seq)                                      \
    JOY_I_SET_SET_TREE(                                                        \
        JOY_SET(compare), JOY_SEQ_TO_TREE_S(s, compare, seq)                   \
    )                                                                          \
/**/

/*!
 * Transform a set into a sequence.
 */
#define JOY_SET_TO_SEQ(set) \
    JOY_SET_TO_SEQ_S(CHAOS_PP_STATE(), set)

#define JOY_SET_TO_SEQ_S(s, set) \
    JOY_TREE_TO_SEQ_S(s, JOY_I_SET_TREE(set))

/*!
 * Transform a set into a tuple.
 */
#define JOY_SET_TO_TUPLE(set) \
    JOY_SET_TO_TUPLE_S(CHAOS_PP_STATE(), set)

#define JOY_SET_TO_TUPLE_S(s, set) \
    JOY_TREE_TO_TUPLE_S(s, JOY_I_SET_TREE(set))

/*!
 * Transform a set into an array.
 */
#define JOY_SET_TO_ARRAY(set) \
    JOY_SET_TO_ARRAY_S(CHAOS_PP_STATE(), set)

#define JOY_SET_TO_ARRAY_S(s, set) \
    JOY_TREE_TO_ARRAY_S(s, JOY_I_SET_TREE(set))

#endif /* !JOY_INTERNAL_SET_H */
