/*!
 * This file defines an interface to create and manipulate preprocessor objects.
 *
 * @author Louis Dionne
 */

#ifndef JOY_CB_OBJECT_H
#define JOY_CB_OBJECT_H

#include "type.h"
#include "../base.h"
#include <chaos/preprocessor/recursion/expr.h>


/*!
 * The type of an object. This is the most basic type of the Joy hierarchy.
 */
#define JOY_CB_OBJECT JOY_CB_OBJECT_S(CHAOS_PP_STATE())

#define JOY_CB_OBJECT_S(state)                                                 \
    JOY_CB_TYPE_S(state, Object, JOY_CB_TYPE_NIL,                              \
                                ((n e w, JOY_I_CB_OBJECT_NEW_ID))              \
                                ((s u p e r, JOY_I_CB_OBJECT_SUPER_ID))        \
                                ((g e t  a t t r, JOY_I_CB_OBJECT_GETATTR_ID)) \
                                ((s e t  a t t r, JOY_I_CB_OBJECT_SETATTR_ID)) \
                                ((s e t  a t t r s, JOY_I_CB_OBJECT_SETATTRS_ID)) \
                                ((d e l  a t t r, JOY_I_CB_OBJECT_DELATTR_ID)) \
                                ((h a s  a t t r, JOY_I_CB_OBJECT_HASATTR_ID)) \
                                ((s e n d, JOY_I_CB_OBJECT_SEND_ID))           \
    )                                                                          \
/**/
#define JOY_CB_OBJECT_S_ID() JOY_CB_OBJECT_S

/*!
 * Create an object.
 */
#define JOY_CB_NEW(type) \
    JOY_CB_NEW_S(CHAOS_PP_STATE(), type)

#define JOY_CB_NEW_S(state, type) \
    JOY_CB_TYPE_GETATTR_S(state, type, n e w)

/*!
 * Create an object.
 *
 * @param attrs A sequence of name:value tuples representing
 *              the attributes of the object.
 */
#define JOY_I_CB_OBJECT_NEW(state, type, attrs) \
    JOY_BASE_S(state, attrs ((t y p e, type)))
#define JOY_I_CB_OBJECT_NEW_ID() JOY_I_CB_OBJECT_NEW

/*!
 * Return the macro as implemented in an object's base type.
 */
#define JOY_CB_SUPER(type, message) \
    JOY_CB_SUPER_S(CHAOS_PP_STATE(), type, message)

#define JOY_CB_SUPER_S(state, type, message) \
    JOY_CB_TYPE_GETATTR_S(state, type, s u p e r) (state, type, message)

#define JOY_I_CB_OBJECT_SUPER(state, type, message) \
    JOY_CB_TYPE_GETATTR_S(state, JOY_CB_TYPE_BASEOF(type), message)
#define JOY_I_CB_OBJECT_SUPER_ID() JOY_I_CB_OBJECT_SUPER

/*!
 * Return the value of an attribute of an object.
 */
#define JOY_CB_GETATTR(self, attr) \
    JOY_CB_GETATTR_S(CHAOS_PP_STATE(), self, attr)

#define JOY_CB_GETATTR_S(state, self, attr) \
    JOY_CB_SEND_S(state, self, g e t  a t t r) (state, self, attr)

#define JOY_I_CB_OBJECT_GETATTR(state, self, attr) \
    JOY_BASE_GETATTR_S(state, self, attr)
#define JOY_I_CB_OBJECT_GETATTR_ID() JOY_I_CB_OBJECT_GETATTR

/*!
 * Overwrite or add an attribute to an object and return the modified object.
 */
#define JOY_CB_SETATTR(self, attr, value) \
    JOY_CB_SETATTR_S(CHAOS_PP_STATE(), self, attr, value)

#define JOY_CB_SETATTR_S(state, self, attr, value) \
    JOY_CB_SEND_S(state, self, s e t  a t t r) (state, self, attr, value)

#define JOY_I_CB_OBJECT_SETATTR(state, self, attr, value) \
    JOY_BASE_SETATTR_S(state, self, attr, value)
#define JOY_I_CB_OBJECT_SETATTR_ID() JOY_I_CB_OBJECT_SETATTR

/*!
 * Overwrite or add many attributes to an object and return the modified object.
 *
 * @param attrs A sequence of name:value tuples.
 */
#define JOY_CB_SETATTRS(self, attrs) \
    JOY_CB_SETATTRS_S(CHAOS_PP_STATE(), self, attrs)

#define JOY_CB_SETATTRS_S(state, self, attrs) \
    JOY_CB_SEND_S(state, self, s e t  a t t r s) (state, self, attrs)

#define JOY_I_CB_OBJECT_SETATTRS(state, self, attrs) \
    JOY_BASE_UPDATE_S(state, self, attrs)
#define JOY_I_CB_OBJECT_SETATTRS_ID() JOY_I_CB_OBJECT_SETATTRS

/*!
 * Delete an attribute of an object and return the modified object.
 */
#define JOY_CB_DELATTR(self, attr) \
    JOY_CB_DELATTR_S(CHAOS_PP_STATE(), self, attr)

#define JOY_CB_DELATTR_S(state, self, attr) \
    JOY_CB_SEND_S(state, self, d e l  a t t r) (state, self, attr)

#define JOY_I_CB_OBJECT_DELATTR(state, self, attr) \
    JOY_BASE_DELATTR_S(state, self, attr)
#define JOY_I_CB_OBJECT_DELATTR_ID() JOY_I_CB_OBJECT_DELATTR

/*!
 * Return whether an object has an attribute.
 */
#define JOY_CB_HASATTR(self, attr) \
    JOY_CB_HASATTR_S(CHAOS_PP_STATE(), self, attr)

#define JOY_CB_HASATTR_S(state, self, attr) \
    JOY_CB_SEND_S(state, self, h a s  a t t r) (state, self, attr)

#define JOY_I_CB_OBJECT_HASATTR(state, self, attr) \
    JOY_BASE_HASATTR_S(state, self, attr)
#define JOY_I_CB_OBJECT_HASATTR_ID() JOY_I_CB_OBJECT_HASATTR

/*!
 * Send a message to an object.
 *
 * This macro searches into an object's type for the @p message selector and
 * returns the implementation associated to it. The implementation can then be
 * called with whatever arguments are needed.
 */
#define JOY_CB_SEND(self, message) \
    JOY_CB_SEND_S(CHAOS_PP_STATE(), self, message)

#define JOY_CB_SEND_S(state, self, message)                                    \
    JOY_CB_TYPE_GETATTR_S(state,                                               \
        JOY_I_CB_OBJECT_GETATTR(state,                                         \
            self, t y p e                                                      \
        ),                                                                     \
        s e n d                                                                \
    ) (state, self, message)                                                   \
/**/

#define JOY_I_CB_OBJECT_SEND(state, self, message)                             \
    JOY_CB_TYPE_GETATTR_S(state,                                               \
        JOY_BASE_GETATTR_S(state, self, t y p e), message                      \
    )                                                                          \
/**/
#define JOY_I_CB_OBJECT_SEND_ID() JOY_I_CB_OBJECT_SEND

#endif /* !JOY_CB_OBJECT_H */
