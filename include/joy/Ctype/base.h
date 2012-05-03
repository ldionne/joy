/*!
 * This file defines an interface to manipulate types with a C representation
 * and associated traits.
 *
 * @author Louis Dionne
 */

#ifndef JOY_CTYPE_BASE_H
#define JOY_CTYPE_BASE_H

#include "../object.h"
#include "../type.h"
#include "traits.h"
#include <chaos/preprocessor/recursion/expr.h>


/*!
 * The Ctype type.
 */
#define JOY_CTYPE JOY_CTYPE_S(CHAOS_PP_STATE())

#define JOY_CTYPE_S(state)                                                     \
    JOY_TYPE_S(state, Ctype, JOY_OBJECT_S(state),                              \
                    ((n e w, JOY_I_CTYPE_NEW_ID))                              \
                    ((d e c l a r a t i o n, JOY_NOT_IMPLEMENTED_ID))          \
                    ((d e f i n i t i o n, JOY_NOT_IMPLEMENTED_ID))            \
                    ((C t y p e  o f, JOY_I_CTYPE_CTYPEOF_ID))                 \
                    ((t r a i t s  o f, JOY_I_CTYPE_TRAITSOF_ID))              \
                    ((s e t  t r a i t s, JOY_I_CTYPE_SET_TRAITS_ID))          \
                    ((h a s  t r a i t, JOY_I_CTYPE_HAS_TRAIT_ID))             \
                    ((a d d  t r a i t, JOY_I_CTYPE_ADD_TRAIT_ID))             \
                    ((d e l  t r a i t, JOY_I_CTYPE_DEL_TRAIT_ID))             \
                                                                               \
                    /* Primary traits */                                       \
                    ((i s  a r r a y, JOY_I_CTYPE_IS_ARRAY_ID))                \
                    ((i s  c l a s s, JOY_I_CTYPE_IS_CLASS_ID))                \
                    ((i s  c o m p l e x, JOY_I_CTYPE_IS_COMPLEX_ID))          \
                    ((i s  e n u m, JOY_I_CTYPE_IS_ENUM_ID))                   \
                    ((i s  f l o a t i n g  p o i n t,                         \
                                            JOY_I_CTYPE_IS_FLOATING_POINT_ID)) \
                    ((i s  f u n c t i o n, JOY_I_CTYPE_IS_FUNCTION_ID))       \
                    ((i s  i n t e g r a l, JOY_I_CTYPE_IS_INTEGRAL_ID))       \
                    ((i s  m e m b e r  f u n c t i o n  p o i n t e r,        \
                                JOY_I_CTYPE_IS_MEMBER_FUNCTION_POINTER_ID))    \
                    ((i s  m e m b e r  o b j e c t  p o i n t e r,            \
                                    JOY_I_CTYPE_IS_MEMBER_OBJECT_POINTER_ID))  \
                    ((i s  p o i n t e r, JOY_I_CTYPE_IS_POINTER_ID))          \
                    ((i s  l v a l u e  r e f e r e n c e,                     \
                                        JOY_I_CTYPE_IS_LVALUE_REFERENCE_ID))   \
                    ((i s  r v a l u e  r e f e r e n c e,                     \
                                        JOY_I_CTYPE_IS_RVALUE_REFERENCE_ID))   \
                    ((i s  u n i o n, JOY_I_CTYPE_IS_UNION_ID))                \
                    ((i s  v o i d, JOY_I_CTYPE_IS_VOID_ID))                   \
                                                                               \
                    /* Secondary traits */                                     \
                    ((i s  a r i t h m e t i c, JOY_I_CTYPE_IS_ARITHMETIC_ID)) \
                    ((i s  c o m p o u n d, JOY_I_CTYPE_IS_COMPOUND_ID))       \
                    ((i s  f u n d a m e n t a l,                              \
                                            JOY_I_CTYPE_IS_FUNDAMENTAL_ID))    \
                    ((i s  m e m b e r  p o i n t e r,                         \
                                            JOY_I_CTYPE_IS_MEMBER_POINTER_ID)) \
                    ((i s  o b j e c t, JOY_I_CTYPE_IS_OBJECT_ID))             \
                    ((i s  r e f e r e n c e, JOY_I_CTYPE_IS_REFERENCE_ID))    \
                    ((i s  s c a l a r, JOY_I_CTYPE_IS_SCALAR_ID))             \
                                                                               \
                    /* General properties */                                   \
                    ((a l i g n m e n t  o f, JOY_I_CTYPE_ALIGNMENT_OF_ID))    \
                    ((h a s  n e w  o p e r a t o r,                           \
                                            JOY_I_CTYPE_HAS_NEW_OPERATOR_ID))  \
                    ((h a s  n o t h r o w  a s s i g n,                       \
                                        JOY_I_CTYPE_HAS_NOTHROW_ASSIGN_ID))    \
                    ((h a s  n o t h r o w  c o n s t r u c t o r,             \
                                    JOY_I_CTYPE_HAS_NOTHROW_CONSTRUCTOR_ID))   \
                ((h a s  n o t h r o w  d e f a u l t  c o n s t r u c t o r,  \
                            JOY_I_CTYPE_HAS_NOTHROW_DEFAULT_CONSTRUCTOR_ID))   \
                    ((h a s  n o t h r o w  c o p y,                           \
                                            JOY_I_CTYPE_HAS_NOTHROW_COPY_ID))  \
                    ((h a s  n o t h r o w  c o p y  c o n s t r u c t o r,    \
                                JOY_I_CTYPE_HAS_NOTHROW_COPY_CONSTRUCTOR_ID))  \
                    ((h a s  t r i v i a l  a s s i g n,                       \
                                        JOY_I_CTYPE_HAS_TRIVIAL_ASSIGN_ID))    \
                    ((h a s  t r i v i a l  c o n s t r u c t o r,             \
                                    JOY_I_CTYPE_HAS_TRIVIAL_CONSTRUCTOR_ID))   \
                ((h a s  t r i v i a l  d e f a u l t  c o n s t r u c t o r,  \
                            JOY_I_CTYPE_HAS_TRIVIAL_DEFAULT_CONSTRUCTOR_ID))   \
                    ((h a s  t r i v i a l  c o p y,                           \
                                            JOY_I_CTYPE_HAS_TRIVIAL_COPY_ID))  \
                    ((h a s  t r i v i a l  c o p y  c o n s t r u c t o r,    \
                                JOY_I_CTYPE_HAS_TRIVIAL_COPY_CONSTRUCTOR_ID))  \
                    ((h a s  t r i v i a l  d e s t r u c t o r,               \
                                    JOY_I_CTYPE_HAS_TRIVIAL_DESTRUCTOR_ID))    \
                    ((h a s  v i r t u a l  d e s t r u c t o r,               \
                                    JOY_I_CTYPE_HAS_VIRTUAL_DESTRUCTOR_ID))    \
                    ((i s  a b s t r a c t, JOY_I_CTYPE_IS_ABSTRACT_ID))       \
                    ((i s  c o n s t, JOY_I_CTYPE_IS_CONST_ID))                \
                    ((i s  e m p t y, JOY_I_CTYPE_IS_EMPTY_ID))                \
                    ((i s  s t a t e l e s s, JOY_I_CTYPE_IS_STATELESS_ID))    \
                    ((i s  p o d, JOY_I_CTYPE_IS_POD_ID))                      \
                    ((i s  p o l y m o r p h i c,                              \
                                            JOY_I_CTYPE_IS_POLYMORPHIC_ID))    \
                    ((i s  s i g n e d, JOY_I_CTYPE_IS_SIGNED_ID))             \
                    ((i s  u n s i g n e d, JOY_I_CTYPE_IS_UNSIGNED_ID))       \
                    ((i s  v o l a t i l e, JOY_I_CTYPE_IS_VOLATILE_ID))       \
                    ((e x t e n t, JOY_I_CTYPE_EXTENT_ID))                     \
                    ((r a n k, JOY_I_CTYPE_RANK_ID))                           \
                                                                               \
                    /* Relationships */                                        \
                    ((i s  b a s e  o f, JOY_I_CTYPE_IS_BASE_OF_ID))           \
                    ((i s  v i r t u a l  b a s e  o f,                        \
                                        JOY_I_CTYPE_IS_VIRTUAL_BASE_OF_ID))    \
                    ((i s  c o n v e r t i b l e,                              \
                                            JOY_I_CTYPE_IS_CONVERTIBLE_ID))    \
                    ((i s  s a m e, JOY_I_CTYPE_IS_SAME_ID))                   \
    )                                                                          \
