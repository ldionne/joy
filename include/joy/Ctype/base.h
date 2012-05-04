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
                            ((n e w, JOY_I_CTYPE_NEW_ID))                      \
                            ((d e c l a r a t i o n, JOY_NOT_IMPLEMENTED_ID))  \
                            ((d e f i n i t i o n, JOY_NOT_IMPLEMENTED_ID))    \
                            ((C t y p e  o f, JOY_I_CTYPE_CTYPEOF_ID))         \
                            ((t r a i t s  o f, JOY_I_CTYPE_TRAITSOF_ID))      \
                            ((s e t  t r a i t s, JOY_I_CTYPE_SET_TRAITS_ID))  \
                            ((h a s  t r a i t, JOY_I_CTYPE_HAS_TRAIT_ID))     \
                            ((a d d  t r a i t, JOY_I_CTYPE_ADD_TRAIT_ID))     \
                            ((d e l  t r a i t, JOY_I_CTYPE_DEL_TRAIT_ID))     \
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
