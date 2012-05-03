/*!
 * This file defines the secondary type traits.
 *
 * @author Louis Dionne
 */

#ifndef JOY_CTYPE_TRAITS_SECONDARY_H
#define JOY_CTYPE_TRAITS_SECONDARY_H

#include "primary.h"
#include <chaos/preprocessor/logical/or.h>


/*!
 * Return whether a @p Ctype represents an arithmetic type.
 */
#define JOY_IS_ARITHMETIC(Ctype) JOY_IS_ARITHMETIC_S(CHAOS_PP_STATE(), Ctype)

#define JOY_IS_ARITHMETIC_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, i s  a r i t h m e t i c) (state, Ctype)

#define JOY_TRAIT_IS_ARITHMETIC i s  a r i t h m e t i c

#define JOY_I_CTYPE_IS_ARITHMETIC_ID() JOY_I_CTYPE_IS_ARITHMETIC
#define JOY_I_CTYPE_IS_ARITHMETIC(state, Ctype)                                \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_IS_ARITHMETIC,                  \
        CHAOS_PP_OR                                                            \
            (JOY_IS_INTEGRAL_S(state, Ctype))                                  \
            (JOY_IS_FLOATING_POINT_S(state, Ctype))                            \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype represents a compound type.
 */
#define JOY_IS_COMPOUND(Ctype) JOY_IS_COMPOUND_S(CHAOS_PP_STATE(), Ctype)

#define JOY_IS_COMPOUND_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, i s  c o m p o u n d) (state, Ctype)

#define JOY_TRAIT_IS_COMPOUND i s  c o m p o u n d

#define JOY_I_CTYPE_IS_COMPOUND_ID() JOY_I_CTYPE_IS_COMPOUND
#define JOY_I_CTYPE_IS_COMPOUND(state, Ctype)                                  \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_IS_COMPOUND,                    \
                                                                               \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype represents a fundamental type.
 */
#define JOY_IS_FUNDAMENTAL(Ctype) JOY_IS_FUNDAMENTAL_S(CHAOS_PP_STATE(), Ctype)

#define JOY_IS_FUNDAMENTAL_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, i s  f u n d a m e n t a l) (state, Ctype)

#define JOY_TRAIT_IS_FUNDAMENTAL i s  f u n d a m e n t a l

#define JOY_I_CTYPE_IS_FUNDAMENTAL_ID() JOY_I_CTYPE_IS_FUNDAMENTAL
#define JOY_I_CTYPE_IS_FUNDAMENTAL(state, Ctype)                               \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_IS_FUNDAMENTAL,                 \
                                                                               \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype represents a member pointer.
 */
#define JOY_IS_MEMBER_POINTER(Ctype) JOY_IS_MEMBER_POINTER_S(CHAOS_PP_STATE(), Ctype)

#define JOY_IS_MEMBER_POINTER_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, i s  m e m b e r  p o i n t e r) (state, Ctype)

#define JOY_TRAIT_IS_MEMBER_POINTER i s  m e m b e r  p o i n t e r

#define JOY_I_CTYPE_IS_MEMBER_POINTER_ID() JOY_I_CTYPE_IS_MEMBER_POINTER
#define JOY_I_CTYPE_IS_MEMBER_POINTER(state, Ctype)                            \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_IS_MEMBER_POINTER,              \
                                                                               \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype represents a C++ object.
 */
#define JOY_IS_OBJECT(Ctype) JOY_IS_OBJECT_S(CHAOS_PP_STATE(), Ctype)

#define JOY_IS_OBJECT_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, i s  o b j e c t) (state, Ctype)

#define JOY_TRAIT_IS_OBJECT i s  o b j e c t

#define JOY_I_CTYPE_IS_OBJECT_ID() JOY_I_CTYPE_IS_OBJECT
#define JOY_I_CTYPE_IS_OBJECT(state, Ctype)                                    \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_IS_OBJECT,                      \
                                                                               \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype represents a reference.
 */
#define JOY_IS_REFERENCE(Ctype) JOY_IS_REFERENCE_S(CHAOS_PP_STATE(), Ctype)

#define JOY_IS_REFERENCE_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, i s  r e f e r e n c e) (state, Ctype)

#define JOY_TRAIT_IS_REFERENCE i s  r e f e r e n c e

#define JOY_I_CTYPE_IS_REFERENCE_ID() JOY_I_CTYPE_IS_REFERENCE
#define JOY_I_CTYPE_IS_REFERENCE(state, Ctype)                                 \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_IS_REFERENCE,                   \
                                                                               \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype represents a scalar type.
 */
#define JOY_IS_SCALAR(Ctype) JOY_IS_SCALAR_S(CHAOS_PP_STATE(), Ctype)

#define JOY_IS_SCALAR_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, i s  s c a l a r) (state, Ctype)

#define JOY_TRAIT_IS_SCALAR i s  s c a l a r

#define JOY_I_CTYPE_IS_SCALAR_ID() JOY_I_CTYPE_IS_SCALAR
#define JOY_I_CTYPE_IS_SCALAR(state, Ctype)                                    \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_IS_SCALAR,                      \
                                                                               \
    )                                                                          \
/**/

#endif /* !JOY_CTYPE_TRAITS_SECONDARY_H */
