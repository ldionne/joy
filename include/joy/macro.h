/*!
 * This file defines an interface to manipulate macros with more flexibility.
 *
 * @author Louis Dionne
 */

#ifndef JOY_MACRO_H
#define JOY_MACRO_H

#include <joy/arglist.h>
#include <joy/pair.h>

#include <chaos/preprocessor/recursion/expr.h>
#include <chaos/preprocessor/seq/elem.h>
#include <chaos/preprocessor/seq/replace.h>
#include <chaos/preprocessor/punctuation/paren.h>


/*!
 * Create a macro object with no arguments.
 */
#define JOY_MACRO(macro) JOY_MACRO_S(CHAOS_PP_STATE(), macro)

#define JOY_MACRO_S(state, macro) JOY_MACRO_WITH_S(state, macro, /* no args */)

/*!
 * Create a macro object with arguments.
 *
 * @param args A sequence of arguments to bind to the macro.
 */
#define JOY_MACRO_WITH(macro, args) \
    JOY_MACRO_WITH_S(CHAOS_PP_STATE(), macro, args)

#define JOY_MACRO_WITH_S(state, macro, args) \
    JOY_PAIR(macro, JOY_ARGLIST_S(state, args))

#define JOY_I_MACRO_UNDER(macro) JOY_PAIR_FIRST(macro)
#define JOY_I_MACRO_ARGLIST(macro) JOY_PAIR_SECOND(macro)

#define JOY_I_MACRO_SET_UNDER(macro, underlying) \
    JOY_PAIR_SET_FIRST(macro, underlying)

#define JOY_I_MACRO_SET_ARGLIST(macro, args) \
    JOY_PAIR_SET_SECOND(macro, args)

/*!
 * Bind an argument to a macro at a specified position.
 */
#define JOY_MACRO_BIND(macro, pos, arg) \
    JOY_MACRO_BIND_S(CHAOS_PP_STATE(), macro, pos, arg)

#define JOY_MACRO_BIND_S(state, macro, pos, arg)                               \
    JOY_I_MACRO_SET_ARGLIST(macro,                                             \
        JOY_ARGLIST_BIND_S(state,                                              \
            JOY_I_MACRO_ARGLIST(macro), pos, arg                               \
        )                                                                      \
    )                                                                          \
/**/

/*!
 * Bind many arguments to a macro, beginning to bind at a specified position.
 */
#define JOY_MACRO_BIND_RANGE(macro, pos, args) \
    JOY_MACRO_BIND_RANGE_S(CHAOS_PP_STATE(), macro, pos, args)

#define JOY_MACRO_BIND_RANGE_S(state, macro, pos, args)                        \
    JOY_I_MACRO_SET_ARGLIST(macro,                                             \
        JOY_ARGLIST_BIND_RANGE_S(state,                                        \
            JOY_I_MACRO_ARGLIST(macro), pos, args                              \
        )                                                                      \
    )                                                                          \
/**/

/*!
 * Append many arguments to the argument list of a macro.
 */
#define JOY_MACRO_APPEND_RANGE(macro, args) \
    JOY_MACRO_APPEND_RANGE_S(CHAOS_PP_STATE(), macro, args)

#define JOY_MACRO_APPEND_RANGE_S(state, macro, args)                           \
    JOY_I_MACRO_SET_ARGLIST(macro,                                             \
        JOY_ARGLIST_APPEND_RANGE_S(state, JOY_I_MACRO_ARGLIST(macro), args)    \
    )                                                                          \
/**/

/*!
 * Prepend many arguments to the argument list of a macro.
 */
#define JOY_MACRO_PREPEND_RANGE(macro, args) \
    JOY_MACRO_PREPEND_RANGE_S(CHAOS_PP_STATE(), macro, args)

#define JOY_MACRO_PREPEND_RANGE_S(state, macro, args)                          \
    JOY_I_MACRO_SET_ARGLIST(macro,                                             \
        JOY_ARGLIST_PREPEND_RANGE_S(state, JOY_I_MACRO_ARGLIST(macro), args)   \
    )                                                                          \
/**/

/*!
 * Call a macro object with its currently bound arguments. If the macro is
 * not fully bound, a preprocessor error is triggered.
 */
#define JOY_MACRO_CALL(macro) JOY_MACRO_CALL_S(CHAOS_PP_STATE(), macro)

#define JOY_MACRO_CALL_S(state, macro)                                         \
    CHAOS_PP_IF(JOY_MACRO_ALLBOUND_S(state, macro)) (                          \
        JOY_I_MACRO_CALL(state, macro),                                        \
        JOY_I_MACRO_CALL_NOT_FULLY_BOUND_EXCEPTION(!)                          \
    )                                                                          \
/**/
#define JOY_I_MACRO_CALL_NOT_FULLY_BOUND_EXCEPTION()

#define JOY_I_MACRO_CALL(state, macro)                                         \
    JOY_I_MACRO_CALL_EXPAND(                                                   \
        JOY_I_MACRO_UNDER(macro) CHAOS_PP_LPAREN()                             \
        JOY_ARGLIST_ASARGS_S(state, JOY_I_MACRO_ARGLIST(macro))                \
        CHAOS_PP_RPAREN()                                                      \
    )                                                                          \
/**/
#define JOY_I_MACRO_CALL_EXPAND(x) x

/*!
 * Return the current arity of the macro, i.e. the number of arguments that
 * must be bound to it before it is called.
 */
#define JOY_MACRO_ARITY(macro) JOY_MACRO_ARITY_S(CHAOS_PP_STATE(), macro)

#define JOY_MACRO_ARITY_S(state, macro) \
    JOY_ARGLIST_ARITY_S(state, JOY_I_MACRO_ARGLIST(macro))

/*!
 * Return whether all the arguments of a macro are currently bound, i.e. if
 * the macro is ready to be called.
 */
#define JOY_MACRO_ALLBOUND(macro) JOY_MACRO_ALLBOUND_S(CHAOS_PP_STATE(), macro)

#define JOY_MACRO_ALLBOUND_S(state, macro) \
    JOY_ARGLIST_ISCOMPLETE_S(state, JOY_I_MACRO_ARGLIST(macro))

#endif /* !JOY_MACRO_H */
