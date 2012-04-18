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
# ifndef CHAOS_PREPROCESSOR_REPETITION_ENUM_SHIFTED_TRAILING_H
# define CHAOS_PREPROCESSOR_REPETITION_ENUM_SHIFTED_TRAILING_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/punctuation/comma_if.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/repetition/enum_shifted.h>
#
# /* CHAOS_PP_ENUM_SHIFTED_TRAILING */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ENUM_SHIFTED_TRAILING(count, ...) CHAOS_PP_ENUM_SHIFTED_TRAILING_S(CHAOS_PP_STATE(), count, __VA_ARGS__)
#    define CHAOS_PP_ENUM_SHIFTED_TRAILING_ CHAOS_PP_LAMBDA(CHAOS_PP_ENUM_SHIFTED_TRAILING_ID)()
# else
#    define CHAOS_PP_ENUM_SHIFTED_TRAILING(count, macro, data) CHAOS_PP_ENUM_SHIFTED_TRAILING_S(CHAOS_PP_STATE(), count, macro, data)
# endif
#
# define CHAOS_PP_ENUM_SHIFTED_TRAILING_ID() CHAOS_PP_ENUM_SHIFTED_TRAILING
#
# /* CHAOS_PP_ENUM_SHIFTED_TRAILING_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ENUM_SHIFTED_TRAILING_S(s, count, ...) CHAOS_PP_COMMA_IF(CHAOS_PP_DEC(count)) CHAOS_PP_ENUM_SHIFTED_S(s, count, __VA_ARGS__)
#    define CHAOS_PP_ENUM_SHIFTED_TRAILING_S_ CHAOS_PP_LAMBDA(CHAOS_PP_ENUM_SHIFTED_TRAILING_S_ID)()
# else
#    define CHAOS_PP_ENUM_SHIFTED_TRAILING_S(s, count, macro, data) CHAOS_PP_COMMA_IF(CHAOS_PP_DEC(count)) CHAOS_PP_ENUM_SHIFTED_S(s, count, macro, data)
# endif
#
# define CHAOS_PP_ENUM_SHIFTED_TRAILING_S_ID() CHAOS_PP_ENUM_SHIFTED_TRAILING_S
#
# endif
