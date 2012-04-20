/*!
 * This file defines a simple interface to manipulate search results.
 *
 * @author Louis Dionne
 */

#ifndef JOY_INTERNAL_SEARCH_RESULT_H
#define JOY_INTERNAL_SEARCH_RESULT_H

#include "pair.h"
#include <chaos/preprocessor/control/if.h>


/*!
 * Create a new search result.
 *
 * @param result The result that was found.
 * @param found A boolean indicating whether the result was found or not, i.e.
 *              whether the result parameter is valid.
 */
#define JOY_SEARCH_RESULT(result, found) JOY_PAIR(result, found)

/*!
 * Unconditionally retrieve the value of a search result.
 */
#define JOY_SEARCH_RESULT_VALUE(res) JOY_PAIR_FIRST(res)

/*!
 * Retrieve the value of a search result only if it was found. If not, return
 * the default value provided.
 */
#define JOY_SEARCH_RESULT_VALUE_D(res, default)                                \
    CHAOS_PP_IF(JOY_SEARCH_RESULT_FOUND(res)) (                                \
        JOY_SEARCH_RESULT_VALUE(res),                                          \
        default                                                                \
    )                                                                          \
/**/

/*!
 * Return whether a result was found.
 */
#define JOY_SEARCH_RESULT_FOUND(res) JOY_PAIR_SECOND(res)

/*!
 * Retrieve the value of a search result only if it was found. If not, a
 * preprocessor error is triggered.
 */
#define JOY_SEARCH_RESULT_VALUE_E(res)                                         \
    CHAOS_PP_IF(JOY_SEARCH_RESULT_FOUND(res)) (                                \
        JOY_SEARCH_RESULT_VALUE(res),                                          \
        JOY_I_SEARCH_VALUE_VALUE_NOT_FOUND_EXCEPTION(!)                        \
    )                                                                          \
/**/
#define JOY_I_SEARCH_VALUE_VALUE_NOT_FOUND_EXCEPTION()

#endif /* !JOY_INTERNAL_SEARCH_RESULT_H */
