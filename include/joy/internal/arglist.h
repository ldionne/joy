/*!
 * This file defines an interface to manipulate argument lists.
 *
 * @author Louis Dionne
 */

#ifndef JOY_INTERNAL_ARGLIST_H
#define JOY_INTERNAL_ARGLIST_H

#include "map.h"
#include "seqzip.h"
#include "seqrange.h"
#include <chaos/preprocessor/comparison/less.h>
#include <chaos/preprocessor/comparison/equal.h>
#include <chaos/preprocessor/arithmetic/dec.h>
#include <chaos/preprocessor/arithmetic/inc.h>
#include <chaos/preprocessor/arithmetic/add.h>
#include <chaos/preprocessor/tuple/rem.h>
#include <chaos/preprocessor/seq/size.h>
#include <chaos/preprocessor/seq/elem.h>
#include <chaos/preprocessor/seq/to_tuple.h>
#include <chaos/preprocessor/recursion/expr.h>


/*!
 * Create an argument list from specified arguments.
 *
 * @param args A sequence of arguments.
 */
#define JOY_ARGLIST(args) JOY_ARGLIST_S(CHAOS_PP_STATE(), args)

#define JOY_ARGLIST_S(state, args)                                             \
    JOY_ARGLIST_BIND_RANGE_S(state,                                            \
        JOY_MAP(JOY_I_ARGLIST_LESS), 0, args                                   \
    )                                                                          \
/**/

#define JOY_I_ARGLIST_LESS(state, lhs, rhs) \
    JOY_MAP_KEY_COMP_ADJUST(JOY_II_ARGLIST_LESS, state, lhs, rhs)

#define JOY_II_ARGLIST_LESS(state, lhs, rhs) CHAOS_PP_LESS(lhs, rhs)

/*!
 * Return whether an argument list is complete, i.e. if all the arguments
 * in the list are bound.
 */
#define JOY_ARGLIST_ISCOMPLETE(arglist) \
    JOY_ARGLIST_ISCOMPLETE_S(CHAOS_PP_STATE(), arglist)

#define JOY_ARGLIST_ISCOMPLETE_S(state, arglist)                               \
    CHAOS_PP_EQUAL(                                                            \
        JOY_ARGLIST_ARITY_S(state, arglist),                                   \
        JOY_ARGLIST_BOUND_S(state, arglist)                                    \
    )                                                                          \
/**/

/*!
 * Bind an argument to a macro at a specified position. If there already is
 * an argument bound at that position, the argument is overwritten.
 */
#define JOY_ARGLIST_BIND(arglist, pos, arg) \
    JOY_ARGLIST_BIND_S(CHAOS_PP_STATE(), arglist, pos, arg)

#define JOY_ARGLIST_BIND_S(state, arglist, pos, arg) \
    JOY_MAP_ADD_S(state, arglist, pos, arg)

/*!
 * Bind many arguments to a macro at a specified position.
 */
#define JOY_ARGLIST_BIND_RANGE(arglist, pos, args) \
    JOY_ARGLIST_BIND_RANGE_S(CHAOS_PP_STATE(), arglist, pos, args)

#define JOY_ARGLIST_BIND_RANGE_S(state, arglist, pos, args)                    \
    JOY_MAP_UPDATE_S(state,                                                    \
        arglist,                                                               \
        JOY_I_ARGLIST_BIND_RANGE_PREPARE(state, pos, args)                     \
    )                                                                          \
/**/

#define JOY_I_ARGLIST_BIND_RANGE_PREPARE(state, from, args)                    \
    JOY_SEQ_TO_MAP_S(state, JOY_I_ARGLIST_LESS,                                \
        JOY_SEQZIP_S(state,                                                    \
            JOY_SEQRANGE_S(state,                                              \
                from, CHAOS_PP_ADD(from, CHAOS_PP_SEQ_SIZE(args))              \
            ), args                                                            \
        )                                                                      \
    )                                                                          \
/**/

/*!
 * Return whether an argument at a specified position is bound.
 */
#define JOY_ARGLIST_ISBOUND(arglist, pos) \
    JOY_ARGLIST_ISBOUND_S(CHAOS_PP_STATE(), arglist, pos)

#define JOY_ARGLIST_ISBOUND_S(state, arglist, pos) \
    JOY_MAP_CONTAINS_S(state, arglist, pos)

/*!
 * Transform an argument list into a representation suitable for use as
 * arguments to a macro call.
 */
