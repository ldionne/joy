/*!
 * This file defines an interface to manipulate and create type traits.
 *
 * @author Louis Dionne
 */

#ifndef JOY_CTYPE_TRAITS_BASE_H
#define JOY_CTYPE_TRAITS_BASE_H

#include "../../internal/strcmp.h"
#include "../../internal/map.h"
#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Create a trait container with specified traits.
 *
 * @param traits A sequence of trait:value tuples.
 */
#define JOY_TRAITS(traits) JOY_TRAITS_S(CHAOS_PP_STATE(), traits)

#define JOY_TRAITS_S(state, traits) \
    JOY_SEQ_TO_MAP_S(state, JOY_I_TRAITS_BASE_LESS, traits)

#define JOY_I_TRAITS_BASE_LESS(state, a, b) \
    JOY_MAP_KEY_COMP_ADJUST(JOY_STRING_LESS_S, state, a, b)

/*!
 * Define a new trait.
 */
#define JOY_DEFINE_TRAIT(Ctype, trait, value_unless_specified) \
    JOY_DEFINE_TRAIT_S(CHAOS_PP_STATE(), Ctype, trait, value_unless_specified)

#define JOY_DEFINE_TRAIT_S(state, Ctype, trait, value_unless_specified)        \
    JOY_MAP_FIND_S(state,                                                      \
        JOY_TRAITSOF_S(state, Ctype), trait,                                   \
        value_unless_specified                                                 \
    )                                                                          \
/**/

#endif /* !JOY_CTYPE_TRAITS_BASE_H */
