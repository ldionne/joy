/*!
 * This file defines the void primitive type.
 *
 * @author Louis Dionne
 */

#ifndef JOY_CTYPE_PRIMITIVE_VOID_H
#define JOY_CTYPE_PRIMITIVE_VOID_H

#include "base.h"
#include "../traits.h"
#include <chaos/preprocessor/recursion/expr.h>


#define JOY_VOID JOY_VOID_S(CHAOS_PP_STATE())

#define JOY_VOID_S(state) JOY_I_VOID(state, JOY_PRIMITIVE_S(state))
#define JOY_I_VOID(state, cached_primitive)                                    \
    JOY_NEW_S(state, cached_primitive) (state, cached_primitive,               \
        void, ((JOY_TRAIT_IS_VOID, 1))                                         \
    )                                                                          \
/**/

#endif /* !JOY_CTYPE_PRIMITIVE_VOID_H */
