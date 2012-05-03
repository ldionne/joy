/*!
 * This file defines the primary type traits.
 *
 * @author Louis Dionne
 */

#ifndef JOY_CTYPE_TRAITS_PRIMARY_H
#define JOY_CTYPE_TRAITS_PRIMARY_H

#include "base.h"
#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Return whether a @p Ctype represents an array type.
 */
#define JOY_IS_ARRAY(Ctype) JOY_IS_ARRAY_S(CHAOS_PP_STATE(), Ctype)

#define JOY_IS_ARRAY_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, i s  a r r a y) (state, Ctype)

#define JOY_TRAIT_IS_ARRAY i s  a r r a y

#define JOY_I_CTYPE_IS_ARRAY_ID() JOY_I_CTYPE_IS_ARRAY
#define JOY_I_CTYPE_IS_ARRAY(state, Ctype)                                     \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_IS_ARRAY,                       \
        0                                                                      \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype represents a C++ class.
 */
#define JOY_IS_CLASS(Ctype) JOY_IS_CLASS_S(CHAOS_PP_STATE(), Ctype)

#define JOY_IS_CLASS_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, i s  c l a s s) (state, Ctype)

#define JOY_TRAIT_IS_CLASS i s  c l a s s

#define JOY_I_CTYPE_IS_CLASS_ID() JOY_I_CTYPE_IS_CLASS
#define JOY_I_CTYPE_IS_CLASS(state, Ctype)                                     \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_IS_CLASS,                       \
        0                                                                      \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype represents a complex type.
 */
#define JOY_IS_COMPLEX(Ctype) JOY_IS_COMPLEX_S(CHAOS_PP_STATE(), Ctype)

#define JOY_IS_COMPLEX_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, i s  c o m p l e x) (state, Ctype)

#define JOY_TRAIT_IS_COMPLEX i s  c o m p l e x

#define JOY_I_CTYPE_IS_COMPLEX_ID() JOY_I_CTYPE_IS_COMPLEX
#define JOY_I_CTYPE_IS_COMPLEX(state, Ctype)                                   \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_IS_COMPLEX,                     \
        0                                                                      \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype represents an enum type.
 */
#define JOY_IS_ENUM(Ctype) JOY_IS_ENUM_S(CHAOS_PP_STATE(), Ctype)

#define JOY_IS_ENUM_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, i s  e n u m) (state, Ctype)

#define JOY_TRAIT_IS_ENUM i s  e n u m

#define JOY_I_CTYPE_IS_ENUM_ID() JOY_I_CTYPE_IS_ENUM
#define JOY_I_CTYPE_IS_ENUM(state, Ctype)                                      \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_IS_ENUM,                        \
        0                                                                      \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype represents a floating point type.
 */
#define JOY_IS_FLOATING_POINT(Ctype) \
    JOY_IS_FLOATING_POINT_S(CHAOS_PP_STATE(), Ctype)

#define JOY_IS_FLOATING_POINT_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, i s  f l o a t i n g  p o i n t) (state, Ctype)

#define JOY_TRAIT_IS_FLOATING_POINT i s  f l o a t i n g  p o i n t

#define JOY_I_CTYPE_IS_FLOATING_POINT_ID() JOY_I_CTYPE_IS_FLOATING_POINT
#define JOY_I_CTYPE_IS_FLOATING_POINT(state, Ctype)                            \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_IS_FLOATING_POINT,              \
        0                                                                      \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype represents a function type.
 */
#define JOY_IS_FUNCTION(Ctype) JOY_IS_FUNCTION_S(CHAOS_PP_STATE(), Ctype)

#define JOY_IS_FUNCTION_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, i s  f u n c t i o n) (state, Ctype)

#define JOY_TRAIT_IS_FUNCTION i s  f u n c t i o n

#define JOY_I_CTYPE_IS_FUNCTION_ID() JOY_I_CTYPE_IS_FUNCTION
#define JOY_I_CTYPE_IS_FUNCTION(state, Ctype)                                  \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_IS_FUNCTION,                    \
        0                                                                      \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype represents an integral type.
 */
#define JOY_IS_INTEGRAL(Ctype) JOY_IS_INTEGRAL_S(CHAOS_PP_STATE(), Ctype)

#define JOY_IS_INTEGRAL_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, i s  i n t e g r a l) (state, Ctype)

#define JOY_TRAIT_IS_INTEGRAL i s  i n t e g r a l

#define JOY_I_CTYPE_IS_INTEGRAL_ID() JOY_I_CTYPE_IS_INTEGRAL
#define JOY_I_CTYPE_IS_INTEGRAL(state, Ctype)                                  \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_IS_INTEGRAL,                    \
        0                                                                      \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype represents a member function pointer.
 */
#define JOY_IS_MEMBER_FUNCTION_POINTER(Ctype) \
    JOY_IS_MEMBER_FUNCTION_POINTER_S(CHAOS_PP_STATE(), Ctype)

#define JOY_IS_MEMBER_FUNCTION_POINTER_S(state, Ctype)                         \
    JOY_SEND_S(state, Ctype, i s  m e m b e r  f u n c t i o n  p o i n t e r) \
                                                                (state, Ctype) \
