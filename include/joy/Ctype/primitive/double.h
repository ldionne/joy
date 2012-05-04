/*!
 * This file defines the double primitive type.
 *
 * @author Louis Dionne
 */

#ifndef JOY_CTYPE_PRIMITIVE_DOUBLE_H
#define JOY_CTYPE_PRIMITIVE_DOUBLE_H

#include "base.h"
#include "../traits.h"
#include <chaos/preprocessor/recursion/expr.h>


#define JOY_DOUBLE JOY_DOUBLE_S(CHAOS_PP_STATE())

#define JOY_DOUBLE_S(state) JOY_I_DOUBLE(state, JOY_PRIMITIVE_S(state))
#define JOY_I_DOUBLE(state, cached_primitive)                                  \
    JOY_NEW_S(state, cached_primitive) (state, cached_primitive,               \
        double, ((JOY_TRAIT_IS_FLOATING_POINT, 1))                             \
    )                                                                          \
/**/

#endif /* !JOY_CTYPE_PRIMITIVE_DOUBLE_H */
