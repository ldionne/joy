/*!
 * This file defines a macro to test whether a preprocessor string is greater
 * than another.
 *
 * @author Louis Dionne
 */

#ifndef JOY_STRING_GT_H
#define JOY_STRING_GT_H

#include <joy/string/lt.h>


#define JOY_STRING_GT(s1, s2) JOY_STRING_LT(s2, s1)
#define JOY_STRING_GT_S(s, s1, s2) JOY_STRING_LT_S(s, s2, s1)

#endif /* !JOY_STRING_GT_H */
