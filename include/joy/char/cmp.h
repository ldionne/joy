/*!
 * This file defines an interface to compare single characters.
 *
 * @author Louis Dionne
 */

#ifndef JOY_CHAR_CMP_H
#define JOY_CHAR_CMP_H

#include <joy/char/value.h>

#include <chaos/preprocessor/control/branch.h>
#include <chaos/preprocessor/comparison/equal.h>
#include <chaos/preprocessor/comparison/less.h>


#define JOY_CHAR_CMP(a, b) \
    JOY_I_CHAR_CMP(JOY_CHAR_VALUE(a), JOY_CHAR_VALUE(b))

#define JOY_I_CHAR_CMP(a, b) CHAOS_PP_BRANCH                                   \
    (0xIF) (CHAOS_PP_EQUAL(a, b)) (                                            \
        JOY_CHAR_CMP_EQUAL                                                     \
    ) (0xELIF) (CHAOS_PP_LESS(a, b)) (                                         \
        JOY_CHAR_CMP_LESSER                                                    \
    ) (0xELSE) (                                                               \
        JOY_CHAR_CMP_GREATER                                                   \
    ) (0xENDIF)                                                                \
/**/

#define JOY_CHAR_CMP_EQUAL 0
#define JOY_CHAR_CMP_LESSER 1
#define JOY_CHAR_CMP_GREATER 2

#endif /* !JOY_CHAR_CMP_H */
