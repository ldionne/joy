/*!
 * This file defines an interface to manipulate a map with object semantics.
 *
 * @author Louis Dionne
 */

#ifndef JOY_OBJECT_H
#define JOY_OBJECT_H

#include <joy/map.h>
#include <joy/string/lt.h>

#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Create a new object ex-nihilo.
 *
 * @param attrs A sequence of attr:value tuples representing the attributes
 *              of the object.
 */
#define JOY_OBJECT(attrs) \
    JOY_OBJECT_S(CHAOS_PP_STATE(), attrs)

#define JOY_OBJECT_S(s, attrs) \
        JOY_SEQ_TO_MAP_S(s, JOY_I_OBJECT_LT, attrs)

#define JOY_I_OBJECT_LT(s, lhs, rhs) \
    JOY_MAP_KEY_CMP_ADJUST(JOY_STRING_LT_S, s, lhs, rhs)

/*!
 * Create a new object inheriting another from another object.
 */
#define JOY_OBJECT_CLONE(super, new_attrs) \
    JOY_OBJECT_CLONE_S(CHAOS_PP_STATE(), super, new_attrs)

#define JOY_OBJECT_CLONE_S(s, super, new_attrs) \
    JOY_OBJECT_SETATTRS_S(s, super, new_attrs)

/*!
 * Return the value of an attribute of an object.
 */
#define JOY_OBJECT_GETATTR(self, attr) \
    JOY_OBJECT_GETATTR_S(CHAOS_PP_STATE(), self, attr)

#define JOY_OBJECT_GETATTR_S(s, self, attr) \
    JOY_MAP_FIND_E_S(s, self, attr)

/*!
 * Overwrite or add an attribute to an object and return the result.
 */
#define JOY_OBJECT_SETATTR(self, attr, value) \
    JOY_OBJECT_SETATTR_S(CHAOS_PP_STATE(), self, attr, value)

#define JOY_OBJECT_SETATTR_S(s, self, attr, value) \
    JOY_MAP_ADD_S(s, self, attr, value)

/*!
 * Overwrite or add many attributes to an object and return the result.
 *
 * @param attrs A sequence of name:value tuples.
 */
#define JOY_OBJECT_SETATTRS(self, attrs) \
    JOY_OBJECT_SETATTRS_S(CHAOS_PP_STATE(), self, attrs)

#define JOY_OBJECT_SETATTRS_S(s, self, attrs)                                  \
    JOY_MAP_UPDATE_S(s, self,                                                  \
        JOY_SEQ_TO_MAP_S(s, JOY_I_BASE_LESS, attrs)                            \
    )                                                                          \
/**/

/*!
 * Delete an attribute of an object and return the result.
 */
#define JOY_OBJECT_DELATTR(self, attr) \
    JOY_OBJECT_DELATTR_S(CHAOS_PP_STATE(), self, attr)

#define JOY_OBJECT_DELATTR_S(s, self, attr) \
    JOY_MAP_REMOVE_S(s, self, attr)

/*!
 * Return whether an object has a given attribute.
 */
#define JOY_OBJECT_HASATTR(self, attr) \
    JOY_OBJECT_HASATTR_S(CHAOS_PP_STATE(), self, attr)

#define JOY_OBJECT_HASATTR_S(s, self, attr) \
    JOY_MAP_CONTAINS_S(s, self, attr)

/*!
 * Send a message to an object.
 */
#define JOY_OBJECT_SEND(self, message) \
    JOY_OBJECT_SEND_S(CHAOS_PP_STATE(), self, message)

#define JOY_OBJECT_SEND_S(s, self, message) \
    JOY_OBJECT_GETATTR_S(s, self, message)

#endif /* !JOY_OBJECT_H */