/**/

#define JOY_TRAIT_IS_MEMBER_FUNCTION_POINTER \
    i s  m e m b e r  f u n c t i o n  p o i n t e r

#define JOY_I_CTYPE_IS_MEMBER_FUNCTION_POINTER_ID() \
    JOY_I_CTYPE_IS_MEMBER_FUNCTION_POINTER
#define JOY_I_CTYPE_IS_MEMBER_FUNCTION_POINTER(state, Ctype)                   \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_IS_MEMBER_FUNCTION_POINTER,     \
        0                                                                      \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype represents a member object pointer.
 */
#define JOY_IS_MEMBER_OBJECT_POINTER(Ctype) \
    JOY_IS_MEMBER_OBJECT_POINTER_S(CHAOS_PP_STATE(), Ctype)

#define JOY_IS_MEMBER_OBJECT_POINTER_S(state, Ctype)                           \
    JOY_SEND_S(state, Ctype, i s  m e m b e r  o b j e c t  p o i n t e r)     \
                                                                (state, Ctype) \
/**/

#define JOY_TRAIT_IS_MEMBER_OBJECT_POINTER \
    i s  m e m b e r  o b j e c t  p o i n t e r

#define JOY_I_CTYPE_IS_MEMBER_OBJECT_POINTER_ID() \
    JOY_I_CTYPE_IS_MEMBER_OBJECT_POINTER
#define JOY_I_CTYPE_IS_MEMBER_OBJECT_POINTER(state, Ctype)                     \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_IS_MEMBER_OBJECT_POINTER,       \
        0                                                                      \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype represents a pointer.
 */
#define JOY_IS_POINTER(Ctype) \
    JOY_IS_POINTER_S(CHAOS_PP_STATE(), Ctype)

#define JOY_IS_POINTER_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, i s  p o i n t e r) (state, Ctype)

#define JOY_TRAIT_IS_POINTER i s  p o i n t e r

#define JOY_I_CTYPE_IS_POINTER_ID() JOY_I_CTYPE_IS_POINTER
#define JOY_I_CTYPE_IS_POINTER(state, Ctype)                                   \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_IS_POINTER,                     \
        0                                                                      \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype represents a left value reference.
 */
#define JOY_IS_LVALUE_REFERENCE(Ctype) \
    JOY_IS_LVALUE_REFERENCE_S(CHAOS_PP_STATE(), Ctype)

#define JOY_IS_LVALUE_REFERENCE_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, i s  l v a l u e  r e f e r e n c e) (state, Ctype)

#define JOY_TRAIT_IS_LVALUE_REFERENCE i s  l v a l u e  r e f e r e n c e

#define JOY_I_CTYPE_IS_LVALUE_REFERENCE_ID() JOY_I_CTYPE_IS_LVALUE_REFERENCE
#define JOY_I_CTYPE_IS_LVALUE_REFERENCE(state, Ctype)                          \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_IS_LVALUE_REFERENCE,            \
        0                                                                      \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype represents a right value reference.
 */
#define JOY_IS_RVALUE_REFERENCE(Ctype) \
    JOY_IS_RVALUE_REFERENCE_S(CHAOS_PP_STATE(), Ctype)

#define JOY_IS_RVALUE_REFERENCE_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, i s  r v a l u e  r e f e r e n c e) (state, Ctype)

#define JOY_TRAIT_IS_RVALUE_REFERENCE i s  r v a l u e  r e f e r e n c e

#define JOY_I_CTYPE_IS_RVALUE_REFERENCE_ID() JOY_I_CTYPE_IS_RVALUE_REFERENCE
#define JOY_I_CTYPE_IS_RVALUE_REFERENCE(state, Ctype)                          \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_IS_RVALUE_REFERENCE,            \
        0                                                                      \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype represents an union type.
 */
#define JOY_IS_UNION(Ctype) \
    JOY_IS_UNION_S(CHAOS_PP_STATE(), Ctype)

#define JOY_IS_UNION_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, i s  u n i o n) (state, Ctype)

#define JOY_TRAIT_IS_UNION i s  u n i o n

#define JOY_I_CTYPE_IS_UNION_ID() JOY_I_CTYPE_IS_UNION
#define JOY_I_CTYPE_IS_UNION(state, Ctype)                                     \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_IS_UNION,                       \
        0                                                                      \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype represents the void type.
 */
#define JOY_IS_VOID(Ctype) \
    JOY_IS_VOID_S(CHAOS_PP_STATE(), Ctype)

#define JOY_IS_VOID_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, i s  v o i d) (state, Ctype)

#define JOY_TRAIT_IS_VOID i s  v o i d

#define JOY_I_CTYPE_IS_VOID_ID() JOY_I_CTYPE_IS_VOID
#define JOY_I_CTYPE_IS_VOID(state, Ctype)                                      \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_IS_VOID,                        \
        0                                                                      \
    )                                                                          \
/**/

#endif /* !JOY_CTYPE_TRAITS_PRIMARY_H */