#define JOY_ARGLIST_ASARGS(arglist) \
    JOY_ARGLIST_ASARGS_S(CHAOS_PP_STATE(), arglist)

#define JOY_ARGLIST_ASARGS_S(state, arglist)                                   \
    JOY_I_ARGLIST_ASARGS_EXPAND(                                               \
        CHAOS_PP_TUPLE_REM(JOY_ARGLIST_BOUND_S(state, arglist))                \
        CHAOS_PP_SEQ_TO_TUPLE(                                                 \
            JOY_MAP_VALUES_S(state, arglist)                                   \
        )                                                                      \
    )                                                                          \
/**/
#define JOY_I_ARGLIST_ASARGS_EXPAND(x) x

/*!
 * Return the current arity of an argument list, i.e. the number of arguments
 * that must be present in an argument list before it is all bound.
 */
#define JOY_ARGLIST_ARITY(arglist) \
    JOY_ARGLIST_ARITY_S(CHAOS_PP_STATE(), arglist)

#define JOY_ARGLIST_ARITY_S(state, arglist)                                    \
    CHAOS_PP_IF(JOY_MAP_EMPTY(arglist)) (                                      \
        0,                                                                     \
        JOY_I_ARGLIST_SEQ_LAST(JOY_MAP_KEYS_S(state, arglist))                 \
    )                                                                          \
/**/

#define JOY_I_ARGLIST_SEQ_LAST(seq)                                            \
    CHAOS_PP_INC(                                                              \
        CHAOS_PP_SEQ_ELEM(                                                     \
            CHAOS_PP_DEC(CHAOS_PP_SEQ_SIZE(seq)), seq                          \
        )                                                                      \
    )                                                                          \
/**/

/*!
 * Return the number of arguments that are currently bound to an argument list.
 */
#define JOY_ARGLIST_BOUND(arglist) \
    JOY_ARGLIST_BOUND_S(CHAOS_PP_STATE(), arglist)

#define JOY_ARGLIST_BOUND_S(state, arglist) JOY_MAP_SIZE_S(state, arglist)

/*!
 * Append an argument to the end of an argument list.
 */
#define JOY_ARGLIST_APPEND(arglist, arg) \
    JOY_ARGLIST_APPEND_S(CHAOS_PP_STATE(), arglist, arg)

#define JOY_ARGLIST_APPEND_S(state, arglist, arg)                              \
    JOY_ARGLIST_BIND_S(state,                                                  \
        arglist, JOY_ARGLIST_ARITY_S(state, arglist), arg                      \
    )                                                                          \
/**/

/*!
 * Append many arguments to the end of an argument list.
 */
#define JOY_ARGLIST_APPEND_RANGE(arglist, args) \
    JOY_ARGLIST_APPEND_RANGE_S(CHAOS_PP_STATE(), arglist, args)

#define JOY_ARGLIST_APPEND_RANGE_S(state, arglist, args)                       \
    JOY_ARGLIST_BIND_RANGE_S(state,                                            \
        arglist, JOY_ARGLIST_ARITY_S(state, arglist), args                     \
    )                                                                          \
/**/

/*!
 * Prepend an argument to the beginning of an argument list.
 */
#define JOY_ARGLIST_PREPEND(arglist, arg) \
    JOY_ARGLIST_PREPEND_S(CHAOS_PP_STATE(), arglist, arg)

#define JOY_ARGLIST_PREPEND_S(state, arglist, arg) \
    JOY_ARGLIST_PREPEND_RANGE_S(state, arglist, (arg))

/*!
 * Prepend many arguments to the beginning of an argument list.
 */
#define JOY_ARGLIST_PREPEND_RANGE(arglist, args) \
    JOY_ARGLIST_PREPEND_RANGE_S(CHAOS_PP_STATE(), arglist, args)

#define JOY_ARGLIST_PREPEND_RANGE_S(state, arglist, args)                      \
    JOY_ARGLIST_S(state,                                                       \
        args JOY_MAP_VALUES_S(state, arglist)                                  \
    )                                                                          \
/**/

/*!
 * Unbind an argument at a specified position. If the argument at that position
 * is not already bound, nothing is done.
 */
#define JOY_ARGLIST_UNBIND(arglist, pos) \
    JOY_ARGLIST_UNBIND_S(CHAOS_PP_STATE(), arglist, pos)

#define JOY_ARGLIST_UNBIND_S(state, arglist, pos) \
    JOY_MAP_DISCARD_S(state, arglist, pos)

#endif /* !JOY_INTERNAL_ARGLIST_H */
