/*!
 * This file defines the float primitive type.
 *
 * @author Louis Dionne
 */

#ifndef JOY_CTYPE_PRIMITIVE_FLOAT_H
#define JOY_CTYPE_PRIMITIVE_FLOAT_H

#include "base.h"
#include "../traits.h"
#include <chaos/preprocessor/recursion/expr.h>


#define JOY_FLOAT JOY_FLOAT_S(CHAOS_PP_STATE())

#define JOY_FLOAT_S(state) JOY_I_FLOAT(state, JOY_PRIMITIVE_S(state))
#define JOY_I_FLOAT(state, cached_primitive)                                   \
    JOY_NEW_S(state, cached_primitive) (state, cached_primitive,               \
        float, ((JOY_TRAIT_IS_FLOATING_POINT, 1))                              \
    )                                                                          \
/**/

#endif /* !JOY_CTYPE_PRIMITIVE_FLOAT_H */
