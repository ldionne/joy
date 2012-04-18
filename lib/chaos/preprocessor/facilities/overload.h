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
# ifndef CHAOS_PREPROCESSOR_FACILITIES_OVERLOAD_H
# define CHAOS_PREPROCESSOR_FACILITIES_OVERLOAD_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/tuple/core.h>
# include <chaos/preprocessor/tuple/size.h>
#
# /* CHAOS_PP_QUICK_OVERLOAD */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_QUICK_OVERLOAD(pre, ...) CHAOS_PP_CAT(pre, CHAOS_PP_TUPLE_QUICK_SIZE((__VA_ARGS__)))
#    define CHAOS_PP_QUICK_OVERLOAD_ID() CHAOS_PP_QUICK_OVERLOAD
#    define CHAOS_PP_QUICK_OVERLOAD_ CHAOS_PP_LAMBDA(CHAOS_PP_QUICK_OVERLOAD)
# endif
#
# /* CHAOS_PP_OVERLOAD */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_OVERLOAD(pre, ...) CHAOS_PP_OVERLOAD_BYPASS(CHAOS_PP_LIMIT_EXPR, pre, __VA_ARGS__)
#    define CHAOS_PP_OVERLOAD_ID() CHAOS_PP_OVERLOAD
#    define CHAOS_PP_OVERLOAD_ CHAOS_PP_LAMBDA(CHAOS_PP_OVERLOAD)
# endif
#
# /* CHAOS_PP_OVERLOAD_BYPASS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_OVERLOAD_BYPASS(s, pre, ...) \
        CHAOS_PP_CAT(pre, CHAOS_PP_TUPLE_SIZE_BYPASS(s, (__VA_ARGS__))) \
        /**/
#    define CHAOS_PP_OVERLOAD_BYPASS_ID() CHAOS_PP_OVERLOAD_BYPASS
#    define CHAOS_PP_OVERLOAD_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_OVERLOAD_BYPASS)
# endif
#
# endif
