/*!
 * This file defines an interface to a generic map (dict) data structure.
 *
 * @author Louis Dionne
 */

#ifndef JOY_INTERNAL_MAP_H
#define JOY_INTERNAL_MAP_H

#include "set.h"
#include "pair.h"
#include <chaos/preprocessor/tuple/size.h>
#include <chaos/preprocessor/tuple/to_seq.h>
#include <chaos/preprocessor/seq/transform.h>
#include <chaos/preprocessor/seq/to_tuple.h>
#include <chaos/preprocessor/seq/to_array.h>
#include <chaos/preprocessor/array/to_seq.h>
#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Return an empty map with a defined macro to sort its element in strict
 * weak ordering.
 */
#define JOY_MAP(key_comp) JOY_PAIR(key_comp, JOY_SET(key_comp))

/*!
 * Use this macro to call your custom strict weak ordering operator.
 *
 * @param compare A predicate acting as a strict weak operator (<).
 */
#define JOY_MAP_KEY_COMP_ADJUST(compare, s, a, b) \
    compare(s, JOY_I_MAP_CELL_KEY(a), JOY_I_MAP_CELL_KEY(b))

/*!
 * Return the macro used by a map to sort its element in strict weak ordering.
 */
#define JOY_MAP_KEY_COMP(map) JOY_PAIR_FIRST(map)

#define JOY_I_MAP_SET(map) JOY_PAIR_SECOND(map)
#define JOY_I_MAP_SET_SET(map, set) JOY_PAIR_SET_SECOND(map, set)

#define JOY_I_MAP_CELL(key, value) JOY_PAIR(key, value)
#define JOY_I_MAP_CELL_KEY(cell) JOY_PAIR_FIRST(cell)
#define JOY_I_MAP_CELL_VALUE(cell) JOY_PAIR_SECOND(cell)

/*!
 * Return whether a map is empty.
 */
#define JOY_MAP_EMPTY(map) JOY_SET_EMPTY(JOY_I_MAP_SET(map))

/*!
 * Return the number of elements in a map.
 */
#define JOY_MAP_SIZE(map) \
    JOY_MAP_SIZE_S(CHAOS_PP_STATE(), map)

#define JOY_MAP_SIZE_S(s, map) \
    JOY_SET_SIZE_S(s, JOY_I_MAP_SET(map))

/*!
 * Return a map with all elements removed from it.
 */
#define JOY_MAP_CLEAR(map) \
    JOY_MAP_CLEAR_S(CHAOS_PP_STATE(), map)

#define JOY_MAP_CLEAR_S(s, map)                                                \
    JOY_I_MAP_SET_SET(                                                         \
        map, JOY_SET_CLEAR_S(s, JOY_I_MAP_SET(map))                            \
    )                                                                          \
/**/

/*!
 * Return the value associated to a key in a map.
 *
 * If the key is not found in the map, default is returned.
 */
#define JOY_MAP_FIND(map, key, default) \
    JOY_MAP_FIND_S(CHAOS_PP_STATE(), map, key, default)

#define JOY_MAP_FIND_S(s, map, key, default)                                   \
    JOY_I_MAP_CELL_VALUE(                                                      \
        JOY_SET_FIND_S(s,                                                      \
            JOY_I_MAP_SET(map), JOY_I_MAP_CELL(key, ~),                        \
                                                JOY_I_MAP_CELL(~, default)     \
        )                                                                      \
    )                                                                          \
/**/

/*!
 * Return the value associated to a key in a map.
 *
 * If the key is not found in the map, a preprocessor error is triggered.
 */
#define JOY_MAP_FIND_E(map, key) \
    JOY_MAP_FIND_E_S(CHAOS_PP_STATE(), map, key)

#define JOY_MAP_FIND_E_S(s, map, key)                                          \
    JOY_I_MAP_CELL_VALUE(                                                      \
        JOY_SET_FIND_E_S(s,                                                    \
            JOY_I_MAP_SET(map), JOY_I_MAP_CELL(key, ~)                         \
        )                                                                      \
    )                                                                          \
/**/

/*!
 * Return whether a map contains the specified key.
 */
#define JOY_MAP_CONTAINS(map, key) \
    JOY_MAP_CONTAINS_S(CHAOS_PP_STATE(), map, key)

#define JOY_MAP_CONTAINS_S(s, map, key) \
    JOY_SET_CONTAINS_S(s, JOY_I_MAP_SET(map), JOY_I_MAP_CELL(key, ~))

/*!
 * Add a key:value pair to a map and return the map thus created.
 *
 * If the key is already present in the map, the value associated to it is
 * updated with the new one.
 */
#define JOY_MAP_ADD(map, key, value) \
    JOY_MAP_ADD_S(CHAOS_PP_STATE(), map, key, value)

