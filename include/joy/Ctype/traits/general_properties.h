/*!
 * This file defines the general properties of a type.
 *
 * @author Louis Dionne
 */

#ifndef JOY_CTYPE_TRAITS_GENERAL_PROPERTIES_H
#define JOY_CTYPE_TRAITS_GENERAL_PROPERTIES_H

#include "secondary.h"


/*!
 * Return the alignment of a @p Ctype.
 */
#define JOY_ALIGNMENT_OF(Ctype) JOY_ALIGNMENT_OF_S(CHAOS_PP_STATE(), Ctype)

#define JOY_ALIGNMENT_OF_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, a l i g n m e n t  o f) (state, Ctype)

#define JOY_TRAIT_ALIGNMENT_OF a l i g n m e n t  o f

#define JOY_I_CTYPE_ALIGNMENT_OF_ID() JOY_I_CTYPE_ALIGNMENT_OF
#define JOY_I_CTYPE_ALIGNMENT_OF(state, Ctype)                                 \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_ALIGNMENT_OF,                   \
                                                                               \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype has a new operator.
 */
#define JOY_HAS_NEW_OPERATOR(Ctype) \
    JOY_HAS_NEW_OPERATOR_S(CHAOS_PP_STATE(), Ctype)

#define JOY_HAS_NEW_OPERATOR_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, h a s  n e w  o p e r a t o r) (state, Ctype)

#define JOY_TRAIT_HAS_NEW_OPERATOR h a s  n e w  o p e r a t o r

#define JOY_I_CTYPE_HAS_NEW_OPERATOR_ID() JOY_I_CTYPE_HAS_NEW_OPERATOR
#define JOY_I_CTYPE_HAS_NEW_OPERATOR(state, Ctype)                             \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_HAS_NEW_OPERATOR,               \
                                                                               \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype has an assignment operator that won't throw.
 */
#define JOY_HAS_NOTHROW_ASSIGN(Ctype) \
    JOY_HAS_NOTHROW_ASSIGN_S(CHAOS_PP_STATE(), Ctype)

#define JOY_HAS_NOTHROW_ASSIGN_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, h a s  n o t h r o w  a s s i g n) (state, Ctype)

#define JOY_TRAIT_HAS_NOTHROW_ASSIGN h a s  n o t h r o w  a s s i g n

#define JOY_I_CTYPE_HAS_NOTHROW_ASSIGN_ID() JOY_I_CTYPE_HAS_NOTHROW_ASSIGN
#define JOY_I_CTYPE_HAS_NOTHROW_ASSIGN(state, Ctype)                           \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_HAS_NOTHROW_ASSIGN,             \
                                                                               \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype has a constructor that won't throw.
 */
#define JOY_HAS_NOTHROW_CONSTRUCTOR(Ctype) \
    JOY_HAS_NOTHROW_CONSTRUCTOR_S(CHAOS_PP_STATE(), Ctype)

#define JOY_HAS_NOTHROW_CONSTRUCTOR_S(state, Ctype)                            \
    JOY_SEND_S(state, Ctype, h a s  n o t h r o w  c o n s t r u c t o r)      \
                                                                (state, Ctype) \
/**/

#define JOY_TRAIT_HAS_NOTHROW_CONSTRUCTOR \
    h a s  n o t h r o w  c o n s t r u c t o r

#define JOY_I_CTYPE_HAS_NOTHROW_CONSTRUCTOR_ID() \
    JOY_I_CTYPE_HAS_NOTHROW_CONSTRUCTOR
#define JOY_I_CTYPE_HAS_NOTHROW_CONSTRUCTOR(state, Ctype)                      \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_HAS_NOTHROW_CONSTRUCTOR,        \
                                                                               \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype has a default constructor that won't throw.
 */
#define JOY_HAS_NOTHROW_DEFAULT_CONSTRUCTOR(Ctype) \
    JOY_HAS_NOTHROW_DEFAULT_CONSTRUCTOR_S(CHAOS_PP_STATE(), Ctype)

#define JOY_HAS_NOTHROW_DEFAULT_CONSTRUCTOR_S(state, Ctype)                    \
    JOY_SEND_S(state,                                                          \
        Ctype, h a s  n o t h r o w  d e f a u l t  c o n s t r u c t o r      \
    ) (state, Ctype)                                                           \
