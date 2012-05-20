/*!
 * This file defines the int primitive type.
 *
 * @author Louis Dionne
 */

#ifndef JOY_CTYPE_PRIMITIVE_INT_H
#define JOY_CTYPE_PRIMITIVE_INT_H

#include "base.h"
#include "../traits.h"
#include <chaos/preprocessor/recursion/expr.h>


#define JOY_INT JOY_INT_S(CHAOS_PP_STATE())

#define JOY_INT_S(state) JOY_I_INT(state, JOY_PRIMITIVE_S(state))
#define JOY_I_INT(state, cached_primitive)                                     \
    JOY_NEW_S(state, cached_primitive) (state, cached_primitive,               \
        int, ((JOY_TRAIT_IS_INTEGRAL, 1))                                      \
    )                                                                          \
/**/

#endif /* !JOY_CTYPE_PRIMITIVE_INT_H */
