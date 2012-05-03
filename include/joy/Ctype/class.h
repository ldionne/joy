/*!
 * This file defines an interface to create and manipulate preprocessor classes.
 *
 * @author Louis Dionne
 */

#ifndef JOY_CTYPE_CLASS_H
#define JOY_CTYPE_CLASS_H

#include "../type.h"
#include "base.h"
#include <chaos/preprocessor/recursion/expr.h>


/*!
 * The type of a C++ class.
 */
#define JOY_CLASS JOY_CLASS_S(CHAOS_PP_STATE())

#define JOY_CLASS_S(state)                                                     \
    JOY_TYPE_S(state, Class, JOY_CTYPE_S(state),                               \
                        ((n e w, JOY_I_CLASS_NEW_ID))                          \
                        ((m e m b e r  o f, JOY_I_CLASS_MEMBEROF_ID))          \
                        ((d e c l a r a t i o n, JOY_I_CLASS_DECLARATION_ID))  \
                        ((d e f i n i t i o n, JOY_I_CLASS_DEFINITION_ID))     \
    )                                                                          \
/**/
#define JOY_CLASS_S_ID() JOY_CLASS_S

/*!
 * Create a new C++ class.
 */
#define JOY_I_CLASS_NEW(state, type, Ctype, members)                           \
    JOY_SETATTRS_S(state,                                                      \
        JOY_SUPER_S(state, JOY_CTYPE_S(state), n e w)                          \
                                                (state, type, Ctype, traits),  \
        ((m e m b e r s, members))                                             \
    )                                                                          \
/**/
#define JOY_I_CLASS_NEW_ID() JOY_I_CLASS_NEW

/*!
 * Return a member of a class.
 */
#define JOY_MEMBEROF(class, member) \
    JOY_MEMBEROF_S(CHAOS_PP_STATE(), class, member)

#define JOY_MEMBEROF_S(state, class, member) \
    JOY_SEND_S(state, class, m e m b e r  o f) (state, class, member)

#define JOY_I_CLASS_MEMBEROF(state, class, member)                             \
    pass                                                                       \
/**/
#define JOY_I_CLASS_MEMBEROF_ID() JOY_I_CLASS_MEMBEROF

/*!
 * Output the declaration of a class.
 */
#define JOY_I_CLASS_DECLARATION(state, self)                                   \
    pass                                                                       \
/**/
#define JOY_I_CLASS_DECLARATION_ID() JOY_I_CLASS_DECLARATION

/*!
 * Output the definition of a class.
 */
#define JOY_I_CLASS_DEFINITION(state, self)                                    \
    pass                                                                       \
/**/
#define JOY_I_CLASS_DEFINITION_ID() JOY_I_CLASS_DEFINITION

#endif /* !JOY_CTYPE_CLASS_H */