#define JOY_MAP_ADD_S(s, map, key, value)                                      \
    JOY_I_MAP_SET_SET(map,                                                     \
        JOY_SET_ADD_S(s,                                                       \
            JOY_I_MAP_SET(map), JOY_I_MAP_CELL(key, value)                     \
        )                                                                      \
    )                                                                          \
/**/

/*!
 * Remove a key:value pair from a map and return the map thus created.
 *
 * If the key is not in the map, nothing is done.
 */
#define JOY_MAP_DISCARD(map, key) \
    JOY_MAP_DISCARD_S(CHAOS_PP_STATE(), map, key)

#define JOY_MAP_DISCARD_S(s, map, key)                                         \
    JOY_I_MAP_SET_SET(map,                                                     \
        JOY_SET_DISCARD_S(s,                                                   \
            JOY_I_MAP_SET(map), JOY_I_MAP_CELL(key, ~)                         \
        )                                                                      \
    )                                                                          \
/**/

/*!
 * Remove a key:value pair from a map and return the map thus created.
 *
 * If the key is not in the map, a preprocessor error is triggered.
 */
#define JOY_MAP_REMOVE(map, key) \
    JOY_MAP_REMOVE_S(CHAOS_PP_STATE(), map, key)

#define JOY_MAP_REMOVE_S(s, map, key)                                          \
    JOY_I_MAP_SET_SET(map,                                                     \
        JOY_SET_REMOVE_S(s,                                                    \
            JOY_I_MAP_SET(map), JOY_I_MAP_CELL(key, ~)                         \
        )                                                                      \
    )                                                                          \
/**/

/*!
 * Filter elements of a map according to a predicate.
 *
 * @param predicate A macro(key, auxiliary_data) to determine
 *                  whether to keep an element.
 * @param data Auxiliary data passed to the predicate.
 */
#define JOY_MAP_FILTER(map, predicate, data) \
    JOY_MAP_FILTER_S(CHAOS_PP_STATE(), map, predicate, data)

#define JOY_MAP_FILTER_S(s, map, predicate, data)                              \
    JOY_I_MAP_SET_SET(map,                                                     \
        JOY_SET_FILTER_S(s, JOY_I_MAP_SET(map), predicate, data)               \
    )                                                                          \
/**/

/*!
 * Return the union of two maps as a new map.
 */
#define JOY_MAP_UNION(a, b) \
    JOY_MAP_UNION_S(CHAOS_PP_STATE(), a, b)

#define JOY_MAP_UNION_S(s, a, b) \
    JOY_I_MAP_SET_SET(a, JOY_SET_UNION_S(s, a, b))

/*!
 * Return the difference of two maps as a new map.
 */
#define JOY_MAP_DIFFERENCE(a, b) \
    JOY_MAP_DIFFERENCE_S(CHAOS_PP_STATE(), a, b)

#define JOY_MAP_DIFFERENCE_S(s, a, b) \
    JOY_I_MAP_SET_SET(a, JOY_SET_DIFFERENCE_S(s, a, b))

/*!
 * Return the intersection of two maps as a new map.
 */
#define JOY_MAP_INTERSECTION(a, b) \
    JOY_MAP_INTERSECTION_S(CHAOS_PP_STATE(), a, b)

#define JOY_MAP_INTERSECTION_S(s, a, b) \
    JOY_I_MAP_SET_SET(a, JOY_SET_INTERSECTION_S(s, a, b))

/*!
 * Return the symmetric difference of two maps as a new map.
 */
#define JOY_MAP_SYMMETRIC_DIFFERENCE(a, b) \
    JOY_MAP_SYMMETRIC_DIFFERENCE_S(CHAOS_PP_STATE(), a, b)

#define JOY_MAP_SYMMETRIC_DIFFERENCE_S(s, a, b) \
    JOY_I_MAP_SET_SET(a, JOY_SET_SYMMETRIC_DIFFERENCE_S(s, a, b))

/*!
 * Update the content of a map with the content of another.
 */
#define JOY_MAP_UPDATE(a, b) \
    JOY_MAP_UPDATE_S(CHAOS_PP_STATE(), a, b)

#define JOY_MAP_UPDATE_S(state, a, b)                                          \
    JOY_I_MAP_SET_SET(a,                                                       \
        JOY_SET_UPDATE_S(state,                                                \
            JOY_I_MAP_SET(a),                                                  \
            JOY_I_MAP_SET(b)                                                   \
        )                                                                      \
    )                                                                          \
/**/

/*!
 * Return the values contained in the map in a sequence.
 */
#define JOY_MAP_VALUES(map) \
    JOY_MAP_VALUES_S(CHAOS_PP_STATE(), map)