/**/
#define JOY_CTYPE_S_ID() JOY_CTYPE_S

/*!
 * Create a C type.
 *
 * A C type is a type with a C representation and traits giving metainformation
 * about that type.
 *
 * @param Ctype  A valid C type acting as the C representation of the type.
 *               It is important that a variable could be declared using this.
 * @param traits A string of traits providing metainformation about the type.
 */
#define JOY_I_CTYPE_NEW(state, type, Ctype, traits)                            \
    JOY_SUPER_S(state, JOY_CTYPE_S(state), n e w) (state,                      \
        type, ((C t y p e, Ctype)) ((t r a i t s, JOY_TRAITS(traits)))         \
    )                                                                          \
/**/
#define JOY_I_CTYPE_NEW_ID() JOY_I_CTYPE_NEW

/*!
 * Return the C representation of a C type.
 */
#define JOY_CTYPEOF(type) \
    JOY_CTYPEOF_S(CHAOS_PP_STATE(), type)

#define JOY_CTYPEOF_S(state, type) \
    JOY_SEND_S(state, type, C t y p e  o f) (state, type)

#define JOY_I_CTYPE_CTYPEOF(state, type) \
    JOY_GETATTR_S(state, type, C t y p e)
#define JOY_I_CTYPE_CTYPEOF_ID() JOY_I_CTYPE_CTYPEOF

