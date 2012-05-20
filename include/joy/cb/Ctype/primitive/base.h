/*!
 * This file defines an interface to create the primitive types of C.
 *
 * @author Louis Dionne
 */

#ifndef JOY_CTYPE_PRIMITIVE_BASE_H
#define JOY_CTYPE_PRIMITIVE_BASE_H

#include "../base.h"
#include <chaos/preprocessor/recursion/expr.h>


/*!
 * A primitive type.
 */
#define JOY_PRIMITIVE JOY_PRIMITIVE_S(CHAOS_PP_STATE())

#define JOY_PRIMITIVE_S(state)                                                 \
    JOY_TYPE_S(state, Primitive C type, JOY_CTYPE_S(state),                    \
                    ((d e c l a r a t i o n, JOY_I_PRIMITIVE_DECLARATION_ID))  \
                    ((d e f i n i t i o n, JOY_I_PRIMITIVE_DEFINITION_ID))     \
    )                                                                          \
/**/
#define JOY_PRIMITIVE_S_ID() JOY_PRIMITIVE_S

/*!
 * Declare a primitive type.
 *
 * By definition, primitive types need'nt be declared.
 */
#define JOY_I_PRIMITIVE_DECLARATION(state, type)
#define JOY_I_PRIMITIVE_DECLARATION_ID() JOY_I_PRIMITIVE_DECLARATION

/*!
 * Define a primitive type.
 *
 * By definition, primitive types need'nt be defined.
 */
#define JOY_I_PRIMITIVE_DEFINITION(state, type)
#define JOY_I_PRIMITIVE_DEFINITION_ID() JOY_I_PRIMITIVE_DEFINITION

#endif /* !JOY_CTYPE_PRIMITIVE_BASE_H */
