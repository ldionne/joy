/*!
 * This file defines the long primitive type.
 *
 * @author Louis Dionne
 */

#ifndef JOY_CTYPE_PRIMITIVE_LONG_H
#define JOY_CTYPE_PRIMITIVE_LONG_H

#include "base.h"
#include "../traits.h"
#include <chaos/preprocessor/recursion/expr.h>


#define JOY_LONG JOY_LONG_S(CHAOS_PP_STATE())

#define JOY_LONG_S(state) JOY_I_LONG(state, JOY_PRIMITIVE_S(state))
#define JOY_I_LONG(state, cached_primitive)                                    \
    JOY_NEW_S(state, cached_primitive) (state, cached_primitive,               \
        long, ((JOY_TRAIT_IS_INTEGRAL, 1))                                     \
    )                                                                          \
/**/

#endif /* !JOY_CTYPE_PRIMITIVE_LONG_H */
