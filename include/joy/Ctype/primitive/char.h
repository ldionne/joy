/*!
 * This file defines the char primitive type.
 *
 * @author Louis Dionne
 */

#ifndef JOY_CTYPE_PRIMITIVE_CHAR_H
#define JOY_CTYPE_PRIMITIVE_CHAR_H

#include "base.h"
#include "../traits.h"
#include <chaos/preprocessor/recursion/expr.h>


#define JOY_CHAR JOY_CHAR_S(CHAOS_PP_STATE())

#define JOY_CHAR_S(state) JOY_I_CHAR(state, JOY_PRIMITIVE_S(state))
#define JOY_I_CHAR(state, cached_primitive)                                    \
    JOY_NEW_S(state, cached_primitive) (state, cached_primitive,               \
        char, ((JOY_TRAIT_IS_INTEGRAL, 1))                                     \
    )                                                                          \
/**/

#endif /* !JOY_CTYPE_PRIMITIVE_CHAR_H */