#define JOY_MAP_VALUES_S(s, map)                                               \
    CHAOS_PP_EXPR_S(s) (                                                       \
        CHAOS_PP_SEQ_TRANSFORM_S(s,                                            \
            JOY_I_MAP_VALUES_ACCUMULATE, JOY_MAP_TO_SEQ_S(s, map), ~           \
        )                                                                      \
    )                                                                          \
/**/

#define JOY_I_MAP_VALUES_ACCUMULATE(s, elem, _) \
    JOY_I_MAP_CELL_VALUE(elem)

/*!
 * Return the keys contained in the map in a sequence.
 */
#define JOY_MAP_KEYS(map) \
    JOY_MAP_KEYS_S(CHAOS_PP_STATE(), map)

#define JOY_MAP_KEYS_S(s, map)                                                 \
    CHAOS_PP_EXPR_S(s) (                                                       \
        CHAOS_PP_SEQ_TRANSFORM_S(s,                                            \
            JOY_I_MAP_KEYS_ACCUMULATE, JOY_MAP_TO_SEQ_S(s, map), ~             \
        )                                                                      \
    )                                                                          \
/**/

#define JOY_I_MAP_KEYS_ACCUMULATE(s, elem, _) \
    JOY_I_MAP_CELL_KEY(elem)

/*!
 * Return the keys and the values contained in the map as a sequence of tuples.
 */
#define JOY_MAP_ITEMS(map) \
    JOY_MAP_ITEMS_S(CHAOS_PP_STATE(), map)

#define JOY_MAP_ITEMS_S(s, map) \
    JOY_MAP_TO_SEQ_S(s, map)

/*!
 * Transform a tuple into a map.
 *
 * @note The tuple must be a tuple of (key, value) tuples.
 */
#define JOY_TUPLE_TO_MAP(compare, tuple) \
    JOY_TUPLE_TO_MAP_S(CHAOS_PP_STATE(), compare, tuple)

#define JOY_TUPLE_TO_MAP_S(s, compare, tuple)                                  \
    JOY_SEQ_TO_MAP_S(s,                                                        \
        compare, CHAOS_PP_TUPLE_TO_SEQ(CHAOS_PP_TUPLE_SIZE(tuple), tuple)      \
    )                                                                          \
/**/

/*!
 * Transform an array into a map.
 *
 * @note The array must be an array of (key, value) tuples.
 */
#define JOY_ARRAY_TO_MAP(compare, array) \
    JOY_ARRAY_TO_MAP_S(CHAOS_PP_STATE(), compare, array)

#define JOY_ARRAY_TO_MAP_S(s, compare, array) \
    JOY_SEQ_TO_MAP_S(s, compare, CHAOS_PP_ARRAY_TO_SEQ(array))

/*!
 * Transform a sequence into a map.
 *
 * @note The sequence must be a sequence of (key, value) tuples.
 */
#define JOY_SEQ_TO_MAP(compare, seq) \
    JOY_SEQ_TO_MAP_S(CHAOS_PP_STATE(), compare, seq)

#define JOY_SEQ_TO_MAP_S(s, compare, seq) \
    JOY_I_SEQ_TO_MAP_I(s, JOY_MAP(compare), seq)

#define JOY_I_SEQ_TO_MAP_I(s, map, seq)                                        \
    JOY_I_MAP_SET_SET(                                                         \
        map, JOY_SEQ_TO_SET_S(s,                                               \
                JOY_SET_VALUE_COMP(JOY_I_MAP_SET(map)), seq                    \
            )                                                                  \
    )                                                                          \
/**/

/*!
 * Transform a map into a sequence.
 */
#define JOY_MAP_TO_SEQ(map) \
    JOY_MAP_TO_SEQ_S(CHAOS_PP_STATE(), map)

#define JOY_MAP_TO_SEQ_S(s, map) \
    JOY_SET_TO_SEQ_S(s, JOY_I_MAP_SET(map))

/*!
 * Transform a map into a tuple.
 */
#define JOY_MAP_TO_TUPLE(map) \
    JOY_MAP_TO_TUPLE_S(CHAOS_PP_STATE(), map)

#define JOY_MAP_TO_TUPLE_S(s, map) \
    CHAOS_PP_SEQ_TO_TUPLE(JOY_MAP_TO_SEQ_S(s, map))

/*!
 * Transform a map into an array.
 */
#define JOY_MAP_TO_ARRAY(map) \
    JOY_MAP_TO_ARRAY_S(CHAOS_PP_STATE(), map)

#define JOY_MAP_TO_ARRAY_S(s, map) \
    CHAOS_PP_SEQ_TO_ARRAY(JOY_MAP_TO_SEQ_S(s, map))

#endif /* !JOY_INTERNAL_MAP_H */
