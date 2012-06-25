/*!
 * This file defines the short primitive type.
 *
 * @author Louis Dionne
 */

#ifndef JOY_CTYPE_PRIMITIVE_SHORT_H
#define JOY_CTYPE_PRIMITIVE_SHORT_H

#include "base.h"
#include "../traits.h"
#include <chaos/preprocessor/recursion/expr.h>


#define JOY_SHORT JOY_SHORT_S(CHAOS_PP_STATE())

#define JOY_SHORT_S(state) JOY_I_SHORT(state, JOY_PRIMITIVE_S(state))
#define JOY_I_SHORT(state, cached_primitive)                                   \
    JOY_NEW_S(state, cached_primitive) (state, cached_primitive,               \
        short, ((JOY_TRAIT_IS_INTEGRAL, 1))                                    \
    )                                                                          \
/**/

#endif /* !JOY_CTYPE_PRIMITIVE_SHORT_H */
