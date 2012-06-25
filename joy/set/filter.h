/*!
 * This file defines a macro to filter out elements from a set.
 *
 * @author Louis Dionne
 */

#ifndef JOY_SET_FILTER_H
#define JOY_SET_FILTER_H

#include <joy/set/core.h>
#include <joy/set/value_cmp.h>
#include <joy/tree/filter.h>

#include <chaos/preprocessor/recursion/expr.h>


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

#endif /* !JOY_SET_FILTER_H */