/*!
 * Return a valid C declaration of that type.
 */
#define JOY_DECLARATION(type) \
    JOY_DECLARATION_S(CHAOS_PP_STATE(), type)

#define JOY_DECLARATION_S(state, type) \
    JOY_SEND_S(state, type, d e c l a r a t i o n) (state, type)

/*!
 * Return a valid C definition of that type.
 */
#define JOY_DEFINITION(type) \
    JOY_DEFINITION_S(CHAOS_PP_STATE(), type)

#define JOY_DEFINITION_S(state, type) \
    JOY_SEND_S(state, type, d e f i n i t i o n) (state, type)

/*!
 * Return the traits of a C type.
 */
#define JOY_TRAITSOF(type) \
    JOY_TRAITSOF_S(CHAOS_PP_STATE(), type)

#define JOY_TRAITSOF_S(state, type) \
    JOY_SEND_S(state, type, t r a i t s  o f) (state, type)

#define JOY_I_CTYPE_TRAITSOF(state, type) \
    JOY_GETATTR_S(state, type, t r a i t s)
#define JOY_I_CTYPE_TRAITSOF_ID() JOY_I_CTYPE_TRAITSOF

/*!
 * Set the traits of a C type to a specified trait container.
 */
#define JOY_SET_TRAITS(type, traits) \
    JOY_SET_TRAITS_S(CHAOS_PP_STATE(), type, traits)

#define JOY_SET_TRAITS_S(state, type, traits) \
    JOY_SEND_S(state, type, s e t  t r a i t s) (state, type, traits)

#define JOY_I_CTYPE_SET_TRAITS(state, type, traits) \
    JOY_SETATTR_S(state, type, t r a i t s, traits)
#define JOY_I_CTYPE_SET_TRAITS_ID() JOY_I_CTYPE_SET_TRAITS

/*!
 * Return whether a C type has a given trait.
 */
#define JOY_HAS_TRAIT(type, trait) \
    JOY_HAS_TRAIT_S(CHAOS_PP_STATE(), type, trait)

#define JOY_HAS_TRAIT_S(state, type, trait) \
    JOY_SEND_S(state, type, h a s  t r a i t) (state, type, trait)

#define JOY_I_CTYPE_HAS_TRAIT(state, type, trait) \
    JOY_TRAITS_CONTAINS_S(state, JOY_TRAITSOF_S(state, type), trait)
#define JOY_I_CTYPE_HAS_TRAIT_ID() JOY_I_CTYPE_HAS_TRAIT

/*!
 * Add a trait to a C type.
 */
#define JOY_ADD_TRAIT(type, trait) \
    JOY_ADD_TRAIT_S(CHAOS_PP_STATE(), type, trait)

#define JOY_ADD_TRAIT_S(state, type, trait) \
    JOY_SEND_S(state, type, a d d  t r a i t) (state, type, trait)

#define JOY_I_CTYPE_ADD_TRAIT(state, type, trait)                              \
    JOY_SET_TRAITS_S(state,                                                    \
        type, JOY_TRAITS_INCLUDE_S(state, JOY_TRAITSOF_S(state, type), trait)  \
    )                                                                          \
/**/
#define JOY_I_CTYPE_ADD_TRAIT_ID() JOY_I_CTYPE_ADD_TRAIT

/*!
 * Remove a trait from a C type.
 */
#define JOY_DEL_TRAIT(type, trait) \
    JOY_DEL_TRAIT_S(CHAOS_PP_STATE(), type, trait)

#define JOY_DEL_TRAIT_S(state, type, trait) \
    JOY_SEND_S(state, type, d e l  t r a i t) (state, type, trait)

#define JOY_I_CTYPE_DEL_TRAIT(state, type, trait)                              \
    JOY_SET_TRAITS_S(state,                                                    \
        type, JOY_TRAITS_EXCLUDE_S(state, JOY_TRAITSOF_S(state, type), trait)  \
    )                                                                          \
/**/
#define JOY_I_CTYPE_HAS_TRAIT_ID() JOY_I_CTYPE_HAS_TRAIT

#endif /* !JOY_CTYPE_BASE_H */
