# /* ********************************************************************
#  *                                                                    *
#  *    (C) Copyright Paul Mensonides 2003-2005.                        *
#  *                                                                    *
#  *    Distributed under the Boost Software License, Version 1.0.      *
#  *    (See accompanying file LICENSE).                                *
#  *                                                                    *
#  *    See http://chaos-pp.sourceforge.net for most recent version.    *
#  *                                                                    *
#  ******************************************************************** */
#
# ifndef CHAOS_PREPROCESSOR_ALGORITHM_FOLD_RIGHT_AUX_H
# define CHAOS_PREPROCESSOR_ALGORITHM_FOLD_RIGHT_AUX_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/control/inline_when.h>
# include <chaos/preprocessor/detection/is_unary.h>
# include <chaos/preprocessor/detection/is_variadic.h>
# include <chaos/preprocessor/generics/core.h>
# include <chaos/preprocessor/generics/typeof.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/lambda/planar.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/eat.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_FOLD_RIGHT_AUX */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOLD_RIGHT_AUX(op, g, data, ...) CHAOS_PP_FOLD_RIGHT_AUX_S(CHAOS_PP_STATE(), op, g, data, __VA_ARGS__)
#    define CHAOS_PP_FOLD_RIGHT_AUX_ CHAOS_PP_LAMBDA(CHAOS_PP_FOLD_RIGHT_AUX_ID)()
# else
#    define CHAOS_PP_FOLD_RIGHT_AUX(op, g, data, state) CHAOS_PP_FOLD_RIGHT_AUX_S(CHAOS_PP_STATE(), op, g, data, state)
# endif
#
# define CHAOS_PP_FOLD_RIGHT_AUX_ID() CHAOS_PP_FOLD_RIGHT_AUX
#
# /* CHAOS_PP_FOLD_RIGHT_AUX_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOLD_RIGHT_AUX_S(s, op, g, data, ...) \
        CHAOS_IP_FOLD_RIGHT_AUX_U(s, op, g, CHAOS_PP_INLINE_WHEN(CHAOS_PP_IS_VARIADIC(data))(CHAOS_PP_REM)(data), (__VA_ARGS__)) \
        /**/
#    define CHAOS_PP_FOLD_RIGHT_AUX_S_ CHAOS_PP_LAMBDA(CHAOS_PP_FOLD_RIGHT_AUX_S_ID)()
# else
#    define CHAOS_PP_FOLD_RIGHT_AUX_S(s, op, g, data, state) \
        CHAOS_IP_FOLD_RIGHT_AUX_U(s, op, g, CHAOS_PP_INLINE_WHEN(CHAOS_PP_IS_UNARY(data))(CHAOS_PP_REM)(data), (state)) \
        /**/
# endif
#
# define CHAOS_PP_FOLD_RIGHT_AUX_S_ID() CHAOS_PP_FOLD_RIGHT_AUX_S
#
# define CHAOS_IP_FOLD_RIGHT_AUX_U(s, op, g, data, ps) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_FOLD_RIGHT_AUX_I( \
        CHAOS_PP_NEXT(s), CHAOS_PP_NEXT(s), \
        op, CHAOS_PP_PLANAR(op), CHAOS_PP_TYPEOF(g), g, data, ps \
    )) \
    /**/
# define CHAOS_IP_FOLD_RIGHT_AUX_INDIRECT() CHAOS_IP_FOLD_RIGHT_AUX_I
# define CHAOS_IP_FOLD_RIGHT_AUX_I(s, o, op, _o, type, g, data, ps) \
    CHAOS_PP_IIF(CHAOS_PP_IS_CONS(g))( \
        CHAOS_IP_FOLD_RIGHT_AUX_II, CHAOS_PP_REM ps CHAOS_PP_TUPLE_EAT(9) \
    )(CHAOS_PP_OBSTRUCT(), s, o, op, _o, type, g, data, ps) \
    /**/
# define CHAOS_IP_FOLD_RIGHT_AUX_II(_, s, o, op, _o, type, g, data, ps) \
    _o()(o, op) \
        CHAOS_PP_ITEM(type, CHAOS_PP_HEAD(g)), CHAOS_PP_REM data, \
        CHAOS_PP_EXPR_S(s) _(CHAOS_IP_FOLD_RIGHT_AUX_INDIRECT _()( \
            CHAOS_PP_NEXT(s), o, op, _o, type, CHAOS_PP_TAIL(g), data, ps \
        )) \
    CHAOS_PP_PLANAR_CLOSE() \
    /**/
#
# endif