/**/

#define JOY_TRAIT_HAS_NOTHROW_DEFAULT_CONSTRUCTOR \
    h a s  n o t h r o w  d e f a u l t  c o n s t r u c t o r

#define JOY_I_CTYPE_HAS_NOTHROW_DEFAULT_CONSTRUCTOR_ID() \
    JOY_I_CTYPE_HAS_NOTHROW_DEFAULT_CONSTRUCTOR
#define JOY_I_CTYPE_HAS_NOTHROW_DEFAULT_CONSTRUCTOR(state, Ctype)              \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_HAS_NOTHROW_DEFAULT_CONSTRUCTOR, \
                                                                               \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype has a copy operator that won't throw.
 */
#define JOY_HAS_NOTHROW_COPY(Ctype) \
    JOY_HAS_NOTHROW_COPY_S(CHAOS_PP_STATE(), Ctype)

#define JOY_HAS_NOTHROW_COPY_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, h a s  n o t h r o w  c o p y) (state, Ctype)

#define JOY_TRAIT_HAS_NOTHROW_COPY h a s  n o t h r o w  c o p y

#define JOY_I_CTYPE_HAS_NOTHROW_COPY_ID() JOY_I_CTYPE_HAS_NOTHROW_COPY
#define JOY_I_CTYPE_HAS_NOTHROW_COPY(state, Ctype)                             \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_HAS_NOTHROW_COPY,               \
                                                                               \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype has a copy constructor that won't throw.
 */
#define JOY_HAS_NOTHROW_COPY_CONSTRUCTOR(Ctype) \
    JOY_HAS_NOTHROW_COPY_CONSTRUCTOR_S(CHAOS_PP_STATE(), Ctype)

#define JOY_HAS_NOTHROW_COPY_CONSTRUCTOR_S(state, Ctype)                       \
    JOY_SEND_S(state, Ctype,                                                   \
        h a s  n o t h r o w  c o p y  c o n s t r u c t o r                   \
    ) (state, Ctype)                                                           \
/**/

#define JOY_TRAIT_HAS_NOTHROW_COPY_CONSTRUCTOR \
    (h a s  n o t h r o w  c o p y  c o n s t r u c t o r)

#define JOY_I_CTYPE_HAS_NOTHROW_COPY_CONSTRUCTOR_ID() \
    JOY_I_CTYPE_HAS_NOTHROW_COPY_CONSTRUCTOR
#define JOY_I_CTYPE_HAS_NOTHROW_COPY_CONSTRUCTOR(state, Ctype)                 \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_HAS_NOTHROW_COPY_CONSTRUCTOR,   \
                                                                               \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype has a trivial assignment operator.
 */
#define JOY_HAS_TRIVIAL_ASSIGN(Ctype) \
    JOY_HAS_TRIVIAL_ASSIGN_S(CHAOS_PP_STATE(), Ctype)

#define JOY_HAS_TRIVIAL_ASSIGN_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, h a s  t r i v i a l  a s s i g n) (state, Ctype)

#define JOY_TRAIT_HAS_TRIVIAL_ASSIGN h a s  t r i v i a l  a s s i g n

#define JOY_I_CTYPE_HAS_TRIVIAL_ASSIGN_ID() JOY_I_CTYPE_HAS_TRIVIAL_ASSIGN
#define JOY_I_CTYPE_HAS_TRIVIAL_ASSIGN(state, Ctype)                           \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_HAS_TRIVIAL_ASSIGN,             \
                                                                               \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype has a trivial constructor.
 */
#define JOY_HAS_TRIVIAL_CONSTRUCTOR(Ctype) \
    JOY_HAS_TRIVIAL_CONSTRUCTOR_S(CHAOS_PP_STATE(), Ctype)

#define JOY_HAS_TRIVIAL_CONSTRUCTOR_S(state, Ctype)                            \
    JOY_SEND_S(state, Ctype,                                                   \
        h a s  t r i v i a l  c o n s t r u c t o r                            \
    ) (state, Ctype)                                                           \
/**/

#define JOY_TRAIT_HAS_TRIVIAL_CONSTRUCTOR \
    h a s  t r i v i a l  c o n s t r u c t o r

