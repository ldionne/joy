/*!
 * This file defines a macro to retrieve the macro used to sort the elements
 * of a set.
 *
 * @author Louis Dionne
 */

#ifndef JOY_SET_VALUE_CMP_H
#define JOY_SET_VALUE_CMP_H

#include <joy/pair.h>


/*!
 * Return the macro used by a set to sort its element using strict weak order.
 */
#define JOY_SET_VALUE_CMP(set) JOY_PAIR_FIRST(set)

#endif /* !JOY_SET_VALUE_CMP_H */
