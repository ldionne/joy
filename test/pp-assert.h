/*!
 * This file defines means of doing static assertions at the preprocessor level.
 */

#ifndef NSTL_PP_ASSERT_H
#define NSTL_PP_ASSERT_H

#include <chaos/preprocessor/comparison.h>
#include <chaos/preprocessor/control/unless.h>


#define ASSERT_TRUE(assertion, message) \
    CHAOS_PP_UNLESS(assertion) (ASSERTION_ERROR(!, message))

#define ASSERTION_ERROR()

#define ASSERT_FALSE(assertion, message) \
    ASSERT_TRUE(CHAOS_PP_NOT(assertion), message)

#define ASSERT_EQUAL(a, b, message) \
    ASSERT_TRUE(CHAOS_PP_EQUAL(a, b), message)

#define ASSERT_NOT_EQUAL(a, b, message) \
    ASSERT_TRUE(CHAOS_PP_NOT_EQUAL(a, b), message)

#define ASSERT_GREATER(a, b, message) \
    ASSERT_TRUE(CHAOS_PP_GREATER(a, b), message)

#define ASSERT_LESS(a, b, message) \
    ASSERT_GREATER(b, a, message)


#endif /* !NSTL_PP_ASSERT_H */