#define JOY_I_CTYPE_HAS_TRIVIAL_CONSTRUCTOR_ID() \
    JOY_I_CTYPE_HAS_TRIVIAL_CONSTRUCTOR
#define JOY_I_CTYPE_HAS_TRIVIAL_CONSTRUCTOR(state, Ctype)                      \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_HAS_TRIVIAL_CONSTRUCTOR,        \
                                                                               \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype has a trivial default constructor.
 */
#define JOY_HAS_TRIVIAL_DEFAULT_CONSTRUCTOR(Ctype) \
    JOY_HAS_TRIVIAL_DEFAULT_CONSTRUCTOR_S(CHAOS_PP_STATE(), Ctype)

#define JOY_HAS_TRIVIAL_DEFAULT_CONSTRUCTOR_S(state, Ctype)                    \
    JOY_SEND_S(state, Ctype,                                                   \
        h a s  t r i v i a l  d e f a u l t  c o n s t r u c t o r             \
    ) (state, Ctype)                                                           \
/**/

#define JOY_TRAIT_HAS_TRIVIAL_DEFAULT_CONSTRUCTOR \
    h a s  t r i v i a l  d e f a u l t  c o n s t r u c t o r

#define JOY_I_CTYPE_HAS_TRIVIAL_DEFAULT_CONSTRUCTOR_ID() \
    JOY_I_CTYPE_HAS_TRIVIAL_DEFAULT_CONSTRUCTOR
#define JOY_I_CTYPE_HAS_TRIVIAL_DEFAULT_CONSTRUCTOR(state, Ctype)              \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_HAS_TRIVIAL_DEFAULT_CONSTRUCTOR, \
                                                                               \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype has a trivial copy operator.
 */
#define JOY_HAS_TRIVIAL_COPY(Ctype) \
    JOY_HAS_TRIVIAL_COPY_S(CHAOS_PP_STATE(), Ctype)

#define JOY_HAS_TRIVIAL_COPY_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, h a s  t r i v i a l  c o p y) (state, Ctype)

#define JOY_TRAIT_HAS_TRIVIAL_COPY h a s  t r i v i a l  c o p y

#define JOY_I_CTYPE_HAS_TRIVIAL_COPY_ID() JOY_I_CTYPE_HAS_TRIVIAL_COPY
#define JOY_I_CTYPE_HAS_TRIVIAL_COPY(state, Ctype)                             \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_HAS_TRIVIAL_COPY,               \
                                                                               \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype has a trivial copy constructor.
 */
#define JOY_HAS_TRIVIAL_COPY_CONSTRUCTOR(Ctype) \
    JOY_HAS_TRIVIAL_COPY_CONSTRUCTOR_S(CHAOS_PP_STATE(), Ctype)

#define JOY_HAS_TRIVIAL_COPY_CONSTRUCTOR_S(state, Ctype)                       \
    JOY_SEND_S(state, Ctype,                                                   \
        h a s  t r i v i a l  c o p y  c o n s t r u c t o r                   \
    ) (state, Ctype)                                                           \
/**/

#define JOY_TRAIT_HAS_TRIVIAL_COPY_CONSTRUCTOR \
    h a s  t r i v i a l  c o p y  c o n s t r u c t o r

#define JOY_I_CTYPE_HAS_TRIVIAL_COPY_CONSTRUCTOR_ID() \
    JOY_I_CTYPE_HAS_TRIVIAL_COPY_CONSTRUCTOR
#define JOY_I_CTYPE_HAS_TRIVIAL_COPY_CONSTRUCTOR(state, Ctype)                 \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_HAS_TRIVIAL_COPY_CONSTRUCTOR,   \
                                                                               \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype has a trivial destructor.
 */
#define JOY_HAS_TRIVIAL_DESTRUCTOR(Ctype) \
    JOY_HAS_TRIVIAL_DESTRUCTOR_S(CHAOS_PP_STATE(), Ctype)

#define JOY_HAS_TRIVIAL_DESTRUCTOR_S(state, Ctype)                             \
    JOY_SEND_S(state, Ctype,                                                   \
        h a s  t r i v i a l  d e s t r u c t o r                              \
    ) (state, Ctype)                                                           \
/**/

#define JOY_TRAIT_HAS_TRIVIAL_DESTRUCTOR \
    h a s  t r i v i a l  d e s t r u c t o r

