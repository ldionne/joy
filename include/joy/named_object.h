/*!
 * This file defines an interface to create and manipulate preprocessor objects.
 *
 * @author Louis Dionne
 */

#ifndef JOY_NAMED_OBJECT_H
#define JOY_NAMED_OBJECT_H

#include "type.h"
#include "object.h"
#include <chaos/preprocessor/recursion/expr.h>


/*!
 * The type of a named object.
 */
#define JOY_NAMED_OBJECT JOY_NAMED_OBJECT_S(CHAOS_PP_STATE())

#define JOY_NAMED_OBJECT_S(state)                                              \
    JOY_TYPE_S(state, NamedObject, JOY_OBJECT_S(state),                        \
                    ((n e w, JOY_I_NAMED_OBJECT_NEW_ID))                       \
                    ((n a m e  o f, JOY_I_NAMED_OBJECT_NAMEOF_ID))             \
                    ((n a m e s p a c e  o f, JOY_I_NAMED_OBJECT_NAMESPACEOF_ID)) \
    )                                                                          \
/**/
#define JOY_NAMED_OBJECT_S_ID() JOY_NAMED_OBJECT_S

/*!
 * Create a named object.
 *
 * @param namespace The containing namespace.
 * @param name The name of the object.
 */
#define JOY_I_NAMED_OBJECT_NEW(state, type, namespace, name, attrs)            \
    JOY_SUPER_S(state, JOY_NAMED_OBJECT_S(state), n e w) (state,               \
        type, attrs ((n a m e s p a c e, namespace)) ((n a m e, name))         \
    )                                                                          \
/**/
#define JOY_I_NAMED_OBJECT_NEW_ID() JOY_I_NAMED_OBJECT_NEW

/*!
 * Return the name of an object.
 */
#define JOY_NAMEOF(self) \
    JOY_NAMEOF_S(CHAOS_PP_STATE(), self)

#define JOY_NAMEOF_S(state, self) \
    JOY_SEND_S(state, self, n a m e  o f) (state, self)

#define JOY_I_NAMED_OBJECT_NAMEOF(state, self) \
    JOY_GETATTR_S(state, self, n a m e)
#define JOY_I_NAMED_OBJECT_NAMEOF_ID() JOY_I_NAMED_OBJECT_NAMEOF

/*!
 * Return the namespace of an object.
 */
#define JOY_NAMESPACEOF(self) \
    JOY_NAMESPACEOF_S(CHAOS_PP_STATE(), self)

#define JOY_NAMESPACEOF_S(state, self) \
    JOY_SEND_S(state, self, n a m e s p a c e  o f) (state, self)

#define JOY_I_NAMED_OBJECT_NAMESPACEOF(state, self) \
    JOY_GETATTR_S(state, self, n a m e s p a c e)
#define JOY_I_NAMED_OBJECT_NAMESPACEOF_ID() JOY_I_NAMED_OBJECT_NAMESPACEOF

#endif /* !JOY_NAMED_OBJECT_H */
