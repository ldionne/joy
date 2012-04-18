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
# ifndef CHAOS_PREPROCESSOR_ALGORITHM_PREPEND_H
# define CHAOS_PREPROCESSOR_ALGORITHM_PREPEND_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/generics/core.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
#
# /* CHAOS_PP_PREPEND */
#
# define CHAOS_PP_PREPEND(g1, g2) CHAOS_PP_PREPEND_BYPASS(CHAOS_PP_LIMIT_EXPR, g1, g2)
# define CHAOS_PP_PREPEND_ID() CHAOS_PP_PREPEND
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_PREPEND_ CHAOS_PP_LAMBDA(CHAOS_PP_PREPEND_ID)()
# endif
#
# /* CHAOS_PP_PREPEND_BYPASS */
#
# define CHAOS_PP_PREPEND_BYPASS(s, g1, g2) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_PREPEND_I(CHAOS_PP_OBSTRUCT(), CHAOS_PP_PREV(s), g1, g2)) \
    /**/
# define CHAOS_PP_PREPEND_BYPASS_ID() CHAOS_PP_PREPEND_BYPASS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_PREPEND_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_PREPEND_BYPASS_ID)()
# endif
#
# define CHAOS_IP_PREPEND_INDIRECT() CHAOS_IP_PREPEND_I
# define CHAOS_IP_PREPEND_I(_, s, g1, g2) \
    CHAOS_PP_IIF _(CHAOS_PP_IS_CONS(g1))( \
        CHAOS_PP_CONS _( \
            CHAOS_PP_EXPR_S(s) _(CHAOS_IP_PREPEND_INDIRECT _()( \
                CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), CHAOS_PP_TAIL _(g1), g2 \
            )), \
            CHAOS_PP_HEAD _(g1) \
        ), \
        g2 \
    ) \
    /**/
#
# endif
