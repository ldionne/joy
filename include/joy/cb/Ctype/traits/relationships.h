/*!
 * This file defines the possible relationships between types.
 *
 * @author Louis Dionne
 */

#ifndef JOY_CTYPE_TRAITS_RELATIONSHIPS_H
#define JOY_CTYPE_TRAITS_RELATIONSHIPS_H

#include "general_properties.h"


/*!
 * Return whether a @p Ctype is a base type of another @p type.
 */
#define JOY_IS_BASE_OF(Ctype, type) \
    JOY_IS_BASE_OF_S(CHAOS_PP_STATE(), Ctype, type)

#define JOY_IS_BASE_OF_S(state, Ctype, type) \
    JOY_SEND_S(state, Ctype, i s  b a s e  o f) (state, Ctype, type)

#define JOY_TRAIT_IS_BASE_OF i s  b a s e  o f

#define JOY_I_CTYPE_IS_BASE_OF_ID() JOY_I_CTYPE_IS_BASE_OF
#define JOY_I_CTYPE_IS_BASE_OF(state, Ctype)                                   \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_IS_BASE_OF,                     \
                                                                               \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype is a virtual base type of another @p type.
 */
#define JOY_IS_VIRTUAL_BASE_OF(Ctype, type) \
    JOY_IS_VIRTUAL_BASE_OF_S(CHAOS_PP_STATE(), Ctype, type)

#define JOY_IS_VIRTUAL_BASE_OF_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, i s  v i r t u a l  b a s e  o f) (state, Ctype)

#define JOY_TRAIT_IS_VIRTUAL_BASE_OF i s  v i r t u a l  b a s e  o f

#define JOY_I_CTYPE_IS_VIRTUAL_BASE_OF_ID() JOY_I_CTYPE_IS_VIRTUAL_BASE_OF
#define JOY_I_CTYPE_IS_VIRTUAL_BASE_OF(state, Ctype)                           \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_IS_VIRTUAL_BASE_OF,             \
                                                                               \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype is convertible into another @p type.
 */
#define JOY_IS_CONVERTIBLE(Ctype, type) \
    JOY_IS_CONVERTIBLE_S(CHAOS_PP_STATE(), Ctype, type)

#define JOY_IS_CONVERTIBLE_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, i s  c o n v e r t i b l e) (state, Ctype)

#define JOY_TRAIT_IS_CONVERTIBLE i s  c o n v e r t i b l e

#define JOY_I_CTYPE_IS_CONVERTIBLE_ID() JOY_I_CTYPE_IS_CONVERTIBLE
#define JOY_I_CTYPE_IS_CONVERTIBLE(state, Ctype)                               \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_IS_CONVERTIBLE,                 \
                                                                               \
    )                                                                          \
/**/

/*!
 * Return whether a @p Ctype is the same as another @p type.
 */
#define JOY_IS_SAME(Ctype) JOY_IS_SAME_S(CHAOS_PP_STATE(), Ctype)

#define JOY_IS_SAME_S(state, Ctype) \
    JOY_SEND_S(state, Ctype, s a m e) (state, Ctype)

#define JOY_TRAIT_IS_SAME (s a m e)

#define JOY_I_CTYPE_IS_SAME_ID() JOY_I_CTYPE_IS_SAME
#define JOY_I_CTYPE_IS_SAME(state, Ctype)                                      \
    JOY_DEFINE_TRAIT_S(state, Ctype, JOY_TRAIT_IS_SAME,                        \
                                                                               \
    )                                                                          \
/**/

#endif /* !JOY_CTYPE_TRAITS_RELATIONSHIPS_H */
