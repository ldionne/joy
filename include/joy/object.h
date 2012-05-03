/*!
 * This file defines an interface to create and manipulate preprocessor objects.
 *
 * @author Louis Dionne
 */

#ifndef JOY_OBJECT_H
#define JOY_OBJECT_H

#include "internal/map.h"
#include "internal/strcmp.h"
#include "type.h"
#include <chaos/preprocessor/recursion/expr.h>


/*!
 * The type of an object. This is the most basic type of the Joy hierarchy.
 */
#define JOY_OBJECT JOY_OBJECT_S(CHAOS_PP_STATE())

#define JOY_OBJECT_S(state)                                                    \
    JOY_TYPE_S(state, Object, JOY_TYPE_NIL,                                    \
                                ((n e w, JOY_I_OBJECT_NEW_ID))                 \
                                ((s u p e r, JOY_I_OBJECT_SUPER_ID))           \
                                ((g e t  a t t r, JOY_I_OBJECT_GETATTR_ID))    \
                                ((s e t  a t t r, JOY_I_OBJECT_SETATTR_ID))    \
                                ((s e t  a t t r s, JOY_I_OBJECT_SETATTRS_ID)) \
                                ((d e l  a t t r, JOY_I_OBJECT_DELATTR_ID))    \
                                ((h a s  a t t r, JOY_I_OBJECT_HASATTR_ID))    \
                                ((s e n d, JOY_I_OBJECT_SEND_ID))              \
    )                                                                          \
/**/
#define JOY_OBJECT_S_ID() JOY_OBJECT_S

/*!
 * Create an object.
 */
#define JOY_NEW(type) \
    JOY_NEW_S(CHAOS_PP_STATE(), type)

#define JOY_NEW_S(state, type) \
    JOY_TYPE_GETATTR_S(state, type, n e w)

/*!
 * Create an object.
 *
 * @param attrs A sequence of name:value tuples representing the attributes of
 *              the object.
 */
#define JOY_I_OBJECT_NEW(state, type, attrs) \
    JOY_SEQ_TO_MAP_S(state, JOY_I_OBJECT_NEW_LESS, attrs ((t y p e, type)))
#define JOY_I_OBJECT_NEW_ID() JOY_I_OBJECT_NEW

#define JOY_I_OBJECT_NEW_LESS(state, a, b) \
    JOY_MAP_KEY_COMP_ADJUST(JOY_STRING_LESS_S, state, a, b)

/*!
 * Return the macro as implemented in an object's base type.
 */
#define JOY_SUPER(type, message) \
    JOY_SUPER_S(CHAOS_PP_STATE(), type, message)

#define JOY_SUPER_S(state, type, message) \
    JOY_TYPE_GETATTR_S(state, type, s u p e r) (state, type, message)

#define JOY_I_OBJECT_SUPER(state, type, message) \
    JOY_TYPE_GETATTR_S(state, JOY_TYPE_BASEOF(type), message)
#define JOY_I_OBJECT_SUPER_ID() JOY_I_OBJECT_SUPER

/*!
 * Return the value of an attribute of an object.
 */
#define JOY_GETATTR(self, attr) \
    JOY_GETATTR_S(CHAOS_PP_STATE(), self, attr)

#define JOY_GETATTR_S(state, self, attr) \
    JOY_SEND_S(state, self, g e t  a t t r) (state, self, attr)

#define JOY_I_OBJECT_GETATTR(state, self, attr) \
    JOY_MAP_FIND_E_S(state, self, attr)
#define JOY_I_OBJECT_GETATTR_ID() JOY_I_OBJECT_GETATTR

/*!
 * Overwrite or add an attribute to an object and return the modified object.
 */
#define JOY_SETATTR(self, attr, value) \
    JOY_SETATTR_S(CHAOS_PP_STATE(), self, attr, value)

#define JOY_SETATTR_S(state, self, attr, value) \
    JOY_SEND_S(state, self, s e t  a t t r) (state, self, attr, value)

#define JOY_I_OBJECT_SETATTR(state, self, attr, value) \
    JOY_MAP_ADD_S(state, self, attr, value)
#define JOY_I_OBJECT_SETATTR_ID() JOY_I_OBJECT_SETATTR

/*!
 * Overwrite or add many attributes to an object and return the modified object.
 *
 * @param attrs A sequence of name:value tuples.
 */
#define JOY_SETATTRS(self, attrs) \
    JOY_SETATTRS_S(CHAOS_PP_STATE(), self, attrs)

#define JOY_SETATTRS_S(state, self, attrs) \
    JOY_SEND_S(state, self, s e t  a t t r s) (state, self, attrs)

#define JOY_I_OBJECT_SETATTRS(state, self, attrs)                              \
    JOY_MAP_UPDATE_S(state, self,                                              \
        JOY_SEQ_TO_MAP_S(state, JOY_I_OBJECT_NEW_LESS, attrs)                  \
    )                                                                          \
/**/
#define JOY_I_OBJECT_SETATTRS_ID() JOY_I_OBJECT_SETATTRS

/*!
 * Delete an attribute of an object and return the modified object.
 */
#define JOY_DELATTR(self, attr) \
    JOY_DELATTR_S(CHAOS_PP_STATE(), self, attr)

#define JOY_DELATTR_S(state, self, attr) \
    JOY_SEND_S(state, self, d e l  a t t r) (state, self, attr)

#define JOY_I_OBJECT_DELATTR(state, self, attr) \
    JOY_MAP_REMOVE_S(state, self, attr)
#define JOY_I_OBJECT_DELATTR_ID() JOY_I_OBJECT_DELATTR

/*!
 * Return whether an object has an attribute.
 */
#define JOY_HASATTR(self, attr) \
    JOY_HASATTR_S(CHAOS_PP_STATE(), self, attr)

#define JOY_HASATTR_S(state, self, attr) \
    JOY_SEND_S(state, self, h a s  a t t r) (state, self, attr)

#define JOY_I_OBJECT_HASATTR(state, self, attr) \
    JOY_MAP_CONTAINS_S(state, self, attr)
#define JOY_I_OBJECT_HASATTR_ID() JOY_I_OBJECT_HASATTR

/*!
 * Send a message to an object.
 *
 * This macro searches into an object's type for the @p message selector and
 * returns the implementation associated to it. The implementation can then be
 * called with whatever arguments are needed.
 */
#define JOY_SEND(self, message) \
    JOY_SEND_S(CHAOS_PP_STATE(), self, message)

#define JOY_SEND_S(state, self, message)                                       \
    JOY_TYPE_GETATTR_S(state,                                                  \
        JOY_I_OBJECT_GETATTR(state,                                            \
            self, t y p e                                                      \
        ),                                                                     \
        s e n d                                                                \
    ) (state, self, message)                                                   \
/**/

#define JOY_I_OBJECT_SEND(state, self, message)                                \
    JOY_TYPE_GETATTR_S(state,                                                  \
        JOY_MAP_FIND_E_S(state, self, t y p e), message                        \
    )                                                                          \
/**/
#define JOY_I_OBJECT_SEND_ID() JOY_I_OBJECT_SEND

#endif /* !JOY_OBJECT_H */
