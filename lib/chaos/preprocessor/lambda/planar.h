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
# ifndef CHAOS_PREPROCESSOR_LAMBDA_PLANAR_H
# define CHAOS_PREPROCESSOR_LAMBDA_PLANAR_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/detection/is_variadic.h>
# include <chaos/preprocessor/lambda/invoke.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/block.h>
# include <chaos/preprocessor/recursion/expr.h>
#
# /* CHAOS_PP_PLANAR */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_PLANAR(x) CHAOS_PP_CAT(CHAOS_IP_PLANAR_, CHAOS_PP_IS_VARIADIC(x))
#    define CHAOS_PP_PLANAR_ CHAOS_PP_LAMBDA(CHAOS_PP_PLANAR)
# else
#    define CHAOS_PP_PLANAR(x) CHAOS_IP_PLANAR_0
# endif
#
# define CHAOS_PP_PLANAR_ID() CHAOS_PP_PLANAR
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_PLANAR_1() CHAOS_IP_PLANAR_11
#    define CHAOS_IP_PLANAR_11(s, expr) CHAOS_IP_PLANAR_111(CHAOS_PP_BLOCK, s, CHAOS_PP_NEXT(s), expr)
#    define CHAOS_IP_PLANAR_111(_, s1, s2, expr) \
        _(2, CHAOS_PP_EXPR_S)(s1)( \
            _(3, CHAOS_PP_EXPR_S)(s2)(_(3, CHAOS_PP_EXPR_S)(s2)( \
                _(2, CHAOS_PP_EXPR_S)(s1)(_(2, CHAOS_PP_INVOKE)(expr, s2, \
        /**/
# endif
#
# define CHAOS_IP_PLANAR_0() CHAOS_IP_PLANAR_00
# define CHAOS_IP_PLANAR_00(s, macro) CHAOS_IP_PLANAR_000(CHAOS_PP_BLOCK, s, CHAOS_PP_NEXT(s), macro)
# define CHAOS_IP_PLANAR_000(_, s1, s2, macro) \
    _(2, CHAOS_PP_EXPR_S)(s1)( \
        _(3, CHAOS_PP_EXPR_S)(s2)(_(3, CHAOS_PP_EXPR_S)(s2)( \
            _(2, CHAOS_PP_EXPR_S)(s1)(_(3, macro)(s2, \
    /**/
#
# /* CHAOS_PP_PLANAR_CLOSE */
#
# define CHAOS_PP_PLANAR_CLOSE() )))))
# define CHAOS_PP_PLANAR_CLOSE_ID() CHAOS_PP_PLANAR_CLOSE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_PLANAR_CLOSE_ CHAOS_PP_LAMBDA(CHAOS_PP_PLANAR_CLOSE)
# endif
#
# endif
