/*!
 * This file defines an interface to create and manipulate types.
 *
 * @author Louis Dionne
 */

#ifndef JOY_TYPE_H
#define JOY_TYPE_H

#include "internal/map.h"
#include "internal/strcmp.h"
#include <chaos/preprocessor/tuple/elem.h>
#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Create a new type.
 *
 * @param name The name of the type.
 * @param base The base type of the type.
 *              A type inherits all the attributes of its base type.
 * @param attrs A sequence of behavior:implementation tuples containing the
 *              attributes of the type. These attributes usually are macros
 *              applicable to an instance of the type.
 */
#define JOY_TYPE(name, base, attrs) \
    JOY_TYPE_S(CHAOS_PP_STATE(), name, base, attrs)

#define JOY_TYPE_S(state, name, base, attrs) \
    (name, base, JOY_I_TYPE_MAKEATTRS(state, base, attrs))
#define JOY_TYPE_S_ID() JOY_TYPE_S

#define JOY_I_TYPE_MAKEATTRS(state, base, new_attrs)                           \
    JOY_MAP_UPDATE_S(state,                                                    \
        JOY_TYPE_ATTRSOF(base),                                                \
        JOY_SEQ_TO_MAP_S(state, JOY_I_TYPE_LESS, new_attrs)                    \
    )                                                                          \
/**/

#define JOY_I_TYPE_LESS(state, a, b) \
    JOY_MAP_KEY_COMP_ADJUST(JOY_STRING_LESS_S, state, a, b)

/*!
 * The empty type. This is only useful as a base for the first type of the
 * Joy hierarchy.
 */
#define JOY_TYPE_NIL ( , , JOY_MAP(JOY_I_TYPE_LESS))
#define JOY_TYPE_NIL_ID() JOY_TYPE_NIL

/*!
 * Return whether a type is the empty type.
 */
#define JOY_I_TYPE_IS_NIL(type) JOY_MAP_EMPTY(JOY_TYPE_ATTRSOF(type))

/*!
 * This macro is used when a macro should be implemented in a derived type.
 *
 * It will trigger a preprocessor error whenever called with more than 0
 * arguments.
 */
#define JOY_NOT_IMPLEMENTED()
#define JOY_NOT_IMPLEMENTED_ID() JOY_NOT_IMPLEMENTED

/*!
 * Retrieve the name of a type.
 */
#define JOY_TYPE_NAMEOF(type) CHAOS_PP_TUPLE_ELEM(3, 0, type)

/*!
 * Retrieve the base type of a type.
 */
#define JOY_TYPE_BASEOF(type) CHAOS_PP_TUPLE_ELEM(3, 1, type)

/*!
 * Retrieve the attributes of a type as a map.
 */
#define JOY_TYPE_ATTRSOF(type) CHAOS_PP_TUPLE_ELEM(3, 2, type)

/*!
 * Retrieve the value of an attribute of a type.
 *
 * @internal Call the result of the search because we store only IDs. Calling
 *              the ID will give the actual value of the attribute.
 */
#define JOY_TYPE_GETATTR(type, attr) \
    JOY_TYPE_GETATTR_S(CHAOS_PP_STATE(), type, attr)

#define JOY_TYPE_GETATTR_S(state, type, attr)                                  \
    CHAOS_PP_EXPR_S(state) (                                                   \
        JOY_I_TYPE_GETATTR(                                                    \
            CHAOS_PP_OBSTRUCT(), CHAOS_PP_NEXT(state), type, attr              \
        )                                                                      \
    )                                                                          \
/**/

#define JOY_I_TYPE_GETATTR_ID() JOY_I_TYPE_GETATTR
#define JOY_I_TYPE_GETATTR(_, state, type, attr) CHAOS_PP_BRANCH               \
    (0xIF) (JOY_I_TYPE_IS_NIL(type)) (                                         \
        JOY_I_TYPE_GETATTR_EXCEPTION_ATTRIBUTE_NOT_FOUND(!)                    \
    ) (0xELIF) (JOY_MAP_CONTAINS_S(state, JOY_TYPE_ATTRSOF(type), attr)) (     \
        JOY_MAP_FIND_E_S(state, JOY_TYPE_ATTRSOF(type), attr)                  \
    ) (0xELSE) _(                                                              \
        CHAOS_PP_EXPR_S _(state) (                                             \
            JOY_I_TYPE_GETATTR_ID _() (CHAOS_PP_OBSTRUCT _(),                  \
                CHAOS_PP_NEXT(state), JOY_TYPE_BASEOF _(type), attr            \
            )                                                                  \
        )                                                                      \
    ) (0xENDIF) /*ID*/()                                                       \
/**/

#endif /* !JOY_TYPE_H */
