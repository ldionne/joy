/*!
 * This file defines an interface to manipulate generic pairs.
 *
 * @author Louis Dionne
 */

#ifndef JOY_PAIR_H
#define JOY_PAIR_H

#include <chaos/preprocessor/tuple/elem.h>
#include <chaos/preprocessor/tuple/replace.h>


/*!
 * Create a pair.
 */
#define JOY_PAIR(first, second) (first, second)

/*!
 * Retrieve the first member of a pair.
 */
#define JOY_PAIR_FIRST(pair) CHAOS_PP_TUPLE_ELEM(2, 0, pair)

/*!
 * Retrieve the second member of a pair.
 */
#define JOY_PAIR_SECOND(pair) CHAOS_PP_TUPLE_ELEM(2, 1, pair)

/*!
 * Set the first member of a pair.
 */
#define JOY_PAIR_SET_FIRST(pair, first) CHAOS_PP_TUPLE_REPLACE(0, pair, first)

/*!
 * Set the second member of a pair.
 */
#define JOY_PAIR_SET_SECOND(pair, second) \
    CHAOS_PP_TUPLE_REPLACE(1, pair, second)

#endif /* !JOY_PAIR_H */
