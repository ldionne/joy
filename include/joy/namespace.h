/*!
 * This file defines an interface to manipulate namespace types.
 *
 * @author Louis Dionne
 */

#ifndef JOY_NAMESPACE_H
#define JOY_NAMESPACE_H

#include "type.h"
#include "named_object.h"
#include "internal/seqzip.h"
#include "internal/map.h"
#include "internal/strcmp.h"
#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/seq/transform.h>


/*!
 * The namespace type.
 */
#define JOY_NAMESPACE JOY_NAMESPACE_S(CHAOS_PP_STATE())

#define JOY_NAMESPACE_S(state)                                                 \
    JOY_TYPE_S(state, Namespace, JOY_NAMED_OBJECT_S(state),                    \
                        ((n e w, JOY_I_NAMESPACE_NEW_ID))                      \
    )                                                                          \
/**/
#define JOY_NAMESPACE_S_ID() JOY_NAMESPACE_S

/*!
 * Create a namespace.
 *
 * A namespace object is a preprocessor object that can hold other objects as
 * its members. The objects it can hold must be named objects.
 *
 * @param members A sequence of named objects that are considered to be inside
 *                  the namespace.
 */
#define JOY_I_NAMESPACE_NEW(state, type, namespace, name, members)             \
    JOY_SUPER_S(state, JOY_NAMESPACE_S(state), n e w) (state,                  \
        type, namespace, name,                                                 \
        ((m e m b e r s, JOY_I_NAMESPACE_PREPARE_MEMBERS(state, members)))     \
    )                                                                          \
/**/
#define JOY_I_NAMESPACE_NEW_ID() JOY_I_NAMESPACE_NEW

#define JOY_I_NAMESPACE_PREPARE_MEMBERS(state, members)                        \
    JOY_SEQ_TO_MAP(JOY_I_NAMESPACE_MEMBERS_LESS,                               \
        JOY_SEQZIP(                                                            \
            CHAOS_PP_EXPR(CHAOS_PP_SEQ_TRANSFORM(                              \
                JOY_I_NAMESPACE_TRANSFORM_OP, members, ~                       \
            )),                                                                \
            members                                                            \
        )                                                                      \
    )                                                                          \
/**/

#define JOY_I_NAMESPACE_TRANSFORM_OP(state, elem, unused_data) \
    JOY_NAMEOF_S(state, elem)

#define JOY_I_NAMESPACE_MEMBERS_LESS(state, a, b) \
    JOY_MAP_KEY_COMP_ADJUST(JOY_STRING_LESS_S, state, a, b)

#endif /* !JOY_NAMESPACE_H */
