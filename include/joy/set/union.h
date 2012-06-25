/*!
 * This file defines a macro to compute the union of two sets.
 *
 * @author Louis Dionne
 */

#ifndef JOY_SET_UNION_H
#define JOY_SET_UNION_H

#include <joy/seq/to_set.h>
#include <joy/set/value_cmp.h>
#include <joy/set/to_seq.h>

#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Return the union of two sets as a new set.
 *
 * (i.e. all elements that are in either set.)
 *
 * @note The comparator function taken is the one in the first set. If the
 *       two comparators are different, it is undefined behavior.
 */
#define JOY_SET_UNION(a, b) \
    JOY_SET_UNION_S(CHAOS_PP_STATE(), a, b)

#define JOY_SET_UNION_S(s, a, b)                                               \
    JOY_SEQ_TO_SET_S(s,                                                        \
        JOY_SET_VALUE_CMP(a),                                                  \
        JOY_SET_TO_SEQ_S(s, a) JOY_SET_TO_SEQ_S(s, b)                          \
    )                                                                          \
/**/

#endif /* !JOY_SET_UNION_H */
