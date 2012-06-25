/*!
 * This file defines an interface to manipulate maps with object semantics.
 *
 * @author Louis Dionne
 */

#ifndef JOY_BASE_H
#define JOY_BASE_H

#include <joy/map.h>
#include <joy/string/lt.h>

#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Create a preprocessor object.
 *
 * @param attrs A sequence of name:value tuples representing
 *             the attributes of the object.
 */
#define JOY_BASE(attrs) \
    JOY_BASE_S(CHAOS_PP_STATE(), attrs)

#define JOY_BASE_S(state, attrs) \
    JOY_SEQ_TO_MAP_S(state, JOY_I_BASE_LESS, attrs)

#define JOY_I_BASE_LESS(state, lhs, rhs) \
    JOY_MAP_KEY_CMP_ADJUST(JOY_STRING_LT_S, state, lhs, rhs)

/*!
 * Return the value of an attribute of an object.
 */
#define JOY_BASE_GETATTR(self, attr) \
    JOY_BASE_GETATTR_S(CHAOS_PP_STATE(), self, attr)

#define JOY_BASE_GETATTR_S(state, self, attr) \
    JOY_MAP_FIND_E_S(state, self, attr)

/*!
 * Overwrite or add an attribute to an object and return the result.
 */
#define JOY_BASE_SETATTR(self, attr, value) \
    JOY_BASE_SETATTR_S(CHAOS_PP_STATE(), self, attr, value)

#define JOY_BASE_SETATTR_S(state, self, attr, value) \
    JOY_MAP_ADD_S(state, self, attr, value)

/*!
 * Overwrite or add many attributes to an object and return the result.
 *
 * @param attrs A sequence of name:value tuples.
 */
#define JOY_BASE_UPDATE(self, attrs) \
    JOY_BASE_UPDATE_S(CHAOS_PP_STATE(), self, attrs)

#define JOY_BASE_UPDATE_S(state, self, attrs)                                  \
    JOY_MAP_UPDATE_S(state, self,                                              \
        JOY_SEQ_TO_MAP_S(state, JOY_I_BASE_LESS, attrs)                        \
    )                                                                          \
/**/

/*!
 * Delete an attribute of an object and return the result.
 */
#define JOY_BASE_DELATTR(self, attr) \
    JOY_BASE_DELATTR_S(CHAOS_PP_STATE(), self, attr)

#define JOY_BASE_DELATTR_S(state, self, attr) \
    JOY_MAP_REMOVE_S(state, self, attr)

/*!
 * Return whether an object has an attribute.
 */
#define JOY_BASE_HASATTR(self, attr) \
    JOY_BASE_HASATTR_S(CHAOS_PP_STATE(), self, attr)

#define JOY_BASE_HASATTR_S(state, self, attr) \
    JOY_MAP_CONTAINS_S(state, self, attr)

#endif /* !JOY_BASE_H */