#define JOY_I_CTYPE_HAS_TRIVIAL_DESTRUCTOR_ID() \
    JOY_I_CTYPE_HAS_TRIVIAL_DESTRUCTOR
#define JOY_I_CTYPE_HAS_TRIVIAL_DESTRUCTOR(state, Ctype)                       \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_HAS_TRIVIAL_DESTRUCTOR,         \
                                                                               \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype has a virtual destructor.
 */
#define JOY_HAS_VIRTUAL_DESTRUCTOR(Ctype) \
    JOY_HAS_VIRTUAL_DESTRUCTOR_S(CHAOS_PP_STATE(), Ctype)

#define JOY_HAS_VIRTUAL_DESTRUCTOR_S(state, Ctype)                             \
    JOY_SEND_S(state, Ctype,                                                   \
        h a s  v i r t u a l  d e s t r u c t o r                              \
    ) (state, Ctype)                                                           \
/**/

#define JOY_TRAIT_HAS_VIRTUAL_DESTRUCTOR \
    h a s  v i r t u a l  d e s t r u c t o r

#define JOY_I_CTYPE_HAS_VIRTUAL_DESTRUCTOR_ID() \
    JOY_I_CTYPE_HAS_VIRTUAL_DESTRUCTOR
#define JOY_I_CTYPE_HAS_VIRTUAL_DESTRUCTOR(state, Ctype)                       \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_HAS_VIRTUAL_DESTRUCTOR,         \
                                                                               \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype represents an abstract type.
 */
#define JOY_IS_ABSTRACT(Ctype) JOY_IS_ABSTRACT_S(CHAOS_PP_STATE(), Ctype)

#define JOY_IS_ABSTRACT_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, i s  a b s t r a c t) (state, Ctype)

#define JOY_TRAIT_IS_ABSTRACT i s  a b s t r a c t

#define JOY_I_CTYPE_IS_ABSTRACT_ID() JOY_I_CTYPE_IS_ABSTRACT
#define JOY_I_CTYPE_IS_ABSTRACT(state, Ctype)                                  \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_IS_ABSTRACT,                    \
                                                                               \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype represents a constant qualified type.
 */
#define JOY_IS_CONST(Ctype) JOY_IS_CONST_S(CHAOS_PP_STATE(), Ctype)

#define JOY_IS_CONST_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, i s  c o n s t) (state, Ctype)

#define JOY_TRAIT_IS_CONST i s  c o n s t

#define JOY_I_CTYPE_IS_CONST_ID() JOY_I_CTYPE_IS_CONST
#define JOY_I_CTYPE_IS_CONST(state, Ctype)                                     \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_IS_CONST,                       \
                                                                               \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype represents an empty type.
 */
#define JOY_IS_EMPTY(Ctype) JOY_IS_EMPTY_S(CHAOS_PP_STATE(), Ctype)

#define JOY_IS_EMPTY_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, i s  e m p t y) (state, Ctype)

#define JOY_TRAIT_IS_EMPTY i s  e m p t y

#define JOY_I_CTYPE_IS_EMPTY_ID() JOY_I_CTYPE_IS_EMPTY
#define JOY_I_CTYPE_IS_EMPTY(state, Ctype)                                     \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_IS_EMPTY,                       \
                                                                               \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype represents a stateless type.
 */
#define JOY_IS_STATELESS(Ctype) JOY_IS_STATELESS_S(CHAOS_PP_STATE(), Ctype)

#define JOY_IS_STATELESS_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, i s  s t a t e l e s s) (state, Ctype)

#define JOY_TRAIT_IS_STATELESS i s  s t a t e l e s s

#define JOY_I_CTYPE_IS_STATELESS_ID() JOY_I_CTYPE_IS_STATELESS
#define JOY_I_CTYPE_IS_STATELESS(state, Ctype)                                 \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_IS_STATELESS,                   \
                                                                               \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype represents a pod (Plain Old Data) type.
 */
#define JOY_IS_POD(Ctype) JOY_IS_POD_S(CHAOS_PP_STATE(), Ctype)

#define JOY_IS_POD_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, i s  p o d) (state, Ctype)

#define JOY_TRAIT_IS_POD i s  p o d

