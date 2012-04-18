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
# ifndef CHAOS_PREPROCESSOR_TUPLE_POP_BACK_H
# define CHAOS_PREPROCESSOR_TUPLE_POP_BACK_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/batch.h>
# include <chaos/preprocessor/tuple/core.h>
# include <chaos/preprocessor/tuple/eat.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_TUPLE_POP_BACK */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_POP_BACK(tuple) CHAOS_PP_TUPLE_POP_BACK_BYPASS(CHAOS_PP_LIMIT_EXPR, tuple)
#    define CHAOS_PP_TUPLE_POP_BACK_ID() CHAOS_PP_TUPLE_POP_BACK
#    define CHAOS_PP_TUPLE_POP_BACK_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_POP_BACK_ID)()
# endif
#
# /* CHAOS_PP_TUPLE_POP_BACK_BYPASS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_POP_BACK_BYPASS(s, tuple) \
        CHAOS_PP_EXPR_S(s)(CHAOS_IP_TUPLE_POP_BACK_1( \
            CHAOS_PP_PREV(s), tuple \
        )) \
        /**/
#    define CHAOS_PP_TUPLE_POP_BACK_BYPASS_ID() CHAOS_PP_TUPLE_POP_BACK_BYPASS
#    define CHAOS_PP_TUPLE_POP_BACK_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_POP_BACK_BYPASS_ID)()
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_TUPLE_POP_BACK_INDIRECT(n) CHAOS_IP_TUPLE_POP_BACK_ ## n
#    define CHAOS_IP_TUPLE_POP_BACK_1(s, tuple) \
        CHAOS_PP_IIF(CHAOS_PP_TUPLE_IS_BATCH(11, tuple))( \
            CHAOS_IP_TUPLE_POP_BACK_1_I, CHAOS_IP_TUPLE_POP_BACK_2 \
        )(s, tuple) \
        /**/
#    define CHAOS_IP_TUPLE_POP_BACK_1_I(s, tuple) \
        CHAOS_IP_TUPLE_POP_BACK_1_II(s, CHAOS_PP_TUPLE_REM_CTOR(?, CHAOS_PP_TUPLE_BATCH(10, tuple)), CHAOS_PP_TUPLE_SANS_BATCH(10, tuple)) \
        /**/
#    define CHAOS_IP_TUPLE_POP_BACK_1_II(...) CHAOS_IP_TUPLE_POP_BACK_1_III(CHAOS_PP_OBSTRUCT(), __VA_ARGS__)
#    define CHAOS_IP_TUPLE_POP_BACK_1_III(_, s, a, b, c, d, e, f, g, h, i, j, tuple) \
        CHAOS_PP_TUPLE_CONS _(CHAOS_PP_TUPLE_CONS _(CHAOS_PP_TUPLE_CONS _(CHAOS_PP_TUPLE_CONS _(CHAOS_PP_TUPLE_CONS _( \
        CHAOS_PP_TUPLE_CONS _(CHAOS_PP_TUPLE_CONS _(CHAOS_PP_TUPLE_CONS _(CHAOS_PP_TUPLE_CONS _(CHAOS_PP_TUPLE_CONS _( \
            CHAOS_PP_EXPR_S _(s)(CHAOS_IP_TUPLE_POP_BACK_INDIRECT _(1)( \
                CHAOS_PP_PREV(s), tuple \
            )), \
            j), i), h), g), f), e), d), c), b), a) \
        /**/
#    define CHAOS_IP_TUPLE_POP_BACK_2(s, tuple) \
        CHAOS_PP_IIF(CHAOS_PP_TUPLE_IS_BATCH(2, tuple))( \
            CHAOS_IP_TUPLE_POP_BACK_2_I, CHAOS_PP_EAT \
        )(CHAOS_PP_OBSTRUCT(), s, tuple) \
        /**/
#    define CHAOS_IP_TUPLE_POP_BACK_2_I(_, s, tuple) \
        CHAOS_PP_TUPLE_CONS _( \
            CHAOS_PP_EXPR_S _(s)(CHAOS_IP_TUPLE_POP_BACK_INDIRECT _(2)( \
                CHAOS_PP_PREV(s), CHAOS_PP_TUPLE_TAIL(tuple) \
            )), \
            CHAOS_PP_TUPLE_HEAD(tuple) \
        ) \
        /**/
# endif
#
# endif
