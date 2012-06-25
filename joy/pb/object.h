/*!
 * This file defines an interface to create and manipulate
 * prototype-based preprocessor objects.
 *
 * @author Louis Dionne
 */

#ifndef JOY_PB_OBJECT_H
#define JOY_PB_OBJECT_H

#include <joy/base.h>
#include <joy/macro.h>

#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Create a new object ex-nihilo.
 *
 * @param attrs A sequence of attr:value tuples representing the attributes
 *              of the object.
 */
#define JOY_PB_OBJECT(attrs) \
    JOY_PB_OBJECT_S(CHAOS_PP_STATE(), attrs)

#define JOY_PB_OBJECT_S(state, attrs) \
    JOY_BASE_S(state, attrs)

/*!
 * Create a new object inheriting another from another object.
 */
#define JOY_PB_CLONE(super, new_attrs) \
    JOY_PB_CLONE_S(CHAOS_PP_STATE(), super, new_attrs)

#define JOY_PB_CLONE_S(state, super, new_attrs) \
    JOY_PB_SETATTRS_S(state, super, new_attrs)

/*!
 * Return the value of an attribute of an object.
 */
#define JOY_PB_GETATTR(self, attr) \
    JOY_PB_GETATTR_S(CHAOS_PP_STATE(), self, attr)

#define JOY_PB_GETATTR_S(state, self, attr) \
    JOY_BASE_GETATTR_S(state, self, attr)

/*!
 * Overwrite or add an attribute to an object and return the result.
 */
#define JOY_PB_SETATTR(self, attr, value) \
    JOY_PB_SETATTR_S(CHAOS_PP_STATE(), self, attr, value)

#define JOY_PB_SETATTR_S(state, self, attr, value) \
    JOY_BASE_SETATTR_S(state, self, attr, value)

/*!
 * Overwrite or add many attributes to an object and return the result.
 */
#define JOY_PB_SETATTRS(self, attrs) \
    JOY_PB_SETATTRS_S(CHAOS_PP_STATE(), self, attrs)

#define JOY_PB_SETATTRS_S(state, self, attrs) \
    JOY_BASE_UPDATE_S(state, self, attrs)

/*!
 * Delete an attribute of an object and return the result.
 */
#define JOY_PB_DELATTR(self, attr) \
    JOY_PB_DELATTR_S(CHAOS_PP_STATE(), self, attr)

#define JOY_PB_DELATTR_S(state, self, attr) \
    JOY_BASE_DELATTR_S(state, self, attr)

/*!
 * Return whether an object has an attribute.
 */
#define JOY_PB_HASATTR(self, attr) \
    JOY_PB_HASATTR_S(CHAOS_PP_STATE(), self, attr)

#define JOY_PB_HASATTR_S(state, self, attr) \
    JOY_BASE_HASATTR_S(state, self, attr)

/*!
 * Send a message to an object.
 */
#define JOY_PB_SEND(self, message) \
    JOY_PB_SEND_S(CHAOS_PP_STATE(), self, message)

#define JOY_PB_SEND_S(state, self, message) \
    JOY_PB_GETATTR_S(state, self, message)

/// send ? call ? how do we handle trailing arguments ?
#define JOY_PB_CALL(self, message)                                             \
    JOY_MACRO_CALL(                                                            \
        JOY_MACRO_INSERT(                                                      \
            JOY_PB_GETATTR(self, message), 0, self                             \
        )                                                                      \
    )                                                                          \
/**/

#endif /* !JOY_PB_OBJECT_H */