#define JOY_I_CTYPE_IS_POD_ID() JOY_I_CTYPE_IS_POD
#define JOY_I_CTYPE_IS_POD(state, Ctype)                                       \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_IS_POD,                         \
        CHAOS_PP_OR                                                            \
            (JOY_IS_SCALAR_S(state, Ctype))                                    \
            (JOY_IS_VOID_S(state, Ctype))                                      \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype represents a polymorphic type.
 */
#define JOY_IS_POLYMORPHIC(Ctype) JOY_IS_POLYMORPHIC_S(CHAOS_PP_STATE(), Ctype)

#define JOY_IS_POLYMORPHIC_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, i s  p o l y m o r p h i c) (state, Ctype)

#define JOY_TRAIT_IS_POLYMORPHIC i s  p o l y m o r p h i c

#define JOY_I_CTYPE_IS_POLYMORPHIC_ID() JOY_I_CTYPE_IS_POLYMORPHIC
#define JOY_I_CTYPE_IS_POLYMORPHIC(state, Ctype)                               \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_IS_POLYMORPHIC,                 \
                                                                               \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype represents a signed type.
 */
#define JOY_IS_SIGNED(Ctype) JOY_IS_SIGNED_S(CHAOS_PP_STATE(), Ctype)

#define JOY_IS_SIGNED_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, i s  s i g n e d) (state, Ctype)

#define JOY_TRAIT_IS_SIGNED i s  s i g n e d

#define JOY_I_CTYPE_IS_SIGNED_ID() JOY_I_CTYPE_IS_SIGNED
#define JOY_I_CTYPE_IS_SIGNED(state, Ctype)                                    \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_IS_SIGNED,                      \
                                                                               \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype represents a signed type.
 */
#define JOY_IS_UNSIGNED(Ctype) JOY_IS_UNSIGNED_S(CHAOS_PP_STATE(), Ctype)

#define JOY_IS_UNSIGNED_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, i s  u n s i g n e d) (state, Ctype)

#define JOY_TRAIT_IS_UNSIGNED i s  u n s i g n e d

#define JOY_I_CTYPE_IS_UNSIGNED_ID() JOY_I_CTYPE_IS_UNSIGNED
#define JOY_I_CTYPE_IS_UNSIGNED(state, Ctype)                                  \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_IS_UNSIGNED,                    \
                                                                               \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype represents a volatile qualified type.
 */
#define JOY_IS_VOLATILE(Ctype) JOY_IS_VOLATILE_S(CHAOS_PP_STATE(), Ctype)

#define JOY_IS_VOLATILE_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, i s  v o l a t i l e) (state, Ctype)

#define JOY_TRAIT_IS_VOLATILE i s  v o l a t i l e

#define JOY_I_CTYPE_IS_VOLATILE_ID() JOY_I_CTYPE_IS_VOLATILE
#define JOY_I_CTYPE_IS_VOLATILE(state, Ctype)                                  \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_IS_VOLATILE,                    \
                                                                               \
    )                                                                          \
/**/

/*!
 * Return the size of the @p n'th dimension of a @p Ctype.
 */
#define JOY_EXTENT(Ctype, n) JOY_EXTENT_S(CHAOS_PP_STATE(), Ctype, n)

#define JOY_EXTENT_S(state, Ctype, n) \
    JOY_SEND_S(state, Ctype, e x t e n t) (state, Ctype, n)

#define JOY_TRAIT_EXTENT e x t e n t

#define JOY_I_CTYPE_EXTENT_ID() JOY_I_CTYPE_EXTENT
#define JOY_I_CTYPE_EXTENT(state, Ctype, n)                                    \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_EXTENT,                         \
                                                                               \
    )                                                                          \
/**/

/*!
 * Return the number of array dimensions of a @p Ctype.
 */
#define JOY_RANK(Ctype) JOY_RANK_S(CHAOS_PP_STATE(), Ctype)

#define JOY_RANK_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, r a n k) (state, Ctype)

#define JOY_TRAIT_RANK r a n k

#define JOY_I_CTYPE_RANK_ID() JOY_I_CTYPE_RANK
#define JOY_I_CTYPE_RANK(state, Ctype)                                         \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_RANK,                           \
                                                                               \
    )                                                                          \
/**/

#endif /* !JOY_CTYPE_TRAITS_GENERAL_PROPERTIES_H */
